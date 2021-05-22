#include "tty.h"

namespace tty {

	uint8_t* vga_memory = (uint8_t*)2048;

	uint16_t tty_x = 0;
	uint16_t tty_y = 0;
	uint8_t  tty_c = vga_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);

	inline uint8_t vga_color(uint8_t fg, uint8_t bg) {
		return bg | fg << 4;
	}

	inline uint16_t vga_entry(char c, uint8_t color) {
		return color | c << 8;
	}

	inline void tty_setcolor(uint8_t color) {
		tty_c = color;
	}

	void putc(uint16_t entry, uint16_t x, uint16_t y) {
		((uint16_t*)vga_memory)[(y * VGA_WIDTH) + x] = entry;
	}

	void putchar(char c) {
		putc(vga_entry(c, tty_c), tty_x, tty_y);
		if (++tty_x == VGA_WIDTH) {
			tty_x = 0;
			if (++tty_y == VGA_HEIGHT) { // We reached the bottom - scroll down
				for(uint16_t i = 0; i < VGA_HEIGHT - 1; i++) {
					for(uint8_t j = 0; j < (VGA_WIDTH * 2); j++) {
						vga_memory[(i * VGA_WIDTH * 2) + j] = vga_memory[((i + 1) * VGA_WIDTH * 2) + j];
					}
				}
				for(uint8_t i = 0; i < (VGA_WIDTH * 2); i++) {
					vga_memory[((VGA_HEIGHT - 1) * VGA_WIDTH * 2) + i] = 0;
				}
			}
		}
	}

	inline void write(const char *str, size_t len) {
		for(size_t i = 0; i < len; i++) putchar(str[i]);
	}

	size_t strlen(const char* str) {
		size_t len = 0;
		while(str[len]) len++;
		return len;
	}

	void puts(const char *str) {
		write(str, strlen(str));
	}

}
