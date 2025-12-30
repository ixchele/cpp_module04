#include <Brain.hpp>
#include <Animal.hpp>

class Cat : public A_Animal {
private:
	Brain	*_brain;

public:
	Cat(void);
	Cat(const std::string type);
	Cat(const Cat &other);
	~Cat(void);

	Cat	&operator=(const Cat &other);

	void	makeSound(void) const;
};
