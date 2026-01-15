#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
REPRO_DIR="$ROOT/repros/lane-core-kernel"

# build-occt/env.sh assumes unset variables may be referenced; avoid nounset failures.
set +u
source "$ROOT/build-occt/env.sh" i
set -u

mkdir -p "$REPRO_DIR/build" "$REPRO_DIR/golden"

cxx="${CXX:-g++}"
"$cxx" -std=c++17 -O2 -g \
  -I"$CSF_OCCTIncludePath" \
  "$REPRO_DIR/core_kernel.cpp" \
  -L"$CSF_OCCTLibPath" \
  -lTKMath -lTKernel \
  -o "$REPRO_DIR/build/core-kernel"

"$REPRO_DIR/build/core-kernel" > "$REPRO_DIR/golden/core-kernel.json"
echo "wrote $REPRO_DIR/golden/core-kernel.json"

