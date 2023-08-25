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
#include "Intern.hpp"

int	main(void)
{
	Intern	pedro;
	AForm	*rrf, *scf, *ppf, *fake;

	rrf = pedro.makeForm("Robotomy Request Form", "Bender");
	std::cout << *rrf;

	scf = pedro.makeForm("Shrubbery Creation Form", "ni");
	std::cout << *scf;
	ppf = pedro.makeForm("Presidential Pardon Form", "Ford");
	std::cout << *ppf;

	fake = pedro.makeForm("Fake False Form", "Bender");
	if (fake)
		std::cout << *fake;

	delete rrf;
	delete scf;
	delete ppf;
	return 0;
}
