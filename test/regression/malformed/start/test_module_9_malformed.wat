;; (assert_melformed "multiple start sections")
(module (module (func $a (unreachable)) (func $b (unreachable)) (start $a) (start $b))
)