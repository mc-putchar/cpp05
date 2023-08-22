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
#include "Form.hpp"

int	main(void)
{
	Bureaucrat bob(std::string("Bobert"), 150);
	Bureaucrat berta(std::string("Roberta"), 1);

	Form f1(std::string("Prisoner release form"), 99, 42);
	Form f2(std::string("Presidential pardon form"), 3, 1);

	std::cout << f1;
	std::cout << f2;

	bob.signForm(f1);
	berta.signForm(f2);

	std::cout << bob << berta;

	try {
		Form fail(std::string("Exception throwing form"), 151, -42);
	} catch (std::exception & e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
