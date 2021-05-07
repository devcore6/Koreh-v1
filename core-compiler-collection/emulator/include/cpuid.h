#pragma once

#define arch_bit ((bits == 32) << 0)
#define fpu_bit ((has_fpu) << 1)

constexpr unsigned long cpu_model = 0x01 << 24;
