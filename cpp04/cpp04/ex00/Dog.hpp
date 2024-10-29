#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
	private:

	public:
		Dog();
		~Dog();

		Dog(const Dog &rhs);
		Dog &operator=(const Dog &rhs);

		void makeSound() const;
};

#endif