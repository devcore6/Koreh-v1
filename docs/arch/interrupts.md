# Interrupt table
## Table of Contents
1. [Hardware-generated exceptions](#hardware-generated-exceptions)
2. [IO-generated interrupts](#io-generated-interrupts)

## Hardware-generated exceptions
|    8bit code    | memory address | name                         | description                                                      |
|-----------------|----------------|------------------------------|------------------------------------------------------------------|
| 00000000 (0x00) |   0x00000000   | Division by zero	          |                                                                  |
| 00000001 (0x01) |   0x00000008   | Single-step interrupt        |                                                                  |
| 00000010 (0x02) |   0x00000010   | Breakpoint                   |                                                                  |
| 00000011 (0x03) |   0x00000018   | Non-maskable interrupt (NMI) |                                                                  |
| 00000100 (0x04) |   0x00000020   | Overflow                     |                                                                  |
| 00000101 (0x05) |   0x00000028   | Invalid opcode               |                                                                  |
| 00000110 (0x06) |   0x00000030   | Double fault                 |                                                                  |
| 00000111 (0x07) |   0x00000038   | Stack fault                  |                                                                  |
| 00001000 (0x08) |   0x00000040   | Coprocessor busy             |                                                                  |
| 00001001 (0x09) |   0x00000048   | Bounds                       |                                                                  |
| 00001010 (0x0A) |   0x00000050   | General protection fault     |                                                                  |
| 00001011 (0x0B) |   0x00000058   | Page fault                   |                                                                  |
| 00001100 (0x0C) |   0x00000060   | Wrong architecture           | Called when trying to run 64-bit instructions on a 32-bit cpu    |

## IO-generated interrupts
|    8bit code    | memory address | name                         | description                                                      |
|-----------------|----------------|------------------------------|------------------------------------------------------------------|
| 00001101 (0x0F) |   0x00000068   | Keyboard data ready          |                                                                  |
