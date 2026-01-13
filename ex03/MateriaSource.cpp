#include "AMateria.hpp"
#include <MateriaSource.hpp>
#include <cstddef>
#include <iostream>
#include <string>

MateriaSource::MateriaSource(void) : _name("armory"){
	for (std::size_t i = 0; i < 4; i++)
		_slots[i] = NULL;
}

MateriaSource::MateriaSource(std::string const &name) : _name(name){
	for (std::size_t i = 0; i < 4; i++)
		_slots[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &other) {
	*this = other;
}

MateriaSource::~MateriaSource(void) {
	for (std::size_t i = 0; i < 4; i++)
		delete _slots[i];
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &other) {
	if (this == &other)
		return *this;

	_name = other._name;
	for (std::size_t i = 0; i < 4; i++) {
		if (!other._slots[i])
			continue;
		delete _slots[i];
		_slots[i] = other._slots[i]->clone();
	}
	return *this;
}

std::string	MateriaSource::getName(void) const {
	return _name;
}

// BUG : passin new AMateria leak
void	MateriaSource::learnMateria(AMateria *m) {
	if (!m)
		return ; // TODO : print a message

	size_t	i = 0;
	while (i < 4 && _slots[i])
		i++;
	if (i >= 4) {
		std::cout << getName() << "is full" << std::endl;
		return;
	}
	std::cout << getName() << " stored " << m->getType() << " at the";
	std::cout << i+1 << "th slot" << std::endl;
	_slots[i] = m;
}

void	MateriaSource::deleteMateria(int idx) {
	if (idx < 0 || idx > 3 || !_slots[idx]) {
		std::cout << "can't remove this Materia";
		std::cout << " from " << getName() << std::endl;
		return ;
	}
	std::cout << idx+1 << "th " << _slots[idx]->getType();
	std::cout << " was removed from " << getName() << std::endl;
	delete _slots[idx];
	_slots[idx] = NULL;
}

AMateria	*MateriaSource::createMateria(std::string const &type) {
	for (size_t i = 0; i < 4; i++) {
		if (!_slots[i] || type != _slots[i]->getType())
			continue;
		return _slots[i]->clone();
	}
	std::cout << "Unknown materia " << type << std::endl;
	return NULL;
}
