#pragma once 
#include "IMateriaSource.hpp"
#include <AMateria.hpp>
#include <string>

class MateriaSource : public IMateriaSource {
	private:
		std::string	_name;
		AMateria	*_slots[4];
	public:
		MateriaSource(void);
		MateriaSource(std::string const &name);
		MateriaSource(MateriaSource const &other);
		~MateriaSource(void);

		MateriaSource	&operator=(MateriaSource const &other);

		std::string	getName(void) const;
		void		learnMateria(AMateria *m);
		void		deleteMateria(int idx);
		AMateria	*createMateria(std::string const &type);
};
