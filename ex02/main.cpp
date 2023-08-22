/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 04:01:20 by mcutura           #+#    #+#             */
/*   Updated: 2023/08/22 04:01:20 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat bob(std::string("Bobert"), 150);
	Bureaucrat berta(std::string("Roberta"), 1);

	AForm* f1 = new ShrubberyCreationForm(std::string("monty"));
	AForm* f2 = new RobotomyRequestForm(std::string("Evaluator"));
	AForm* f3 = new PresidentialPardonForm(std::string("MC Putchar"));

	std::cout << *f1;
	bob.signForm(*f1);
	std::cout << *f2;
	bob.signForm(*f2);
	std::cout << *f3;
	bob.signForm(*f3);

	berta.signForm(*f1);
	berta.signForm(*f2);
	berta.signForm(*f3);

	std::cout << bob << berta;

	bob.executeForm(*f1);

	berta.executeForm(*f2);
	berta.executeForm(*f2);
	berta.executeForm(*f2);

	
	berta.executeForm(*f1);
	berta.executeForm(*f3);

	delete f1;
	delete f2;
	delete f3;
	return 0;
}
