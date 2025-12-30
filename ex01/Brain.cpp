#include <Brain.hpp>
#include <cstddef>
#include <iostream>

static void	log(std::string logMessage) {
	std::cout << "[LOG]: " << logMessage << std::endl;
}

Brain::Brain(void) {
	log("Brain default constructor called");
}

Brain::Brain(const Brain &other) {
	log("Brain copy constructor called");
	*this = other;
}

Brain::~Brain(void) {
	log("Brain destructor called");
	
}

Brain	&Brain::operator=(const Brain &other) {
	if (this != &other)
		for (size_t i = 0; i < 100; ++i) {
			_ideas[i] = other._ideas[i];
		}
	return *this;
}
