(module
  (type    (func))                           
  (type $S (func))                           
  (type    (func (param)))                   
  (type    (func (result i32)))              
  (type    (func (param) (result i32)))      
  (type $T (func (param i32) (result i32)))  
  (type $U (func (param i32)))               

  (func $print (import "spectest" "print_i32") (type 6))

  (func (type 0))
  (func (type $S))

  (func (export "one") (type 4) (i32.const 13))
  (func (export "two") (type $T) (i32.add (local.get 0) (i32.const 1)))

  
  
  (func (export "three") (type $T) (param $a i32) (result i32)
    (i32.sub (local.get 0) (i32.const 2))
  )

  (func (export "four") (type $U) (call $print (local.get 0)))
)