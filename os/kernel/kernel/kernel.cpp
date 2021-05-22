#include "tty.h"

extern "C" void kernel_main() {
	tty::puts("Hello, world!");
}
