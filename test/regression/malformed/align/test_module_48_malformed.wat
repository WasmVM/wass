;; (assert_melformed "alignment")
(module (module (memory 0) (func (drop (f32.load align=7 (i32.const 0)))))
)