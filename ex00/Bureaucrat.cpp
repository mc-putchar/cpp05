/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 03:35:35 by mcutura           #+#    #+#             */
/*   Updated: 2023/08/22 03:35:35 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* Constructors */
Bureaucrat::Bureaucrat()	{}

Bureaucrat::Bureaucrat(std::string name, int grade)
		: _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy)
		: _name(copy.getName()), _grade(copy.getGrade())
{}

/* Destructors */
Bureaucrat::~Bureaucrat()	{}

/* Operators */
Bureaucrat & Bureaucrat::operator=(Bureaucrat const & assign)
{
	if (this != &assign)
		this->_grade = assign.getGrade();
	return *this;
}

/* Getters/Setters */
std::string Bureaucrat::getName(void) const
{
	return this->_name;
}

int Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

/* Methods */
void Bureaucrat::incrementGrade(void)
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	this->_grade++;
}

/* Exceptions */
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high\n";
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low\n";
}

std::ostream & operator<<(std::ostream & ostream, Bureaucrat const & bur)
{
	ostream << bur.getName() << ", bureaucrat grade " << bur.getGrade() << "." 
		<< std::endl;
	return ostream;
}
