/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 03:17:53 by mcutura           #+#    #+#             */
/*   Updated: 2024/05/08 05:06:27 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
	public:
		/* Constructors */
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & copy);

		/* Destructors */
		~Bureaucrat();

		/* Operators */
		Bureaucrat & operator=(Bureaucrat const & assign);

		/* Getters/Setters */
		std::string getName(void) const;
		int getGrade(void) const;

		/* Methods */
		void incrementGrade(void);
		void decrementGrade(void);

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
		int					_grade;
};

std::ostream & operator<<(std::ostream & ostream, Bureaucrat const & bur);

#endif
