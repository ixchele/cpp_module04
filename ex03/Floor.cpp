#include <Floor.hpp>

Floor::Floor(void) : _head(NULL) {
	//pass
}

Floor::Floor(const Floor &other) {
	*this = other;
}

Floor::~Floor(void) {
	Node	*current = _head;

	while (current) {
		Node	*next = current->next;
		delete current->materia;
		delete current;
		current = next;
	}
}

Floor	&Floor::operator=(const Floor &other) {
	if (this == &other)
		return *this;

	_head = other._head;
	return *this;
}

void	Floor::drop(AMateria *materia) {
	if (!materia)
		return;

	Node	*node = new Node;
	node->materia = materia;
	node->next = _head;
	_head = node;
}
