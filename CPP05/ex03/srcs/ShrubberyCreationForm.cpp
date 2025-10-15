/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:59:13 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/15 19:22:31 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : \
AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other) : AForm(other)
{
	this->_target = other.getTarget();
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &other)
{
	this->_target = other.getTarget();
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string	const &ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSignedStatus())
		throw UnsignedFormException();
	else if (this->getExecuteRequirement() < executor.getGrade())
		throw GradeTooLowException();
	
	std::ofstream	graft;

	graft.open(std::string(this->_target + "_shrubbery").c_str());
	graft << this->tree_str << std::endl;
	graft.close();
}

const std::string ShrubberyCreationForm::tree_str = "            .        +          .      .          .\n"\
"     .            _        .                    .\n"\
"  ,              /;-._,-.____        ,-----.__\n"\
" ((        .    (_:#::_.:::. `-._   /:, /-._, `._,\n"\
"  `                 \\   _|`\"=:_::.`.);  \\ __/ /\n"\
"                      ,    `./  \\:. `.   )==-'  .\n"\
"    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           .\n"\
".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o\n"\
"       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .\n"\
"  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7\n"\
"   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/\n"\
"              \\:  `  X` _| _,\\/'   .-'\n"\
".               \":._:`\\____  /:'  /      .           .\n"\
"                    \\::.  :\\/:'  /              +\n"\
"   .                 `.:.  /:'  }      .\n"\
"           .           ):_(:;   \\           .\n"\
"                      /:. _/ ,  |\n"\
"                   . (|::.     ,`                  .\n"\
"     .                |::.    {\\\n"\
"                      |::.\\  \\ `.\n"\
"                      |:::(\\    |\n"\
"              O       |:::/{ }  |                  (o\n"\
"               )  ___/#\\::`/ (O \"==._____   O, (O  /`\n"\
"          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~\n"\
"      ~~~~~~~~~~~~~~~~~~~~~~~\\\\W~~~~~~~~~~~~\\|/~~";
