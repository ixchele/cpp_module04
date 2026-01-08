#include "AMateria.hpp"
#include <Character.hpp>
#include <cstddef>
#include <string>

Character::Character(void) : _name("Steve") {
	for (std::size_t i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const std::string &name) : _name(name) {
	for (std::size_t i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character &other) {
	*this = other;
}

Character::~Character(void) {
	for (std::size_t i = 0; i < 4; i++)
		delete _inventory[i];
}

Character	&Character::operator=(const Character &other) {
	if (this == &other)
		return *this;

	_name = other.getName();
	for (std::size_t i = 0; i < 4; i++)
		_inventory[i] = other._inventory[i];

	return *this;
}
