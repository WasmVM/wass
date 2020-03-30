;; (assert_melformed "i32 constant")
(module (memory 1)(func (drop (i32.load offset=4294967296 (i32.const 0))))
)