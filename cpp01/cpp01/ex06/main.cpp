#include "harl.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Correct Usage: ./harlFilter <level>" << std::endl;
		return 1;
	} else {
		Harl harl;
		std::string level = av[1];
		harl.complain(level);
	}
	return (0);
}