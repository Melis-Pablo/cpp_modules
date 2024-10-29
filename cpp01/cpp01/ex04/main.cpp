#include "replace.hpp"

int main(int ac, char **av) {
	if (ac != 4) {
		std::cout << "Correct Usage: ./replace <Filename> <S1> <S2>" << std::endl;
		return 1;
	}
	else {
		Replace replace_ins(av[1]);
		replace_ins.replace(av[2], av[3]);
	}
	return 0;
}