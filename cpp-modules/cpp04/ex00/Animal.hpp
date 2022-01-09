#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal {
 protected:
  std::string type;

 public:
  Animal();
  Animal(const std::string name);
  ~Animal();
  Animal(const Animal& obj);
  virtual void makeSound(void) const;
  std::string getType(void) const;
  Animal& operator=(const Animal& obj);
};

#endif