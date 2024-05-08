/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 04:01:20 by mcutura           #+#    #+#             */
/*   Updated: 2024/05/08 05:55:25 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <string>

#include "Form.hpp"
#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat bob(std::string("Bobert"), 150);
	Bureaucrat berta(std::string("Roberta"), 3);

	Form f1(std::string("Prisoner release form"), 99, 42);
	Form f2(std::string("Presidential pardon form"), 3, 1);

	std::cout << bob << berta;
	std::cout << f1 << f2;

	bob.signForm(f1);
	berta.signForm(f1);
	berta.signForm(f2);
	std::cout << f1 << f2;

	try {
		Form fail(std::string("Exception throwing form"), 15, -42);
	} catch (std::exception & e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		Form fail(std::string("Exception throwing form"), 151, 42);
	} catch (std::exception & e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
