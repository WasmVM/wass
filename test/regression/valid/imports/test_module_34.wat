(module
  (import "spectest" "global_i32" (global i32))
  (global (import "spectest" "global_i32") i32)

  (import "spectest" "global_i32" (global $x i32))
  (global $y (import "spectest" "global_i32") i32)

  
  
  (import "spectest" "global_f32" (global f32))
  (import "spectest" "global_f64" (global f64))

  (func (export "get-0") (result i32) (global.get 0))
  (func (export "get-1") (result i32) (global.get 1))
  (func (export "get-x") (result i32) (global.get $x))
  (func (export "get-y") (result i32) (global.get $y))
)