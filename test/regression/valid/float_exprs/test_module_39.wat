(module
  (func (export "f32.i32.no_fold_trunc_s_convert_s") (param $x f32) (result f32)
    (f32.convert_i32_s (i32.trunc_f32_s (local.get $x))))
  (func (export "f32.i32.no_fold_trunc_u_convert_s") (param $x f32) (result f32)
    (f32.convert_i32_s (i32.trunc_f32_u (local.get $x))))
  (func (export "f32.i32.no_fold_trunc_s_convert_u") (param $x f32) (result f32)
    (f32.convert_i32_u (i32.trunc_f32_s (local.get $x))))
  (func (export "f32.i32.no_fold_trunc_u_convert_u") (param $x f32) (result f32)
    (f32.convert_i32_u (i32.trunc_f32_u (local.get $x))))
  (func (export "f64.i32.no_fold_trunc_s_convert_s") (param $x f64) (result f64)
    (f64.convert_i32_s (i32.trunc_f64_s (local.get $x))))
  (func (export "f64.i32.no_fold_trunc_u_convert_s") (param $x f64) (result f64)
    (f64.convert_i32_s (i32.trunc_f64_u (local.get $x))))
  (func (export "f64.i32.no_fold_trunc_s_convert_u") (param $x f64) (result f64)
    (f64.convert_i32_u (i32.trunc_f64_s (local.get $x))))
  (func (export "f64.i32.no_fold_trunc_u_convert_u") (param $x f64) (result f64)
    (f64.convert_i32_u (i32.trunc_f64_u (local.get $x))))
  (func (export "f32.i64.no_fold_trunc_s_convert_s") (param $x f32) (result f32)
    (f32.convert_i64_s (i64.trunc_f32_s (local.get $x))))
  (func (export "f32.i64.no_fold_trunc_u_convert_s") (param $x f32) (result f32)
    (f32.convert_i64_s (i64.trunc_f32_u (local.get $x))))
  (func (export "f32.i64.no_fold_trunc_s_convert_u") (param $x f32) (result f32)
    (f32.convert_i64_u (i64.trunc_f32_s (local.get $x))))
  (func (export "f32.i64.no_fold_trunc_u_convert_u") (param $x f32) (result f32)
    (f32.convert_i64_u (i64.trunc_f32_u (local.get $x))))
  (func (export "f64.i64.no_fold_trunc_s_convert_s") (param $x f64) (result f64)
    (f64.convert_i64_s (i64.trunc_f64_s (local.get $x))))
  (func (export "f64.i64.no_fold_trunc_u_convert_s") (param $x f64) (result f64)
    (f64.convert_i64_s (i64.trunc_f64_u (local.get $x))))
  (func (export "f64.i64.no_fold_trunc_s_convert_u") (param $x f64) (result f64)
    (f64.convert_i64_u (i64.trunc_f64_s (local.get $x))))
  (func (export "f64.i64.no_fold_trunc_u_convert_u") (param $x f64) (result f64)
    (f64.convert_i64_u (i64.trunc_f64_u (local.get $x))))
)