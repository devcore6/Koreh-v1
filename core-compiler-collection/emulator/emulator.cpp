#include <emulator.h>

uint8_t getmemorysize(uint8_t size) {
	if(size == 0) return 1;
	if(size == 1) return 2;
	if(size == 2) return 4;
	if(size == 3) return 8;
	return 1;
}

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

void interrupt(uint8_t intcode, uint64_t _rax, uint64_t _rbx, core_t *core) {
	if(intcode < INT_KEYBOARD_DATA_READY) core->interrupts++;
	if(core->interrupts == 3) {
		std::cerr << "Triple fault detected - shutting down\n";
		for(auto c : _cores) {
			c->promise.set_value();
		}
		exit(-5);
	}
	if(intcode != INT_DOUBLE_FAULT) {
		if(bits == 32) {
			writememory(core->regs[eax]->getvalue(), core->regs[esp]->getvalue() - 4, 4, core);
			core->regs[rsp]->setvalue(core->regs[esp]->getvalue() - 4);
			writememory(core->regs[ebx]->getvalue(), core->regs[esp]->getvalue() - 4, 4, core);
			core->regs[rsp]->setvalue(core->regs[esp]->getvalue() - 4);
		} else {
			writememory(core->regs[rax]->getvalue(), core->regs[rsp]->getvalue() - 8, 8, core);
			core->regs[rsp]->setvalue(core->regs[rsp]->getvalue() - 8);
			writememory(core->regs[rbx]->getvalue(), core->regs[rsp]->getvalue() - 8, 8, core);
			core->regs[rsp]->setvalue(core->regs[rsp]->getvalue() - 8);
		}
		if(core->regs[rsp]->getvalue() < core->regs[rbp]->getvalue()) { interrupt(INT_DOUBLE_FAULT, _rax, _rbx, core); return; }
	}
	core->regs[rax]->setvalue(_rax);
	core->regs[rbx]->setvalue(_rbx);
	throw intcode;
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

uint8_t getbytesize(uint8_t size) {
	if(size == 0) return 1;
	if(size == 1) return 2;
	if(size == 2) return 4;
	if(size == 3) return 8;
	return 0;
}

register_t findreg(uint8_t address) {
	for(size_t i = 0; i < registers.size(); i++) if(registers[i].address == address) return registers[i];
	return register_t();
}

uint64_t readmemory(uint64_t address, uint8_t size, core_t* core) {
	if(address + size > memorysize) { interrupt(INT_BOUNDS, address + size, 0, core); return 0; }
	if(size == 8 && bits == 32) { interrupt(INT_WRONG_ARCH, address, 0, core); return 0; }
	if(size == 1) { return memory[address]; }
	if(size == 2) { return *((uint16_t*)(memory + address)); }
	if(size == 4) { return *((uint32_t*)(memory + address)); }
	if(size == 82) { return *((uint64_t*)(memory + address)); }
	return 0;
}

uint64_t readmemorybe(uint64_t address, uint8_t size, core_t* core) {
	uint64_t out = 0;
	if(address + size > memorysize) { interrupt(INT_BOUNDS, address + size, 0, core); return 0; }
	if(size == 8 && bits == 32) { interrupt(INT_WRONG_ARCH, address, 0, core); return 0; }
	for(size_t i = 0; i < size; i++) {
		out <<= 8;
		out |= memory[address + i];
	}
	return out;
}

void writememory(uint64_t data, uint64_t address, uint8_t size, core_t* core) {
	if(address + size > memorysize) { interrupt(INT_BOUNDS, address + size, 0, core); return; }
	if(size == 8 && bits == 32) { interrupt(INT_WRONG_ARCH, address, 0, core); return; }
	if(size == 1) { memory[address] = (uint8_t)data; }
	if(size == 2) { *((uint16_t*)(memory + address)) = (uint16_t)data; }
	if(size == 4) { *((uint32_t*)(memory + address)) = (uint32_t)data; }
	if(size == 8) { *((uint64_t*)(memory + address)) = (uint64_t)data; }
}

uint64_t getvalue(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	uint64_t value = 0;
	uint8_t size = getsize(instruction);
	switch(instruction.arg2) {
		case 1: {
			if(instruction.arg1 == 3) {
				if(bits == 32) { interrupt(INT_INVALID_OPCODE, rirval, ridrval, core); break; }
				value = rirval;
				switch(size) {
					case 0: { value &= 0xFF; break; }
					case 1: { value &= 0xFFFF; break; }
					case 2: { value &= 0xFFFFFFFF; break; }
					case 3: { interrupt(INT_INVALID_OPCODE, rirval, ridrval, core); break; }
				}
			} else {
				value = ridrval;
				switch(size) {
					case 0: { value &= 0xFF; break; }
					case 1: { value &= 0xFFFF; break; }
					case 2: { value &= 0xFFFFFFFF; break; }
					case 3: { if(bits == 32) interrupt(INT_WRONG_ARCH, rirval, ridrval, core); break; }
				}
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
				case 3: { if(bits == 32) interrupt(INT_WRONG_ARCH, rirval, ridrval, core); break; }
			}
		}
		case 3: {
			switch(size) {
				case 0: { value = readmemory(ridrval, 1, core); break; }
				case 1: { value = readmemory(ridrval, 2, core); break; }
				case 2: { value = readmemory(ridrval, 4, core); break; }
				case 3: { if(bits == 32) interrupt(INT_WRONG_ARCH, rirval, ridrval, core);
						  else value = readmemory(ridrval, 8, core); break; }
			}
			break;
		}
	}
	return value;
}

// BEGIN INSTRUCTION SET

void __mov(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	uint64_t value = getvalue(instruction, rirval, ridrval, core);
	uint8_t size = getsize(instruction);
	switch(instruction.arg1) {
		case 0:
		case 1: { interrupt(INT_INVALID_OPCODE, rirval, ridrval, core); break; }
		case 2: {
			core->regs[findreg(getregister(rirval, true))]->setvalue(value);
			break;
		}
		case 3: {
			writememory(value, ridrval, getmemorysize(size), core);
			break;
		}
	}
}

void __load(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	switch(getsize(instruction)) {
		case 0: { core->regs[findreg(getregister(rirval, true))]->setvalue(readmemory(core->regs[findreg(getregister(rirval, false))]->getvalue(), 1, core)); break; }
		case 1: { core->regs[findreg(getregister(rirval, true))]->setvalue(readmemory(core->regs[findreg(getregister(rirval, false))]->getvalue(), 2, core)); break; }
		case 2: { core->regs[findreg(getregister(rirval, true))]->setvalue(readmemory(core->regs[findreg(getregister(rirval, false))]->getvalue(), 4, core)); break; }
		case 3:
		{
			if(bits == 32) { interrupt(INT_WRONG_ARCH, rirval, ridrval, core); return; }
							 else core->regs[findreg(getregister(rirval, true))]->setvalue(readmemory(core->regs[findreg(getregister(rirval, false))]->getvalue(), 8, core)); break; }
	}
}

void __save(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	writememory(core->regs[findreg(getregister(rirval, false))]->getvalue(),
				core->regs[findreg(getregister(rirval, true))]->getvalue(),
				getsize(instruction), core);
}

void __inc(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	uint8_t size = getsize(instruction);
	switch(instruction.arg1) {
		case 0:
		case 1: { interrupt(INT_INVALID_OPCODE, rirval, ridrval, core); break; }
		case 2: {
			core->regs[findreg(getregister(rirval, true))]->setvalue(core->regs[findreg(getregister(rirval, true))]->getvalue() + 1);
			break;
		}
		case 3: {
			writememory(readmemory(ridrval, getbytesize(size), core) + 1, ridrval, getmemorysize(size), core);
			break;
		}
	}
}

void __dec(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	uint8_t size = getsize(instruction);
	switch(instruction.arg1) {
		case 0:
		case 1: { interrupt(INT_INVALID_OPCODE, rirval, ridrval, core); break; }
		case 2: {
			core->regs[findreg(getregister(rirval, true))]->setvalue(core->regs[findreg(getregister(rirval, true))]->getvalue() - 1);
			break;
		}
		case 3: {
			writememory(readmemory(ridrval, getbytesize(size), core) - 1, ridrval, getmemorysize(size), core);
			break;
		}
	}
}

void __add(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	uint64_t value = getvalue(instruction, rirval, ridrval, core);
	uint8_t size = getsize(instruction);
	switch(instruction.arg1) {
		case 0:
		case 1: { interrupt(INT_INVALID_OPCODE, rirval, ridrval, core); break; }
		case 2: {
			core->regs[findreg(getregister(rirval, true))]->setvalue(core->regs[findreg(getregister(rirval, true))]->getvalue() + value);
			break;
		}
		case 3: {
			writememory(readmemory(ridrval, getbytesize(size), core) + value, ridrval, getmemorysize(size), core);
			break;
		}
	}
}

void __sub(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	uint64_t value = getvalue(instruction, rirval, ridrval, core);
	uint8_t size = getsize(instruction);
	switch(instruction.arg1) {
		case 0:
		case 1: { interrupt(INT_INVALID_OPCODE, rirval, ridrval, core); break; }
		case 2: {
			core->regs[findreg(getregister(rirval, true))]->setvalue(core->regs[findreg(getregister(rirval, true))]->getvalue() - value);
			break;
		}
		case 3: {
			writememory(readmemory(ridrval, getbytesize(size), core) - value, ridrval, getmemorysize(size), core);
			break;
		}
	}
}

void __mul(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	uint8_t size = getsize(instruction);
	uint64_t value1 = core->regs[rax]->getvalue();
	uint64_t value2 = core->regs[rbx]->getvalue();
	switch(size) {
		case 0: { value1 &= 0x00000000000000FF; value2 &= 0x00000000000000FF; break; }
		case 1: { value1 &= 0x000000000000FFFF; value2 &= 0x000000000000FFFF; break; }
		case 2: { value1 &= 0x00000000FFFFFFFF; value2 &= 0x00000000FFFFFFFF; break; }
		case 3: { if(bits == 32) { interrupt(INT_WRONG_ARCH, rirval, ridrval, core); return; } break; }
	}
	if(size < 3) {
		uint64_t result = value1 * value2;
		switch(size) {
			case 0: {
				core->regs[cl]->setvalue((result & 0x000000000000FF00) >> 8);
				core->regs[dl]->setvalue(result & 0x00000000000000FF);
				break;
			}
			case 1: {
				core->regs[cx]->setvalue((result & 0x00000000FFFF0000) >> 16);
				core->regs[dx]->setvalue(result & 0x000000000000FFFF);
				break;
			}
			case 2: {
				core->regs[ecx]->setvalue((result & 0xFFFFFFFF00000000) >> 32);
				core->regs[edx]->setvalue(result & 0x00000000FFFFFFFF);
				break;
			}
		}
	} else {
		// I'll make my life easy as far as 128-bit multiplication is concerned:
		uint64_t high = 0, low = 0;
#ifdef _MSC_VER
		low = _umul128(value1, value2, &high);
#elif defined(__GNUC__) || defined(__clang_major__)
		unsigned __int128 res = (unsigned __int128)value1 * value2;
		high = (uint64_t)((res & ((unsigned __int128)(0xFFFFFFFFFFFFFFFF) << 64)) >> 64);
		low = (uint64_t)(res & 0xFFFFFFFFFFFFFFFF);
#else
# error "Please use Visual Studio, GCC or Clang to compile the emulator (non-standard uint128_t required)."
#endif
		core->regs[rcx]->setvalue(high);
		core->regs[rdx]->setvalue(low);
	}
}

void __imul(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	uint8_t size = getsize(instruction);
	int64_t value1 = (int64_t)core->regs[rax]->getvalue();
	int64_t value2 = (int64_t)core->regs[rbx]->getvalue();
	switch(size) {
		case 0: { value1 &= 0x00000000000000FF; value2 &= 0x00000000000000FF; break; }
		case 1: { value1 &= 0x000000000000FFFF; value2 &= 0x000000000000FFFF; break; }
		case 2: { value1 &= 0x00000000FFFFFFFF; value2 &= 0x00000000FFFFFFFF; break; }
		case 3: { if(bits == 32) { interrupt(INT_WRONG_ARCH, rirval, ridrval, core); return; } break; }
	}
	if(size < 3) {
		switch(size) {
			case 0: {
				int16_t result = (int16_t)value1 * (int16_t)value2;
				core->regs[cl]->setvalue((uint64_t)((result & 0x000000000000FF00) >> 8));
				core->regs[dl]->setvalue((uint64_t)(result & 0x00000000000000FF));
				break;
			}
			case 1: {
				int32_t result = (int32_t)value1 * (int32_t)value2;
				core->regs[cx]->setvalue((uint64_t)((result & 0x00000000FFFF0000) >> 16));
				core->regs[dx]->setvalue((uint64_t)(result & 0x000000000000FFFF));
				break;
			}
			case 2: {
				int64_t result = value1 * value2;
				core->regs[ecx]->setvalue((uint64_t)((result & 0xFFFFFFFF00000000) >> 32));
				core->regs[edx]->setvalue((uint64_t)(result & 0x00000000FFFFFFFF));
				break;
			}
		}
	} else {
		// I'll make my life easy as far as 128-bit multiplication is concerned:
		int64_t high = 0, low = 0;
#ifdef _MSC_VER
		low = _mul128(value1, value2, &high); // visual studio doesnt have a 128-bit integer type :(
#elif defined(__GNUC__) || defined(__clang_major__)
		__int128 res = (__int128)value1 * value2;
		high = (uint64_t)((res & ((__int128)(0xFFFFFFFFFFFFFFFF) << 64)) >> 64);
		low = (uint64_t)(res & 0xFFFFFFFFFFFFFFFF);
#else
# error "Please use Visual Studio, GCC or Clang to compile the emulator (non-standard uint128_t required)."
#endif
		core->regs[rcx]->setvalue((uint64_t)high);
		core->regs[rdx]->setvalue((uint64_t)low);
	}
}

void __div(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	uint8_t size = getsize(instruction);
	uint64_t value1 = core->regs[rax]->getvalue();
	uint64_t value2 = core->regs[rbx]->getvalue();
	switch(size) {
		case 0: { value1 &= 0x00000000000000FF; value2 &= 0x00000000000000FF; break; }
		case 1: { value1 &= 0x000000000000FFFF; value2 &= 0x000000000000FFFF; break; }
		case 2: { value1 &= 0x00000000FFFFFFFF; value2 &= 0x00000000FFFFFFFF; break; }
		case 3: { if(bits == 32) { interrupt(INT_WRONG_ARCH, rirval, ridrval, core); return; } break; }
	}
	uint64_t result = value1 / value2;
	uint64_t rest = value1 % value2;
	switch(size) {
		case 0: {
			core->regs[cl]->setvalue(result & 0x00000000000000FF);
			core->regs[dl]->setvalue(rest & 0x00000000000000FF);
			break;
		}
		case 1: {
			core->regs[cl]->setvalue(result & 0x000000000000FFFF);
			core->regs[dl]->setvalue(rest & 0x000000000000FFFF);
			break;
		}
		case 2: {
			core->regs[cl]->setvalue(result & 0x00000000FFFFFFFF);
			core->regs[dl]->setvalue(rest & 0x00000000FFFFFFFF);
			break;
		}
		case 3: {
			core->regs[cl]->setvalue(result);
			core->regs[dl]->setvalue(rest);
			break;
		}
	}
}

void __idiv(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	uint8_t size = getsize(instruction);
	int64_t value1 = (int64_t)core->regs[rax]->getvalue();
	int64_t value2 = (int64_t)core->regs[rbx]->getvalue();
	switch(size) {
		case 0: { value1 &= 0x00000000000000FF; value2 &= 0x00000000000000FF; break; }
		case 1: { value1 &= 0x000000000000FFFF; value2 &= 0x000000000000FFFF; break; }
		case 2: { value1 &= 0x00000000FFFFFFFF; value2 &= 0x00000000FFFFFFFF; break; }
		case 3: { if(bits == 32) { interrupt(INT_WRONG_ARCH, rirval, ridrval, core); return; } break; }
	}
	switch(size) {
		case 0: {
			int8_t result = (int8_t)value1 / (int8_t)value2;
			int8_t rest = (int8_t)value1 % (int8_t)value2;
			core->regs[cl]->setvalue((uint64_t)result);
			core->regs[dl]->setvalue((uint64_t)rest);
			break;
		}
		case 1: {
			int16_t result = (int16_t)value1 / (int16_t)value2;
			int16_t rest = (int16_t)value1 % (int16_t)value2;
			core->regs[cl]->setvalue((uint64_t)result);
			core->regs[dl]->setvalue((uint64_t)rest);
			break;
		}
		case 2: {
			int32_t result = (int32_t)value1 / (int32_t)value2;
			int32_t rest = (int32_t)value1 % (int32_t)value2;
			core->regs[cl]->setvalue((uint64_t)result);
			core->regs[dl]->setvalue((uint64_t)rest);
			break;
		}
		case 3: {
			int64_t result = value1 / value2;
			int64_t rest = value1 % value2;
			core->regs[cl]->setvalue((uint64_t)result);
			core->regs[dl]->setvalue((uint64_t)rest);
			break;
		}
	}
}

void __push(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	uint64_t value = getvalue(instruction, rirval, ridrval, core);
	uint8_t size = getsize(instruction);
	switch(size) {
		case 0: {
			writememory(value, core->regs[rsp]->getvalue() - 1, 1, core);
			core->regs[rsp]->setvalue(core->regs[rsp]->getvalue() - 1);
			break;
		}
		case 1: {
			writememory(value, core->regs[rsp]->getvalue() - 2, 2, core);
			core->regs[rsp]->setvalue(core->regs[rsp]->getvalue() - 2);
			break;
		}
		case 2: {
			writememory(value, core->regs[rsp]->getvalue() - 4, 4, core);
			core->regs[rsp]->setvalue(core->regs[rsp]->getvalue() - 4);
			break;
		}
		case 3: {
			writememory(value, core->regs[rsp]->getvalue() - 8, 8, core);
			core->regs[rsp]->setvalue(core->regs[rsp]->getvalue() - 8);
			break;
		}
	}
	if(core->regs[rsp]->getvalue() < core->regs[rbp]->getvalue()) interrupt(INT_STACK_FAULT, rirval, ridrval, core);
}

void __pop(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	switch(getsize(instruction)) {
		case 0: {
			core->regs[findreg(getregister(rirval, true))]->setvalue(readmemory(core->regs[rsp]->getvalue(), 1, core));
			core->regs[rsp]->setvalue(core->regs[rsp]->getvalue() + 1);
			break;
		}
		case 1: {
			core->regs[findreg(getregister(rirval, true))]->setvalue(readmemory(core->regs[rsp]->getvalue(), 2, core));
			core->regs[rsp]->setvalue(core->regs[rsp]->getvalue() + 2);
			break;
		}
		case 2: {
			core->regs[findreg(getregister(rirval, true))]->setvalue(readmemory(core->regs[rsp]->getvalue(), 4, core));
			core->regs[rsp]->setvalue(core->regs[rsp]->getvalue() + 4);
			break;
		}
		case 3: {
			if(bits == 32) { interrupt(INT_WRONG_ARCH, rirval, ridrval, core); return; }
			core->regs[findreg(getregister(rirval, true))]->setvalue(readmemory(core->regs[rsp]->getvalue(), 8, core));
			core->regs[rsp]->setvalue(core->regs[rsp]->getvalue() + 8);
			break;
		}
	}
}

void __call(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	if(getsize(instruction) == 2) {
		if(bits == 64) { interrupt(INT_WRONG_ARCH, rirval, ridrval, core); return; }
		writememory(core->regs[rpc]->getvalue(), core->regs[esp]->getvalue() - 4, 4, core);
		core->regs[rsp]->setvalue(core->regs[rsp]->getvalue() - 4);
		core->regs[rpc]->setvalue(ridrval & 0x00000000FFFFFFFF);
	} else if(getsize(instruction) == 3) {
		if(bits == 32) { interrupt(INT_WRONG_ARCH, rirval, ridrval, core); return; }
		writememory(core->regs[rpc]->getvalue(), core->regs[rsp]->getvalue() - 8, 8, core);
		core->regs[rsp]->setvalue(core->regs[rsp]->getvalue() - 8);
		core->regs[rpc]->setvalue(ridrval);
	}
}

void __return(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	if(getsize(instruction) == 2) {
		if(bits == 64) { interrupt(INT_WRONG_ARCH, rirval, ridrval, core); return; }
		core->regs[rpc]->setvalue(readmemory(core->regs[rsp]->getvalue(), 4, core));
		core->regs[rsp]->setvalue(core->regs[rsp]->getvalue() + 4);
	} else if(getsize(instruction) == 3) {
		if(bits == 32) { interrupt(INT_WRONG_ARCH, rirval, ridrval, core); return; }
		core->regs[rpc]->setvalue(readmemory(core->regs[rsp]->getvalue(), 8, core));
		core->regs[rsp]->setvalue(core->regs[rsp]->getvalue() + 8);
	}
}

void __int(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	uint8_t size = getsize(instruction);
	switch(size) {
		case 0: {
			if(instruction.arg1 == 1) throw (uint8_t)(ridrval & 0x00000000000000FF);
			if(instruction.arg1 == 2) throw (uint8_t)(core->regs[findreg(getregister(rirval, true))]->getvalue());
			break;
		}
		case 3: {
			if(bits == 32) { interrupt(INT_WRONG_ARCH, rirval, ridrval, core); return; }
			[[fallthrough]];
		}
		case 2: {
			throw memory[ridrval];
			break;
		}
	}
}

void __cli(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	core->regs[cr0]->setvalue(core->regs[cr0]->getvalue() & ~interrupt_flag);
}

void __sti(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	core->regs[cr0]->setvalue(core->regs[cr0]->getvalue() | interrupt_flag);
}

void __or(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	uint64_t value = getvalue(instruction, rirval, ridrval, core);
	uint8_t size = getsize(instruction);
	switch(instruction.arg1) {
		case 0:
		case 1: { interrupt(INT_INVALID_OPCODE, rirval, ridrval, core); break; }
		case 2: {
			core->regs[findreg(getregister(rirval, true))]->setvalue(core->regs[findreg(getregister(rirval, true))]->getvalue() | value);
			break;
		}
		case 3: {
			writememory(readmemory(ridrval, getbytesize(size), core) | value, ridrval, getmemorysize(size), core);
			break;
		}
	}
}

void __xor(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	uint64_t value = getvalue(instruction, rirval, ridrval, core);
	uint8_t size = getsize(instruction);
	switch(instruction.arg1) {
		case 0:
		case 1: { interrupt(INT_INVALID_OPCODE, rirval, ridrval, core); break; }
		case 2: {
			core->regs[findreg(getregister(rirval, true))]->setvalue(core->regs[findreg(getregister(rirval, true))]->getvalue() ^ value);
			break;
		}
		case 3: {
			writememory(readmemory(ridrval, getbytesize(size), core) ^ value, ridrval, getmemorysize(size), core);
			break;
		}
	}
}

void __and(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	uint64_t value = getvalue(instruction, rirval, ridrval, core);
	uint8_t size = getsize(instruction);
	switch(instruction.arg1) {
		case 0:
		case 1: { interrupt(INT_INVALID_OPCODE, rirval, ridrval, core); break; }
		case 2: {
			core->regs[findreg(getregister(rirval, true))]->setvalue(core->regs[findreg(getregister(rirval, true))]->getvalue() & value);
			break;
		}
		case 3: {
			writememory(readmemory(ridrval, getbytesize(size), core) & value, ridrval, getmemorysize(size), core);
			break;
		}
	}
}

void __nand(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	uint64_t value = getvalue(instruction, rirval, ridrval, core);
	uint8_t size = getsize(instruction);
	switch(instruction.arg1) {
		case 0:
		case 1: { interrupt(INT_INVALID_OPCODE, rirval, ridrval, core); break; }
		case 2: {
			core->regs[findreg(getregister(rirval, true))]->setvalue(~(core->regs[findreg(getregister(rirval, true))]->getvalue() & value));
			break;
		}
		case 3: {
			writememory(~(readmemory(ridrval, getbytesize(size), core) & value), ridrval, getmemorysize(size), core);
			break;
		}
	}
}

void __nor(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	uint64_t value = getvalue(instruction, rirval, ridrval, core);
	uint8_t size = getsize(instruction);
	switch(instruction.arg1) {
		case 0:
		case 1: { interrupt(INT_INVALID_OPCODE, rirval, ridrval, core); break; }
		case 2: {
			core->regs[findreg(getregister(rirval, true))]->setvalue(~(core->regs[findreg(getregister(rirval, true))]->getvalue() | value));
			break;
		}
		case 3: {
			writememory(~(readmemory(ridrval, getbytesize(size), core) | value), ridrval, getmemorysize(size), core);
			break;
		}
	}
}

void __xnor(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	uint64_t value = getvalue(instruction, rirval, ridrval, core);
	uint8_t size = getsize(instruction);
	switch(instruction.arg1) {
		case 0:
		case 1: { interrupt(INT_INVALID_OPCODE, rirval, ridrval, core); break; }
		case 2: {
			core->regs[findreg(getregister(rirval, true))]->setvalue(~(core->regs[findreg(getregister(rirval, true))]->getvalue() ^ value));
			break;
		}
		case 3: {
			writememory(~(readmemory(ridrval, getbytesize(size), core) ^ value), ridrval, getmemorysize(size), core);
			break;
		}
	}
}

void __not(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	uint8_t size = getsize(instruction);
	switch(instruction.arg1) {
		case 0:
		case 1: { interrupt(INT_INVALID_OPCODE, rirval, ridrval, core); break; }
		case 2: {
			core->regs[findreg(getregister(rirval, true))]->setvalue(~core->regs[findreg(getregister(rirval, true))]->getvalue());
			break;
		}
		case 3: {
			writememory(~readmemory(ridrval, getbytesize(size), core), ridrval, getmemorysize(size), core);
			break;
		}
	}
}

void __shl(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	uint64_t value = getvalue(instruction, rirval, ridrval, core);
	uint8_t size = getsize(instruction);
	switch(instruction.arg1) {
		case 0:
		case 1: { interrupt(INT_INVALID_OPCODE, rirval, ridrval, core); break; }
		case 2: {
			core->regs[findreg(getregister(rirval, true))]->setvalue(core->regs[findreg(getregister(rirval, true))]->getvalue() << value);
			break;
		}
		case 3: {
			writememory(readmemory(ridrval, getbytesize(size), core) << value, ridrval, getmemorysize(size), core);
			break;
		}
	}
}

void __shr(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	uint64_t value = getvalue(instruction, rirval, ridrval, core);
	uint8_t size = getsize(instruction);
	switch(instruction.arg1) {
		case 0:
		case 1: { interrupt(INT_INVALID_OPCODE, rirval, ridrval, core); break; }
		case 2: {
			core->regs[findreg(getregister(rirval, true))]->setvalue(core->regs[findreg(getregister(rirval, true))]->getvalue() >> value);
			break;
		}
		case 3: {
			writememory(readmemory(ridrval, getbytesize(size), core) >> value, ridrval, getmemorysize(size), core);
			break;
		}
	}
}

void __je(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	if(core->regs[cr0]->getvalue() & equal_flag) core->regs[rpc]->setvalue(ridrval);
}

void __jne(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	if(!(core->regs[cr0]->getvalue() & equal_flag)) core->regs[rpc]->setvalue(ridrval);
}

void __jg(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	if(core->regs[cr0]->getvalue() & greater_flag) core->regs[rpc]->setvalue(ridrval);
}

void __jl(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	if(!(core->regs[cr0]->getvalue() & greater_flag) && !(core->regs[cr0]->getvalue() & equal_flag)) core->regs[rpc]->setvalue(ridrval);
}

void __jge(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	if((core->regs[cr0]->getvalue() & greater_flag) || (core->regs[cr0]->getvalue() & equal_flag)) core->regs[rpc]->setvalue(ridrval);
}

void __jle(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	if(!(core->regs[cr0]->getvalue() & greater_flag)) core->regs[rpc]->setvalue(ridrval);
}

void __jz(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	if(!(core->regs[cr0]->getvalue() & not_zero_flag)) core->regs[rpc]->setvalue(ridrval);
}

void __jnz(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	if(core->regs[cr0]->getvalue() & not_zero_flag) core->regs[rpc]->setvalue(ridrval);
}

void __cmp(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	uint64_t value = getvalue(instruction, rirval, ridrval, core);
	uint8_t size = getsize(instruction);
	switch(instruction.arg1) {
		case 0:
		case 1: { interrupt(INT_INVALID_OPCODE, rirval, ridrval, core); break; }
		case 2: {
			if(core->regs[findreg(getregister(rirval, true))]->getvalue() == value)
				core->regs[cr0]->setvalue(core->regs[cr0]->getvalue() | equal_flag);
			else core->regs[cr0]->setvalue(core->regs[cr0]->getvalue() & ~equal_flag);
			if(core->regs[findreg(getregister(rirval, true))]->getvalue() > value)
				core->regs[cr0]->setvalue(core->regs[cr0]->getvalue() | greater_flag);
			else core->regs[cr0]->setvalue(core->regs[cr0]->getvalue() & ~greater_flag);
			if(core->regs[findreg(getregister(rirval, true))]->getvalue() == 0)
				core->regs[cr0]->setvalue(core->regs[cr0]->getvalue() & ~not_zero_flag);
			else core->regs[cr0]->setvalue(core->regs[cr0]->getvalue() | not_zero_flag);
			break;
		}
		case 3: {
			if(readmemory(ridrval, getbytesize(size), core) == value)
				core->regs[cr0]->setvalue(core->regs[cr0]->getvalue() | equal_flag);
			else core->regs[cr0]->setvalue(core->regs[cr0]->getvalue() & ~equal_flag);
			if(readmemory(ridrval, getbytesize(size), core) > value)
				core->regs[cr0]->setvalue(core->regs[cr0]->getvalue() | equal_flag);
			else core->regs[cr0]->setvalue(core->regs[cr0]->getvalue() & ~equal_flag);
			if(readmemory(ridrval, getbytesize(size), core) == 0)
				core->regs[cr0]->setvalue(core->regs[cr0]->getvalue() & ~not_zero_flag);
			else core->regs[cr0]->setvalue(core->regs[cr0]->getvalue() | not_zero_flag);
			break;
		}
	}
}

void __jmp(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	core->regs[rpc]->setvalue(ridrval);
}

void __wait(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) { }

void __cpuid(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	switch(core->regs[eax]->getvalue()) {
		case 0: {
			// EAX=0: Highest Function Parameter and Manufacturer ID
			core->regs[eax]->setvalue(0x00000001);
			core->regs[ebx]->setvalue(0x6B6F7265); // kore
			core->regs[ecx]->setvalue(0x68316B6F); // h1ko
			core->regs[edx]->setvalue(0x72656831); // reh1
			break;
		}
		case 1: {
			// EAX=1: Processor Info and Feature Bits
			core->regs[eax]->setvalue(arch_bit |
									  fpu_bit |
									  cpu_model);
		}
	}
}

void __mcr(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	if(ridrval > cores) { interrupt(INT_NMI, NMI_NO_SUCH_COPROCESSOR, ridrval, core); return; }
	_cores[ridrval]->regs[findreg(getregister(rirval, true))]->setvalue(core->regs[findreg(getregister(rirval, false))]->getvalue());
}

void __mrc(instruction_t instruction, uint64_t rirval, uint64_t ridrval, core_t* core) {
	if(ridrval > cores) { interrupt(INT_NMI, NMI_NO_SUCH_COPROCESSOR, ridrval, core); return; }
	core->regs[findreg(getregister(rirval, false))]->setvalue(_cores[ridrval]->regs[findreg(getregister(rirval, true))]->getvalue());
}

// END INSTRUCTION SET



bool initfunctions() {
	size_t count = 0;
	for(size_t i = 0; i < 25; i++) { addfunction(&__mov, count); count++; }
	for(size_t i = 0; i < 7; i++) { addfunction(&__load, count); count++; }
	for(size_t i = 0; i < 7; i++) { addfunction(&__save, count); count++; }
	for(size_t i = 0; i < 11; i++) { addfunction(&__inc, count); count++; }
	for(size_t i = 0; i < 11; i++) { addfunction(&__dec, count); count++; }
	for(size_t i = 0; i < 25; i++) { addfunction(&__add, count); count++; }
	for(size_t i = 0; i < 25; i++) { addfunction(&__sub, count); count++; }
	for(size_t i = 0; i < 4; i++) { addfunction(&__mul, count); count++; }
	for(size_t i = 0; i < 4; i++) { addfunction(&__imul, count); count++; }
	for(size_t i = 0; i < 4; i++) { addfunction(&__div, count); count++; }
	for(size_t i = 0; i < 4; i++) { addfunction(&__idiv, count); count++; }
	for(size_t i = 0; i < 15; i++) { addfunction(&__push, count); count++; }
	for(size_t i = 0; i < 4; i++) { addfunction(&__pop, count); count++; }
	for(size_t i = 0; i < 2; i++) { addfunction(&__call, count); count++; }
	for(size_t i = 0; i < 2; i++) { addfunction(&__return, count); count++; }
	for(size_t i = 0; i < 4; i++) { addfunction(&__int, count); count++; }
	addfunction(&__cli, count); count++;
	addfunction(&__sti, count); count++;
	for(size_t i = 0; i < 25; i++) { addfunction(&__or, count); count++; }
	for(size_t i = 0; i < 25; i++) { addfunction(&__xor, count); count++; }
	for(size_t i = 0; i < 25; i++) { addfunction(&__and, count); count++; }
	for(size_t i = 0; i < 25; i++) { addfunction(&__nand, count); count++; }
	for(size_t i = 0; i < 25; i++) { addfunction(&__nor, count); count++; }
	for(size_t i = 0; i < 25; i++) { addfunction(&__xnor, count); count++; }
	for(size_t i = 0; i < 11; i++) { addfunction(&__not, count); count++; }
	for(size_t i = 0; i < 25; i++) { addfunction(&__shl, count); count++; }
	for(size_t i = 0; i < 25; i++) { addfunction(&__shr, count); count++; }
	for(size_t i = 0; i < 2; i++) { addfunction(&__je, count); count++; }
	for(size_t i = 0; i < 2; i++) { addfunction(&__jne, count); count++; }
	for(size_t i = 0; i < 2; i++) { addfunction(&__jg, count); count++; }
	for(size_t i = 0; i < 2; i++) { addfunction(&__jl, count); count++; }
	for(size_t i = 0; i < 2; i++) { addfunction(&__jge, count); count++; }
	for(size_t i = 0; i < 2; i++) { addfunction(&__jle, count); count++; }
	for(size_t i = 0; i < 2; i++) { addfunction(&__jz, count); count++; }
	for(size_t i = 0; i < 2; i++) { addfunction(&__jnz, count); count++; }
	for(size_t i = 0; i < 25; i++) { addfunction(&__cmp, count); count++; }
	for(size_t i = 0; i < 2; i++) { addfunction(&__jmp, count); count++; }
	addfunction(&__wait, count); count++;
	addfunction(&__cpuid, count); count++;
	for(size_t i = 0; i < 4; i++) { addfunction(&__mcr, count); count++; }
	for(size_t i = 0; i < 4; i++) { addfunction(&__mrc, count); count++; }
	return true;
}

bool initedfunctions = initfunctions();
