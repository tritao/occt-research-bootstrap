# DRAWEXE script for FreeCAD issue #8549 (OCCT fillet bumpy on cylinder edge).
#
# Usage (inside DRAWEXE):
#   pload MODELING VISUALIZATION
#   pload MeshTest
#   source bumpy-cylinder-fillet.tcl
#
# This script intentionally stays "semi-manual":
# it creates the shapes and tells you which variables to use,
# because edge indexing from `explode` can vary across builds.

proc _globalize {args} {
  # DRAW objects are stored as Tcl variables; inside procs they must be declared global
  # to be visible/usable after the proc returns (and across other helper procs).
  set vars {}
  foreach v $args {
    if {$v != ""} { lappend vars $v }
  }
  if {[llength $vars] != 0} {
    uplevel 1 [linsert $vars 0 global]
  }
}

proc _ensure_toolkits {} {
  # Try to make this script runnable in non-interactive mode (DRAWEXE < script.tcl).
  # Commands like `cylinder` and `blend` live in MODELING toolkits.
  if {[llength [info commands cylinder]] == 0} {
    catch {pload MODELING VISUALIZATION}
  }
  if {[llength [info commands cylinder]] == 0} {
    puts ""
    puts "ERROR: missing DRAW command 'cylinder'."
    puts "Hint: run 'pload MODELING VISUALIZATION' before sourcing this script,"
    puts "or rebuild DRAWEXE with OCCT Draw/MODELING modules enabled."
    puts ""
    return 0
  }
  if {[llength [info commands mpincmesh]] == 0} {
    catch {pload MeshTest}
  }
  if {[llength [info commands mpincmesh]] == 0} {
    puts ""
    puts "WARN: missing 'mpincmesh' (MeshTest plugin)."
    puts "You can still create fillets, but you won't be able to vary meshing deflection here."
    puts "Try: pload MeshTest"
    puts ""
  }
  return 1
}

proc _mk_cyl {name r h} {
  puts ""
  puts "=== make cylinder: $name (R=$r H=$h) ==="
  _globalize $name
  if {[llength [info commands pcylinder]] != 0} {
    pcylinder $name $r $h
  } else {
    # Fallback: beware name collision with GeomliteTest "cylinder" (creates a surface).
    cylinder $name $r $h
  }
  for {set i 1} {$i <= 32} {incr i} {
    _globalize "${name}_$i"
  }
  explode $name e
  puts "Edges for $name are now: ${name}_1 ${name}_2 ${name}_3 ..."
  puts "Tip: display edges to pick a circular rim edge:"
  if {[llength [info commands vinit]] != 0} {
    puts "  vinit; vdisplay ${name}_1 ${name}_2 ${name}_3; vfit"
  } else {
    puts "  (visualization commands not available; use 'dump'/'dtyp' to inspect edges)"
  }
  puts "Pick a circular rim edge variable (NOT the seam) and use it as EDGE."
}

proc _mk_fillet {res shape radius edgeVar} {
  puts ""
  puts "=== fillet: $res = fillet($shape, r=$radius, edge=$edgeVar) ==="
  puts "Command:"
  puts "  blend $res $shape $radius $edgeVar"
  _globalize $res $shape $edgeVar
  blend $res $shape $radius $edgeVar
}

proc _mesh_show {shape defl angle} {
  puts ""
  puts "=== mesh+show: $shape (defl=$defl angle=$angle) ==="
  puts "Commands:"
  _globalize $shape
  if {[llength [info commands mpincmesh]] != 0} {
    puts "  mpincmesh $shape $defl $angle"
    mpincmesh $shape $defl $angle
  } else {
    puts "  (mpincmesh unavailable; skipping remeshing)"
  }
  if {[llength [info commands vinit]] != 0} {
    puts "  vinit; vdisplay $shape; vsetdispmode 1; vfit"
    vinit
    vdisplay $shape
    vsetdispmode 1
    vfit
  }
}

proc repro_8549 {} {
  if {[_ensure_toolkits] == 0} {
    return
  }
  puts ""
  puts "## Repro for FreeCAD issue #8549"
  puts "Goal: compare cylinder radii (25, 64, 65) with a 1mm fillet on a circular rim edge."
  puts "Then vary mesh deflection to see if 'bumps' are tessellation-driven."
  puts ""

  foreach r {25 64 65} {
    set name "cyl$r"
    _mk_cyl $name $r 10
    puts ""
    puts "Now choose an edge (example): set EDGE ${name}_2"
    puts "Then run:"
    puts "  set EDGE ${name}_2"
    puts "  _mk_fillet f$r $name 1 \$EDGE"
    puts "  _mesh_show f$r 0.2 0.5"
    puts "  _mesh_show f$r 0.05 0.5"
    puts "  _mesh_show f$r 0.01 0.5"
  }

  puts ""
  puts "If bumps change with deflection, suspect triangulation/display rather than fillet surface."
}

# Auto-run by default when sourced interactively.
# If you're running this script non-interactively, you may prefer to call `repro_8549` yourself.
repro_8549
