;; (assert_melformed "invalid UTF-8 encoding")
(module (func (export "\ff\fe\00\00"))
)