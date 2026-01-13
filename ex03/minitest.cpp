#include <Ice.hpp>
#include <Cure.hpp>
#include <Character.hpp>
#include <Floor.hpp>
#include <MateriaSource.hpp>
#include <iostream>

int	main () {
	// Floor	world = Floor();
	//
	// Character	spellcaster = Character("hamid", &world);
	// Character	training_dummies= Character("training dummies", &world);
	//
	// Ice		*spell = new Ice();
	// Cure	*potion = new Cure();
	//
	// spellcaster.equip(spell);
	// spellcaster.equip(potion);
	//
	// spellcaster.use(0, training_dummies);
	// spellcaster.use(1, training_dummies);
	//
	// spellcaster.unequip(0);
	// spellcaster.unequip(1);
	//
	// spellcaster.use(0, training_dummies);
	// spellcaster.use(1, training_dummies);
	{
		Floor	world = Floor();
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		std::cout << "------------------------------------------" << std::endl;
		Character npc1("hamid", &world);						// Default Constructor
		std::cout << "NPC1 Name is: " << npc1.getName() << std::endl;
		Character npc2(npc1);				// Copy Constructor (Deep)
		std::cout << "NPC2 Name is: " << npc2.getName() << std::endl;
		Character *npc3 = new Character("Tifa", &world);
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
		delete tmp;
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
