(module
  (type (func (result i32)))
  (import "spectest" "table" (table 10 20 funcref))
  (elem 0 (i32.const 1) $f $g)

  (func (export "call") (param i32) (result i32)
    (call_indirect (type 0) (local.get 0))
  )
  (func $f (result i32) (i32.const 11))
  (func $g (result i32) (i32.const 22))
)