;; (assert_melformed "unexpected token")
(module (type $sig (func (param i32) (result i32)))(func (result i32) (type $sig) (param i32) (i32.const 0))
)