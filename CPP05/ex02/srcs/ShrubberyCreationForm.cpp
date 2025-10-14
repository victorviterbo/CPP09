

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : \
AForm("ShrubberyCreationForm", false, 145, 137)
{
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other) : \
AForm(other.getName(), other.getSignedStatus(), other.getSignRequirement(), other.getExecuteRequirement())
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
	if (this->getExecuteRequirement() < executor.getGrade())
		throw GradeTooLowException();

	std::ofstream	graft;
	std::ifstream	tree;
	std::string		line;

	graft.open(this->_target + "_shrubbery");
	tree.open("tree.txt");
    while (std::getline(tree, line)) {
        graft << line << std::endl;
    }
	graft.close();
	tree.close();
}


const std::string tree = 
"            .        +          .      .          ."
"     .            _        .                    ."
"  ,              /;-._,-.____        ,-----.__"
" ((        .    (_:#::_.:::. `-._   /:, /-._, `._,"
"  `                 \\   _|`\"=:_::.`.);  \\ __/ /"
"                      ,    `./  \\:. `.   )==-'  ."
"    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ."
".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o"
"       .    /:+- - + +- : :- + + -:'  /(o-) \\)     ."
"  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7"
"   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/"
"              \\:  `  X` _| _,\\/'   .-'"
".               \":._:`\\____  /:'  /      .           ."
"                    \\::.  :\\/:'  /              +"
"   .                 `.:.  /:'  }      ."
"           .           ):_(:;   \\           ."
"                      /:. _/ ,  |"
"                   . (|::.     ,`                  ."
"     .                |::.    {\\"
"                      |::.\\  \\ `."
"                      |:::(\\    |"
"              O       |:::/{ }  |                  (o"
"               )  ___/#\\::`/ (O \"==._____   O, (O  /`"
"          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~"
"      ~~~~~~~~~~~~~~~~~~~~~~~\\\\W~~~~~~~~~~~~\\|/~~";
