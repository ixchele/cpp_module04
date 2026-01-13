#include "AMateria.hpp"
#include <ICharacter.hpp>
#include <Ice.hpp>
#include <iostream>

Ice::Ice(void) : AMateria("ice") {
	//pass
}

Ice::~Ice(void) {
	//pass
}

AMateria	*Ice::clone(void) const {
	return new Ice(*this);
}

void	Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}	
