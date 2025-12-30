#include <Animal.hpp>
#include <Brain.hpp>

class Dog : public A_Animal {
private:
	Brain	*_brain;

public:
	Dog(void);
	Dog(const Dog &other);
	~Dog(void);

	Dog	&operator=(const Dog &other);

	void	makeSound(void) const;
};
