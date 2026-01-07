#include "ICharacter.hpp"
#include <AMateria.hpp>
#include <iostream>

AMateria::AMateria(std::string const &type) : _type(type) {
	//pass
}

AMateria::AMateria(const AMateria &other) : _type(other.getType()) {
	//pass
}

AMateria::~AMateria(void) {
	//pass
}


std::string const &AMateria::getType(void) const {
	return _type;
}

void	AMateria::use(ICharacter &target) {
	//pass
	std::cout << "AMateria used on " << target.getName() << std::endl;
}
