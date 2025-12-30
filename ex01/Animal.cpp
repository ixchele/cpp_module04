#include <Animal.hpp>
#include <iostream>

static void	log(std::string logMessage) {
	std::cout << "[LOG]: " << logMessage << std::endl;
}

Animal::Animal(void) : _type("animal") {
	log("Animal default constructor called");
}

Animal::Animal(const std::string type) : _type(type) {
	log("Animal parameterized constructor called");
}

Animal::Animal(const Animal &other) {
	log("Animal copy constructor called");
	*this = other;
}

Animal::~Animal(void) {
	log("Animal destructor called");
}

Animal	&Animal::operator=(const Animal &other) {
	if (this == &other)
		_type = other._type;
	return *this;
}

std::string	Animal::getType(void) const {
	return _type;
}

void	Animal::setType(const std::string type) {
	_type = type;
}

void	Animal::makeSound(void) const {
	std::cout << "*ANIMAL SOUND*" << std::endl;
}
