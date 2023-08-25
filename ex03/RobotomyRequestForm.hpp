/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 07:00:46 by mcutura           #+#    #+#             */
/*   Updated: 2023/08/22 07:00:46 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		/* Constructors */
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const & target);
		RobotomyRequestForm(RobotomyRequestForm const & copy);

		/* Destructors */
		~RobotomyRequestForm();

		/* Operators */
		RobotomyRequestForm & operator=(RobotomyRequestForm const &assign);

		/* Getters/Setters */
		std::string getTarget(void) const;

		/* Methods */
		void formExecute(Bureaucrat const &) const;
		static AForm * Create(std::string const & target);

	private:
		std::string	_target;
};

#endif
