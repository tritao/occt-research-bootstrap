# Fully automatic variant of the #8549 repro:
# - auto-picks a usable edge by trying each exploded edge
# - runs headless-friendly (no vinit/vdisplay required)
#
# Usage:
#   DRAWEXE -f notes/issues/freecad/fillet/08549/bumpy-cylinder-fillet-auto.tcl
#
# Or inside an interactive DRAW session:
#   source notes/issues/freecad/fillet/08549/bumpy-cylinder-fillet-auto.tcl

proc _globalize {args} {
  # DRAW objects are stored as Tcl variables; inside procs they must be declared global
  # to be visible/usable by DRAW commands (blend/explode/isdraw/etc).
  set vars {}
  foreach v $args {
    if {$v != ""} { lappend vars $v }
  }
  if {[llength $vars] != 0} {
    uplevel 1 [linsert $vars 0 global]
  }
}

proc _ensure_toolkits {} {
  if {[llength [info commands cylinder]] == 0 && [llength [info commands pcylinder]] == 0} {
    catch {pload MODELING VISUALIZATION}
  }
  if {[llength [info commands cylinder]] == 0 && [llength [info commands pcylinder]] == 0} {
    puts "ERROR: missing DRAW primitive commands ('pcylinder' or 'cylinder'); load MODELING toolkits"
    return 0
  }
  if {[llength [info commands blend]] == 0} {
    catch {pload MODELING}
  }
  if {[llength [info commands explode]] == 0} {
    catch {pload MODELING}
  }
  if {[llength [info commands mpincmesh]] == 0} {
    catch {pload MeshTest}
  }
  return 1
}

proc _shape_exists {name} {
  if {[llength [info commands isdraw]] == 0} {
    # Conservative: if we can't check, assume it exists to avoid false negatives.
    return 1
  }
  _globalize $name
  return [isdraw $name]
}

proc _try_fillet {res shape radius edgeVar} {
  puts "TRY: blend $res $shape $radius $edgeVar"
  _globalize $res $shape $edgeVar
  set msg ""
  set code [catch {blend $res $shape $radius $edgeVar} msg]
  if {$code != 0} {
    puts "  TCL_ERROR: $msg"
  }
  if {[_shape_exists $res]} {
    puts "OK: $res created"
    return 1
  }
  puts "FAIL: $res not created"
  return 0
}

proc _is_circular_edge {edgeVar} {
  # Prefer rim edges: on a cylinder these are circles; the seam is a line.
  # Uses SWDRAW_ShapeAnalysis "getanacurve" if available.
  if {[llength [info commands getanacurve]] == 0} {
    return 0
  }
  _globalize $edgeVar __tmp_cir
  catch {del __tmp_cir}
  # "cir" = circle; use a tight tol since this is an analytic cylinder.
  catch {getanacurve __tmp_cir $edgeVar cir 1.0e-9}
  set ok [_shape_exists __tmp_cir]
  catch {del __tmp_cir}
  return $ok
}

proc _cleanup_prefix {prefix maxN} {
  # Avoid stale objects from prior interactive runs.
  if {[llength [info commands del]] == 0} { return }
  _globalize $prefix
  catch {del $prefix}
  for {set i 1} {$i <= $maxN} {incr i} {
    set v "${prefix}_$i"
    _globalize $v
    catch {del $v}
  }
}

proc _collect_exploded_edges {shape maxN} {
  set edges {}
  if {[llength [info commands isdraw]] == 0} {
    return $edges
  }
  for {set i 1} {$i <= $maxN} {incr i} {
    set e "${shape}_$i"
    _globalize $e
    if {[isdraw $e]} {
      if {[llength [info commands dtyp]] != 0} {
        set t [string trim [dtyp $e]]
        if {[string first "EDGE" $t] < 0} {
          continue
        }
      }
      lappend edges $e
    }
  }
  return $edges
}

proc _mk_solid_cylinder {name r h} {
  # IMPORTANT: 'cylinder' is ambiguous in DRAW (can be an analytic surface when GeomliteTest is loaded).
  # Prefer 'pcylinder' (BRep primitive) when available.
  set cmd ""
  if {[llength [info commands pcylinder]] != 0} {
    set cmd "pcylinder"
  } elseif {[llength [info commands cylinder]] != 0} {
    set cmd "cylinder"
  }

  if {$cmd == ""} {
    puts "ERROR: no cylinder command available"
    return 0
  }

  set ::_last_cylinder_cmd $cmd
  puts "MK_CYLINDER: $cmd $name $r $h"
  _globalize $name
  if {$cmd == "pcylinder"} {
    pcylinder $name $r $h
  } else {
    cylinder $name $r $h
  }
  return 1
}

proc _mk_case {r h filletRad defls} {
  set cyl "cyl$r"
  set out "f$r"

  puts ""
  puts "=== CASE: cylinder R=$r H=$h fillet=$filletRad ==="
  _globalize $cyl $out
  _cleanup_prefix $cyl 32
  _cleanup_prefix $out 32
  if {[_mk_solid_cylinder $cyl $r $h] == 0} {
    return 0
  }

  if {[llength [info commands isdraw]] != 0} {
    puts "SHAPE_EXISTS: $cyl => [isdraw $cyl]"
  }
  if {[llength [info commands dtyp]] != 0} {
    puts "SHAPE_TYPE: $cyl => [string trim [dtyp $cyl]]"
  }

  # explode doesn't reliably return the created names via Tcl result;
  # instead, we call explode for its side-effects and then probe ${cyl}_N.
  for {set i 1} {$i <= 32} {incr i} {
    _globalize "${cyl}_$i"
  }
  explode $cyl e
  set edges [_collect_exploded_edges $cyl 32]
  # If we accidentally created an analytic surface (common after 'pload ALL'),
  # retry using 'pcylinder' (BRep primitive) if available.
  if {[llength $edges] == 0
      && [info exists ::_last_cylinder_cmd]
      && $::_last_cylinder_cmd == "cylinder"
      && [llength [info commands pcylinder]] != 0} {
    puts "WARN: no edges from explode; retrying with 'pcylinder' (likely 'cylinder' created a surface)"
    if {[_mk_solid_cylinder $cyl $r $h] == 0} {
      return 0
    }
    explode $cyl e
    set edges [_collect_exploded_edges $cyl 32]
  }
  puts "EDGES: [join $edges { }]"
  if {[llength $edges] == 0} {
    puts "ERROR: explode returned no edges for $cyl"
    return 0
  }

  if {[llength [info commands dtyp]] != 0} {
    foreach e $edges {
      puts "EDGE_TYPE: $e => [string trim [dtyp $e]]"
    }
  }

  # Prefer circular (rim) edges over non-circular ones (e.g. seam).
  set circleEdges {}
  set otherEdges {}
  if {[llength [info commands getanacurve]] != 0} {
    foreach e $edges {
      if {[_is_circular_edge $e]} {
        lappend circleEdges $e
        puts "EDGE_CLASS: $e => CIRCLE"
      } else {
        lappend otherEdges $e
        puts "EDGE_CLASS: $e => NON_CIRCLE"
      }
    }
  } else {
    set otherEdges $edges
    puts "WARN: 'getanacurve' not available; cannot auto-skip seam edge"
  }

  # Try each candidate edge and keep the first successful fillet.
  set ok 0
  foreach e [concat $circleEdges $otherEdges] {
    if {[_try_fillet $out $cyl $filletRad $e]} {
      puts "SELECTED_EDGE: $e"
      set ok 1
      break
    }
  }

  if {!$ok} {
    puts "ERROR: could not fillet any edge on $cyl"
    return 0
  }

  # Mesh at multiple deflections (if available).
  if {[llength [info commands mpincmesh]] != 0} {
    _globalize $out
    foreach d $defls {
      puts "MESH: mpincmesh $out $d 0.5"
      catch {mpincmesh $out $d 0.5}
    }
  } else {
    puts "WARN: mpincmesh not available; skipping meshing sweep"
  }

  # Quick introspection hooks for logs.
  if {[llength [info commands dump]] != 0} {
    puts "DUMP_SHAPE: $out"
    catch {dump $out}
  }
  return 1
}

proc repro_8549_auto {} {
  if {[_ensure_toolkits] == 0} { return }
  puts "## Repro #8549 (auto): cylinder rim fillet bumpiness"
  set defls {0.2 0.05 0.01}

  # Reported: bumps present for R=25..64, disappear at R=65 (with fillet radius 1, H=10)
  _mk_case 25 10 1 $defls
  _mk_case 64 10 1 $defls
  _mk_case 65 10 1 $defls

  puts ""
  puts "NEXT: If visual bumps change with deflection, suspect triangulation/display."
  puts "NEXT: For geometry type, use: explode f25 f; mksurface s f25_?; dump s"
}

repro_8549_auto
