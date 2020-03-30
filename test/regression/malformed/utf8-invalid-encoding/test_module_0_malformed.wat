;; (assert_melformed "invalid UTF-8 encoding")
(module (func (export "\00\00\fe\ff"))
)