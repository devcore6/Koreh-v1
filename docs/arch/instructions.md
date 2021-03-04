# Instructions 
## Table of Contents
1. [Memory instructions](#memory-instructions)
2. [Arithmetic instructions](#memory-instructions)
3. [Stack instructions](#stack-instructions)
4. [Logical instructions](#logical-instructions)
5. [Conditional instructions](#conditional-instructions)
6. [Miscellaneous instructions](#miscellaneous-instructions)
7. [Coprocessor instructions](#coprocessor-instructions)

## Memory instructions
| name  |     op code      | arguments | description                                                                                                                      |
|-------|------------------|-----------|----------------------------------------------------------------------------------------------------------------------------------|
| movb  | 0000000000000001 | %reg,%reg | Copies the value of the second 8-bit register to the first 8-bit register                                                        |
| movb  | 0000000000000001 | %reg,val  | Copies a 8-bit value to a 8-bit register                                                                                         |
| movb  | 0000000000000001 | %reg,$adr | Copies a 8-bit value from a 32-bit memory address stored in %idr                                                                 |
| movb  | 1000000000000001 | %reg,$adr | Copies a 8-bit value from a 64-bit memory address stored in %idr                                                                 |
| movb  | 0000000000000001 | $adr,%reg | Copies the value of a 8-bit register to a 32-bit memory address stored in %idr                                                   |
| movb  | 1000000000000001 | $adr,%reg | Copies the value of a 8-bit register to a 64-bit memory address stored in %idr                                                   |
| movb  | 1000000000000001 | $adr,val  | Copies a 8-bit value to a 64-bit memory address stored in %idr                                                                   |
| mov   | 0010000000000001 | %reg,%reg | Copies the value of the second 16-bit register to the first 16-bit register                                                      |
| mov   | 0010000000000001 | %reg,val  | Copies a 16-bit value to a 16-bit register                                                                                       |
| mov   | 0010000000000001 | %reg,$adr | Copies a 16-bit value from a 32-bit memory address stored in %idr                                                                |
| mov   | 1010000000000001 | %reg,$adr | Copies a 16-bit value from a 64-bit memory address stored in %idr                                                                |
| mov   | 0010000000000001 | $adr,%reg | Copies the value of a 16-bit register to a 32-bit memory address stored in %idr                                                  |
| mov   | 1010000000000001 | $adr,%reg | Copies the value of a 16-bit register to a 64-bit memory address stored in %idr                                                  |
| mov   | 1010000000000001 | $adr,val  | Copies a 16-bit value to a 64-bit memory address stored in %idr                                                                  |
| movl  | 0100000000000001 | %reg,%reg | Copies the value of the second 32-bit register to the first 32-bit register                                                      |
| movl  | 0100000000000001 | %reg,val  | Copies a 32-bit value to a 32-bit register                                                                                       |
| movl  | 0100000000000001 | %reg,$adr | Copies a 32-bit value from a 32-bit memory address stored in %idr                                                                |
| movl  | 1100000000000001 | %reg,$adr | Copies a 32-bit value from a 64-bit memory address stored in %idr                                                                |
| movl  | 0100000000000001 | $adr,%reg | Copies the value of a 32-bit register to a 32-bit memory address stored in %idr                                                  |
| movl  | 1100000000000001 | $adr,%reg | Copies the value of a 32-bit register to a 64-bit memory address stored in %idr                                                  |
| movl  | 1100000000000001 | $adr,val  | Copies a 32-bit value to a 64-bit memory address stored in %idr                                                                  |
| movq  | 1110000000000001 | %reg,%reg | Copies the value of the second 64-bit register to the first 64-bit register                                                      |
| movq  | 1110000000000001 | %reg,val  | Copies a 64-bit value to a 64-bit register                                                                                       |
| movq  | 1110000000000001 | %reg,$adr | Copies a 64-bit value from a 64-bit memory address stored in %idr                                                                |
| movq  | 1110000000000001 | $adr,%reg | Copies the value of a 64-bit register to a 64-bit memory address stored in %idr                                                  |
| loadb | 0000000000000010 | %reg,%reg | Loads an 8-bit value from a 32-bit memory address stored in the second 32-bit register onto the first 8-bit register             |
| loadb | 1000000000000010 | %reg,%reg | Loads an 8-bit value from a 64-bit memory address stored in the second 64-bit register onto the first 8-bit register             |
| load  | 0010000000000010 | %reg,%reg | Loads a 16-bit value from a 32-bit memory address stored in the second 32-bit register onto the first 16-bit register            |
| load  | 1010000000000010 | %reg,%reg | Loads a 16-bit value from a 64-bit memory address stored in the second 64-bit register onto the first 16-bit register            |
| loadl | 0100000000000010 | %reg,%reg | Loads a 32-bit value from a 32-bit memory address stored in the second 32-bit register onto the first 32-bit register            |
| loadl | 1100000000000010 | %reg,%reg | Loads a 32-bit value from a 64-bit memory address stored in the second 64-bit register onto the first 32-bit register            |
| loadq | 1110000000000010 | %reg,%reg | Loads a 64-bit value from a 64-bit memory address stored in the second 64-bit register onto the first 64-bit register            |
| saveb | 0000000000000011 | %reg,%reg | Saves an 8-bit value from the second 8-bit register onto a 32-bit memory address stored in the first 32-bit register             |
| saveb | 1000000000000011 | %reg,%reg | Saves an 8-bit value from the second 8-bit register onto a 64-bit memory address stored in the first 64-bit register             |
| save  | 0010000000000011 | %reg,%reg | Saves a 16-bit value from the second 16-bit register onto a 32-bit memory address stored in the first 32-bit register            |
| save  | 1010000000000011 | %reg,%reg | Saves a 16-bit value from the second 16-bit register onto a 64-bit memory address stored in the first 64-bit register            |
| savel | 0100000000000011 | %reg,%reg | Saves a 32-bit value from the second 32-bit register onto a 32-bit memory address stored in the first 32-bit register            |
| savel | 1100000000000011 | %reg,%reg | Saves a 32-bit value from the second 32-bit register onto a 64-bit memory address stored in the first 64-bit register            |
| saveq | 1110000000000011 | %reg,%reg | Saves a 64-bit value from the second 64-bit register onto a 64-bit memory address stored in the first 64-bit register            |

## Arithmetic instructions
| name  |     op code      | arguments | description                                                                                                                      |
|-------|------------------|-----------|----------------------------------------------------------------------------------------------------------------------------------|
| incb  | 0000000000000100 | %reg      | Increments an 8-bit register                                                                                                     |
| incb  | 0000000000000100 | $adr      | Increments an 8-bit value in a 32-bit memory address                                                                             |
| incb  | 1000000000000100 | $adr      | Increments an 8-bit value in a 64-bit memory address                                                                             |
| inc   | 0010000000000100 | %reg      | Increments a 16-bit register                                                                                                     |
| inc   | 0010000000000100 | $adr      | Increments a 16-bit value in a 32-bit memory address                                                                             |
| inc   | 1010000000000100 | $adr      | Increments a 16-bit value in a 64-bit memory address                                                                             |
| incl  | 0100000000000100 | %reg      | Increments a 32-bit register                                                                                                     |
| incl  | 0100000000000100 | $adr      | Increments a 32-bit value in a 32-bit memory address                                                                             |
| incl  | 1100000000000100 | $adr      | Increments a 32-bit value in a 64-bit memory address                                                                             |
| incq  | 1110000000000100 | %reg      | Increments a 64-bit register                                                                                                     |
| incq  | 1110000000000100 | $adr      | Increments a 64-bit value in a 64-bit memory address                                                                             |
| decb  | 0000000000000101 | %reg      | Decrements an 8-bit register                                                                                                     |
| decb  | 0000000000000101 | $adr      | Decrements an 8-bit value in a 32-bit memory address                                                                             |
| decb  | 1000000000000101 | $adr      | Decrements an 8-bit value in a 64-bit memory address                                                                             |
| dec   | 0010000000000101 | %reg      | Decrements a 16-bit register                                                                                                     |
| dec   | 0010000000000101 | $adr      | Decrements a 16-bit value in a 32-bit memory address                                                                             |
| dec   | 1010000000000101 | $adr      | Decrements a 16-bit value in a 64-bit memory address                                                                             |
| decl  | 0100000000000101 | %reg      | Decrements a 32-bit register                                                                                                     |
| decl  | 0100000000000101 | $adr      | Decrements a 32-bit value in a 32-bit memory address                                                                             |
| decl  | 1100000000000101 | $adr      | Decrements a 32-bit value in a 64-bit memory address                                                                             |
| decq  | 1110000000000101 | %reg      | Decrements a 64-bit register                                                                                                     |
| decq  | 1110000000000101 | $adr      | Decrements a 64-bit value in a 64-bit memory address                                                                             |
| addb  | 0000000000000110 | %reg,%reg | Adds the value of the second 8-bit register to that of the first                                                                 |
| addb  | 0000000000000110 | %reg,val  | Adds an 8-bit value to an 8-bit register                                                                                         |
| addb  | 0000000000000110 | %reg,$adr | Adds an 8-bit value from a 32-bit memory address onto an 8-bit register                                                          |
| addb  | 1000000000000110 | %reg,$adr | Adds an 8-bit value from a 64-bit memory address onto an 8-bit register                                                          |
| addb  | 0000000000000110 | $adr,%reg | Adds the value of an 8-bit register to that of a 32-bit memory address                                                           |
| addb  | 1000000000000110 | $adr,%reg | Adds the value of an 8-bit register to that of a 64-bit memory address                                                           |
| addb  | 1000000000000110 | $adr,val  | Adds an 8-bit value to the 8-bit value of a 64-bit memory address                                                                |
| add   | 0010000000000110 | %reg,%reg | Adds the value of the second 16-bit register to that of the first                                                                |
| add   | 0010000000000110 | %reg,val  | Adds a 16-bit value to a 16-bit register                                                                                         |
| add   | 0010000000000110 | %reg,$adr | Adds a 16-bit value from a 32-bit memory address onto a 16-bit register                                                          |
| add   | 1010000000000110 | %reg,$adr | Adds a 16-bit value from a 64-bit memory address onto a 16-bit register                                                          |
| add   | 0010000000000110 | $adr,%reg | Adds the value of a 16-bit register to that of a 32-bit memory address                                                           |
| add   | 1010000000000110 | $adr,%reg | Adds the value of a 16-bit register to that of a 64-bit memory address                                                           |
| add   | 1010000000000110 | $adr,val  | Adds a 16-bit value to the 16-bit value of a 64-bit memory address                                                               |
| addl  | 0100000000000110 | %reg,%reg | Adds the value of the second 32-bit register to that of the first                                                                |
| addl  | 0100000000000110 | %reg,val  | Adds a 32-bit value to a 32-bit register                                                                                         |
| addl  | 0100000000000110 | %reg,$adr | Adds a 32-bit value from a 32-bit memory address onto a 32-bit register                                                          |
| addl  | 1100000000000110 | %reg,$adr | Adds a 32-bit value from a 64-bit memory address onto a 32-bit register                                                          |
| addl  | 0100000000000110 | $adr,%reg | Adds the value of a 32-bit register to that of a 32-bit memory address                                                           |
| addl  | 1100000000000110 | $adr,%reg | Adds the value of a 32-bit register to that of a 64-bit memory address                                                           |
| addl  | 1100000000000110 | $adr,val  | Adds a 32-bit value to the 32-bit value of a 64-bit memory address                                                               |
| addq  | 1110000000000110 | %reg,%reg | Adds the value of the second 64-bit register to that of the first                                                                |
| addq  | 1110000000000110 | %reg,val  | Adds a 64-bit value to a 64-bit register                                                                                         |
| addq  | 1110000000000110 | %reg,$adr | Adds a 64-bit value from a 64-bit memory address onto a 64-bit register                                                          |
| addq  | 1110000000000110 | $adr,%reg | Adds the value of a 64-bit register to that of a 64-bit memory address                                                           |
| subb  | 0000000000000111 | %reg,%reg | Subtracts the value of the second 8-bit register from that of the first                                                          |
| subb  | 0000000000000111 | %reg,val  | Subtracts an 8-bit value from an 8-bit register                                                                                  |
| subb  | 0000000000000111 | %reg,$adr | Subtracts an 8-bit value from a 32-bit memory address from an 8-bit register                                                     |
| subb  | 1000000000000111 | %reg,$adr | Subtracts an 8-bit value from a 64-bit memory address from an 8-bit register                                                     |
| subb  | 0000000000000111 | $adr,%reg | Subtracts the value of an 8-bit register from that of a 32-bit memory address                                                    |
| subb  | 1000000000000111 | $adr,%reg | Subtracts the value of an 8-bit register from that of a 64-bit memory address                                                    |
| subb  | 1000000000000111 | $adr,val  | Subtracts an 8-bit value from the 8-bit value of a 64-bit memory address                                                         |
| sub   | 0010000000000111 | %reg,%reg | Subtracts the value of the second 16-bit register from that of the first                                                         |
| sub   | 0010000000000111 | %reg,val  | Subtracts a 16-bit value from a 16-bit register                                                                                  |
| sub   | 0010000000000111 | %reg,$adr | Subtracts a 16-bit value from a 32-bit memory address from a 16-bit register                                                     |
| sub   | 1010000000000111 | %reg,$adr | Subtracts a 16-bit value from a 64-bit memory address from a 16-bit register                                                     |
| sub   | 0010000000000111 | $adr,%reg | Subtracts the value of a 16-bit register from that of a 32-bit memory address                                                    |
| sub   | 1010000000000111 | $adr,%reg | Subtracts the value of a 16-bit register from that of a 64-bit memory address                                                    |
| sub   | 1010000000000111 | $adr,val  | Subtracts a 16-bit value from the 16-bit value of a 64-bit memory address                                                        |
| subl  | 0100000000000111 | %reg,%reg | Subtracts the value of the second 32-bit register from that of the first                                                         |
| subl  | 0100000000000111 | %reg,val  | Subtracts a 32-bit value from a 32-bit register                                                                                  |
| subl  | 0100000000000111 | %reg,$adr | Subtracts a 32-bit value from a 32-bit memory address from a 32-bit register                                                     |
| subl  | 1100000000000111 | %reg,$adr | Subtracts a 32-bit value from a 64-bit memory address from a 32-bit register                                                     |
| subl  | 0100000000000111 | $adr,%reg | Subtracts the value of a 32-bit register from that of a 32-bit memory address                                                    |
| subl  | 1100000000000111 | $adr,%reg | Subtracts the value of a 32-bit register from that of a 64-bit memory address                                                    |
| subl  | 1100000000000111 | $adr,val  | Subtracts a 32-bit value from the 32-bit value of a 64-bit memory address                                                        |
| subq  | 1110000000000111 | %reg,%reg | Subtracts the value of the second 64-bit register from that of the first                                                         |
| subq  | 1110000000000111 | %reg,val  | Subtracts a 64-bit value from a 64-bit register                                                                                  |
| subq  | 1110000000000111 | %reg,$adr | Subtracts a 64-bit value from a 64-bit memory address from a 64-bit register                                                     |
| subq  | 1110000000000111 | $adr,%reg | Subtracts the value of a 64-bit register from that of a 64-bit memory address                                                    |
| mulb  | 0000000000001000 |           | Unsigned multiplication of the data from AL with BL and saves the result on CL and DL (DL being the smaller value)               |
| mul   | 0010000000001000 |           | Unsigned multiplication of the data from AX with BX and saves the result on CX and DX (DX being the smaller value)               |
| mull  | 0100000000001000 |           | Unsigned multiplication of the data from EAX with EBX and saves the result on ECX and EDX (EDX being the smaller value)          |
| mulq  | 1110000000001000 |           | Unsigned multiplication of the data from RAX with RBX and saves the result on RCX and RDX (RDX being the smaller value)          |
| imulb | 0000000000001001 |           | Signed multiplication of the data from AL with BL and saves the result on CL and DL (DL being the smaller value)                 |
| imul  | 0010000000001001 |           | Signed multiplication of the data from AX with BX and saves the result on CX and DX (DX being the smaller value)                 |
| imull | 0100000000001001 |           | Signed multiplication of the data from EAX with EBX and saves the result on ECX and EDX (EDX being the smaller value)            |
| imulq | 1110000000001001 |           | Signed multiplication of the data from RAX with RBX and saves the result on RCX and RDX (RDX being the smaller value)            |
| divb  | 0000000000001010 |           | Unsigned division of the data from AL with BL and saves the result on CL and the rest on DL                                      |
| div   | 0010000000001010 |           | Unsigned division of the data from AX with BX and saves the result on CX and the rest on DX                                      |
| divl  | 0100000000001010 |           | Unsigned division of the data from EAX with EBX and saves the result on ECX and the rest on EDX                                  |
| divq  | 1110000000001010 |           | Unsigned division of the data from RAX with RBX and saves the result on RCX and the rest on RDX                                  |
| idivb | 0000000000001011 |           | Signed division of the data from AL with BL and saves the result on CL and the rest on DL                                        |
| idiv  | 0010000000001011 |           | Signed division of the data from AX with BX and saves the result on CX and the rest on DX                                        |
| idivl | 0100000000001011 |           | Signed division of the data from EAX with EBX and saves the result on ECX and the rest on EDX                                    |
| idivq | 1110000000001011 |           | Signed division of the data from RAX with RBX and saves the result on RCX and the rest on RDX                                    |

## Stack instructions
| name  |     op code      | arguments | description                                                                                                                      |
|-------|------------------|-----------|----------------------------------------------------------------------------------------------------------------------------------|
| pushb | 0000000000001100 | %reg      | Pushes an 8-bit register onto the stack                                                                                          |
| pushb | 0000000000001100 | val       | Pushes an 8-bit value onto the stack                                                                                             |
| pushb | 0000000000001100 | $adr      | Pushes the 8-bit value of a 32-bit address onto the stack                                                                        |
| pushb | 0000000000001100 | $adr      | Pushes the 8-bit value of a 64-bit address onto the stack                                                                        |
| push  | 0010000000001100 | %reg      | Pushes a 16-bit register onto the stack                                                                                          |
| push  | 0010000000001100 | val       | Pushes a 16-bit value onto the stack                                                                                             |
| push  | 0010000000001100 | $adr      | Pushes the 16-bit value of a 32-bit address onto the stack                                                                       |
| push  | 0010000000001100 | $adr      | Pushes the 16-bit value of a 64-bit address onto the stack                                                                       |
| pushl | 0100000000001100 | %reg      | Pushes a 32-bit register onto the stack                                                                                          |
| pushl | 0100000000001100 | val       | Pushes a 32-bit value onto the stack                                                                                             |
| pushl | 0100000000001100 | $adr      | Pushes the 32-bit value of a 32-bit address onto the stack                                                                       |
| pushl | 0100000000001100 | $adr      | Pushes the 32-bit value of a 64-bit address onto the stack                                                                       |
| pushq | 1110000000001100 | %reg      | Pushes a 64-bit register onto the stack                                                                                          |
| pushq | 1110000000001100 | val       | Pushes a 64-bit value onto the stack                                                                                             |
| pushq | 1110000000001100 | $adr      | Pushes the 64-bit value of a 64-bit address onto the stack                                                                       |
| popb  | 0000000000001101 | %reg      | Pops an 8-bit value from the stack onto an 8-bit register                                                                        |
| pop   | 0010000000001101 | %reg      | Pops a 16-bit value from the stack onto a 16-bit register                                                                        |
| popl  | 0100000000001101 | %reg      | Pops a 32-bit value from the stack onto a 32-bit register                                                                        |
| popq  | 1110000000001101 | %reg      | Pops a 64-bit value from the stack onto a 64-bit register                                                                        |
| call  | 0100000000001110 | function  | Jumps to a subroutine and puts the return address on the call stack - same as pushl %epc; jmp function                           |
| call  | 1110000000001110 | function  | Jumps to a subroutine and puts the return address on the call stack - same as pushq %rpc; jmp function                           |
| ret   | 0100000000001111 |           | Returns from a subroutine by loading the program counter from the stack top - same as popl %epc                                  |
| ret   | 1110000000001111 |           | Returns from a subroutine by loading the program counter from the stack top - same as popq %epc                                  |
| int   | 0000000000010000 | %reg      | Sends an interrupt stored on an 8-bit register                                                                                   |
| int   | 0000000000010000 | $adr      | Sends an interrupt stored on a 32-bit address                                                                                    |
| int   | 1000000000010000 | $adr      | Sends an interrupt stored on a 64-bit address                                                                                    |
| int   | 0000000000010000 | val       | Sends an interrupt equivalent to an 8-bit value                                                                                  |
| cli   | 0000000000010001 |           | Clears the interrupt flag                                                                                                        |
| sti   | 0000000000010010 |           | Sets the interrupt flag                                                                                                          |

## Logical instructions
| name  |     op code      | arguments | description                                                                                                                      |
|-------|------------------|-----------|----------------------------------------------------------------------------------------------------------------------------------|
| orb   | 0000000000010011 | %reg,%reg | Logical or of 2 8-bit registers, saves result on the first register                                                              |
| orb   | 0000000000010011 | %reg,val  | Logical or of an 8-bit register with an 8-bit value                                                                              |
| orb   | 0000000000010011 | %reg,$adr | Logical or of an 8-bit register with an 8-bit value stored on a 32-bit memory address                                            |
| orb   | 1000000000010011 | %reg,$adr | Logical or of an 8-bit register with an 8-bit value stored on a 64-bit memory address                                            |
| orb   | 0000000000010011 | $adr,%reg | Logical or of an 8-bit value stored on a 32-bit memory address with an 8-bit register                                            |
| orb   | 1000000000010011 | $adr,%reg | Logical or of an 8-bit value stored on a 64-bit memory address with an 8-bit register                                            |
| orb   | 1000000000010011 | $adr,val  | Logical or of an 8-bit value stored on a 64-bit memory address with an 8-bit value                                               |
| or    | 0010000000010011 | %reg,%reg | Logical or of 2 16-bit registers, saves result on the first register                                                             |
| or    | 0010000000010011 | %reg,val  | Logical or of a 16-bit register with a 16-bit value                                                                              |
| or    | 0010000000010011 | %reg,$adr | Logical or of a 16-bit register with a 16-bit value stored on a 32-bit memory address                                            |
| or    | 1010000000010011 | %reg,$adr | Logical or of a 16-bit register with a 16-bit value stored on a 64-bit memory address                                            |
| or    | 0010000000010011 | $adr,%reg | Logical or of a 16-bit value stored on a 32-bit memory address with a 16-bit register                                            |
| or    | 1010000000010011 | $adr,%reg | Logical or of a 16-bit value stored on a 64-bit memory address with a 16-bit register                                            |
| or    | 1010000000010011 | $adr,val  | Logical or of a 16-bit value stored on a 64-bit memory address with a 16-bit value                                               |
| orl   | 0100000000010011 | %reg,%reg | Logical or of 2 32-bit registers, saves result on the first register                                                             |
| orl   | 0100000000010011 | %reg,val  | Logical or of a 32-bit register with a 32-bit value                                                                              |
| orl   | 0100000000010011 | %reg,$adr | Logical or of a 32-bit register with a 32-bit value stored on a 32-bit memory address                                            |
| orl   | 1100000000010011 | %reg,$adr | Logical or of a 32-bit register with a 32-bit value stored on a 64-bit memory address                                            |
| orl   | 0100000000010011 | $adr,%reg | Logical or of a 32-bit value stored on a 32-bit memory address with a 32-bit register                                            |
| orl   | 1100000000010011 | $adr,%reg | Logical or of a 32-bit value stored on a 64-bit memory address with a 32-bit register                                            |
| orl   | 1100000000010011 | $adr,val  | Logical or of a 32-bit value stored on a 64-bit memory address with a 32-bit value                                               |
| orq   | 1110000000010011 | %reg,%reg | Logical or of 2 64-bit registers, saves result on the first register                                                             |
| orq   | 1110000000010011 | %reg,val  | Logical or of a 64-bit register with a 64-bit value                                                                              |
| orq   | 1110000000010011 | %reg,$adr | Logical or of a 64-bit register with a 64-bit value stored on a 64-bit memory address                                            |
| orq   | 1110000000010011 | $adr,%reg | Logical or of a 64-bit value stored on a 64-bit memory address with a 64-bit register                                            |
| xorb  | 0000000000010100 | %reg,%reg | Logical xor of 2 8-bit registers, saves result on the first register                                                             |
| xorb  | 0000000000010100 | %reg,val  | Logical xor of an 8-bit register with an 8-bit value                                                                             |
| xorb  | 0000000000010100 | %reg,$adr | Logical xor of an 8-bit register with an 8-bit value stored on a 32-bit memory address                                           |
| xorb  | 1000000000010100 | %reg,$adr | Logical xor of an 8-bit register with an 8-bit value stored on a 64-bit memory address                                           |
| xorb  | 0000000000010100 | $adr,%reg | Logical xor of an 8-bit value stored on a 32-bit memory address with an 8-bit register                                           |
| xorb  | 1000000000010100 | $adr,%reg | Logical xor of an 8-bit value stored on a 64-bit memory address with an 8-bit register                                           |
| xorb  | 1000000000010100 | $adr,val  | Logical xor of an 8-bit value stored on a 64-bit memory address with an 8-bit value                                              |
| xor   | 0010000000010100 | %reg,%reg | Logical xor of 2 16-bit registers, saves result on the first register                                                            |
| xor   | 0010000000010100 | %reg,val  | Logical xor of a 16-bit register with a 16-bit value                                                                             |
| xor   | 0010000000010100 | %reg,$adr | Logical xor of a 16-bit register with a 16-bit value stored on a 32-bit memory address                                           |
| xor   | 1010000000010100 | %reg,$adr | Logical xor of a 16-bit register with a 16-bit value stored on a 64-bit memory address                                           |
| xor   | 0010000000010100 | $adr,%reg | Logical xor of a 16-bit value stored on a 32-bit memory address with a 16-bit register                                           |
| xor   | 1010000000010100 | $adr,%reg | Logical xor of a 16-bit value stored on a 64-bit memory address with a 16-bit register                                           |
| xor   | 1010000000010100 | $adr,val  | Logical xor of a 16-bit value stored on a 64-bit memory address with a 16-bit value                                              |
| xorl  | 0100000000010100 | %reg,%reg | Logical xor of 2 32-bit registers, saves result on the first register                                                            |
| xorl  | 0100000000010100 | %reg,val  | Logical xor of a 32-bit register with a 32-bit value                                                                             |
| xorl  | 0100000000010100 | %reg,$adr | Logical xor of a 32-bit register with a 32-bit value stored on a 32-bit memory address                                           |
| xorl  | 1100000000010100 | %reg,$adr | Logical xor of a 32-bit register with a 32-bit value stored on a 64-bit memory address                                           |
| xorl  | 0100000000010100 | $adr,%reg | Logical xor of a 32-bit value stored on a 32-bit memory address with a 32-bit register                                           |
| xorl  | 1100000000010100 | $adr,%reg | Logical xor of a 32-bit value stored on a 64-bit memory address with a 32-bit register                                           |
| xorl  | 1100000000010100 | $adr,val  | Logical xor of a 32-bit value stored on a 64-bit memory address with a 32-bit value                                              |
| xorq  | 1110000000010100 | %reg,%reg | Logical xor of 2 64-bit registers, saves result on the first register                                                            |
| xorq  | 1110000000010100 | %reg,val  | Logical xor of a 64-bit register with a 64-bit value                                                                             |
| xorq  | 1110000000010100 | %reg,$adr | Logical xor of a 64-bit register with a 64-bit value stored on a 64-bit memory address                                           |
| xorq  | 1110000000010100 | $adr,%reg | Logical xor of a 64-bit value stored on a 64-bit memory address with a 64-bit register                                           |
| andb  | 0000000000010101 | %reg,%reg | Logical and of 2 8-bit registers, saves result on the first register                                                             |
| andb  | 0000000000010101 | %reg,val  | Logical and of an 8-bit register with an 8-bit value                                                                             |
| andb  | 0000000000010101 | %reg,$adr | Logical and of an 8-bit register with an 8-bit value stored on a 32-bit memory address                                           |
| andb  | 1000000000010101 | %reg,$adr | Logical and of an 8-bit register with an 8-bit value stored on a 64-bit memory address                                           |
| andb  | 0000000000010101 | $adr,%reg | Logical and of an 8-bit value stored on a 32-bit memory address with an 8-bit register                                           |
| andb  | 1000000000010101 | $adr,%reg | Logical and of an 8-bit value stored on a 64-bit memory address with an 8-bit register                                           |
| andb  | 1000000000010101 | $adr,val  | Logical and of an 8-bit value stored on a 64-bit memory address with an 8-bit value                                              |
| and   | 0010000000010101 | %reg,%reg | Logical and of 2 16-bit registers, saves result on the first register                                                            |
| and   | 0010000000010101 | %reg,val  | Logical and of a 16-bit register with a 16-bit value                                                                             |
| and   | 0010000000010101 | %reg,$adr | Logical and of a 16-bit register with a 16-bit value stored on a 32-bit memory address                                           |
| and   | 1010000000010101 | %reg,$adr | Logical and of a 16-bit register with a 16-bit value stored on a 64-bit memory address                                           |
| and   | 0010000000010101 | $adr,%reg | Logical and of a 16-bit value stored on a 32-bit memory address with a 16-bit register                                           |
| and   | 1010000000010101 | $adr,%reg | Logical and of a 16-bit value stored on a 64-bit memory address with a 16-bit register                                           |
| and   | 1010000000010101 | $adr,val  | Logical and of a 16-bit value stored on a 64-bit memory address with a 16-bit value                                              |
| andl  | 0100000000010101 | %reg,%reg | Logical and of 2 32-bit registers, saves result on the first register                                                            |
| andl  | 0100000000010101 | %reg,val  | Logical and of a 32-bit register with a 32-bit value                                                                             |
| andl  | 0100000000010101 | %reg,$adr | Logical and of a 32-bit register with a 32-bit value stored on a 32-bit memory address                                           |
| andl  | 1100000000010101 | %reg,$adr | Logical and of a 32-bit register with a 32-bit value stored on a 64-bit memory address                                           |
| andl  | 0100000000010101 | $adr,%reg | Logical and of a 32-bit value stored on a 32-bit memory address with a 32-bit register                                           |
| andl  | 1100000000010101 | $adr,%reg | Logical and of a 32-bit value stored on a 64-bit memory address with a 32-bit register                                           |
| andl  | 1100000000010101 | $adr,val  | Logical and of a 32-bit value stored on a 64-bit memory address with a 32-bit value                                              |
| andq  | 1110000000010101 | %reg,%reg | Logical and of 2 64-bit registers, saves result on the first register                                                            |
| andq  | 1110000000010101 | %reg,val  | Logical and of a 64-bit register with a 64-bit value                                                                             |
| andq  | 1110000000010101 | %reg,$adr | Logical and of a 64-bit register with a 64-bit value stored on a 64-bit memory address                                           |
| andq  | 1110000000010101 | $adr,%reg | Logical and of a 64-bit value stored on a 64-bit memory address with a 64-bit register                                           |
| nandb | 0000000000010110 | %reg,%reg | Logical nand of 2 8-bit registers, saves result on the first register                                                            |
| nandb | 0000000000010110 | %reg,val  | Logical nand of an 8-bit register with an 8-bit value                                                                            |
| nandb | 0000000000010110 | %reg,$adr | Logical nand of an 8-bit register with an 8-bit value stored on a 32-bit memory address                                          |
| nandb | 1000000000010110 | %reg,$adr | Logical nand of an 8-bit register with an 8-bit value stored on a 64-bit memory address                                          |
| nandb | 0000000000010110 | $adr,%reg | Logical nand of an 8-bit value stored on a 32-bit memory address with an 8-bit register                                          |
| nandb | 1000000000010110 | $adr,%reg | Logical nand of an 8-bit value stored on a 64-bit memory address with an 8-bit register                                          |
| nandb | 1000000000010110 | $adr,val  | Logical nand of an 8-bit value stored on a 64-bit memory address with an 8-bit value                                             |
| nand  | 0010000000010110 | %reg,%reg | Logical nand of 2 16-bit registers, saves result on the first register                                                           |
| nand  | 0010000000010110 | %reg,val  | Logical nand of a 16-bit register with a 16-bit value                                                                            |
| nand  | 0010000000010110 | %reg,$adr | Logical nand of a 16-bit register with a 16-bit value stored on a 32-bit memory address                                          |
| nand  | 1010000000010110 | %reg,$adr | Logical nand of a 16-bit register with a 16-bit value stored on a 64-bit memory address                                          |
| nand  | 0010000000010110 | $adr,%reg | Logical nand of a 16-bit value stored on a 32-bit memory address with a 16-bit register                                          |
| nand  | 1010000000010110 | $adr,%reg | Logical nand of a 16-bit value stored on a 64-bit memory address with a 16-bit register                                          |
| nand  | 1010000000010110 | $adr,val  | Logical nand of a 16-bit value stored on a 64-bit memory address with a 16-bit value                                             |
| nandl | 0100000000010110 | %reg,%reg | Logical nand of 2 32-bit registers, saves result on the first register                                                           |
| nandl | 0100000000010110 | %reg,val  | Logical nand of a 32-bit register with a 32-bit value                                                                            |
| nandl | 0100000000010110 | %reg,$adr | Logical nand of a 32-bit register with a 32-bit value stored on a 32-bit memory address                                          |
| nandl | 1100000000010110 | %reg,$adr | Logical nand of a 32-bit register with a 32-bit value stored on a 64-bit memory address                                          |
| nandl | 0100000000010110 | $adr,%reg | Logical nand of a 32-bit value stored on a 32-bit memory address with a 32-bit register                                          |
| nandl | 1100000000010110 | $adr,%reg | Logical nand of a 32-bit value stored on a 64-bit memory address with a 32-bit register                                          |
| nandl | 1100000000010110 | $adr,val  | Logical nand of a 32-bit value stored on a 64-bit memory address with a 32-bit value                                             |
| nandq | 1110000000010110 | %reg,%reg | Logical nand of 2 64-bit registers, saves result on the first register                                                           |
| nandq | 1110000000010110 | %reg,val  | Logical nand of a 64-bit register with a 64-bit value                                                                            |
| nandq | 1110000000010110 | %reg,$adr | Logical nand of a 64-bit register with a 64-bit value stored on a 64-bit memory address                                          |
| nandq | 1110000000010110 | $adr,%reg | Logical nand of a 64-bit value stored on a 64-bit memory address with a 64-bit register                                          |
| norb  | 0000000000010111 | %reg,%reg | Logical nor of 2 8-bit registers, saves result on the first register                                                             |
| norb  | 0000000000010111 | %reg,val  | Logical nor of an 8-bit register with an 8-bit value                                                                             |
| norb  | 0000000000010111 | %reg,$adr | Logical nor of an 8-bit register with an 8-bit value stored on a 32-bit memory address                                           |
| norb  | 1000000000010111 | %reg,$adr | Logical nor of an 8-bit register with an 8-bit value stored on a 64-bit memory address                                           |
| norb  | 0000000000010111 | $adr,%reg | Logical nor of an 8-bit value stored on a 32-bit memory address with an 8-bit register                                           |
| norb  | 1000000000010111 | $adr,%reg | Logical nor of an 8-bit value stored on a 64-bit memory address with an 8-bit register                                           |
| norb  | 1000000000010111 | $adr,val  | Logical nor of an 8-bit value stored on a 64-bit memory address with an 8-bit value                                              |
| nor   | 0010000000010111 | %reg,%reg | Logical nor of 2 16-bit registers, saves result on the first register                                                            |
| nor   | 0010000000010111 | %reg,val  | Logical nor of a 16-bit register with a 16-bit value                                                                             |
| nor   | 0010000000010111 | %reg,$adr | Logical nor of a 16-bit register with a 16-bit value stored on a 32-bit memory address                                           |
| nor   | 1010000000010111 | %reg,$adr | Logical nor of a 16-bit register with a 16-bit value stored on a 64-bit memory address                                           |
| nor   | 0010000000010111 | $adr,%reg | Logical nor of a 16-bit value stored on a 32-bit memory address with a 16-bit register                                           |
| nor   | 1010000000010111 | $adr,%reg | Logical nor of a 16-bit value stored on a 64-bit memory address with a 16-bit register                                           |
| nor   | 1010000000010111 | $adr,val  | Logical nor of a 16-bit value stored on a 64-bit memory address with a 16-bit value                                              |
| norl  | 0100000000010111 | %reg,%reg | Logical nor of 2 32-bit registers, saves result on the first register                                                            |
| norl  | 0100000000010111 | %reg,val  | Logical nor of a 32-bit register with a 32-bit value                                                                             |
| norl  | 0100000000010111 | %reg,$adr | Logical nor of a 32-bit register with a 32-bit value stored on a 32-bit memory address                                           |
| norl  | 1100000000010111 | %reg,$adr | Logical nor of a 32-bit register with a 32-bit value stored on a 64-bit memory address                                           |
| norl  | 0100000000010111 | $adr,%reg | Logical nor of a 32-bit value stored on a 32-bit memory address with a 32-bit register                                           |
| norl  | 1100000000010111 | $adr,%reg | Logical nor of a 32-bit value stored on a 64-bit memory address with a 32-bit register                                           |
| norl  | 1100000000010111 | $adr,val  | Logical nor of a 32-bit value stored on a 64-bit memory address with a 32-bit value                                              |
| norq  | 1110000000010111 | %reg,%reg | Logical nor of 2 64-bit registers, saves result on the first register                                                            |
| norq  | 1110000000010111 | %reg,val  | Logical nor of a 64-bit register with a 64-bit value                                                                             |
| norq  | 1110000000010111 | %reg,$adr | Logical nor of a 64-bit register with a 64-bit value stored on a 64-bit memory address                                           |
| norq  | 1110000000010111 | $adr,%reg | Logical nor of a 64-bit value stored on a 64-bit memory address with a 64-bit register                                           |
| xnorb | 0000000000011000 | %reg,%reg | Logical xnor of 2 8-bit registers, saves result on the first register                                                            |
| xnorb | 0000000000011000 | %reg,val  | Logical xnor of an 8-bit register with an 8-bit value                                                                            |
| xnorb | 0000000000011000 | %reg,$adr | Logical xnor of an 8-bit register with an 8-bit value stored on a 32-bit memory address                                          |
| xnorb | 1000000000011000 | %reg,$adr | Logical xnor of an 8-bit register with an 8-bit value stored on a 64-bit memory address                                          |
| xnorb | 0000000000011000 | $adr,%reg | Logical xnor of an 8-bit value stored on a 32-bit memory address with an 8-bit register                                          |
| xnorb | 1000000000011000 | $adr,%reg | Logical xnor of an 8-bit value stored on a 64-bit memory address with an 8-bit register                                          |
| xnorb | 1000000000011000 | $adr,val  | Logical xnor of an 8-bit value stored on a 64-bit memory address with an 8-bit value                                             |
| xnor  | 0010000000011000 | %reg,%reg | Logical xnor of 2 16-bit registers, saves result on the first register                                                           |
| xnor  | 0010000000011000 | %reg,val  | Logical xnor of a 16-bit register with a 16-bit value                                                                            |
| xnor  | 0010000000011000 | %reg,$adr | Logical xnor of a 16-bit register with a 16-bit value stored on a 32-bit memory address                                          |
| xnor  | 1010000000011000 | %reg,$adr | Logical xnor of a 16-bit register with a 16-bit value stored on a 64-bit memory address                                          |
| xnor  | 0010000000011000 | $adr,%reg | Logical xnor of a 16-bit value stored on a 32-bit memory address with a 16-bit register                                          |
| xnor  | 1010000000011000 | $adr,%reg | Logical xnor of a 16-bit value stored on a 64-bit memory address with a 16-bit register                                          |
| xnor  | 1010000000011000 | $adr,val  | Logical xnor of a 16-bit value stored on a 64-bit memory address with a 16-bit value                                             |
| xnorl | 0100000000011000 | %reg,%reg | Logical xnor of 2 32-bit registers, saves result on the first register                                                           |
| xnorl | 0100000000011000 | %reg,val  | Logical xnor of a 32-bit register with a 32-bit value                                                                            |
| xnorl | 0100000000011000 | %reg,$adr | Logical xnor of a 32-bit register with a 32-bit value stored on a 32-bit memory address                                          |
| xnorl | 1100000000011000 | %reg,$adr | Logical xnor of a 32-bit register with a 32-bit value stored on a 64-bit memory address                                          |
| xnorl | 0100000000011000 | $adr,%reg | Logical xnor of a 32-bit value stored on a 32-bit memory address with a 32-bit register                                          |
| xnorl | 1100000000011000 | $adr,%reg | Logical xnor of a 32-bit value stored on a 64-bit memory address with a 32-bit register                                          |
| xnorl | 1100000000011000 | $adr,val  | Logical xnor of a 32-bit value stored on a 64-bit memory address with a 32-bit value                                             |
| xnorq | 1110000000011000 | %reg,%reg | Logical xnor of 2 64-bit registers, saves result on the first register                                                           |
| xnorq | 1110000000011000 | %reg,val  | Logical xnor of a 64-bit register with a 64-bit value                                                                            |
| xnorq | 1110000000011000 | %reg,$adr | Logical xnor of a 64-bit register with a 64-bit value stored on a 64-bit memory address                                          |
| xnorq | 1110000000011000 | $adr,%reg | Logical xnor of a 64-bit value stored on a 64-bit memory address with a 64-bit register                                          |
| notb  | 0000000000011001 | %reg      | Logical not of an 8-bit register                                                                                                 |
| notb  | 0000000000011001 | $adr      | Logical not of an 8-bit value stored on a 32-bit memory address                                                                  |
| notb  | 1000000000011001 | $adr      | Logical not of an 8-bit value stored on a 64-bit memory address                                                                  |
| not   | 0010000000011001 | %reg      | Logical not of a 16-bit register                                                                                                 |
| not   | 0010000000011001 | $adr      | Logical not of a 16-bit value stored on a 32-bit memory address                                                                  |
| not   | 1010000000011001 | $adr      | Logical not of a 16-bit value stored on a 64-bit memory address                                                                  |
| notl  | 0100000000011001 | %reg      | Logical not of a 32-bit register                                                                                                 |
| notl  | 0100000000011001 | $adr      | Logical not of a 32-bit value stored on a 32-bit memory address                                                                  |
| notl  | 1100000000011001 | $adr      | Logical not of a 32-bit value stored on a 64-bit memory address                                                                  |
| notq  | 1110000000011001 | %reg      | Logical not of a 64-bit register                                                                                                 |
| notq  | 1110000000011001 | $adr      | Logical not of a 64-bit value stored on a 64-bit memory address                                                                  |
| shlb  | 0000000000011010 | %reg,%reg | Bitshift left of 2 8-bit registers, saves result on the first register                                                           |
| shlb  | 0000000000011010 | %reg,val  | Bitshift left of an 8-bit register with an 8-bit value                                                                           |
| shlb  | 0000000000011010 | %reg,$adr | Bitshift left of an 8-bit register with an 8-bit value stored on a 32-bit memory address                                         |
| shlb  | 1000000000011010 | %reg,$adr | Bitshift left of an 8-bit register with an 8-bit value stored on a 64-bit memory address                                         |
| shlb  | 0000000000011010 | $adr,%reg | Bitshift left of an 8-bit value stored on a 32-bit memory address with an 8-bit register                                         |
| shlb  | 1000000000011010 | $adr,%reg | Bitshift left of an 8-bit value stored on a 64-bit memory address with an 8-bit register                                         |
| shlb  | 1000000000011010 | $adr,val  | Bitshift left of an 8-bit value stored on a 64-bit memory address with an 8-bit value                                            |
| shl   | 0010000000011010 | %reg,%reg | Bitshift left of 2 16-bit registers, saves result on the first register                                                          |
| shl   | 0010000000011010 | %reg,val  | Bitshift left of a 16-bit register with a 16-bit value                                                                           |
| shl   | 0010000000011010 | %reg,$adr | Bitshift left of a 16-bit register with a 16-bit value stored on a 32-bit memory address                                         |
| shl   | 1010000000011010 | %reg,$adr | Bitshift left of a 16-bit register with a 16-bit value stored on a 64-bit memory address                                         |
| shl   | 0010000000011010 | $adr,%reg | Bitshift left of a 16-bit value stored on a 32-bit memory address with a 16-bit register                                         |
| shl   | 1010000000011010 | $adr,%reg | Bitshift left of a 16-bit value stored on a 64-bit memory address with a 16-bit register                                         |
| shl   | 1010000000011010 | $adr,val  | Bitshift left of a 16-bit value stored on a 64-bit memory address with a 16-bit value                                            |
| shll  | 0100000000011010 | %reg,%reg | Bitshift left of 2 32-bit registers, saves result on the first register                                                          |
| shll  | 0100000000011010 | %reg,val  | Bitshift left of a 32-bit register with a 32-bit value                                                                           |
| shll  | 0100000000011010 | %reg,$adr | Bitshift left of a 32-bit register with a 32-bit value stored on a 32-bit memory address                                         |
| shll  | 1100000000011010 | %reg,$adr | Bitshift left of a 32-bit register with a 32-bit value stored on a 64-bit memory address                                         |
| shll  | 0100000000011010 | $adr,%reg | Bitshift left of a 32-bit value stored on a 32-bit memory address with a 32-bit register                                         |
| shll  | 1100000000011010 | $adr,%reg | Bitshift left of a 32-bit value stored on a 64-bit memory address with a 32-bit register                                         |
| shll  | 1100000000011010 | $adr,val  | Bitshift left of a 32-bit value stored on a 64-bit memory address with a 32-bit value                                            |
| shlq  | 1110000000011010 | %reg,%reg | Bitshift left of 2 64-bit registers, saves result on the first register                                                          |
| shlq  | 1110000000011010 | %reg,val  | Bitshift left of a 64-bit register with a 64-bit value                                                                           |
| shlq  | 1110000000011010 | %reg,$adr | Bitshift left of a 64-bit register with a 64-bit value stored on a 64-bit memory address                                         |
| shlq  | 1110000000011010 | $adr,%reg | Bitshift left of a 64-bit value stored on a 64-bit memory address with a 64-bit register                                         |
| shrb  | 0000000000011011 | %reg,%reg | Bitshift right of 2 8-bit registers, saves result on the first register                                                          |
| shrb  | 0000000000011011 | %reg,val  | Bitshift right of an 8-bit register with an 8-bit value                                                                          |
| shrb  | 0000000000011011 | %reg,$adr | Bitshift right of an 8-bit register with an 8-bit value stored on a 32-bit memory address                                        |
| shrb  | 1000000000011011 | %reg,$adr | Bitshift right of an 8-bit register with an 8-bit value stored on a 64-bit memory address                                        |
| shrb  | 0000000000011011 | $adr,%reg | Bitshift right of an 8-bit value stored on a 32-bit memory address with an 8-bit register                                        |
| shrb  | 1000000000011011 | $adr,%reg | Bitshift right of an 8-bit value stored on a 64-bit memory address with an 8-bit register                                        |
| shrb  | 1000000000011011 | $adr,val  | Bitshift right of an 8-bit value stored on a 64-bit memory address with an 8-bit value                                           |
| shr   | 0010000000011011 | %reg,%reg | Bitshift right of 2 16-bit registers, saves result on the first register                                                         |
| shr   | 0010000000011011 | %reg,val  | Bitshift right of a 16-bit register with a 16-bit value                                                                          |
| shr   | 0010000000011011 | %reg,$adr | Bitshift right of a 16-bit register with a 16-bit value stored on a 32-bit memory address                                        |
| shr   | 1010000000011011 | %reg,$adr | Bitshift right of a 16-bit register with a 16-bit value stored on a 64-bit memory address                                        |
| shr   | 0010000000011011 | $adr,%reg | Bitshift right of a 16-bit value stored on a 32-bit memory address with a 16-bit register                                        |
| shr   | 1010000000011011 | $adr,%reg | Bitshift right of a 16-bit value stored on a 64-bit memory address with a 16-bit register                                        |
| shr   | 1010000000011011 | $adr,val  | Bitshift right of a 16-bit value stored on a 64-bit memory address with a 16-bit value                                           |
| shrl  | 0100000000011011 | %reg,%reg | Bitshift right of 2 32-bit registers, saves result on the first register                                                         |
| shrl  | 0100000000011011 | %reg,val  | Bitshift right of a 32-bit register with a 32-bit value                                                                          |
| shrl  | 0100000000011011 | %reg,$adr | Bitshift right of a 32-bit register with a 32-bit value stored on a 32-bit memory address                                        |
| shrl  | 1100000000011011 | %reg,$adr | Bitshift right of a 32-bit register with a 32-bit value stored on a 64-bit memory address                                        |
| shrl  | 0100000000011011 | $adr,%reg | Bitshift right of a 32-bit value stored on a 32-bit memory address with a 32-bit register                                        |
| shrl  | 1100000000011011 | $adr,%reg | Bitshift right of a 32-bit value stored on a 64-bit memory address with a 32-bit register                                        |
| shrl  | 1100000000011011 | $adr,val  | Bitshift right of a 32-bit value stored on a 64-bit memory address with a 32-bit value                                           |
| shrq  | 1110000000011011 | %reg,%reg | Bitshift right of 2 64-bit registers, saves result on the first register                                                         |
| shrq  | 1110000000011011 | %reg,val  | Bitshift right of a 64-bit register with a 64-bit value                                                                          |
| shrq  | 1110000000011011 | %reg,$adr | Bitshift right of a 64-bit register with a 64-bit value stored on a 64-bit memory address                                        |
| shrq  | 1110000000011011 | $adr,%reg | Bitshift right of a 64-bit value stored on a 64-bit memory address with a 64-bit register                                        |

## Conditional instructions
| name  |     op code      | arguments | description                                                                                                                      |
|-------|------------------|-----------|----------------------------------------------------------------------------------------------------------------------------------|
| je    | 0100000000011100 | function  | Jumps to a function if the 2 previously comapred values are equal                                                                |
| je    | 1110000000011100 | function  | Jumps to a function if the 2 previously comapred values are equal                                                                |
| jne   | 0100000000011101 | function  | Jumps to a function if the 2 previously comapred values are not equal                                                            |
| jne   | 1110000000011101 | function  | Jumps to a function if the 2 previously comapred values are not equal                                                            |
| jg    | 0100000000011110 | function  | Jumps to a function if the first previously comapred values is greater than the second                                           |
| jg    | 1110000000011110 | function  | Jumps to a function if the first previously comapred values is greater than the second                                           |
| jl    | 0100000000011111 | function  | Jumps to a function if the first previously comapred values is lower than the second                                             |
| jl    | 1110000000011111 | function  | Jumps to a function if the first previously comapred values is lower than the second                                             |
| jge   | 0100000000100000 | function  | Jumps to a function if the first previously comapred values is greater than the second or the two values are equal               |
| jge   | 1110000000100000 | function  | Jumps to a function if the first previously comapred values is greater than the second or the two values are equal               |
| jle   | 0100000000100001 | function  | Jumps to a function if the first previously comapred values is lower than the second or the two values are equal                 |
| jle   | 1110000000100001 | function  | Jumps to a function if the first previously comapred values is lower than the second or the two values are equal                 |
| jz    | 0100000000100010 | function  | Jumps to a function if the last result was zero                                                                                  |
| jz    | 1110000000100010 | function  | Jumps to a function if the last result was zero                                                                                  |
| jnz   | 0100000000100011 | function  | Jumps to a function if the last result was not zero                                                                              |
| jnz   | 1110000000100011 | function  | Jumps to a function if the last result was not zero                                                                              |
| cmpb  | 0000000000100100 | %reg,%reg | Compares two 8-bit registers                                                                                                     |
| cmpb  | 0000000000100100 | %reg,val  | Compares an 8-bit register with an 8-bit value                                                                                   |
| cmpb  | 0000000000100100 | %reg,$adr | Compares an 8-bit register with an 8-bit value stored on a 32-bit memory address                                                 |
| cmpb  | 1000000000100100 | %reg,$adr | Compares an 8-bit register with an 8-bit value stored on a 64-bit memory address                                                 |
| cmpb  | 0000000000100100 | $adr,%reg | Compares an 8-bit value stored on a 32-bit memory address with an 8-bit register                                                 |
| cmpb  | 1000000000100100 | $adr,%reg | Compares an 8-bit value stored on a 64-bit memory address with an 8-bit register                                                 |
| cmpb  | 1000000000100100 | $adr,val  | Compares an 8-bit value stored on a 64-bit memory address with an 8-bit value                                                    |
| cmp   | 0010000000100100 | %reg,%reg | Compares two 16-bit registers                                                                                                    |
| cmp   | 0010000000100100 | %reg,val  | Compares a 16-bit register with a 16-bit value                                                                                   |
| cmp   | 0010000000100100 | %reg,$adr | Compares a 16-bit register with a 16-bit value stored on a 32-bit memory address                                                 |
| cmp   | 1010000000100100 | %reg,$adr | Compares a 16-bit register with a 16-bit value stored on a 64-bit memory address                                                 |
| cmp   | 0010000000100100 | $adr,%reg | Compares a 16-bit value stored on a 32-bit memory address with a 16-bit register                                                 |
| cmp   | 1010000000100100 | $adr,%reg | Compares a 16-bit value stored on a 64-bit memory address with a 16-bit register                                                 |
| cmp   | 1010000000100100 | $adr,val  | Compares a 16-bit value stored on a 64-bit memory address with a 16-bit value                                                    |
| cmpl  | 0100000000100100 | %reg,%reg | Compares two 32-bit registers                                                                                                    |
| cmpl  | 0100000000100100 | %reg,val  | Compares a 32-bit register with a 32-bit value                                                                                   |
| cmpl  | 0100000000100100 | %reg,$adr | Compares a 32-bit register with a 32-bit value stored on a 32-bit memory address                                                 |
| cmpl  | 1100000000100100 | %reg,$adr | Compares a 32-bit register with a 32-bit value stored on a 64-bit memory address                                                 |
| cmpl  | 0100000000100100 | $adr,%reg | Compares a 32-bit value stored on a 32-bit memory address with a 32-bit register                                                 |
| cmpl  | 1100000000100100 | $adr,%reg | Compares a 32-bit value stored on a 64-bit memory address with a 32-bit register                                                 |
| cmpl  | 1100000000100100 | $adr,val  | Compares a 32-bit value stored on a 64-bit memory address with a 32-bit value                                                    |
| cmpq  | 1110000000100100 | %reg,%reg | Compares two 64-bit registers                                                                                                    |
| cmpq  | 1110000000100100 | %reg,val  | Compares a 64-bit register with a 64-bit value                                                                                   |
| cmpq  | 1110000000100100 | %reg,$adr | Compares a 64-bit register with a 64-bit value stored on a 64-bit memory address                                                 |
| cmpq  | 1110000000100100 | $adr,%reg | Compares a 64-bit value stored on a 64-bit memory address with a 64-bit register                                                 |

## Miscellaneous instructions
| name  |     op code      | arguments | description                                                                                                                      |
|-------|------------------|-----------|----------------------------------------------------------------------------------------------------------------------------------|
| jmp   | 0100000000100101 | function  | Jumps to a function                                                                                                              |
| jmp   | 1110000000100101 | function  | Jumps to a function                                                                                                              |
| wait  | 0000000000100110 |           | Waits for one clock                                                                                                              |
| cpuid | 0000000000101001 |           | Gets info on the cpu                                                                                                             |

## Coprocessor instructions
| name  |     op code      |  arguments   | description                                                                                                                   |
|-------|------------------|--------------|-------------------------------------------------------------------------------------------------------------------------------|
| mcrb  | 0000000000100111 | id,%reg,%reg | Copies the value of the 8-bit register on the current processor to the 8-bit register of a coprocessor                        |
| mcr   | 0010000000100111 | id,%reg,%reg | Copies the value of the 16-bit register on the current processor to the 16-bit register of a coprocessor                      |
| mcrl  | 0100000000100111 | id,%reg,%reg | Copies the value of the 32-bit register on the current processor to the 32-bit register of a coprocessor                      |
| mcrq  | 1110000000100111 | id,%reg,%reg | Copies the value of the 64-bit register on the current processor to the 64-bit register of a coprocessor                      |
| mrcb  | 0000000000101000 | id,%reg,%reg | Copies the value of the 8-bit register on a coprocessor to the 8-bit register of the current processor                        |
| mrc   | 0010000000101000 | id,%reg,%reg | Copies the value of the 16-bit register on a coprocessor to the 16-bit register of the current processor                      |
| mrcl  | 0100000000101000 | id,%reg,%reg | Copies the value of the 32-bit register on a coprocessor to the 32-bit register of the current processor                      |
| mrcq  | 1110000000101000 | id,%reg,%reg | Copies the value of the 64-bit register on a coprocessor to the 64-bit register of the current processor                      |
