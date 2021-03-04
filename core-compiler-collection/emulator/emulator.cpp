#include <emulator.h>

uint64_t reg_t::getvalue() {
	switch(size) {
		case 3: { return *value; }
		case 2: { return *value & 0x00000000FFFFFFFF; }
		case 1: { return *value & 0x000000000000FFFF; }
		case 0: { return *value & 0x00000000000000FF; }
	}
	return 0;
}

void reg_t::setvalue(uint64_t val) {
	switch(size) {
		case 3: { *value = val; return; }
		case 2: { *value &= 0xFFFFFFFF00000000; *value |= val; return; }
		case 1: { *value &= 0xFFFFFFFFFFFF0000; *value |= val; return; }
		case 0: { *value &= 0xFFFFFFFFFFFFFF00; *value |= val; return; }
	}
}

reg_t::reg_t(register_t reg) {
	address = reg.address;
	size = reg.size;
	owner = true;
	upper = false;
	value = new uint64_t;
}

reg_t::reg_t(register_t reg, reg_t* reg_) {
	address = reg.address;
	size = reg.size;
	owner = false;
	upper = reg.name[reg.name.size() - 1] == 'h';
	value = reg_->value;
}

reg_t::~reg_t() {
	if(owner) delete value;
}

reg_t* regs_t::operator[](register_t reg) {
	for(uint8_t i = 0; i < data.size(); i++) if(data[i]->address == reg.address) return data[i];
	return NULL;
}

regs_t::regs_t() {
	reg_t* reg;

	reg_t* regrax = new reg_t(rax); data.push_back(regrax);

	reg = new reg_t(al, regrax); data.push_back(reg);
	reg = new reg_t(ah, regrax); data.push_back(reg);
	reg = new reg_t(ax, regrax); data.push_back(reg);
	reg = new reg_t(eax, regrax); data.push_back(reg);

	reg_t* regrbx = new reg_t(rbx); data.push_back(regrbx);

	reg = new reg_t(bl, regrbx); data.push_back(reg);
	reg = new reg_t(bh, regrbx); data.push_back(reg);
	reg = new reg_t(bx, regrbx); data.push_back(reg);
	reg = new reg_t(ebx, regrbx); data.push_back(reg);

	reg_t* regrcx = new reg_t(rcx); data.push_back(regrcx);

	reg = new reg_t(cl, regrcx); data.push_back(reg);
	reg = new reg_t(ch, regrcx); data.push_back(reg);
	reg = new reg_t(cx, regrcx); data.push_back(reg);
	reg = new reg_t(ecx, regrcx); data.push_back(reg);

	reg_t* regrdx = new reg_t(rdx); data.push_back(regrdx);

	reg = new reg_t(dl, regrdx); data.push_back(reg);
	reg = new reg_t(dh, regrdx); data.push_back(reg);
	reg = new reg_t(dx, regrdx); data.push_back(reg);
	reg = new reg_t(edx, regrdx); data.push_back(reg);

	reg_t* regrex = new reg_t(rex); data.push_back(regrex);

	reg = new reg_t(el, regrex); data.push_back(reg);
	reg = new reg_t(eh, regrex); data.push_back(reg);
	reg = new reg_t(ex, regrex); data.push_back(reg);
	reg = new reg_t(eex, regrex); data.push_back(reg);

	reg_t* regrfx = new reg_t(rfx); data.push_back(regrfx);

	reg = new reg_t(fl, regrfx); data.push_back(reg);
	reg = new reg_t(fh, regrfx); data.push_back(reg);
	reg = new reg_t(fx, regrfx); data.push_back(reg);
	reg = new reg_t(efx, regrfx); data.push_back(reg);

	reg_t* regrgx = new reg_t(rgx); data.push_back(regrgx);

	reg = new reg_t(gl, regrgx); data.push_back(reg);
	reg = new reg_t(gh, regrgx); data.push_back(reg);
	reg = new reg_t(gx, regrgx); data.push_back(reg);
	reg = new reg_t(egx, regrgx); data.push_back(reg);

	reg_t* regrhx = new reg_t(rhx); data.push_back(regrhx);

	reg = new reg_t(hl, regrhx); data.push_back(reg);
	reg = new reg_t(hh, regrhx); data.push_back(reg);
	reg = new reg_t(hx, regrhx); data.push_back(reg);
	reg = new reg_t(ehx, regrhx); data.push_back(reg);

	reg_t* regrix = new reg_t(rix); data.push_back(regrix);

	reg = new reg_t(il, regrix); data.push_back(reg);
	reg = new reg_t(ih, regrix); data.push_back(reg);
	reg = new reg_t(ix, regrix); data.push_back(reg);
	reg = new reg_t(eix, regrix); data.push_back(reg);

	reg_t* regrjx = new reg_t(rjx); data.push_back(regrjx);

	reg = new reg_t(jl, regrjx); data.push_back(reg);
	reg = new reg_t(jh, regrjx); data.push_back(reg);
	reg = new reg_t(jx, regrjx); data.push_back(reg);
	reg = new reg_t(ejx, regrjx); data.push_back(reg);

	reg_t* regrkx = new reg_t(rkx); data.push_back(regrkx);

	reg = new reg_t(kl, regrkx); data.push_back(reg);
	reg = new reg_t(kh, regrkx); data.push_back(reg);
	reg = new reg_t(kx, regrkx); data.push_back(reg);
	reg = new reg_t(ekx, regrkx); data.push_back(reg);

	reg_t* regrsp = new reg_t(rsp); data.push_back(regrsp);

	reg = new reg_t(spl, regrsp); data.push_back(reg);
	reg = new reg_t(sph, regrsp); data.push_back(reg);
	reg = new reg_t(sp, regrsp); data.push_back(reg);
	reg = new reg_t(esp, regrsp); data.push_back(reg);

	reg_t* regrbp = new reg_t(rbp); data.push_back(regrbp);

	reg = new reg_t(bpl, regrbp); data.push_back(reg);
	reg = new reg_t(bph, regrbp); data.push_back(reg);
	reg = new reg_t(bp, regrbp); data.push_back(reg);
	reg = new reg_t(ebp, regrbp); data.push_back(reg);

	reg_t* regrsi = new reg_t(rsi); data.push_back(regrsi);

	reg = new reg_t(sil, regrsi); data.push_back(reg);
	reg = new reg_t(sih, regrsi); data.push_back(reg);
	reg = new reg_t(si, regrsi); data.push_back(reg);
	reg = new reg_t(esi, regrsi); data.push_back(reg);

	reg_t* regrdi = new reg_t(rdi); data.push_back(regrdi);

	reg = new reg_t(dil, regrdi); data.push_back(reg);
	reg = new reg_t(dih, regrdi); data.push_back(reg);
	reg = new reg_t(di, regrdi); data.push_back(reg);
	reg = new reg_t(edi, regrdi); data.push_back(reg);

	reg = new reg_t(cr0); data.push_back(reg);
	reg = new reg_t(cr1); data.push_back(reg);
	reg = new reg_t(cr2); data.push_back(reg);
	reg = new reg_t(cr3); data.push_back(reg);
	reg = new reg_t(cr4); data.push_back(reg);
	reg = new reg_t(cr5); data.push_back(reg);
	reg = new reg_t(cr6); data.push_back(reg);
	reg = new reg_t(cr7); data.push_back(reg);

	reg = new reg_t(rpc); data.push_back(reg);
	reg = new reg_t(epc, reg); data.push_back(reg);

	reg = new reg_t(rir); data.push_back(reg);
	reg = new reg_t(ir, reg); data.push_back(reg);

	reg = new reg_t(ridr); data.push_back(reg);
	reg = new reg_t(idr, reg); data.push_back(reg);
}

regs_t::~regs_t() {
	for(uint8_t i = 0; i < data.size(); i++) delete data[i];
}

std::vector<function_t> functions;

void addfunction(void (*function)(instruction_t instruction, uint64_t rrval, uint64_t ridrval, core_t* core), size_t id) {
	if(id > validinstructions.size()) return;
	function_t func = { validinstructions[id], function };
	functions.push_back(func);
}

uint8_t getregister(uint64_t rirval, bool first = true) {
	return (uint8_t)((first ? (rirval >> 40) : (rirval >> 32)) & 0x00000000000000FF);
}

uint8_t getsize(instruction_t instruction) {
	return (uint8_t)((instruction.opcode >> 13) & 3);
}

register_t findreg(uint8_t address) {
	for(size_t i = 0; i < registers.size(); i++) if(registers[i].address == address) return registers[i];
	return register_t();
}

uint64_t readmemory(uint64_t address, uint8_t size) {
	uint64_t out = 0;
	if(address + size > memorysize) { /* todo: fault */ }
	if(size > 8) return 0;
	for(uint8_t i = 0; i < size; i++) out |= memory[address + i] << (8 * i);
	return out;
}

void writememory(uint64_t data, uint64_t address, uint8_t size) {
	if(address + size > memorysize) { /* todo: fault */ }
	if(size > 8) return;
	for(uint8_t i = 0; i < size; i++) memory[address + i] = (uint8_t)((data >> (8 * i)) & 0xFF);
}


// BEGIN INSTRUCTION SET

void __mov(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	uint64_t value = 0;
	uint8_t size = getsize(instruction);
	switch(instruction.arg2) {
		case 0: break; // todo: fault
		case 1: {
			value = ridrval;
			switch(size) {
				case 0: { value &= 0x00000000000000FF; break; }
				case 1: { value &= 0x000000000000FFFF; break; }
				case 2: { value &= 0x00000000FFFFFFFF; break; }
				case 3: { if(bits == 32) { /* todo: fault */ } break; }
			}
			break;
		}
		case 2: {
			value = core->regs[findreg(getregister(rirval, false))]->getvalue();
			// todo: fault if size doesn't match
			switch(size) {
				case 0: { value &= 0x00000000000000FF; break; }
				case 1: { value &= 0x000000000000FFFF; break; }
				case 2: { value &= 0x00000000FFFFFFFF; break; }
				case 3: { if(bits == 32) { /* todo: fault */ } break; }
			}
			break;
		}
		case 3: {
			switch(size) {
				case 0: { value = readmemory(ridrval, 1); break; }
				case 1: { value = readmemory(ridrval, 2); break; }
				case 2: { value = readmemory(ridrval, 4); break; }
				case 3: { if(bits == 32) { /* todo: fault */ } else value = readmemory(ridrval, 8); break; }
			}
			break;
		}
	}
	switch(instruction.arg1) {
		case 0:
		case 1: break; // todo: fault
		case 2: {
			core->regs[findreg(getregister(rirval, true))]->setvalue(value);
			break;
		}
		case 3: {
			writememory(value, ridrval, size);
			break;
		}
	}
}

// END INSTRUCTION SET



bool initfunctions() {
	for(size_t i = 0; i < 26; i++) addfunction(&__mov, i); // 26 MOV variations from validinstructions[0...25]
	return true;
}

bool initedfunctions = initfunctions();