;; (assert_melformed "alignment")
(module (module (memory 0) (func (drop (i64.load8_u align=7 (i32.const 0)))))
)