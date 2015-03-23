#include "Console.hh"

#include <iostream>
#include <cstdlib>

namespace ui {

Console::Console() {


	this->Log("console started");
}

Console::~Console() {
	this->Log("terminating console");


}

void Console::Log(std::string text) {
	std::cout << text << std::endl;
}

int Console::FatalError(std::string text) {
	std::cout << "FATAL: " << text << std::endl;
	return EXIT_FAILURE;
}

} /* namespace ui */
