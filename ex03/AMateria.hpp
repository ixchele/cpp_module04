#pragma once
#include <string>

class ICharacter;

class  AMateria {
	protected:
		std::string	const _type;
	public:
		AMateria(std::string const &type);
		AMateria(const AMateria &other);
		virtual ~AMateria(void);

		std::string const &getType(void) const;
		
		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target); 
};
