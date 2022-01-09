#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound();  // will output the cat sound!
  j->makeSound();
  meta->makeSound();

  std::cout << std::endl;

  const WrongAnimal* meta2 = new WrongAnimal();
  const WrongAnimal* i2 = new WrongCat();
  std::cout << i2->getType() << " " << std::endl;
  i2->makeSound();
  meta2->makeSound();
}
