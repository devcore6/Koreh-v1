#include <shared.h>

std::vector <instruction_t> validinstructions;

std::vector<uint8_t> getargt(instruction_t instruction) {
	std::vector<uint8_t> out;
	if(instruction.arg1 == 0) return out;
	out.push_back(instruction.arg1);
	if(instruction.arg2 == 0) return out;
	out.push_back(instruction.arg2);
	if(instruction.arg3 == 0) return out;
	out.push_back(instruction.arg3);
	return out;
}

void addinstruction(std::string name, uint16_t opcode, uint8_t arg1, uint8_t arg2, uint8_t arg3) {
	instruction_t instruction = { name, opcode, arg1, arg2, arg3 };
	validinstructions.push_back(instruction);
}

bool initinstructions() {
	addinstruction("movb", 0b0000000000000001, 2, 2);
	addinstruction("movb", 0b0000010000000001, 2, 1);
	addinstruction("movb", 0b0000100000000001, 2, 3);
	addinstruction("movb", 0b1000100000000001, 2, 3);
	addinstruction("movb", 0b0000110000000001, 3, 2);
	addinstruction("movb", 0b1000110000000001, 3, 2);
	addinstruction("movb", 0b1001000000000001, 3, 1);
	addinstruction("mov", 0b0010000000000001, 2, 2);
	addinstruction("mov", 0b0010010000000001, 2, 1);
	addinstruction("mov", 0b0010100000000001, 2, 3);
	addinstruction("mov", 0b1010100000000001, 2, 3);
	addinstruction("mov", 0b0010110000000001, 3, 2);
	addinstruction("mov", 0b1010110000000001, 3, 2);
	addinstruction("mov", 0b1011000000000001, 3, 1);
	addinstruction("movl", 0b0100000000000001, 2, 2);
	addinstruction("movl", 0b0100010000000001, 2, 1);
	addinstruction("movl", 0b0100100000000001, 2, 3);
	addinstruction("movl", 0b1100100000000001, 2, 3);
	addinstruction("movl", 0b0100110000000001, 3, 2);
	addinstruction("movl", 0b1100110000000001, 3, 2);
	addinstruction("movl", 0b1101000000000001, 3, 1);
	addinstruction("movq", 0b1110000000000001, 2, 2);
	addinstruction("movq", 0b1110010000000001, 2, 1);
	addinstruction("movq", 0b1110100000000001, 2, 3);
	addinstruction("movq", 0b1110110000000001, 3, 2);
	addinstruction("loadb", 0b0000000000000010, 2, 2);
	addinstruction("loadb", 0b1000000000000010, 2, 2);
	addinstruction("load", 0b0010000000000010, 2, 2);
	addinstruction("load", 0b1010000000000010, 2, 2);
	addinstruction("loadl", 0b0100000000000010, 2, 2);
	addinstruction("loadl", 0b1100000000000010, 2, 2);
	addinstruction("loadq", 0b1110000000000010, 2, 2);
	addinstruction("saveb", 0b0000000000000011, 2, 2);
	addinstruction("saveb", 0b1000000000000011, 2, 2);
	addinstruction("save", 0b0010000000000011, 2, 2);
	addinstruction("save", 0b1010000000000011, 2, 2);
	addinstruction("savel", 0b0100000000000011, 2, 2);
	addinstruction("savel", 0b1100000000000011, 2, 2);
	addinstruction("saveq", 0b1110000000000011, 2, 2);
	addinstruction("incb", 0b0000000000000100, 2);
	addinstruction("incb", 0b0001000000000100, 3);
	addinstruction("incb", 0b1001000000000100, 3);
	addinstruction("inc", 0b0010000000000100, 2);
	addinstruction("inc", 0b0011000000000100, 3);
	addinstruction("inc", 0b1011000000000100, 3);
	addinstruction("incl", 0b0100000000000100, 2);
	addinstruction("incl", 0b0101000000000100, 3);
	addinstruction("incl", 0b1101000000000100, 3);
	addinstruction("incq", 0b1110000000000100, 2);
	addinstruction("incq", 0b1111000000000100, 3);
	addinstruction("decb", 0b0000000000000101, 2);
	addinstruction("decb", 0b0001000000000101, 3);
	addinstruction("decb", 0b1001000000000101, 3);
	addinstruction("dec", 0b0010000000000101, 2);
	addinstruction("dec", 0b0011000000000101, 3);
	addinstruction("dec", 0b1011000000000101, 3);
	addinstruction("decl", 0b0100000000000101, 2);
	addinstruction("decl", 0b0101000000000101, 3);
	addinstruction("decl", 0b1101000000000101, 3);
	addinstruction("decq", 0b1110000000000101, 2);
	addinstruction("decq", 0b1111000000000101, 3);
	addinstruction("addb", 0b0000000000000110, 2, 2);
	addinstruction("addb", 0b0000010000000110, 2, 1);
	addinstruction("addb", 0b0000100000000110, 2, 3);
	addinstruction("addb", 0b1000100000000110, 2, 3);
	addinstruction("addb", 0b0000110000000110, 3, 2);
	addinstruction("addb", 0b1000110000000110, 3, 2);
	addinstruction("addb", 0b1001000000000110, 3, 1);
	addinstruction("add", 0b0010000000000110, 2, 2);
	addinstruction("add", 0b0010010000000110, 2, 1);
	addinstruction("add", 0b0010100000000110, 2, 3);
	addinstruction("add", 0b1010100000000110, 2, 3);
	addinstruction("add", 0b0010110000000110, 3, 2);
	addinstruction("add", 0b1010110000000110, 3, 2);
	addinstruction("add", 0b1011000000000110, 3, 1);
	addinstruction("addl", 0b0100000000000110, 2, 2);
	addinstruction("addl", 0b0100010000000110, 2, 1);
	addinstruction("addl", 0b0100100000000110, 2, 3);
	addinstruction("addl", 0b1100100000000110, 2, 3);
	addinstruction("addl", 0b0100110000000110, 3, 2);
	addinstruction("addl", 0b1100110000000110, 3, 2);
	addinstruction("addl", 0b1101000000000110, 3, 1);
	addinstruction("addq", 0b1110000000000110, 2, 2);
	addinstruction("addq", 0b1110010000000110, 2, 1);
	addinstruction("addq", 0b1110100000000110, 2, 3);
	addinstruction("addq", 0b1110110000000110, 3, 2);
	addinstruction("subb", 0b0000000000000111, 2, 2);
	addinstruction("subb", 0b0000010000000111, 2, 1);
	addinstruction("subb", 0b0000100000000111, 2, 3);
	addinstruction("subb", 0b1000100000000111, 2, 3);
	addinstruction("subb", 0b0000110000000111, 3, 2);
	addinstruction("subb", 0b1000110000000111, 3, 2);
	addinstruction("subb", 0b1001000000000111, 3, 1);
	addinstruction("sub", 0b0010000000000111, 2, 2);
	addinstruction("sub", 0b0010010000000111, 2, 1);
	addinstruction("sub", 0b0010100000000111, 2, 3);
	addinstruction("sub", 0b1010100000000111, 2, 3);
	addinstruction("sub", 0b0010110000000111, 3, 2);
	addinstruction("sub", 0b1010110000000111, 3, 2);
	addinstruction("sub", 0b1011000000000111, 3, 1);
	addinstruction("subl", 0b0100000000000111, 2, 2);
	addinstruction("subl", 0b0100010000000111, 2, 1);
	addinstruction("subl", 0b0100100000000111, 2, 3);
	addinstruction("subl", 0b1100100000000111, 2, 3);
	addinstruction("subl", 0b0100110000000111, 3, 2);
	addinstruction("subl", 0b1100110000000111, 3, 2);
	addinstruction("subl", 0b1101000000000111, 3, 1);
	addinstruction("subq", 0b1110000000000111, 2, 2);
	addinstruction("subq", 0b1110010000000111, 2, 1);
	addinstruction("subq", 0b1110100000000111, 2, 3);
	addinstruction("subq", 0b1110110000000111, 3, 2);
	addinstruction("mulb", 0b0000000000001000);
	addinstruction("mul", 0b0010000000001000);
	addinstruction("mull", 0b0100000000001000);
	addinstruction("mulq", 0b1110000000001000);
	addinstruction("imulb", 0b0000000000001001);
	addinstruction("imul", 0b0010000000001001);
	addinstruction("imull", 0b0100000000001001);
	addinstruction("imulq", 0b1110000000001001);
	addinstruction("divb", 0b0000000000001010);
	addinstruction("div", 0b0010000000001010);
	addinstruction("divl", 0b0100000000001010);
	addinstruction("divq", 0b1110000000001010);
	addinstruction("idivb", 0b0000000000001011);
	addinstruction("idiv", 0b0010000000001011);
	addinstruction("idivl", 0b0100000000001011);
	addinstruction("idivq", 0b1110000000001011);
	addinstruction("pushb", 0b0000000000001100, 2);
	addinstruction("pushb", 0b0000100000001100, 1);
	addinstruction("pushb", 0b0001000000001100, 3);
	addinstruction("pushb", 0b1001000000001100, 3);
	addinstruction("push", 0b0010000000001100, 2);
	addinstruction("push", 0b0010100000001100, 1);
	addinstruction("push", 0b0011000000001100, 3);
	addinstruction("push", 0b1011000000001100, 3);
	addinstruction("pushl", 0b0100000000001100, 2);
	addinstruction("pushl", 0b0100100000001100, 1);
	addinstruction("pushl", 0b0101000000001100, 3);
	addinstruction("pushl", 0b1101000000001100, 3);
	addinstruction("pushq", 0b1110000000001100, 2);
	addinstruction("pushq", 0b1110100000001100, 1);
	addinstruction("pushq", 0b1111000000001100, 3);
	addinstruction("popb", 0b0000000000001101, 2);
	addinstruction("pop", 0b0010000000001101, 2);
	addinstruction("popl", 0b0100000000001101, 2);
	addinstruction("popq", 0b1110000000001101, 2);
	addinstruction("call", 0b0100000000001110, 4);
	addinstruction("call", 0b1110000000001110, 4);
	addinstruction("ret", 0b0100000000001111);
	addinstruction("ret", 0b1110000000001111);
	addinstruction("int", 0b0000000000010000, 2);
	addinstruction("int", 0b0101000000010000, 3);
	addinstruction("int", 0b1001000000010000, 3);
	addinstruction("int", 0b0000100000010000, 1);
	addinstruction("cli", 0b0000000000010001);
	addinstruction("sti", 0b0000000000010010);
	addinstruction("orb", 0b0000000000010011, 2, 2);
	addinstruction("orb", 0b0000010000010011, 2, 1);
	addinstruction("orb", 0b0000100000010011, 2, 3);
	addinstruction("orb", 0b1000100000010011, 2, 3);
	addinstruction("orb", 0b0000110000010011, 3, 2);
	addinstruction("orb", 0b1000110000010011, 3, 2);
	addinstruction("orb", 0b1001000000010011, 3, 1);
	addinstruction("or", 0b0010000000010011, 2, 2);
	addinstruction("or", 0b0010010000010011, 2, 1);
	addinstruction("or", 0b0010100000010011, 2, 3);
	addinstruction("or", 0b1010100000010011, 2, 3);
	addinstruction("or", 0b0010110000010011, 3, 2);
	addinstruction("or", 0b1010110000010011, 3, 2);
	addinstruction("or", 0b1011000000010011, 3, 1);
	addinstruction("orl", 0b0100000000010011, 2, 2);
	addinstruction("orl", 0b0100010000010011, 2, 1);
	addinstruction("orl", 0b0100100000010011, 2, 3);
	addinstruction("orl", 0b1100100000010011, 2, 3);
	addinstruction("orl", 0b0100110000010011, 3, 2);
	addinstruction("orl", 0b1100110000010011, 3, 2);
	addinstruction("orl", 0b1101000000010011, 3, 1);
	addinstruction("orq", 0b1110000000010011, 2, 2);
	addinstruction("orq", 0b1110010000010011, 2, 1);
	addinstruction("orq", 0b1110100000010011, 2, 3);
	addinstruction("orq", 0b1110110000010011, 3, 2);
	addinstruction("xorb", 0b0000000000010100, 2, 2);
	addinstruction("xorb", 0b0000010000010100, 2, 1);
	addinstruction("xorb", 0b0000100000010100, 2, 3);
	addinstruction("xorb", 0b1000100000010100, 2, 3);
	addinstruction("xorb", 0b0000110000010100, 3, 2);
	addinstruction("xorb", 0b1000110000010100, 3, 2);
	addinstruction("xorb", 0b1001000000010100, 3, 1);
	addinstruction("xor", 0b0010000000010100, 2, 2);
	addinstruction("xor", 0b0010010000010100, 2, 1);
	addinstruction("xor", 0b0010100000010100, 2, 3);
	addinstruction("xor", 0b1010100000010100, 2, 3);
	addinstruction("xor", 0b0010110000010100, 3, 2);
	addinstruction("xor", 0b1010110000010100, 3, 2);
	addinstruction("xor", 0b1011000000010100, 3, 1);
	addinstruction("xorl", 0b0100000000010100, 2, 2);
	addinstruction("xorl", 0b0100010000010100, 2, 1);
	addinstruction("xorl", 0b0100100000010100, 2, 3);
	addinstruction("xorl", 0b1100100000010100, 2, 3);
	addinstruction("xorl", 0b0100110000010100, 3, 2);
	addinstruction("xorl", 0b1100110000010100, 3, 2);
	addinstruction("xorl", 0b1101000000010100, 3, 1);
	addinstruction("xorq", 0b1110000000010100, 2, 2);
	addinstruction("xorq", 0b1110010000010100, 2, 1);
	addinstruction("xorq", 0b1110100000010100, 2, 3);
	addinstruction("xorq", 0b1110110000010100, 3, 2);
	addinstruction("andb", 0b0000000000010101, 2, 2);
	addinstruction("andb", 0b0000010000010101, 2, 1);
	addinstruction("andb", 0b0000100000010101, 2, 3);
	addinstruction("andb", 0b1000100000010101, 2, 3);
	addinstruction("andb", 0b0000110000010101, 3, 2);
	addinstruction("andb", 0b1000110000010101, 3, 2);
	addinstruction("andb", 0b1001000000010101, 3, 1);
	addinstruction("and", 0b0010000000010101, 2, 2);
	addinstruction("and", 0b0010010000010101, 2, 1);
	addinstruction("and", 0b0010100000010101, 2, 3);
	addinstruction("and", 0b1010100000010101, 2, 3);
	addinstruction("and", 0b0010110000010101, 3, 2);
	addinstruction("and", 0b1010110000010101, 3, 2);
	addinstruction("and", 0b1011000000010101, 3, 1);
	addinstruction("andl", 0b0100000000010101, 2, 2);
	addinstruction("andl", 0b0100010000010101, 2, 1);
	addinstruction("andl", 0b0100100000010101, 2, 3);
	addinstruction("andl", 0b1100100000010101, 2, 3);
	addinstruction("andl", 0b0100110000010101, 3, 2);
	addinstruction("andl", 0b1100110000010101, 3, 2);
	addinstruction("andl", 0b1101000000010101, 3, 1);
	addinstruction("andq", 0b1110000000010101, 2, 2);
	addinstruction("andq", 0b1110010000010101, 2, 1);
	addinstruction("andq", 0b1110100000010101, 2, 3);
	addinstruction("andq", 0b1110110000010101, 3, 2);
	addinstruction("nandb", 0b0000000000010110, 2, 2);
	addinstruction("nandb", 0b0000010000010110, 2, 1);
	addinstruction("nandb", 0b0000100000010110, 2, 3);
	addinstruction("nandb", 0b1000100000010110, 2, 3);
	addinstruction("nandb", 0b0000110000010110, 3, 2);
	addinstruction("nandb", 0b1000110000010110, 3, 2);
	addinstruction("nandb", 0b1001000000010110, 3, 1);
	addinstruction("nand", 0b0010000000010110, 2, 2);
	addinstruction("nand", 0b0010010000010110, 2, 1);
	addinstruction("nand", 0b0010100000010110, 2, 3);
	addinstruction("nand", 0b1010100000010110, 2, 3);
	addinstruction("nand", 0b0010110000010110, 3, 2);
	addinstruction("nand", 0b1010110000010110, 3, 2);
	addinstruction("nand", 0b1011000000010110, 3, 1);
	addinstruction("nandl", 0b0100000000010110, 2, 2);
	addinstruction("nandl", 0b0100010000010110, 2, 1);
	addinstruction("nandl", 0b0100100000010110, 2, 3);
	addinstruction("nandl", 0b1100100000010110, 2, 3);
	addinstruction("nandl", 0b0100110000010110, 3, 2);
	addinstruction("nandl", 0b1100110000010110, 3, 2);
	addinstruction("nandl", 0b1101000000010110, 3, 1);
	addinstruction("nandq", 0b1110000000010110, 2, 2);
	addinstruction("nandq", 0b1110010000010110, 2, 1);
	addinstruction("nandq", 0b1110100000010110, 2, 3);
	addinstruction("nandq", 0b1110110000010110, 3, 2);
	addinstruction("norb", 0b0000000000010111, 2, 2);
	addinstruction("norb", 0b0000010000010111, 2, 1);
	addinstruction("norb", 0b0000100000010111, 2, 3);
	addinstruction("norb", 0b1000100000010111, 2, 3);
	addinstruction("norb", 0b0000110000010111, 3, 2);
	addinstruction("norb", 0b1000110000010111, 3, 2);
	addinstruction("norb", 0b1001000000010111, 3, 1);
	addinstruction("nor", 0b0010000000010111, 2, 2);
	addinstruction("nor", 0b0010010000010111, 2, 1);
	addinstruction("nor", 0b0010100000010111, 2, 3);
	addinstruction("nor", 0b1010100000010111, 2, 3);
	addinstruction("nor", 0b0010110000010111, 3, 2);
	addinstruction("nor", 0b1010110000010111, 3, 2);
	addinstruction("nor", 0b1011000000010111, 3, 1);
	addinstruction("norl", 0b0100000000010111, 2, 2);
	addinstruction("norl", 0b0100010000010111, 2, 1);
	addinstruction("norl", 0b0100100000010111, 2, 3);
	addinstruction("norl", 0b1100100000010111, 2, 3);
	addinstruction("norl", 0b0100110000010111, 3, 2);
	addinstruction("norl", 0b1100110000010111, 3, 2);
	addinstruction("norl", 0b1101000000010111, 3, 1);
	addinstruction("norq", 0b1110000000010111, 2, 2);
	addinstruction("norq", 0b1110010000010111, 2, 1);
	addinstruction("norq", 0b1110100000010111, 2, 3);
	addinstruction("norq", 0b1110110000010111, 3, 2);
	addinstruction("xnorb", 0b0000000000011000, 2, 2);
	addinstruction("xnorb", 0b0000010000011000, 2, 1);
	addinstruction("xnorb", 0b0000100000011000, 2, 3);
	addinstruction("xnorb", 0b1000100000011000, 2, 3);
	addinstruction("xnorb", 0b0000110000011000, 3, 2);
	addinstruction("xnorb", 0b1000110000011000, 3, 2);
	addinstruction("xnorb", 0b1001000000011000, 3, 1);
	addinstruction("xnor", 0b0010000000011000, 2, 2);
	addinstruction("xnor", 0b0010010000011000, 2, 1);
	addinstruction("xnor", 0b0010100000011000, 2, 3);
	addinstruction("xnor", 0b1010100000011000, 2, 3);
	addinstruction("xnor", 0b0010110000011000, 3, 2);
	addinstruction("xnor", 0b1010110000011000, 3, 2);
	addinstruction("xnor", 0b1011000000011000, 3, 1);
	addinstruction("xnorl", 0b0100000000011000, 2, 2);
	addinstruction("xnorl", 0b0100010000011000, 2, 1);
	addinstruction("xnorl", 0b0100100000011000, 2, 3);
	addinstruction("xnorl", 0b1100100000011000, 2, 3);
	addinstruction("xnorl", 0b0100110000011000, 3, 2);
	addinstruction("xnorl", 0b1100110000011000, 3, 2);
	addinstruction("xnorl", 0b1101000000011000, 3, 1);
	addinstruction("xnorq", 0b1110000000011000, 2, 2);
	addinstruction("xnorq", 0b1110010000011000, 2, 1);
	addinstruction("xnorq", 0b1110100000011000, 2, 3);
	addinstruction("xnorq", 0b1110110000011000, 3, 2);
	addinstruction("notb", 0b0000000000011001, 2);
	addinstruction("notb", 0b0001000000011001, 3);
	addinstruction("notb", 0b1001000000011001, 3);
	addinstruction("not", 0b0010000000011001, 2);
	addinstruction("not", 0b0011000000011001, 3);
	addinstruction("not", 0b1011000000011001, 3);
	addinstruction("notl", 0b0100000000011001, 2);
	addinstruction("notl", 0b0101000000011001, 3);
	addinstruction("notl", 0b1101000000011001, 3);
	addinstruction("notq", 0b1110000000011001, 2);
	addinstruction("notq", 0b1111000000011001, 3);
	addinstruction("shlb", 0b0000000000011010, 2, 2);
	addinstruction("shlb", 0b0000010000011010, 2, 1);
	addinstruction("shlb", 0b0000100000011010, 2, 3);
	addinstruction("shlb", 0b1000100000011010, 2, 3);
	addinstruction("shlb", 0b0000110000011010, 3, 2);
	addinstruction("shlb", 0b1000110000011010, 3, 2);
	addinstruction("shlb", 0b1001000000011010, 3, 1);
	addinstruction("shl", 0b0010000000011010, 2, 2);
	addinstruction("shl", 0b0010010000011010, 2, 1);
	addinstruction("shl", 0b0010100000011010, 2, 3);
	addinstruction("shl", 0b1010100000011010, 2, 3);
	addinstruction("shl", 0b0010110000011010, 3, 2);
	addinstruction("shl", 0b1010110000011010, 3, 2);
	addinstruction("shl", 0b1011000000011010, 3, 1);
	addinstruction("shll", 0b0100000000011010, 2, 2);
	addinstruction("shll", 0b0100010000011010, 2, 1);
	addinstruction("shll", 0b0100100000011010, 2, 3);
	addinstruction("shll", 0b1100100000011010, 2, 3);
	addinstruction("shll", 0b0100110000011010, 3, 2);
	addinstruction("shll", 0b1100110000011010, 3, 2);
	addinstruction("shll", 0b1101000000011010, 3, 1);
	addinstruction("shlq", 0b1110000000011010, 2, 2);
	addinstruction("shlq", 0b1110010000011010, 2, 1);
	addinstruction("shlq", 0b1110100000011010, 2, 3);
	addinstruction("shlq", 0b1110110000011010, 3, 2);
	addinstruction("shrb", 0b0000000000011011, 2, 2);
	addinstruction("shrb", 0b0000010000011011, 2, 1);
	addinstruction("shrb", 0b0000100000011011, 2, 3);
	addinstruction("shrb", 0b1000100000011011, 2, 3);
	addinstruction("shrb", 0b0000110000011011, 3, 2);
	addinstruction("shrb", 0b1000110000011011, 3, 2);
	addinstruction("shrb", 0b1001000000011011, 3, 1);
	addinstruction("shr", 0b0010000000011011, 2, 2);
	addinstruction("shr", 0b0010010000011011, 2, 1);
	addinstruction("shr", 0b0010100000011011, 2, 3);
	addinstruction("shr", 0b1010100000011011, 2, 3);
	addinstruction("shr", 0b0010110000011011, 3, 2);
	addinstruction("shr", 0b1010110000011011, 3, 2);
	addinstruction("shr", 0b1011000000011011, 3, 1);
	addinstruction("shrl", 0b0100000000011011, 2, 2);
	addinstruction("shrl", 0b0100010000011011, 2, 1);
	addinstruction("shrl", 0b0100100000011011, 2, 3);
	addinstruction("shrl", 0b1100100000011011, 2, 3);
	addinstruction("shrl", 0b0100110000011011, 3, 2);
	addinstruction("shrl", 0b1100110000011011, 3, 2);
	addinstruction("shrl", 0b1101000000011011, 3, 1);
	addinstruction("shrq", 0b1110000000011011, 2, 2);
	addinstruction("shrq", 0b1110010000011011, 2, 1);
	addinstruction("shrq", 0b1110100000011011, 2, 3);
	addinstruction("shrq", 0b1110110000011011, 3, 2);
	addinstruction("je", 0b0100000000011100, 4);
	addinstruction("je", 0b1110000000011100, 4);
	addinstruction("jne", 0b0100000000011101, 4);
	addinstruction("jne", 0b1110000000011101, 4);
	addinstruction("jg", 0b0100000000011110, 4);
	addinstruction("jg", 0b1110000000011110, 4);
	addinstruction("jl", 0b0100000000011111, 4);
	addinstruction("jl", 0b1110000000011111, 4);
	addinstruction("jge", 0b0100000000100000, 4);
	addinstruction("jge", 0b1110000000100000, 4);
	addinstruction("jle", 0b0100000000100001, 4);
	addinstruction("jle", 0b1110000000100001, 4);
	addinstruction("jz", 0b0100000000100010, 4);
	addinstruction("jz", 0b1110000000100010, 4);
	addinstruction("jnz", 0b0100000000100011, 4);
	addinstruction("jnz", 0b1110000000100011, 4);
	addinstruction("cmpb", 0b0000000000100100, 2, 2);
	addinstruction("cmpb", 0b0000010000100100, 2, 1);
	addinstruction("cmpb", 0b0000100000100100, 2, 3);
	addinstruction("cmpb", 0b1000100000100100, 2, 3);
	addinstruction("cmpb", 0b0000110000100100, 3, 2);
	addinstruction("cmpb", 0b1000110000100100, 3, 2);
	addinstruction("cmpb", 0b1001000000100100, 3, 1);
	addinstruction("cmp", 0b0010000000100100, 2, 2);
	addinstruction("cmp", 0b0010010000100100, 2, 1);
	addinstruction("cmp", 0b0010100000100100, 2, 3);
	addinstruction("cmp", 0b1010100000100100, 2, 3);
	addinstruction("cmp", 0b0010110000100100, 3, 2);
	addinstruction("cmp", 0b1010110000100100, 3, 2);
	addinstruction("cmp", 0b1011000000100100, 3, 1);
	addinstruction("cmpl", 0b0100000000100100, 2, 2);
	addinstruction("cmpl", 0b0100010000100100, 2, 1);
	addinstruction("cmpl", 0b0100100000100100, 2, 3);
	addinstruction("cmpl", 0b1100100000100100, 2, 3);
	addinstruction("cmpl", 0b0100110000100100, 3, 2);
	addinstruction("cmpl", 0b1100110000100100, 3, 2);
	addinstruction("cmpl", 0b1101000000100100, 3, 1);
	addinstruction("cmpq", 0b1110000000100100, 2, 2);
	addinstruction("cmpq", 0b1110010000100100, 2, 1);
	addinstruction("cmpq", 0b1110100000100100, 2, 3);
	addinstruction("cmpq", 0b1110110000100100, 3, 2);
	addinstruction("jmp", 0b0100000000100101, 4);
	addinstruction("jmp", 0b1110000000100101, 4);
	addinstruction("wait", 0b0000000000100110);
	addinstruction("cpuid", 0b0000000000101001);
	addinstruction("mcrb", 0b0001110000100111, 1, 2, 2);
	addinstruction("mcr", 0b0011110000100111, 1, 2, 2);
	addinstruction("mcrl", 0b0101110000100111, 1, 2, 2);
	addinstruction("mcrq", 0b1111110000100111, 1, 2, 2);
	addinstruction("mrcb", 0b0001110000101000, 1, 2, 2);
	addinstruction("mrc", 0b0011110000101000, 1, 2, 2);
	addinstruction("mrcl", 0b0101110000101000, 1, 2, 2);
	addinstruction("mrcq", 0b1111110000101000, 1, 2, 2);
	return true;
}

bool loadedinstructions = initinstructions();