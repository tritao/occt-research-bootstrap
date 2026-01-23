#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
from pathlib import Path

from jsonschema.validators import validator_for


def fail(msg: str) -> None:
    print(f"[FAIL] {msg}")


def ok(msg: str) -> None:
    print(f"[OK] {msg}")


def _is_finite_number(x: object) -> bool:
    if not isinstance(x, (int, float)):
        return False
    return math.isfinite(float(x))


def _validate_vec3(data: object, *, ctx: str) -> list[str]:
    if not isinstance(data, list) or len(data) != 3:
        return [f"{ctx}: expected vec3 array length 3"]
    if any(not _is_finite_number(x) for x in data):
        return [f"{ctx}: contains non-finite entries"]
    return []


def _validate_bbox(obj: object, *, ctx: str) -> list[str]:
    if not isinstance(obj, dict):
        return [f"{ctx}: expected object"]
    errs: list[str] = []
    errs.extend(_validate_vec3(obj.get("min"), ctx=f"{ctx}.min"))
    errs.extend(_validate_vec3(obj.get("max"), ctx=f"{ctx}.max"))
    return errs


def validate_model_json(schema: dict, model_path: Path) -> list[str]:
    Validator = validator_for(schema)
    validator = Validator(schema)

    try:
        data = json.loads(model_path.read_text(encoding="utf-8"))
    except Exception as e:  # noqa: BLE001
        return [f"{model_path}: failed to parse JSON: {e}"]

    try:
        validator.validate(data)
    except Exception as e:  # noqa: BLE001
        return [f"{model_path}: schema validation failed: {e}"]

    errs: list[str] = []

    def check_shape_stats(stats: object, ctx: str) -> None:
        if not isinstance(stats, dict):
            errs.append(f"{ctx}: expected object")
            return
        bbox = stats.get("bbox")
        errs.extend(_validate_bbox(bbox, ctx=f"{ctx}.bbox"))

    check_shape_stats(data.get("input"), f"{model_path}: input")

    pre = data.get("precheck")
    if isinstance(pre, dict) and pre.get("bad_shape") is not None:
        check_shape_stats(pre.get("bad_shape"), f"{model_path}: precheck.bad_shape")

    res = data.get("result")
    if isinstance(res, dict):
        if res.get("shape") is not None:
            check_shape_stats(res.get("shape"), f"{model_path}: result.shape")

        # Basic invariant: if IsDone, shape must be present.
        if res.get("is_done") is True and res.get("shape") is None:
            errs.append(f"{model_path}: result.is_done=true but result.shape is null")

    return errs


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--root", default=".", help="repo root (default: .)")
    ap.add_argument(
        "--schema",
        default="tools/schemas/offsets_brepoffset_model.schema.json",
        help="path to offsets model schema (default: tools/schemas/offsets_brepoffset_model.schema.json)",
    )
    ap.add_argument(
        "--artifacts",
        default="repros/lane-offsets/golden/artifacts",
        help="path to offsets artifacts dir (default: repros/lane-offsets/golden/artifacts)",
    )
    args = ap.parse_args()

    root = Path(args.root).resolve()
    schema_path = (root / args.schema).resolve()
    artifacts_dir = (root / args.artifacts).resolve()

    if not schema_path.is_file():
        fail(f"missing schema: {schema_path}")
        return 1
    if not artifacts_dir.is_dir():
        fail(f"missing artifacts dir: {artifacts_dir}")
        return 1

    schema = json.loads(schema_path.read_text(encoding="utf-8"))
    Validator = validator_for(schema)
    Validator.check_schema(schema)
    ok(f"schema OK: {schema_path.relative_to(root)} ({Validator.__name__})")

    model_paths = sorted(artifacts_dir.glob("*/model.json"))
    if not model_paths:
        fail(f"no model.json files under {artifacts_dir.relative_to(root)}")
        return 1

    errors: list[str] = []
    for p in model_paths:
        errors.extend(validate_model_json(schema, p))

    if errors:
        for e in errors:
            fail(e)
        fail(f"{len(errors)} model.json issues found")
        return 1

    ok(f"{len(model_paths)} model.json files validated")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

