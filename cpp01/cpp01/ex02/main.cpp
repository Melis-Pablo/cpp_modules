#include <iostream>

int main(void) {
	std::string str = "HI THIS IS BRAIN";
	std::string *str_PTR = &str;
	std::string &str_REF = str;

	std::cout << "The memory address of the string variable: " << &str << std::endl;
	std::cout << "The memory address held by stringPTR: " << str_PTR << std::endl;
	std::cout << "The memory address held by stringREF: " << &str_REF << std::endl;

	std::cout << "The value of the string variable: " << str << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *str_PTR << std::endl;
	std::cout << "The value pointed to by stringREF: " << str_REF << std::endl;

	return (0);
}