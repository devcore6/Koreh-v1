#pragma once
#include <shared.h>

constexpr uint32_t version = (0 << 24) | (0 << 16) | (1 << 8) | 1; // release << 24 | major << 16 | minor << 8 | 1=alpha 2=beta

#include <instruction.h>

// main.cpp
extern std::vector<unsigned char> binarydata;
extern bool bootable;
extern uint8_t mode;
extern size_t errors;

// asm.cpp
extern void addlabel(std::string);
extern uint64_t getaddress(std::string);
extern void schedulereplace(size_t, std::string);
extern void doreplaces();