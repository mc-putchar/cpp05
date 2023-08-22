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

int	main(void)
{
	Bureaucrat bob(std::string("Bobert"), 150);
	Bureaucrat berta(std::string("Roberta"), 1);

	try {
		Bureaucrat squ(std::string("Squirell"), -1);
	} catch (std::exception & e) {
		std::cout << "Exception: " << e.what();
	}
	
	try {
		Bureaucrat squ(std::string("Squirell"), 151);
	} catch (std::exception & e) {
		std::cout << "Exception: " << e.what();
	}

	std::cout << bob << berta;

	try {
		bob.decrementGrade();
	} catch (std::exception & e) {
		std::cout << "Exception: " << e.what();
	}

	try {
		berta.incrementGrade();
	} catch (std::exception & e) {
		std::cout << "Exception: " << e.what();
	}
	return 0;
}
