/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 02:20:59 by gipark            #+#    #+#             */
/*   Updated: 2021/05/18 04:57:43 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

std::string const &ShrubberyCreationForm::name = std::string("Shrubbery Creation");

std::string const ShrubberyCreationForm::trees[3] = {
	"                                              .\n" \
	"                                   .         ;\n" \
	"      .              .              ;%     ;;\n" \
	"        ,           ,                :;%  %;\n" \
	"         :         ;                   :;%;'     .,\n" \
	",.        %;     %;            ;        %;'    ,;\n" \
	"  ;       ;%;  %%;        ,     %;    ;%;    ,%'\n" \
	"   %;       %;%;      ,  ;       %;  ;%;   ,%;'\n" \
	"    ;%;      %;        ;%;        % ;%;  ,%;'\n" \
	"     `%;.     ;%;     %;'         `;%%;.%;'\n" \
	"      `:;%.    ;%%. %@;        %; ;@%;%'\n" \
	"         `:%;.  :;bd%;          %;@%;'\n" \
	"           `@%:.  :;%.         ;@@%;'\n" \
	"             `@%.  `;@%.      ;@@%;\n" \
	"               `@%%. `@%%    ;@@%;\n" \
	"                 ;@%. :@%%  %@@%;\n" \
	"                   %@bd%%%bd%%:;\n" \
	"                     #@%%%%%:;;\n" \
	"                     %@@%%%::;\n" \
	"                     %@@@%(o);  . '\n" \
	"                     %@@@o%;:(.,'\n" \
	"                 `.. %@@@o%::;\n" \
	"                    `)@@@o%::;\n" \
	"                     %@@(o)::;\n" \
	"                    .%@@@@%::;\n" \
	"                    ;%@@@@%::;.\n" \
	"                   ;%@@@@%%:;;;.\n" \
	"               ...;%@@@@@%%:;;;;,.."
};

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target):
	Form(ShrubberyCreationForm::name, 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other):
	Form(other), target(other.target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const char* ShrubberyCreationForm::TargetFileOpenException::what() const throw()
{
	return "ShrubberyCreationFormException: Cannot open file";
}

const char* ShrubberyCreationForm::WriteException::what() const throw()
{
	return "ShrubberyCreationFormException: Error while writing to the file";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	(void)other;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
	std::string const shrubName = (this->target + "_shrubbery");
	std::ofstream outfile(shrubName, std::ios::out | std::ios::app);

	if (!outfile.is_open() || outfile.bad())
		throw TargetFileOpenException();
	int treeCount = (rand() % 6) + 1;
	for (int i = 0; i < treeCount; i++)
	{
		outfile << ShrubberyCreationForm::trees[rand() % 3];
		if (outfile.bad())
		{
			outfile << std::endl;
			outfile.close();
			throw WriteException();
		}
	}
	outfile << std::endl;
	outfile.close();
}
