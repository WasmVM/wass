(module $Pm
  (memory (import "Mm" "mem") 1 8)

  (func (export "grow") (param $a i32) (result i32)
    (memory.grow (local.get 0))
  )
)