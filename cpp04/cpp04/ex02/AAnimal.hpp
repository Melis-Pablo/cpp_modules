#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal {
	protected:
		std::string _type;

	public:
		AAnimal();
		AAnimal(std::string type);
		virtual ~AAnimal();
		/* virtual destructor: 
			- if a class has a virtual function
			- and a pointer of that class is deleted
			- the destructor of the derived class is called
			- if the destructor of the base class is not virtual
			- the destructor of the derived class is not called
		*/

		AAnimal(const AAnimal &rhs);
		AAnimal &operator=(const AAnimal &rhs);

		virtual void makeSound() const = 0;
		std::string getType() const;
		void setType(std::string type);
};

#endif