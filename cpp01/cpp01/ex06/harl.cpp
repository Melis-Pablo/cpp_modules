#include "harl.hpp"

void Harl::_debug(void) {
	std::cout << "[DEBUG]: This is a debug message" << std::endl;
}

void Harl::_info(void) {
	std::cout << "[INFO]: This is an info message" << std::endl;
}

void Harl::_warning(void) {
	std::cout << "[WARNING]: This is a warning message" << std::endl;
}

void Harl::_error(void) {
	std::cout << "[ERROR]: This is an error message" << std::endl;
}

Harl::Harl() {
}

Harl::~Harl() {
}

void	Harl::complain(std::string level) {
	std::string levels[] = {"debug", "info", "warning", "error"};
	int i = 0;
	while (i < 4 && levels[i].compare(level))
		i++;
	switch (i)
	{
	case 0:
		this->_debug();
		this->_info();
		this->_warning();
		this->_error();
		break;
	case 1:
		this->_info();
		this->_warning();
		this->_error();
		break;
	case 2:
		this->_warning();
		this->_error();
		break;
	case 3:
		this->_error();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}