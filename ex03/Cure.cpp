#include <ICharacter.hpp>
#include <Cure.hpp>
#include <iostream>

Cure::Cure(void) : AMateria("cure") {
	//pass
}

Cure::Cure(const Cure &other) : AMateria(other) {
	//pass
}

Cure::~Cure(void) {
	//pass
}

Cure	*Cure::clone(void) const {
	return new Cure(*this);
}

void	Cure::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}	
