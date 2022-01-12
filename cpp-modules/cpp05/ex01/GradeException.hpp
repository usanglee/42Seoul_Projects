#ifndef GRADEEXCEPTION_HPP
#define GRADEEXCEPTION_HPP
#include <iostream>

class GradeTooHighException : public std::exception {
 public:
  const char* what() const throw();
};

class GradeTooLowException : public std::exception {
 public:
  const char* what() const throw();
};

#endif