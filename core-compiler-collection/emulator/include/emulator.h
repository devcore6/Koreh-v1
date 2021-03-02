#pragma once
#include <shared.h>

extern uint64_t cores;
extern uint64_t frequency;
extern uint8_t bits;

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
};

struct function_t {
	instruction_t instruction;
	void (*function)(uint64_t rirval, uint64_t ridrval, core_t* core);
};
