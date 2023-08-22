/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 07:39:57 by mcutura           #+#    #+#             */
/*   Updated: 2023/08/22 07:39:57 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		/* Constructors */
		Intern();
		Intern(Intern const & copy);

		/* Destructor */
		~Intern();

		/* Operators */
		Intern & operator=(Intern const & assign);

		/* Exceptions */
		class NonExistentFormException : public std::exception
		{
			virtual const char* what() const throw();
		};

		/* Methods */
		AForm * makeForm(std::string const & form, std::string const & target);
		int formNameLookup(std::string const & form);

	private:
};

#endif
