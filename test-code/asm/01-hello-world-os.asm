movq %rsp, 65536;               Set stack top to 64KB
movq %rbp, 65536;               Set stack bottom to 64KB

pushb 150;                      Push VGA_WIDTH (=150) on the stack - VGA_WIDTH  = (%rbp)
pushb 50;                       Push VGA_HEIGHT (=50) on the stack - VGA_HEIGHT = (%rbp + 1)

push 0;                         Push tty::tty_x on the stack       - tty::tty_x = (%rbp + 2)
push 0;                         Push tty::tty_y on the stack       - tty::tty_y = (%rbp + 4)

pushb 240;                      Push tty::tty_c on the stack       - tty::tty_c = (%rbp + 6)

jmp kernel_main;                Jump to kernel_main

tty__vga_color:
    movb %al, %sil;             Sets al (return register) to sil (first argument)
    shlb %al, 4;                al << 4
    orb  %al, %dil;             Sets al to al | dil (second argument)
    andq %rax, 255;             Removes everything but al from rax
    ret;                        Returns from function

tty__vga_entry:
    movb %al, %dil;             Sets al (return register) to dil (second argument)
    movb %ah, %sil;             Sets ah to sil (first argument)
    andq %rax, 65535;           Removes everything but ax from rax
    ret;                        Returns from function

tty__setcolor:
    movq %rbx, %rbp;            Copies the base pointer onto rbx
    addq %rbx, 6;               Adds 6 to rbx (%rbx = %rbp + 6 = tty::tty_c)
    saveb %sil, %rbx;           Saves the first argument onto tty::tty_c
    ret;                        Returns from function

tty__putc:
    popq %rkx;                  Copies the return address to rkx
    loadb %al, %rbp;            Sets al to the value rbp points to (VGA_WIDTH)
    popb %bl;                   Gets third argument (y) on bl
    mulb;                       Multiplies al with bl (y * VGA_WIDTH)
    movb %bh, %cl;              Stores the result of the multiplication on bx
    movb %bl, %dl;              Stores the result of the multiplication on bx
    andq %rbx, 65535;           Removes everything but bx from rbx
    andq %rdx, 255;             Removes everything but dl from rdx
    addq %rbx, %rdi;            Adds second argument (x) to bx ((y * VGA_WIDTH) + x)
    addq %rbx, 2048;            Adds 2048 (vga_memory) to rbx (vga_memory + (y * VGA_WIDTH) + x)
    savew %si, %rbx;            Saves the entry in the first argument onto (vga_memory + (y * VGA_WIDTH) + x)
    pushq %rkx;                 Pushes the return address back on the stack to be able to return
    ret;                        Returns from function

tty__putchar:
    movq %rbx, %rbp;            Copies the base pointer onto rbx
    addq %rbx, 2;               Adds 2 to rbx (%rbx = %rbp + 2 = tty::tty_x)
    loadb %el, %rbx;            Loads tty::tty_x onto el
    addq %rbx, 2;               Adds 2 to rbx (%rbx = %rbp + 4 = tty::tty_y)
    loadb %eh, %rbx;            Loads tty::tty_y onto eh
    addq %rbx, 2;               Adds 2 to rbx (%rbx = %rbp + 6 = tty::tty_c)
    loadb %dil, %rbx;           Loads tty::tty_c onto dil
    call tty__vga_entry;        Calls tty::vga_entry, result saved on %ax
    movw %si, %ax;              Moves value returned from tty::vga_enter to %si (first argument for next function)
    movb %dil, %el;             Moves tty::tty_x to %dil (second argument for next function)
    pushb %eh;                  Pushes tty::tty_y onto the stack (third argument for next function)
    call tty__putc;             Calls tty::putc
    inc %el;                    Increment %el (new value for tty::tty_x)
    loadb %fl, %rbp;            Load $%rbp onto %fl (VGA_WIDTH)
    cmp %el, %fl;               Compare %el (new tty_x) and %fl (VGA_WIDTH)
    movq %rbx, %rbp;            Copy the base pointer onto rbx
    addq %rbx, 2;               Adds 2 to rbx (%rbx = %rbp + 2 = tty::tty_x)
    je tty__putchar__x__if;     Jump to if(tty_x == VGA_WIDTH)
    movb %gl, %el;              Copy %el to %gl;
    andq %rgx, 255;             Remove everything but %gl from %rgx
    savew %gx, %rbx;            Saves the new value for tty::tty_x
    ret;                        Returns from function

tty__putchar__x__if:
    movb %el, 0;                Set tty::tty_x = 0
    saveb %el, %rbx;            Saves the new value for tty::tty_x
    inc %eh;                    Increment %eh (new value for tty::tty_y)
    dec %rbx;                   Decrement %rbx (now poitns to %rbp + 1 == VGA_HEIGHT)
    loadb %fh, %rbp;            Loads $%rbp onto %fh (VGA_HEIGHT)
    cmp %eh, %fh;               Compare %eh and %fx (tty::tty_y and VGA_HEIGHT)
    addq %rbx, 3;               Add 3 to rbx (%rbx = %rbp + 4 = tty::tty_y)
    movq %rcx, 0;               Set rcx to 0
    je tty__putchar__y__if;     Jump to if(tty_y == VGA_HEIGHT)
    movb %gl, %eh;              Copy %eh to %gl;
    andq %rgx, 255;             Remove everything but %gl from %rgx
    savew %gx, %rbx;            Saves the new value for tty::tty_y
    ret;                        Returns from function

tty__putchar__y__if:
    decw %fh;                   Decrement VGA_HEIGHT
    cmp %cx, %fh;               Compare %cx (counter) and %fh (VGA_HEIGHT - 1)
    incw %fh;                   Increment VGA_HEIGHT
    jge tty__putchar__loop2beg; If we're done with the loop, jump to the next
    movq %rdx, 0;               Set %rdx (counter) to 0
    call tty__putchar__loop1;   Call the first nested loop
    inc %cx;                    Increment loop counter
    jmp tty__putchar__y__if;    Jump to top of loop

tty__putchar__loop1:
    push %fl;                   Push %fl onto stack
    addw %fl, %fl;              Multiply %fl by 2
    cmp %dx, %fl;               Compare %dx (counter) and %fl (VGA_WIDTH * 2)
    popw %fl;                   Pop %fl from stack (VGA_WIDTH)
    jge tty__putchar__loop1ret; Jump to end of loop if not lower
    movq %rbx, 2048;            Set rbx to vga_memory
    pushq %rax;                 Push registers used for multiplication
    pushq %rbx;                 Push registers used for multiplication
    pushq %rcx;                 Push registers used for multiplication
    pushq %rdx;                 Push registers used for multiplication
    movq %rax, %rcx;            Move counter to %rax (for multiplication)
    movb %bl, %fl;              Move VGA_WIDTH to %bl (for multiplication)
    andq %rbx, 255;             Remove everything but %bl from %rbx
    mulq;                       Multiply %rax with %rbx
    addq %rdx, %rdx;            Multiply %rdx by 2
    movq %rax, %rdx;            Move %rdx to %rax to allow us to pop %rdx back from stack
    popq %rdx;                  Pop old %rdx from stack
    addq %rax, %rdx;            Add counter to %rax
    movq %rbx, %rax;            Copy %rax to %rbx
    movq %hl, %gl;              Copy VGA_WIDTH to %hl
    andq %rhx, 255;             Keep only %hl on %rhx
    subq %rbx, %rhx;            Subtract VGA_WIDTH from %rbx
    loadb %rbx, %rbx;           Load vga_memory[((i + 1) * VGA_WIDTH * 2) + j];
    saveb %rax, %rbx;           And save it on vga_memory[(i * VGA_WIDTH * 2) + j];
    popq %rcx;                  Pop old %rcx from stack
    popq %rbx;                  Pop old %rbx from stack
    popq %rax;                  Pop old %rax from stack
    inc %dx;                    Increment counter
    jmp tty__putchar__loop1;    Jump to top of loop


tty__putchar__loop1ret:
    ret;                        Returns from loop

tty__putchar__loop2beg:
    movq %rix, %rfx;            Copy %rfx to %rix
    andq %rix, 65280;           Keep only %ih (VGA_HEIGHT) on %rix
    shrq %rix, 8;               Shift %ih to %il
    dec %rix;                   Decrement %rix (VGA_HEIGHT - 1)
    addq %rix, %rix;            Multiply it by 2 ((VGA_HEIGHT - 1) * 2)
    pushq %rax;                 Push registers used for multiplication
    pushq %rbx;                 Push registers used for multiplication
    pushq %rcx;                 Push registers used for multiplication
    pushq %rdx;                 Push registers used for multiplication
    movq %rax, %rix;            Copy it over to %rax for multiplication
    movb %bl, %fl;              Copy VGA_WIDTH to %bl for multiplication
    andq %rbx, 255;             Keep only VGA_WIDTH for multiplication
    mul;                        Multiply them ((VGA_HEIGHT - 1) * VGA_WIDTH * 2)
    movq %rix, %rdx;            Save the result on %rix
    popq %rdx;                  Pop old %rdx from stack
    popq %rcx;                  Pop old %rcx from stack
    popq %rbx;                  Pop old %rbx from stack
    popq %rax;                  Pop old %rax from stack
    movq %rdx, 0;               Set %rdx to 0
    addq %rix, 2048;            Add address of vga_memory to %rix (vga_memory + ((VGA_HEIGHT - 1) * VGA_WIDTH * 2))
    jmp tty__putchar__loop2;    Jump to last loop

tty__putchar__loop2:
    push %fl;                   Push %fl onto stack
    addw %fl, %fl;              Multiply %fl by 2
    cmp %dx, %fl;               Compare %dx (counter) and %fl (VGA_WIDTH * 2)
    popw %fl;                   Pop %fl from stack (VGA_WIDTH)
    jge tty__putchar__ret;      Jump to end of function if not lower
    incq %rix;                  Increment %rix
    saveb %rix, 0;              Set vga_memory[((VGA_HEIGHT - 1) * VGA_WIDTH * 2) + i] = 0;
    inc %dx;                    Increment counter
    jmp tty__putchar__loop2;    Jump to top of loop

tty__putchar__ret:
    ret;                        Return from function here

tty__write:
    movq %rfx, %rsi;            Moves the string to %rfx
    movq %rgx, %rdi;            Moves the string length to %rgx
    andq %rsi, 0;               Set %rsi back to 0
    jmp tty__write__loop;       Jumps to the loop
    
tty__write__loop:
    cmp %rgx, 0;                Checks that the remaining string length is not 0
    jz tty__write__end;         Jump to end of function if the string is over
    loadb %sil, %rfx;           Load the next character from the string
    call tty__putchar;          Write the character with tty::putchar
    dec %rgx;                   Decrement %rgx (remaining string is now one less character)
    inc %rfx;                   Increment %rfx (go to next character)
    jmp tty__write__loop;       Go back to the top of the loop

tty__write__end:
    ret;                        Return from tty::write here

tty__puts:
    call strlen;                Gets the length of the given string onto %rax
    movq %rdi, %rax;            Moves it to %rdi (second argument)
    call tty__write;            Calls tty__write
    ret;                        Returns from function

strlen:
    andq %rax, 0;               Set %rax to 0
    jmp strlen__loop;           Go to while(str[len]) loop

strlen__loop:
    loadb %bl, %rsi;            Load next character onto %bl
    cmpb %bl, 0;                Compare %bl with 0
    jz strlen__ret;             If %bk == 0 jump to end of function
    inc %rax
    jmp strlen__loop;           Go back to the top of the loop

strlen__ret:
    ret;                        Return from strlen here

kernel_main:
    movb $131072, 'H';          Create Hello world string
    movb $131073, 'e';          Create Hello world string
    movb $131074, 'l';          Create Hello world string
    movb $131075, 'l';          Create Hello world string
    movb $131076, 'o';          Create Hello world string
    movb $131077, ' ';          Create Hello world string
    movb $131078, 'w';          Create Hello world string
    movb $131079, 'o';          Create Hello world string
    movb $131080, 'r';          Create Hello world string
    movb $131081, 'l';          Create Hello world string
    movb $131082, 'd';          Create Hello world string
    movb $131083, '!';          Create Hello world string
    movb $131084, 0;            Create Hello world string
    movq %rsi, 131072;          Set first argument to memory address for Hello world string
    call tty__puts;             Call tty::puts
    jmp endless;                Jump to endless loop

endless:
    jmp endless;                Endless loop
