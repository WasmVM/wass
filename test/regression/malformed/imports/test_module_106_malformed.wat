;; (assert_melformed "import after global")
(module (global i64 (i64.const 0)) (import "" "" (table 0 funcref))
)