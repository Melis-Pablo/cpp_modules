#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria* _source[4];
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource &src);
		MateriaSource &operator=(const MateriaSource &src);

		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
		AMateria* getMateria(std::string const & type) const;
};

#endif