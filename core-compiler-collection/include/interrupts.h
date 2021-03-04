#pragma once

enum {
	INT_DIVIDE_BY_ZERO              = 0x00,
	INT_SINGLE_STEP                 = 0x01,
	INT_BREAKPOINT                  = 0x02,
	INT_NMI                         = 0x03,
	INT_OVERFLOW                    = 0x04,
	INT_INVALID_OPCODE              = 0x05,
	INT_DOUBLE_FAULT                = 0x06,
	INT_STACK_FAULT                 = 0x07,
	INT_COPROCESSOR_BUSY            = 0x08,
	INT_BOUNDS                      = 0x09,
	INT_GENERAL_PROTECTION_FAULT    = 0x0A,
	INT_PAGE_FAULT                  = 0x0B,
	INT_WRONG_ARCH					= 0x0C,

	INT_KEYBOARD_DATA_READY         = 0x0D
};