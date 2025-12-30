#include <Cat.hpp>
#include <iostream>

static void	log(std::string logMessage) {
	std::cout << "[LOG]: " << logMessage << std::endl;
}

Cat::Cat(void) : A_Animal("Cat") {
	log("Cat default constructor called");
	_brain = new Brain();
}

Cat::Cat(const Cat &other) {
	log("Cat copy constructor called");
	*this = other;
}

Cat::~Cat(void) {
	log("Cat destructor called");
	delete _brain;
}

Cat	&Cat::operator=(const Cat &other) {
	if (this != &other)
		A_Animal::operator=(other);
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout << "*MIAOU-MIAOU*" << std::endl;
}
