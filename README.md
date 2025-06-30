# Betatron-001 Simulator

## Overview

**Betatron-001** is a simulated computer that mimics the behavior of a very simple processor. It has:

- 100 words of memory (values from 0000 to 9999)
- An **accumulator** for performing operations
- A **program counter** to track instruction execution
- A set of **13 machine code instructions**

Programs are entered line-by-line and executed with the `RUN` command.

---

## Features

- Simulates fetch-decode-execute cycle
- Supports input/output, arithmetic, and control flow
- Easily testable with `.mlp` files
- Useful for learning low-level computation concepts

---

## 📁 Project Structure

```plaintext
Betatron/
├── Betatron.h         # Class and opcode definitions
├── Betatron.cpp       # Implementation of instruction logic
├── main.cpp           # Main function to run the simulator (do not modify)
├── examples/
│   ├── countto4.mlp   # Print 0 to 4
│   ├── inputplus2.mlp # Input + 2
│   ├── sum.mlp        # Sum of 2 inputs
│   ├── maxof2.mlp     # Compare 2 inputs
│   ├── loop.mlp       # (Level 3) Print Y, X times
│   └── prime.mlp      # (Level 4) Print primes ≤ X
└── README.md          # This file
```
## Instruction Set

| Mnemonic  | Opcode | Description                                                                 |
|-----------|--------|-----------------------------------------------------------------------------|
| INPUT     | 10     | Read from keyboard. If operand = 0, store in accumulator; else in memory[operand] |
| OUTPUT    | 20     | Print to screen. If operand = 0, print accumulator; else print memory[operand] |
| INC       | 30     | Increment accumulator                                                       |
| DEC       | 31     | Decrement accumulator                                                       |
| ADD       | 40     | Add memory[operand] to accumulator                                          |
| SUB       | 41     | Subtract memory[operand] from accumulator                                   |
| LOAD      | 50     | Load memory[operand] into accumulator                                       |
| STORE     | 60     | Store accumulator into memory[operand]                                      |
| JUMP      | 70     | Jump to instruction at memory[operand]                                      |
| JUMPPOS   | 71     | Jump if accumulator > 0                                                     |
| JUMPZERO  | 72     | Jump if accumulator == 0                                                    |
| HALT      | 99     | Stop execution                                                              |
| SKIP      | 00     | Do nothing                                                                  |

##  Notes

- `memory[0]` is **unusable**
- Programs always begin execution at **memory[1]**
- Use only **4-digit numbers** for instructions and data (e.g., `0072`, `2609`)
- The **accumulator can store negative values**, but **memory cells cannot** — they must always contain non-negative integers from `0000` to `9999`

