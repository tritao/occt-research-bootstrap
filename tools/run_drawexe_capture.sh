#!/usr/bin/env bash
set -euo pipefail

usage() {
  cat <<'EOF'
Usage:
  tools/run_drawexe_capture.sh --drawexe /path/to/DRAWEXE --script path/to/script.tcl --out path/to/log.txt [--mode batch|virtual|interactive]

Notes:
  - Captures stdout+stderr into --out.
  - Exits with DRAWEXE's exit code.
  - Default mode is batch (no GUI/viewers).
EOF
}

DRAWEXE=""
SCRIPT=""
OUT=""
MODE="batch"

while [[ $# -gt 0 ]]; do
  case "$1" in
    --drawexe)
      DRAWEXE="${2:-}"
      shift 2
      ;;
    --script)
      SCRIPT="${2:-}"
      shift 2
      ;;
    --out)
      OUT="${2:-}"
      shift 2
      ;;
    --mode)
      MODE="${2:-}"
      shift 2
      ;;
    -h|--help)
      usage
      exit 0
      ;;
    *)
      echo "unknown arg: $1" >&2
      usage >&2
      exit 2
      ;;
  esac
done

if [[ -z "${DRAWEXE}" || -z "${SCRIPT}" || -z "${OUT}" ]]; then
  usage >&2
  exit 2
fi

if [[ ! -x "${DRAWEXE}" ]]; then
  echo "DRAWEXE not executable: ${DRAWEXE}" >&2
  exit 2
fi

if [[ ! -f "${SCRIPT}" ]]; then
  echo "script not found: ${SCRIPT}" >&2
  exit 2
fi

mkdir -p "$(dirname "${OUT}")"

mode_flag="-b"
case "${MODE}" in
  batch) mode_flag="-b" ;;
  virtual) mode_flag="-v" ;;
  interactive) mode_flag="-i" ;;
  *)
    echo "unknown --mode: ${MODE} (expected: batch|virtual|interactive)" >&2
    exit 2
    ;;
esac

set +e
"${DRAWEXE}" "${mode_flag}" -f "${SCRIPT}" >"${OUT}" 2>&1
code=$?
set -e

echo "wrote ${OUT}"
exit "${code}"
