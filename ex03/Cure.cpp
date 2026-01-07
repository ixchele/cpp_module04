#include "AMateria.hpp"
#include <Cure.hpp>

Cure::Cure(void) : AMateria("cure") {
	//pass
}

Cure::Cure(const Cure &other) : AMateria(other) {
}

Cure::~Cure(void) {
	//pass
}

Cure	*Cure::clone(void) const {
	return new Cure(*this);
}
