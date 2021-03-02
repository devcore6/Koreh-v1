#pragma once

/*
 * register_t
 * data structure containing the name and address for registers.
 * check docs/arch/registers.md for more information
 */
struct register_t {
	std::string name;
	uint8_t address;
	uint8_t size;
};

extern register_t addregister(std::string name, uint8_t address, uint8_t size);

extern std::vector<register_t> registers;

extern register_t al;
extern register_t ah;
extern register_t ax;
extern register_t eax;
extern register_t rax;
extern register_t bl;
extern register_t bh;
extern register_t bx;
extern register_t ebx;
extern register_t rbx;
extern register_t cl;
extern register_t ch;
extern register_t cx;
extern register_t ecx;
extern register_t rcx;
extern register_t dl;
extern register_t dh;
extern register_t dx;
extern register_t edx;
extern register_t rdx;
extern register_t el;
extern register_t eh;
extern register_t ex;
extern register_t eex;
extern register_t rex;
extern register_t fl;
extern register_t fh;
extern register_t fx;
extern register_t efx;
extern register_t rfx;
extern register_t gl;
extern register_t gh;
extern register_t gx;
extern register_t egx;
extern register_t rgx;
extern register_t hl;
extern register_t hh;
extern register_t hx;
extern register_t ehx;
extern register_t rhx;
extern register_t il;
extern register_t ih;
extern register_t ix;
extern register_t eix;
extern register_t rix;
extern register_t jl;
extern register_t jh;
extern register_t jx;
extern register_t ejx;
extern register_t rjx;
extern register_t kl;
extern register_t kh;
extern register_t kx;
extern register_t ekx;
extern register_t rkx;
extern register_t spl;
extern register_t sph;
extern register_t sp;
extern register_t esp;
extern register_t rsp;
extern register_t bpl;
extern register_t bph;
extern register_t bp;
extern register_t ebp;
extern register_t rbp;
extern register_t sil;
extern register_t sih;
extern register_t si;
extern register_t esi;
extern register_t rsi;
extern register_t dil;
extern register_t dih;
extern register_t di;
extern register_t edi;
extern register_t rdi;
extern register_t cr0;
extern register_t cr1;
extern register_t cr2;
extern register_t cr3;
extern register_t cr4;
extern register_t cr5;
extern register_t cr6;
extern register_t cr7;
extern register_t epc;
extern register_t rpc;
extern register_t ir;
extern register_t rir;
extern register_t idr;
extern register_t ridr;