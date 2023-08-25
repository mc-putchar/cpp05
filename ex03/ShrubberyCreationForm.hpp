/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 06:01:06 by mcutura           #+#    #+#             */
/*   Updated: 2023/08/22 06:01:06 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		/* Constructors */
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const & target);
		ShrubberyCreationForm(ShrubberyCreationForm const & copy);

		/* Destructors */
		~ShrubberyCreationForm();

		/* Operators */
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const &assign);

		/* Getters/Setters */
		std::string getTarget(void) const;

		/* Methods */
		void formExecute(Bureaucrat const &) const;
		static AForm * Create(std::string const & target);

	private:
		std::string	_target;
};

#endif
