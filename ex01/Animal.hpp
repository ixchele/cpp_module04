#pragma once
#include <string>

class Animal {
	protected:
	std::string	_type;

	public:
	Animal(void);
	Animal(const std::string type);
	Animal(const Animal &other);
	virtual ~Animal(void);

	Animal	&operator=(const Animal &other);

	std::string	getType(void) const;
	void		setType(const std::string type);

	virtual void	makeSound(void) const;
};
