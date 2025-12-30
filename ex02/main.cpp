#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const int size = 10;
    A_Animal* animals[size];

    std::cout << "=== Creating animals ===" << std::endl;

    // First half: Dogs
    for (int i = 0; i < size / 2; i++) {
        animals[i] = new Dog();
    }

    // Second half: Cats
    for (int i = size / 2; i < size; i++) {
        animals[i] = new Cat();
    }

    std::cout << "\n=== Making sounds ===" << std::endl;
    for (int i = 0; i < size; i++) {
        animals[i]->makeSound();
    }

    std::cout << "\n=== Deleting animals ===" << std::endl;
    for (int i = 0; i < size; i++) {
        delete animals[i];   // 🔥 delete as Animal*
    }

    return 0;
}
