/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 04:42:57 by mcutura           #+#    #+#             */
/*   Updated: 2023/08/22 04:42:57 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* Constructors */
Form::Form() : _name(""), _is_signed(false), _sign_grade(1), _execute_grade(1)
{}

Form::Form(std::string name, int sign_grade, int execute_grade)
		: _name(name), _is_signed(false), 
		_sign_grade(sign_grade), _execute_grade(execute_grade)
{
	if (_sign_grade < 1 || _execute_grade < 1)
		throw Form::GradeTooHighException();
	if (_sign_grade > 150 || _execute_grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const & copy) 
		: _name(copy.getName()), _is_signed(copy.getIsSigned()), 
		_sign_grade(copy.getSignGrade()), _execute_grade(copy.getExecuteGrade())
{}

/* Destructors */
Form::~Form()	{}

/* Operators */
Form & Form::operator=(Form const & assign)
{
	if (this != &assign)
		this->_is_signed = assign.getIsSigned();
	return *this;
}

/* Getters/Setters */
std::string Form::getName(void) const
{
	return this->_name;
}

bool Form::getIsSigned(void) const
{
	return this->_is_signed;
}

int Form::getSignGrade(void) const
{
	return this->_sign_grade;
}

int Form::getExecuteGrade(void) const
{
	return this->_execute_grade;
}

/* Methods */
void Form::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw Form::GradeTooLowException();
	this->_is_signed = true;
}

/* Exceptions */
const char* Form::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "grade too low";
}


std::ostream & operator<<(std::ostream & ostream, Form const & form)
{
	ostream	<< (form.getIsSigned() ? "Signed " : "Unsigned ") 
			<< "form: " << form.getName() 
			<< " | Grade required - to sign: " << form.getSignGrade()
			<< " - to execute: " << form.getExecuteGrade()
			<< std::endl;
	return ostream;
}
