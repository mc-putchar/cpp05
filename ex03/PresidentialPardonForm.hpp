/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 06:52:25 by mcutura           #+#    #+#             */
/*   Updated: 2024/05/08 06:20:42 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		/* Constructors */
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const & target);
		PresidentialPardonForm(PresidentialPardonForm const & copy);

		/* Destructors */
		~PresidentialPardonForm();

		/* Operators */
		PresidentialPardonForm & operator=
				(PresidentialPardonForm const & assign);

		/* Getters/Setters */
		std::string getTarget(void) const;

		/* Methods */
		void formExecute(Bureaucrat const &) const;
		static AForm * Create(std::string const & target);

	private:
		std::string	_target;
};

#endif
