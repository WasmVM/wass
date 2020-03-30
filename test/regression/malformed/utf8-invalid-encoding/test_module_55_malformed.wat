;; (assert_melformed "invalid UTF-8 encoding")
(module (func (export "\ed\00\80"))
)