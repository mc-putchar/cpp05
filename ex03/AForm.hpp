/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 05:54:15 by mcutura           #+#    #+#             */
/*   Updated: 2024/05/08 05:59:19 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP


# include <iostream>
# include <string>
# include <exception>

# include "Bureaucrat.hpp"

class AForm
{
	public:
		/* Constructors */
		AForm(std::string name, int sign_grade, int execute_grade);
		AForm(AForm const & copy);

		/* Destructors */
		virtual ~AForm();

		/* Operators */
		AForm & operator=(AForm const & assign);

		/* Getters/Setters */
		std::string getName(void) const;
		bool getIsSigned(void) const;
		int getSignGrade(void) const;
		int getExecuteGrade(void) const;

		/* Methods */
		void beSigned(Bureaucrat const & bureaucrat);
		void execute(Bureaucrat const & executor) const;
		virtual void formExecute(Bureaucrat const &) const = 0;

		/* Exceptions */
		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			virtual const char* what() const throw();
		};

	private:
		std::string const	_name;
		bool				_is_signed;
		int const			_sign_grade;
		int const			_execute_grade;
};

std::ostream & operator<<(std::ostream & ostream, AForm const & form);

#endif
