(module
  (func (export "f32.silver_means") (param $n f32) (result f32)
    (f32.mul (f32.const 0.5)
             (f32.add (local.get $n)
                      (f32.sqrt (f32.add (f32.mul (local.get $n) (local.get $n))
                                         (f32.const 4.0))))))
  (func (export "f64.silver_means") (param $n f64) (result f64)
    (f64.mul (f64.const 0.5)
             (f64.add (local.get $n)
                      (f64.sqrt (f64.add (f64.mul (local.get $n) (local.get $n))
                                         (f64.const 4.0))))))
)