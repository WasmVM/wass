;; (assert_melformed "inline function type")
(module (type $sig (func (param i32) (result i32)))(table 0 funcref)(func  (call_indirect (type $sig) (param i32) (i32.const 0) (i32.const 0)))
)