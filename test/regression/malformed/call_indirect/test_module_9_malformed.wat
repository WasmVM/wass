;; (assert_melformed "inline function type")
(module (type $sig (func (param i32) (result i32)))(table 0 funcref)(func (result i32)  (call_indirect (type $sig) (result i32) (i32.const 0)))
)