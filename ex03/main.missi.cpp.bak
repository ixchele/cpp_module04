#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	std::cout << "---------------- SUBJECT: ----------------" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		std::cout << "------------------------------------------" << std::endl;
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		std::cout << "------------------------------------------" << std::endl;
		ICharacter* bob = new Character("bob");
		std::cout << "------------------------------------------" << std::endl;
		me->use(0, *bob);
		me->use(1, *bob);
		std::cout << "------------------------------------------" << std::endl;
		delete bob;
		delete me;
		delete src;
		// return 0;
	}
	std::cout << "---------- MateriaSource TESTS: ----------" << std::endl;
	{
		MateriaSource src1;					// Default Constructor
		MateriaSource src2(src1);			// Copy Constructor (Deep)
		MateriaSource *src3 = new MateriaSource();
		std::cout << "------------------------------------------" << std::endl;
		src2.learnMateria(new Ice);
		src3->learnMateria(new Cure);		// Slot 0
		src3->learnMateria(NULL);			// Invalid Materia!
		std::cout << "------------------------------------------" << std::endl;
		*src3 = src2;						// Copy Assignment (Deep)
		std::cout << "------------------------------------------" << std::endl;
		AMateria *test;
		test = src3->createMateria("ice");	// To see if Copy was Correct
		delete test;
		test = src3->createMateria("cure");	// Cure not yet Learned!
		test = src3->createMateria("Ice");	// Incorrect/Unknown Materia!
		std::cout << "------------------------------------------" << std::endl;
		src3->learnMateria(new Cure);		// Slot 1
		src3->learnMateria(new Cure);		// Slot 2
		src3->learnMateria(new Cure);		// Slot 3
		src3->learnMateria(new Cure);		// Slots Full! 
		std::cout << "------------------------------------------" << std::endl;
		delete src3;
	}
	std::cout << "------------ Character TESTS: ------------" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		std::cout << "------------------------------------------" << std::endl;
		Character npc1;						// Default Constructor
		std::cout << "NPC1 Name is: " << npc1.getName() << std::endl;
		Character npc2(npc1);				// Copy Constructor (Deep)
		std::cout << "NPC2 Name is: " << npc2.getName() << std::endl;
		Character *npc3 = new Character("Tifa");
		std::cout << "NPC3 Name is: " << npc3->getName() << std::endl;
		std::cout << "------------------------------------------" << std::endl;
		AMateria* tmp;
		tmp = src->createMateria("cure");
		npc2.equip(tmp);
		tmp = src->createMateria("ice");
		npc3->equip(tmp);					// Slot 0
		npc3->equip(NULL);					// Invalid Materia!
		std::cout << "------------------------------------------" << std::endl;
		*npc3 = npc2;						// Copy Assignment (Deep)
		std::cout << "NPC3 Name is: " << npc3->getName() << std::endl;
		std::cout << "------------------------------------------" << std::endl;
		npc3->use(0, npc1);					// Should use Cure
		std::cout << "------------------------------------------" << std::endl;
		tmp = src->createMateria("ice");
		npc3->equip(tmp);					// Slot 1
		tmp = src->createMateria("ice");
		npc3->equip(tmp);					// Slot 2
		tmp = src->createMateria("ice");
		npc3->equip(tmp);					// Slot 3
		tmp = src->createMateria("ice");
		npc3->equip(tmp);					// Belt is Full!
		std::cout << "------------------------------------------" << std::endl;
		npc3->use(2, npc1);					// Should use Ice
		npc3->use(5, npc1);					// Invalid Belt Slot!
		std::cout << "------------------------------------------" << std::endl;
		npc3->unequip(1);
		npc3->unequip(1);					// Empty Belt Slot!
		npc3->unequip(8);					// Invalid Belt Slot!
		std::cout << "------------------------------------------" << std::endl;
		tmp = src->createMateria("cure");
		npc3->equip(tmp);					// Should be Equipped at Slot 1
		npc3->use(1, npc1);					// Should use Cure
		std::cout << "------------------------------------------" << std::endl;
		delete npc3;
		delete src;
	}
}
