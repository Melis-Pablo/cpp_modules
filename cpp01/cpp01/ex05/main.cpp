#include "harl.hpp"

int main(void) {
	Harl harl;
	std::string level;

	do {
	std::cout << "Enter the level of complaint: ";
	std::cin >> level;
	harl.complain(level);
	} while (level != "exit");

	return (0);
}