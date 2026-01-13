#include "AMateria.hpp"
#include "Floor.hpp"
#include "ICharacter.hpp"
#include <Character.hpp>
#include <cstddef>
#include <iostream>
#include <string>

Character::Character(Floor *floor) : _name("Steve"), _floor(floor) {
	for (std::size_t i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const std::string &name, Floor *floor)
	: _name(name), _floor(floor) {
	for (std::size_t i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character &other) {
	*this = other;
}

Character::~Character(void) {
	for (int i = 0; i < 4; i++) {
		delete _inventory[i];
	}
}

Character	&Character::operator=(const Character &other) {
	if (this == &other)
		return *this;

	_name = other.getName();
	for (std::size_t i = 0; i < 4; i++)
	{
		if (!other._inventory[i])
			continue;
		delete _inventory[i];
		_inventory[i] = other._inventory[i]->clone();
	}
	_floor = other._floor;
	return *this;
}

std::string const	&Character::getName(void) const {
	return _name;
}

AMateria const	*Character::getMateria(int idx) const {
	return _inventory[idx];
}

Floor	*Character::getFloor(void) const {
	return _floor;
}

void	Character::equip(AMateria *m) {
	if (!m) {
		std::cout << "it's not a materia" << std::endl;
		return;
	}
	size_t	i = 0;

	while (i < 4 && _inventory[i])
		i++;
	if (i >= 4) {
		std::cout << getName() << "'s inventory is full" << std::endl;
		return;
	}
	std::cout << getName() << " equiped " << m->getType() << " on his " << i+1 << "th slot";
	std::cout << std::endl;
	_inventory[i] = m;
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx > 3 || !_inventory[idx]) {
		std::cout << getName() << "'s can't unequip this Materia" << std::endl;
		return;
	}
	std::cout << getName() << " unequiped " << _inventory[idx]->getType() << " from his " << idx+1 << "th slot" << std::endl;
	getFloor()->drop(_inventory[idx]);
	_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx > 3 || !_inventory[idx]) {
		std::cout << getName() << " has no Materia at this slot" << std::endl;
		return;
	}
	_inventory[idx]->use(target);
}
