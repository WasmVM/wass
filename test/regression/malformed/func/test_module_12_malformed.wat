;; (assert_melformed "inline function type")
(module (type $sig (func (param i32) (result i32)))(func (type $sig) (param i32) (i32.const 0))
)