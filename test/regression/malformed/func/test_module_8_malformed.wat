;; (assert_melformed "unexpected token")
(module (type $sig (func (param i32) (result i32)))(func (result i32) (param i32) (type $sig) (i32.const 0))
)