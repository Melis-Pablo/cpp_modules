#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice &rhs);
		Ice &operator=(const Ice &rhs);
		~Ice();

		virtual AMateria *clone() const;
		virtual void use(ICharacter &target);
};

#endif