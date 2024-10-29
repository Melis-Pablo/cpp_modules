#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
	private:
		std::string _name;
		AMateria *_materia[4];

	public:
		Character(std::string name);
		Character(const Character &copy);
		Character &operator=(const Character &rhs);
		~Character();

		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};

#endif