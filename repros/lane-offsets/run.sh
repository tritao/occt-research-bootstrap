#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
REPRO_DIR="$ROOT/repros/lane-offsets"

# build-occt/env.sh assumes unset variables may be referenced; avoid nounset failures.
source "$ROOT/tools/occt_env.sh"

mkdir -p "$REPRO_DIR/build" "$REPRO_DIR/golden"

cxx="${CXX:-g++}"
"$cxx" -std=c++17 -O2 -g \
  -I"$CSF_OCCTIncludePath" \
  "$REPRO_DIR/offsets.cpp" \
  -L"$CSF_OCCTLibPath" \
  -Wl,-rpath,"$CSF_OCCTLibPath" \
  -lTKOffset -lTKBO -lTKBool -lTKTopAlgo -lTKGeomAlgo -lTKBRep -lTKPrim -lTKGeomBase -lTKG3d -lTKG2d -lTKMath -lTKMesh -lTKShHealing -lTKernel \
  -o "$REPRO_DIR/build/offsets"

"$REPRO_DIR/build/offsets" --artifacts-dir "$REPRO_DIR/golden/artifacts" > "$REPRO_DIR/golden/offsets.json"
echo "wrote $REPRO_DIR/golden/offsets.json"
