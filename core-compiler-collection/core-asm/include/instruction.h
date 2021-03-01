#pragma once

/*
 * instruction_t
 * data structure for instructions.
 * check docs/arch/instructions.md for more information
 * also check docs/arch/instruction-encoding.md for more information on instruction encoding
 */
struct instruction_t {
	std::string name;
	uint16_t opcode;
	uint8_t arg1 = 0; // 0 = not required, 1 = value, 2 = register, 3 = memory, 4 = function
	uint8_t arg2 = 0; // 0 = not required, 1 = value, 2 = register, 3 = memory, 4 = function
	uint8_t arg3 = 0; // 0 = not required, 1 = value, 2 = register, 3 = memory, 4 = function
};

extern std::vector<instruction_t> validinstructions;
extern std::vector<uint8_t> getargt(instruction_t);
extern void addinstruction(std::string name, uint16_t opcode, uint8_t arg1 = 0, uint8_t arg2 = 0, uint8_t arg3 = 0);