\
#!/usr/bin/env bash
set -euo pipefail

OCCT_DIR="${1:?usage: build_occt.sh <occt_dir> <build_dir>}"
BUILD_DIR="${2:?usage: build_occt.sh <occt_dir> <build_dir>}"

./tools/configure_occt.sh "$OCCT_DIR" "$BUILD_DIR"

jobs="${OCCT_BUILD_JOBS:-4}"
cmake --build "$BUILD_DIR" -j"$jobs"

# Symlink compile DB to repo root for tooling
root="$(cd "$(dirname "$BUILD_DIR")" && pwd)"
ln -sf "$BUILD_DIR/compile_commands.json" "$root/compile_commands.json"

echo "[occt] Build complete."
