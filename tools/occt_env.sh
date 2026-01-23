#!/usr/bin/env bash
set -euo pipefail

# Lightweight OCCT env for repro scripts.
#
# We intentionally avoid sourcing `build-occt/env.sh` because it can contain
# absolute paths that become stale when the repo is moved/renamed.

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

inc="$ROOT/build-occt/include/opencascade"
if [[ ! -d "$inc" ]]; then
  echo "[occt_env] missing include dir: $inc" >&2
  return 1
fi

# The generated include wrappers in build-occt often embed absolute paths to the
# repo checkout used at configure time (e.g. /home/.../occt-research-bootstrap/...).
# If the repo was moved/renamed, those wrappers break compilation. Patch them
# in-place (build dir is gitignored) to point at the current repo root.
_probe="$inc/Standard_VersionInfo.hxx"
if [[ -f "$_probe" ]]; then
  _line="$(head -n 1 "$_probe" || true)"
  if [[ "$_line" =~ ^#include\ \"(.+)/occt/src/Standard/Standard_VersionInfo\.hxx\"$ ]]; then
    _old_root="${BASH_REMATCH[1]}"
    if [[ -n "$_old_root" && "$_old_root" != "$ROOT" ]]; then
      echo "[occt_env] patching build include wrappers: $_old_root -> $ROOT" >&2
      find "$inc" -maxdepth 1 -type f -print0 | xargs -0 sed -i "s|$_old_root/occt/src/|$ROOT/occt/src/|g"
    fi
  fi
fi

lib=""
for cand in "$ROOT/build-occt/lin64/gcc/libi" "$ROOT/build-occt/lin64/gcc/lib" "$ROOT/build-occt/lin64/gcc/lib64"; do
  if [[ -d "$cand" ]]; then
    lib="$cand"
    break
  fi
done
if [[ -z "$lib" ]]; then
  echo "[occt_env] missing OCCT lib dir under $ROOT/build-occt/lin64/gcc (expected libi/lib)" >&2
  return 1
fi

export CSF_OCCTIncludePath="$inc"
export CSF_OCCTLibPath="$lib"
export LD_LIBRARY_PATH="$CSF_OCCTLibPath${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"
