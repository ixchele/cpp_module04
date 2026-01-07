#include <AMateria.hpp>

class Ice : AMateria {
	private:
		
	public:
		Ice(void);
		~Ice(void);
		
		AMateria	*clone(void) const;
		void		use(ICharacter &target);
};
