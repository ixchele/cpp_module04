#include <Animal.hpp>
#include <iostream>

static void	log(std::string logMessage) {
	std::cout << "[LOG]: " << logMessage << std::endl;
}

A_Animal::A_Animal(void) : _type("animal") {
	log("A_Animal default constructor called");
}

A_Animal::A_Animal(const std::string type) : _type(type) {
	log("A_Animal parameterized constructor called");
}

A_Animal::A_Animal(const A_Animal &other) {
	log("A_Animal copy constructor called");
	*this = other;
}

A_Animal::~A_Animal(void) {
	log("A_Animal destructor called");
}

A_Animal	&A_Animal::operator=(const A_Animal &other) {
	if (this == &other)
		_type = other._type;
	return *this;
}

std::string	A_Animal::getType(void) const {
	return _type;
}

void	A_Animal::setType(const std::string type) {
	_type = type;
}
