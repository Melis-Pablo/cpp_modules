#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		_source[i] = NULL;
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (_source[i] != NULL) {
			delete _source[i];
		}
	}
}

MateriaSource::MateriaSource(const MateriaSource &src) {
	for (int i = 0; i < 4; i++) {
		_source[i] = src._source[i];
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src) {
	for (int i = 0; i < 4; i++) {
		_source[i] = src._source[i];
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (_source[i] == NULL) {
			_source[i] = m;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (_source[i] != NULL && _source[i]->getType() == type) {
			return _source[i]->clone();
		}
	}
	return NULL;
}

AMateria* MateriaSource::getMateria(std::string const & type) const {
	for (int i = 0; i < 4; i++) {
		if (_source[i] != NULL && _source[i]->getType() == type) {
			return _source[i];
		}
	}
	return NULL;
}