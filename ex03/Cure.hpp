#include <AMateria.hpp>

class Cure : public AMateria {
	private:
		
	public:
		Cure(void);
		~Cure(void);
		
		AMateria	*clone(void) const;
		void		use(ICharacter &target);
};
