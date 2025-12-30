#include <Dog.hpp>
#include <iostream>

static void	log(std::string logMessage) {
	std::cout << "[LOG]: " << logMessage << std::endl;
}

Dog::Dog(void) : A_Animal("Dog") {
	log("Dog default constructor called");
	_brain = new Brain();
}

Dog::Dog(const Dog &other) {
	log("Dog copy constructor called");
	*this = other;
}

Dog::~Dog(void) {
	log("Dog destructor called");
	delete _brain;
}

Dog	&Dog::operator=(const Dog &other) {
	if (this != &other)
		A_Animal::operator=(other);
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout << "*OUAF-OUAF*" << std::endl;
}
