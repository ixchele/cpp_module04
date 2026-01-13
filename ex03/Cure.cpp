#include "AMateria.hpp"
#include <ICharacter.hpp>
#include <Cure.hpp>
#include <iostream>

Cure::Cure(void) : AMateria("cure") {
	//pass
}

Cure::~Cure(void) {
	//pass
}

AMateria	*Cure::clone(void) const {
	return new Cure(*this);
}

void	Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}	
