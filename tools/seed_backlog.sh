#!/usr/bin/env bash
set -euo pipefail

# Seed a first task in Backlog.md if it does not exist.
TITLE="Lane selection + initial task generation"

if ! command -v backlog >/dev/null 2>&1; then
  echo "[backlog] backlog not on PATH. Did you run: source ./env.sh ?"
  exit 2
fi

if [ ! -d "./backlog" ]; then
  echo "[backlog] backlog/ not initialized. Run: just backlog-init"
  exit 2
fi

# Avoid duplicate tasks if already seeded.
if rg -n --fixed-strings "$TITLE" backlog >/dev/null 2>&1; then
  echo "[backlog] Task already exists: $TITLE"
  exit 0
fi

backlog task add "$TITLE"
echo "[backlog] Added task: $TITLE"
