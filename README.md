# Wass

WebAssembly assembler for WasmVM

# Quick start

TODO:

# Design

## Assembling process

```graphviz
digraph{
    node [shape=box];
    "Validate Module" [style=dotted]
    input [style=invis]
    output [style=invis]
    input -> "Remove comments" [label="  Wasm text file"]
    "Remove comments" -> "Parse module" [label="  Char Array"]
    "Parse module" -> "Compose module"  [label="  Blocks & Tokens"]
    "Compose module" -> "Validate Module" [label="  WasmModule"]
    "Validate Module" -> "Code generate" [label="  WasmModule"]
    "Code generate" -> output [label="  Wasm binary file"]
}
```

## Remove comments

Feature:

* Match single-line comment
* Match block-comment
* Ignore non-comment characters

Error:

* Unmatched block-end parentheses
    * SyntaxError

## Parse module

Feature:

* Match parentheses-wrapped block
* Match block name
* Match identifiers
* Match string literal
* Match integer literal
* Match floating-point literal
* Build syntax tree according to each module

Error:

Several SyntaxErrors

## Compose module

Feature:

* Merge sections into one instance
* Analyze semantics and compose to WasmModule

Error:

Several SemanticErrors

## [Later] Validate module

Feature: 

* Validate WasmModule according to official validation algorithm

Error:

Several ModuleErrors

## Code generate

Feature:

* Generate WebAssembly binary code from WasmModule

## Misc

### File IO

* Read file
* Write file

### Command-line
* Option parser

### Test

#### Unit test

* Using gtest

#### Regression

* Generated from `WasmVM/testsuite`
* Remove `return`, `trap`
* Ignore `invalid` until validation being developed in the future