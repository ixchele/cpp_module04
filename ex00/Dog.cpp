#include "Animal.hpp"
#include <Dog.hpp>
#include <iostream>

static void	log(std::string logMessage) {
	std::cout << "[LOG]: " << logMessage << std::endl;
}

Dog::Dog(void) : Animal("Dog") {
	log("Dog default constructor called");
}

Dog::Dog(const Dog &other) {
	log("Dog copy constructor called");
	*this = other;
}

Dog::~Dog(void) {
	log("Dog destructor called");
}

Dog	&Dog::operator=(const Dog &other) {
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout << "*OUAF-OUAF*" << std::endl;
}
