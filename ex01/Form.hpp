/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 04:33:51 by mcutura           #+#    #+#             */
/*   Updated: 2023/08/22 04:33:51 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP


# include <iostream>
# include <string>
# include <exception>

# include "Bureaucrat.hpp"

// class Bureaucrat;

class Form
{
	public:
		/* Constructors */
		Form();
		Form(std::string name, int sign_grade, int execute_grade);
		Form(Form const & copy);

		/* Destructors */
		~Form();

		/* Operators */
		Form & operator=(Form const & assign);

		/* Getters/Setters */
		std::string getName(void) const;
		bool getIsSigned(void) const;
		int getSignGrade(void) const;
		int getExecuteGrade(void) const;

		/* Methods */
		void beSigned(Bureaucrat const & bureaucrat);

		/* Exceptions */
		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};

	private:
		std::string const	_name;
		bool				_is_signed;
		int const			_sign_grade;
		int const			_execute_grade;
};

std::ostream & operator<<(std::ostream & ostream, Form const & form);


#endif