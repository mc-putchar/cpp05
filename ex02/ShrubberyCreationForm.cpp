/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 06:01:20 by mcutura           #+#    #+#             */
/*   Updated: 2023/08/22 06:01:20 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* Constructors */
ShrubberyCreationForm::ShrubberyCreationForm()
		: AForm(std::string("Shrubbery Creation Form"), 145, 137)	{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
		: AForm(std::string("Shrubbery Creation Form"), 145, 137),
		_target(target)	{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy)
		: AForm((AForm &)copy)	{}

/* Destructors */
ShrubberyCreationForm::~ShrubberyCreationForm()	{}

/* Operators */
ShrubberyCreationForm & ShrubberyCreationForm::
		operator=(ShrubberyCreationForm const &assign)
{
	if (this != &assign)
		this->_target = assign.getTarget();
	return *this;
}

/* Getters/Setters */
std::string ShrubberyCreationForm::getTarget(void) const
{
	return this->_target;
}

/* Methods */
void ShrubberyCreationForm::formExecute(Bureaucrat const &) const
{
	std::string filename = "./" + this->getTarget() + "_shruberry";
	std::ofstream shrubbery(filename.c_str());
	shrubbery << "           {{ }{" << std::endl;
	shrubbery << "          {{}}}{{" << std::endl;
	shrubbery << "        {{}}{}}" << std::endl;
	shrubbery << "           }}}}{" << std::endl;
	shrubbery << "          {{}}}" << std::endl;
	shrubbery << "         }{{}{}}" << std::endl;
	shrubbery << "           {{}{}}" << std::endl;
	shrubbery << "         }}{{}}" << std::endl;
	shrubbery << "          {{}}{{" << std::endl;
	shrubbery << "           \\  /" << std::endl;
	shrubbery << "        .-''| |``-." << std::endl;
	shrubbery << "       '-._/_o_\\_.-'" << std::endl;
	shrubbery << "        `._     _.'" << std::endl;
	shrubbery << "         | :M_C: |" << std::endl;
	shrubbery << "         `._    .'" << std::endl;
	shrubbery << "            `--'" << std::endl;
	shrubbery << "                     .o00o" << std::endl;
	shrubbery << "                   o000000oo" << std::endl;
	shrubbery << "                  00000000000o" << std::endl;
	shrubbery << "                 00000000000000" << std::endl;
	shrubbery << "              oooooo  00000000  o88o" << std::endl;
	shrubbery << "           ooOOOOOOOoo  ```''  888888" << std::endl;
	shrubbery << "         OOOOOOOOOOOO'.qQQQQq. `8888'" << std::endl;
	shrubbery << "        oOOOOOOOOOO'.QQQQQQQQQQ/.88'" << std::endl;
	shrubbery << "        OOOOOOOOOO'.QQQQQQQQQQ/ /q" << std::endl;
	shrubbery << "         OOOOOOOOO QQQQQQQQQQ/ /QQ" << std::endl;
	shrubbery << "           OOOOOOOOO `QQQQQQ/ /QQ'" << std::endl;
	shrubbery << "             OO:M_C:O `QQQ/  /Q'" << std::endl;
	shrubbery << "                \\\\. \\ |  // |" << std::endl;
	shrubbery << "                d\\ \\\\\\|_////" << std::endl;
	shrubbery << "                qP| \\\\ _' `|Ob" << std::endl;
	shrubbery << "                   \\  / \\  \\Op" << std::endl;
	shrubbery << "                   |  | O| |" << std::endl;
	shrubbery << "           _       /\\. \\_/ /\\" << std::endl;
	shrubbery << "            `---__/|_\\\\   //|  __" << std::endl;
	shrubbery << "                  `-'  `-'`-'-'" << std::endl;
	shrubbery.close();
}
