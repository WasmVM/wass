(module
  (import "spectest" "memory" (memory 0 3))  
  (func (export "grow") (param i32) (result i32) (memory.grow (local.get 0)))
)