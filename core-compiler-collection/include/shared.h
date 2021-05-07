#include <cstdint>				// uint8_t, uint16_t, uint32_t, uint64_t
#include <string>				// std::string
#include <vector>				// std::vector
#include <iostream>				// std::cout, std::cerr, std::endl
#include <concepts>				// std::same_as, std::copy_constructible
#include <fstream>				// std::ifstream, std::ofstream
#include <filesystem>			// std::filesystem::temp_directory_path, std::filesystem::remove
#include <thread>				// std::thread, std::this_thread
#include <future>				// std::future, std::promise, std::future_status
#include <chrono>				// std::chrono::high_resolution_clock, std::chrono::duration, std::chrono::duration_cast

#include <version.h>
#include <templates.h>
#include <register.h>
#include <instruction.h>
#include <interrupts.h>
#include <flags.h>
