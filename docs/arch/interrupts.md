# Interrupt table
## Table of Contents
1. [Hardware-generated exceptions](#hardware-generated-exceptions)
2. [IO-generated interrupts](#io-generated-interrupts)

## Hardware-generated exceptions
|    8bit code    | 32-bit memory address | 64-bit memory address | name                         | description                                                      |
|-----------------|-----------------------|-----------------------|------------------------------|------------------------------------------------------------------|
| 00000000 (0x00) |      0x00000000       |  0x0000000000000000   | Division by zero	         |                                                                  |
| 00000001 (0x01) |      0x00000004       |  0x0000000000000008   | Single-step interrupt        |                                                                  |
| 00000010 (0x02) |      0x00000008       |  0x0000000000000010   | Breakpoint                   |                                                                  |
| 00000011 (0x03) |      0x0000000B       |  0x0000000000000018   | Non-maskable interrupt (NMI) |                                                                  |
| 00000100 (0x04) |      0x00000010       |  0x0000000000000020   | Overflow                     |                                                                  |
| 00000101 (0x05) |      0x00000014       |  0x0000000000000028   | Invalid opcode               |                                                                  |
| 00000110 (0x06) |      0x00000018       |  0x0000000000000030   | Double fault                 |                                                                  |
| 00000111 (0x07) |      0x0000001B       |  0x0000000000000038   | Stack fault                  |                                                                  |
| 00001000 (0x08) |      0x00000020       |  0x0000000000000040   | Coprocessor busy             |                                                                  |
| 00001001 (0x09) |      0x00000024       |  0x0000000000000048   | Bounds                       |                                                                  |
| 00001010 (0x0A) |      0x00000028       |  0x0000000000000050   | General protection fault     |                                                                  |
| 00001011 (0x0B) |      0x0000002B       |  0x0000000000000058   | Page fault                   |                                                                  |
| 00001100 (0x0C) |      0x00000030       |  0x0000000000000060   | Wrong architecture           | Called when trying to run 64-bit instructions on a 32-bit cpu    |

## IO-generated interrupts
|    8bit code    | 32-bit memory address | 64-bit memory address | name                         | description                                                      |
|-----------------|-----------------------|-----------------------|------------------------------|------------------------------------------------------------------|
| 00001101 (0x0F) |      0x00000034       |  0x0000000000000068   | Keyboard data ready          |                                                                  |
