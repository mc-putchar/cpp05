/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 04:01:20 by mcutura           #+#    #+#             */
/*   Updated: 2024/05/08 06:14:38 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat bob(std::string("Bobert"), 145);
	Bureaucrat berta(std::string("Roberta"), 3);

	AForm* f1 = new ShrubberyCreationForm(std::string("monty"));
	AForm* f2 = new RobotomyRequestForm(std::string("Evaluator"));
	AForm* f3 = new PresidentialPardonForm(std::string("MC Putchar"));

	std::cout << bob << berta;
	std::cout << *f1;
	bob.signForm(*f1);
	std::cout << *f2;
	bob.signForm(*f2);
	std::cout << *f3;
	bob.signForm(*f3);

	if (f1->getIsSigned())
		std::cout << f1->getName() << " is already signed." << std::endl;
	else
		berta.signForm(*f1);
	if (f2->getIsSigned())
		std::cout << f2->getName() << " is already signed." << std::endl;
	else
		berta.signForm(*f2);
	if (f3->getIsSigned())
		std::cout << f3->getName() << " is already signed." << std::endl;
	else
		berta.signForm(*f3);

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
