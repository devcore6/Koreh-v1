#pragma once
#include <shared.h>
#include <cpuid.h>

constexpr uint32_t version = (0 << 24) | (0 << 16) | (1 << 8) | 1; // release << 24 | major << 16 | minor << 8 | 1=alpha 2=beta

extern uint64_t cores;
extern uint64_t frequency;
extern uint8_t bits;
extern uint64_t memorysize;
extern uint8_t* memory;

constexpr bool has_fpu = false;

struct reg_t {
	bool upper = false;
	bool owner = false;
	uint8_t address = 0;
	uint8_t size = 0;
	uint64_t* value = NULL;
	uint64_t getvalue();
	void setvalue(uint64_t);
	reg_t(register_t);
	reg_t(register_t, reg_t*);
	~reg_t();
};

struct regs_t {
	std::vector<reg_t*> data;
	reg_t *operator[](register_t reg);
	regs_t();
	~regs_t();
};

struct core_t {
	uint64_t id;
	regs_t regs;
	std::promise<void> promise;
};

struct function_t {
	instruction_t instruction;
	void (*function)(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core);
};

extern std::vector<core_t*> _cores;
extern std::vector<function_t> functions;

extern uint64_t readmemory(uint64_t address, uint8_t size);
extern void writememory(uint64_t data, uint64_t address, uint8_t size);