#include "Form.hpp"

#include "Bureaucrat.hpp"
#include "GradeException.hpp"

Form::Form(const std::string name, int signGrade, int execGrade,
           const std::string target)
    : name(name),
      isSign(false),
      signGrade(signGrade),
      execGrade(execGrade),
      target(target) {
  if (this->signGrade < 1 || this->execGrade < 1) throw GradeTooHighException();
  if (this->signGrade > 150 || this->execGrade > 150)
    throw GradeTooLowException();
}

Form::Form(const Form& obj)
    : name(obj.name),
      isSign(obj.isSign),
      signGrade(obj.signGrade),
      execGrade(obj.execGrade),
      target(obj.target) {}

Form::~Form() {}

Form& Form::operator=(const Form& obj) {
  this->isSign = obj.isSign;
  return (*this);
}

const std::string& Form::getName(void) const { return (this->name); }

const bool& Form::getIsSign(void) const { return (this->isSign); }

const int& Form::getSignGrade(void) const { return (this->signGrade); }

const int& Form::getExecGrade(void) const { return (this->execGrade); }

const std::string& Form::getTarget(void) const { return (this->target); }

void Form::beSigned(const Bureaucrat& obj) {
  if (obj.getGrade() > this->signGrade) {
    throw GradeTooLowException();
  }
  this->isSign = true;
}

void Form::checkForm(Bureaucrat const& executor) const {
  if (this->getIsSign() == false) throw NoSignedException();
  if (this->execGrade < executor.getGrade()) {
    throw GradeTooLowException();
  }
}

std::ostream& operator<<(std::ostream& stream, const Form& obj) {
  stream << "form: " << obj.getName() << ", is sign: " << obj.getIsSign()
         << ", sign grade: " << obj.getSignGrade()
         << ", exec sign: " << obj.getExecGrade();
  return (stream);
}