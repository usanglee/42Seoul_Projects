#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>

class Form;

class Bureaucrat {
 private:
  const std::string name;
  int grade;

 public:
  Bureaucrat(const std::string name, int grade);
  Bureaucrat(const Bureaucrat& obj);
  ~Bureaucrat();
  Bureaucrat& operator=(const Bureaucrat& obj);
  const std::string& getName(void) const;
  const int& getGrade(void) const;
  void increaseGrade(int amount);
  void decreaseGrade(int amount);
  void signForm(Form& obj);
  void executeForm(Form const& form);
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& obj);

#endif
