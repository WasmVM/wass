;; (assert_melformed "unexpected token")
(module (type $sig (func (param i32) (result i32)))(table 0 funcref)(func (result i32)  (call_indirect (param i32) (type $sig) (result i32)    (i32.const 0) (i32.const 0)  ))
)