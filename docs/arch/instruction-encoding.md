# Instruction encoding
Instructions can be either 8 or 16 bytes in size, depending on the specific implementation for the target (whether it is a 132-bit or 64-bit machine).
The compiler stores this data in 2 64-bit unsigned integers.
Instructions are stored on the %ir and %idr registers.
The data is structured as following:
## %ir
### 32-bit and up
- (required) 1-bit instruction size prefix (0 -> 8 bytes, 1 -> 16 bytes)
- (required) 2-bit argument size prefix (00 -> byte, 01 -> word, 10 -> long, 11 -> quad)
- (required) 13-bit opcode
- (optional) 8-bit register address or 00000000 to indicate fixed value or 11111111 to indicate memory address stored in %idr
- (optional) 8-bit register address or 00000000 to indicate fixed value or 11111111 to indicate memory address stored in %idr

### 64-bit only
- (optional) 32-bit immediate data

## %idr
- (optional) 32 or 64-bit immediate data