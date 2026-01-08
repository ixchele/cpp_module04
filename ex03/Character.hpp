#pragma once
#include "AMateria.hpp"
#include <ICharacter.hpp>
#include <pthread.h>
#include <string>

class Character : public ICharacter {
	private:
		AMateria	*_inventory[4];
		std::string	_name;
	public:
		Character(void);
		Character(const std::string &name);
		Character(const Character &other);
		~Character(void);

		Character	&operator=(const Character &other); 

		std::string const	&getName(void) const;
		AMateria			*getMateria(int idx);
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);
};
