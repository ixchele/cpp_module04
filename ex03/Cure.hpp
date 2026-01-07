#include <AMateria.hpp>

class Cure : AMateria {
	private:
		
	public:
		Cure(void);
		Cure(const Cure &other);
		~Cure(void);
		
		Cure	&operator=(const Cure &other);
		
		Cure	*clone(void) const;
		void		use(ICharacter &target);
};
