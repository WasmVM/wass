(module
  
  (func (export "stmt") (param $i i32) (result i32)
    (local $j i32)
    (local.set $j (i32.const 100))
    (block $switch
      (block $7
        (block $default
          (block $6
            (block $5
              (block $4
                (block $3
                  (block $2
                    (block $1
                      (block $0
                        (br_table $0 $1 $2 $3 $4 $5 $6 $7 $default
                          (local.get $i)
                        )
                      ) 
                      (return (local.get $i))
                    ) 
                    (nop)
                    
                  ) 
                  
                ) 
                (local.set $j (i32.sub (i32.const 0) (local.get $i)))
                (br $switch)
              ) 
              (br $switch)
            ) 
            (local.set $j (i32.const 101))
            (br $switch)
          ) 
          (local.set $j (i32.const 101))
          
        ) 
        (local.set $j (i32.const 102))
      ) 
      
    )
    (return (local.get $j))
  )

  
  (func (export "expr") (param $i i64) (result i64)
    (local $j i64)
    (local.set $j (i64.const 100))
    (return
      (block $switch (result i64)
        (block $7
          (block $default
            (block $4
              (block $5
                (block $6
                  (block $3
                    (block $2
                      (block $1
                        (block $0
                          (br_table $0 $1 $2 $3 $4 $5 $6 $7 $default
                            (i32.wrap_i64 (local.get $i))
                          )
                        ) 
                        (return (local.get $i))
                      ) 
                      (nop)
                      
                    ) 
                    
                  ) 
                  (br $switch (i64.sub (i64.const 0) (local.get $i)))
                ) 
                (local.set $j (i64.const 101))
                
              ) 
              
            ) 
            
          ) 
          (br $switch (local.get $j))
        ) 
        (i64.const -5)
      )
    )
  )

  
  (func (export "arg") (param $i i32) (result i32)
    (return
      (block $2 (result i32)
        (i32.add (i32.const 10)
          (block $1 (result i32)
            (i32.add (i32.const 100)
              (block $0 (result i32)
                (i32.add (i32.const 1000)
                  (block $default (result i32)
                    (br_table $0 $1 $2 $default
                      (i32.mul (i32.const 2) (local.get $i))
                      (i32.and (i32.const 3) (local.get $i))
                    )
                  )
                )
              )
            )
          )
        )
      )
    )
  )

  
  (func (export "corner") (result i32)
    (block
      (br_table 0 (i32.const 0))
    )
    (i32.const 1)
  )
)