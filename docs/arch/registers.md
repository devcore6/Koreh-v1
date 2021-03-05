# Registers
## CPU
| 8b lh addr | 8b lh name | 8b hh addr | 8b hh name | 16b  addr  | 16b name |  32b addr  | 32b name |  64b addr  | 64b name | purpose                                      |
|------------|------------|------------|------------|------------|----------|------------|----------|------------|----------|----------------------------------------------|
|  00000001  |    %al     |  00010001  |    %ah     |  00100001  |   %ax    |  00110001  |   %eax   |  01000001  |   %rax   | stores return value from functions           |
|  00000010  |    %bl     |  00010010  |    %bh     |  00100010  |   %bx    |  00110010  |   %ebx   |  01000010  |   %rbx   | general purpose register                     |
|  00000011  |    %cl     |  00010011  |    %ch     |  00100011  |   %cx    |  00110011  |   %ecx   |  01000011  |   %rcx   | general purpose register, also loop counter  |
|  00000100  |    %dl     |  00010100  |    %dh     |  00100100  |   %dx    |  00110100  |   %edx   |  01000100  |   %rdx   | general purpose register                     |
|  00000101  |    %el     |  00010101  |    %eh     |  00100101  |   %ex    |  00110101  |   %eex   |  01000101  |   %rex   | general purpose register                     |
|  00000110  |    %fl     |  00010110  |    %fh     |  00100110  |   %fx    |  00110110  |   %efx   |  01000110  |   %rfx   | general purpose register                     |
|  00000111  |    %gl     |  00010111  |    %gh     |  00100111  |   %gx    |  00110111  |   %egx   |  01000111  |   %rgx   | general purpose register                     |
|  00001000  |    %hl     |  00011000  |    %hh     |  00101000  |   %hx    |  00111000  |   %ehx   |  01001000  |   %rhx   | general purpose register                     |
|  00001001  |    %il     |  00011001  |    %ih     |  00101001  |   %ix    |  00111001  |   %eix   |  01001001  |   %rix   | general purpose register                     |
|  00001010  |    %jl     |  00011010  |    %jh     |  00101010  |   %jx    |  00111010  |   %ejx   |  01001010  |   %rjx   | general purpose register                     |
|  00001011  |    %kl     |  00011011  |    %kh     |  00101011  |   %kx    |  00111011  |   %ekx   |  01001011  |   %rkx   | general purpose register                     |
|  00001100  |    %spl    |  00011100  |    %sph    |  00101100  |   %sp    |  00111100  |   %esp   |  01001100  |   %rsp   | stack pointer, points to top of stack        |
|  00001101  |    %bpl    |  00011101  |    %bph    |  00101101  |   %bp    |  00111101  |   %ebp   |  01001101  |   %rbp   | base pointer, points to base of stack        |
|  00001110  |    %sil    |  00011110  |    %sih    |  00101110  |   %si    |  00111110  |   %esi   |  01001110  |   %rsi   | first function argument                      |
|  00001111  |    %dil    |  00011111  |    %dih    |  00101111  |   %di    |  00111111  |   %edi   |  01001111  |   %rdi   | second function argument                     |
|    ----    |    ----    |    ----    |    ----    |    ----    |   ----   |  10000000  |   %cr0   |    ----    |   ----   | control register 0                           |
|    ----    |    ----    |    ----    |    ----    |    ----    |   ----   |  10000001  |   %cr1   |    ----    |   ----   | control register 1                           |
|    ----    |    ----    |    ----    |    ----    |    ----    |   ----   |  10000010  |   %cr2   |    ----    |   ----   | control register 2                           |
|    ----    |    ----    |    ----    |    ----    |    ----    |   ----   |  10000011  |   %cr3   |    ----    |   ----   | control register 3                           |
|    ----    |    ----    |    ----    |    ----    |    ----    |   ----   |  10000100  |   %cr4   |    ----    |   ----   | control register 4                           |
|    ----    |    ----    |    ----    |    ----    |    ----    |   ----   |  10000101  |   %cr5   |    ----    |   ----   | control register 5                           |
|    ----    |    ----    |    ----    |    ----    |    ----    |   ----   |  10000110  |   %cr6   |    ----    |   ----   | control register 6                           |
|    ----    |    ----    |    ----    |    ----    |    ----    |   ----   |  10000111  |   %cr7   |    ----    |   ----   | control register 7                           |
|    ----    |    ----    |    ----    |    ----    |    ----    |   ----   |  10001000  |   %epc   |  10001001  |   %rpc   | program counter                              |
|    ----    |    ----    |    ----    |    ----    |    ----    |   ----   |  10001010  |   %ir    |  10001011  |   %rir   | instruction register                         |
|    ----    |    ----    |    ----    |    ----    |    ----    |   ----   |  10001100  |   %idr   |  10001101  |   %ridr  | instruction data                             |

## FPU
|  32b addr  | 32b name |  64b addr  | 64b name | 128b addr  | 128b name | purpose                                      |
|------------|----------|------------|----------|------------|-----------|----------------------------------------------|
|  11000000  |   %fax   |  11000001  |   %dax   |  11000010  |   %qax    | general purpose register                     |
|  11000100  |   %fbx   |  11000101  |   %dbx   |  11000110  |   %qbx    | general purpose register                     |
|  11001000  |   %fcx   |  11001001  |   %dcx   |  11001010  |   %qcx    | general purpose register                     |
|  11001100  |   %fdx   |  11001101  |   %ddx   |  11001110  |   %qdx    | general purpose register                     |
|  11010000  |   %fex   |  11010001  |   %dex   |  11010010  |   %qex    | general purpose register                     |
|  11010100  |   %ffx   |  11010101  |   %dfx   |  11010110  |   %qfx    | general purpose register                     |
|  11011000  |   %fgx   |  11011001  |   %dgx   |  11011010  |   %qgx    | general purpose register                     |
|  11011100  |   %fhx   |  11011101  |   %dhx   |  11011110  |   %qhx    | general purpose register                     |