;; (assert_melformed "inline function type")
(module (type $sig (func))(func (type $sig) (result i32) (i32.const 0))
)