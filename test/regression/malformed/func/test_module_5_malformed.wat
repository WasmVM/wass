;; (assert_melformed "unexpected token")
(module (type $sig (func (param i32) (result i32)))(func (param i32) (type $sig) (result i32) (i32.const 0))
)