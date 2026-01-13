#pragma once
#include "AMateria.hpp"

// NOTE : “I inject a shared Floor instance into Characters
// 		   to keep ownership explicit and avoid global state.”
class Floor {
private:
	struct Node {
		AMateria	*materia;
		Node		*next;
	};
	Node	*_head;

public:
	Floor(void);
	Floor(const Floor &other);
	~Floor(void);

	Floor	&operator=(const Floor &other);

	void	drop(AMateria *materia);
};
