/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 07:01:55 by mcutura           #+#    #+#             */
/*   Updated: 2023/08/22 07:01:55 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* Constructors */
RobotomyRequestForm::RobotomyRequestForm()
		: AForm(std::string("Robotomy Request Form"), 72, 45)	{}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
		: AForm(std::string("Robotomy Request Form"), 72, 45),
		_target(target)	{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy)
		: AForm((AForm &)copy)	{}

/* Destructors */
RobotomyRequestForm::~RobotomyRequestForm()	{}

/* Operators */
RobotomyRequestForm & RobotomyRequestForm::
		operator=(RobotomyRequestForm const &assign)
{
	if (this != &assign)
		this->_target = assign.getTarget();
	return *this;
}

/* Getters/Setters */
std::string RobotomyRequestForm::getTarget(void) const
{
	return this->_target;
}

/* Methods */
void RobotomyRequestForm::formExecute(Bureaucrat const &) const
{
	if (std::rand() & 1) 
		std::cout	<< this->_target << " has been robotomized successfully."
					<< std::endl;
	else
	 	std::cout	<< "Robotomy on " << this->_target << " has failed." 
					<< std::endl;
}

AForm * RobotomyRequestForm::Create(std::string const & target)
{
	return new RobotomyRequestForm(target);
}
