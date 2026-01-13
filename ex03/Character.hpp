#pragma once
#include "AMateria.hpp"
#include "Floor.hpp"
#include <ICharacter.hpp>
#include <pthread.h>
#include <string>

class Character : public ICharacter {
	private:
		AMateria	*_inventory[4];
		std::string	_name;
		Floor		*_floor;
	public:
		Character(Floor *floor);
		Character(const std::string &name, Floor *floor);
		Character(const Character &other);
		~Character(void);

		Character	&operator=(const Character &other); 

		std::string const	&getName(void) const;
		AMateria const		*getMateria(int idx) const;
		Floor				*getFloor() const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);
};
