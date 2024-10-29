#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FlagTrap.hpp"

class DiamondTrap : public ScavTrap, public FlagTrap {
	private:
		std::string _name;

	public:
		DiamondTrap(std::string name);
		~DiamondTrap(void);
		
		void	whoAmI(void);
};

#endif