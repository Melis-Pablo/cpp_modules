#include "harl.hpp"

void Harl::_debug(void) {
	std::cout << "DEBUG: This is a debug message" << std::endl;
}

void Harl::_info(void) {
	std::cout << "INFO: This is an info message" << std::endl;
}

void Harl::_warning(void) {
	std::cout << "WARNING: This is a warning message" << std::endl;
}

void Harl::_error(void) {
	std::cout << "ERROR: This is an error message" << std::endl;
}

Harl::Harl() {
}

Harl::~Harl() {
}

void	Harl::complain(std::string level) {
	t_func functs[] = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string levels[] = {"debug", "info", "warning", "error"};
	int i = 0;
	while (i < 4 && levels[i].compare(level))
		i++;
	if (i < 4)
		(this->*functs[i])();
}