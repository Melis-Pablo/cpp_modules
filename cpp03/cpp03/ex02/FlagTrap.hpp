#ifndef FLAGTRAP_HPP
#define FLAGTRAP_HPP

#include "ClapTrap.hpp"

class FlagTrap : public ClapTrap {
	private:
		/* forbidden constructor */
		FlagTrap(void);
	public:
		FlagTrap(std::string name);
		~FlagTrap(void);

		void highFivesGuys(void);
};

#endif