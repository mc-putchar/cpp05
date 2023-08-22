/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 06:54:22 by mcutura           #+#    #+#             */
/*   Updated: 2023/08/22 06:54:22 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* Constructors */
PresidentialPardonForm::PresidentialPardonForm()
		: AForm(std::string("Presidential Pardon Form"), 25, 5)	{}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
		: AForm(std::string("Presidential Pardon Form"), 25, 5),
		_target(target)	{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy)
		: AForm((AForm &)copy)	{}

/* Destructors */
PresidentialPardonForm::~PresidentialPardonForm()	{}

/* Operators */
PresidentialPardonForm & PresidentialPardonForm::
		operator=(PresidentialPardonForm const &assign)
{
	if (this != &assign)
		this->_target = assign.getTarget();
	return *this;
}

/* Getters/Setters */
std::string PresidentialPardonForm::getTarget(void) const
{
	return this->_target;
}

/* Methods */
void PresidentialPardonForm::formExecute(Bureaucrat const &) const
{
	std::cout	<< this->_target << " has been pardoned "
				<< "by the magnanimous decree of our Galactic President"
				<< " Zaphod Beeblebrox. Awesome!" << std::endl; 
}
