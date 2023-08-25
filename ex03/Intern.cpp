/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 07:39:39 by mcutura           #+#    #+#             */
/*   Updated: 2023/08/22 07:39:39 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


/* Constructors */
Intern::Intern()	{}
Intern::Intern(Intern const & copy)
{
	(void)copy;
}

/* Destructor */
Intern::~Intern()	{}

/* Operators */
Intern & Intern::operator=(Intern const & assign)
{
	(void)assign;
	return *this;
}

/* Exceptions */
const char* Intern::NonExistentFormException::what() const throw()
{
	return "the requested form doesn't exist";
}

/* Methods */
AForm * Intern::makeForm(std::string const & form_name, std::string const & target)
{
	static CreateFormCallbacks const create_form = {
						ShrubberyCreationForm::Create,
						RobotomyRequestForm::Create,
						PresidentialPardonForm::Create };

	try {
		return create_form[this->formNameLookup(form_name)](target);
	} catch (std::exception & e) {
		std::cout 	<< "Intern claims that " << form_name << " " << e.what() 
					<< ". Preposterous!" << std::endl;
	}
	return NULL;
}

int	Intern::formNameLookup(std::string const & form)
{
	static std::string const form_names[] = {
						std::string("Shrubbery Creation Form"),
						std::string("Robotomy Request Form"),
						std::string("Presidential Pardon Form") };

	for (int i = 0; i < 3; ++i)
	{
		if (!form_names[i].compare(form))
		{
			std::cout << "Intern creates " << form_names[i] << std::endl;
			return i;
		}
	}
	throw NonExistentFormException();
}
