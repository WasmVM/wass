;; (assert_melformed "import after global")
(module (global i64 (i64.const 0)) (import "" "" (global f32))
)