/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 05:53:26 by mcutura           #+#    #+#             */
/*   Updated: 2023/08/22 05:53:26 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* Constructors */
AForm::AForm() : _name(""), _is_signed(false), _sign_grade(1), _execute_grade(1)
{}

AForm::AForm(std::string name, int sign_grade, int execute_grade)
		: _name(name), _is_signed(false), 
		_sign_grade(sign_grade), _execute_grade(execute_grade)
{
	if (_sign_grade < 1 || _execute_grade < 1)
		throw AForm::GradeTooHighException();
	if (_sign_grade > 150 || _execute_grade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const & copy) 
		: _name(copy.getName()), _is_signed(copy.getIsSigned()), 
		_sign_grade(copy.getSignGrade()), _execute_grade(copy.getExecuteGrade())
{}

/* Destructors */
AForm::~AForm()	{}

/* Operators */
AForm & AForm::operator=(AForm const & assign)
{
	if (this != &assign)
		this->_is_signed = assign.getIsSigned();
	return *this;
}

/* Getters/Setters */
std::string AForm::getName(void) const
{
	return this->_name;
}

bool AForm::getIsSigned(void) const
{
	return this->_is_signed;
}

int AForm::getSignGrade(void) const
{
	return this->_sign_grade;
}

int AForm::getExecuteGrade(void) const
{
	return this->_execute_grade;
}

/* Methods */
void AForm::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw AForm::GradeTooLowException();
	this->_is_signed = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();
	this->formExecute(executor);
}

/* Exceptions */
const char* AForm::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "grade too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "form not signed";
}


std::ostream & operator<<(std::ostream & ostream, AForm const & form)
{
	ostream	<< (form.getIsSigned() ? "Signed " : "Unsigned ") 
			<< "form: " << form.getName() 
			<< " | Grade required - to sign: " << form.getSignGrade()
			<< " - to execute: " << form.getExecuteGrade()
			<< std::endl;
	return ostream;
}
