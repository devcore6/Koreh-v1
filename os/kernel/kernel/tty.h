namespace tty {

	using uint8_t = unsigned char;
	using uint16_t = unsigned short;
	using size_t = unsigned long long;

	constexpr uint8_t VGA_WIDTH = 160;
	constexpr uint8_t VGA_HEIGHT = 50;

	enum {
		VGA_COLOR_BLACK = 0,
		VGA_COLOR_BLUE = 1,
		VGA_COLOR_GREEN = 2,
		VGA_COLOR_CYAN = 3,
		VGA_COLOR_RED = 4,
		VGA_COLOR_MAGENTA = 5,
		VGA_COLOR_BROWN = 6,
		VGA_COLOR_LIGHT_GREY = 7,
		VGA_COLOR_DARK_GREY = 8,
		VGA_COLOR_LIGHT_BLUE = 9,
		VGA_COLOR_LIGHT_GREEN = 10,
		VGA_COLOR_LIGHT_CYAN = 11,
		VGA_COLOR_LIGHT_RED = 12,
		VGA_COLOR_LIGHT_MAGENTA = 13,
		VGA_COLOR_LIGHT_BROWN = 14,
		VGA_COLOR_WHITE = 15,
	};

	extern inline uint8_t vga_color(uint8_t fg, uint8_t bg);
	extern inline uint16_t vga_entry(char c, uint8_t color) ;
	extern inline void setcolor(uint8_t color);
	extern void putc(uint16_t entry, uint16_t x, uint16_t y);
	extern void putchar(char c);
	extern void puts(const char *str);

}
