(module
  (func $f (result f64) (f64.const 0))  
  (func $g (param i32))                 
  (type $t (func (param i32)))

  (func $i32->void (type 0))                
  (func $void->f64 (type 1) (f64.const 0))  
  (func $check
    (call $i32->void (i32.const 0))
    (drop (call $void->f64))
  )
)