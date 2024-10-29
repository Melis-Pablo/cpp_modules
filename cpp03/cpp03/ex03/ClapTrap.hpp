#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
		/* forbidden constructor */
		ClapTrap(void);

	public:
		ClapTrap(std::string name);
		~ClapTrap();

		ClapTrap(const ClapTrap& rhs);
		ClapTrap& operator=(const ClapTrap& rhs);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif