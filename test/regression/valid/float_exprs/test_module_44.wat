(module
  (func (export "f32.no_fold_lt_if") (param $x f32) (param $y f32) (result f32)
    (if (result f32) (f32.lt (local.get $x) (local.get $y))
      (then (local.get $x)) (else (local.get $y))
    )
  )
  (func (export "f32.no_fold_le_if") (param $x f32) (param $y f32) (result f32)
    (if (result f32) (f32.le (local.get $x) (local.get $y))
      (then (local.get $x)) (else (local.get $y))
    )
  )
  (func (export "f32.no_fold_gt_if") (param $x f32) (param $y f32) (result f32)
    (if (result f32) (f32.gt (local.get $x) (local.get $y))
      (then (local.get $x)) (else (local.get $y))
    )
  )
  (func (export "f32.no_fold_ge_if") (param $x f32) (param $y f32) (result f32)
    (if (result f32) (f32.ge (local.get $x) (local.get $y))
      (then (local.get $x)) (else (local.get $y))
    )
  )

  (func (export "f64.no_fold_lt_if") (param $x f64) (param $y f64) (result f64)
    (if (result f64) (f64.lt (local.get $x) (local.get $y))
      (then (local.get $x)) (else (local.get $y))
    )
  )
  (func (export "f64.no_fold_le_if") (param $x f64) (param $y f64) (result f64)
    (if (result f64) (f64.le (local.get $x) (local.get $y))
      (then (local.get $x)) (else (local.get $y))
    )
  )
  (func (export "f64.no_fold_gt_if") (param $x f64) (param $y f64) (result f64)
    (if (result f64) (f64.gt (local.get $x) (local.get $y))
      (then (local.get $x)) (else (local.get $y))
    )
  )
  (func (export "f64.no_fold_ge_if") (param $x f64) (param $y f64) (result f64)
    (if (result f64) (f64.ge (local.get $x) (local.get $y))
      (then (local.get $x)) (else (local.get $y))
    )
  )
)