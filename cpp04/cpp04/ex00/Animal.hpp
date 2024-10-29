#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
	protected:
		std::string _type;

	public:
		Animal();
		Animal(std::string type);
		virtual ~Animal();
		/* virtual destructor: 
			- if a class has a virtual function
			- and a pointer of that class is deleted
			- the destructor of the derived class is called
			- if the destructor of the base class is not virtual
			- the destructor of the derived class is not called
		*/

		Animal(const Animal &rhs);
		Animal &operator=(const Animal &rhs);

		virtual void makeSound() const;
		std::string getType() const;
		void setType(std::string type);
};

#endif