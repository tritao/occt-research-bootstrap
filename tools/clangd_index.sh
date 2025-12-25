#!/usr/bin/env bash
set -euo pipefail

ROOT="${1:-$(pwd)}"
BUILD_DIR="${2:-$ROOT/build-occt}"
OUT_DIR="${3:-$ROOT/.cache/clangd-index}"

if ! command -v clangd-indexer >/dev/null 2>&1; then
  echo "[clangd-index] clangd-indexer not found. Install clangd indexing tools or skip."
  exit 1
fi

mkdir -p "$OUT_DIR"

echo "[clangd-index] Building index from $BUILD_DIR/compile_commands.json ..."
out_file="$OUT_DIR/clangd.dex"
clangd-indexer \
  --executor=all-TUs \
  -p "$BUILD_DIR" \
  "$BUILD_DIR/compile_commands.json" > "$out_file"

echo "[clangd-index] Done: $out_file"
