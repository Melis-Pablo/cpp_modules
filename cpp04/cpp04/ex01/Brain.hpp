#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
	protected:
		std::string _ideas[100];
	public:
		Brain();
		~Brain();
		Brain(const Brain &brain);
		Brain &operator=(const Brain &brain);
};


#endif