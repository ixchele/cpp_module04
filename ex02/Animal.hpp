#pragma once
#include <string>

class A_Animal {
	protected:
	std::string	_type;

	public:
	A_Animal(void);
	A_Animal(const std::string type);
	A_Animal(const A_Animal &other);
	virtual ~A_Animal(void);

	A_Animal	&operator=(const A_Animal &other);

	std::string	getType(void) const;
	void		setType(const std::string type);
	virtual void	makeSound(void) const = 0;
};
