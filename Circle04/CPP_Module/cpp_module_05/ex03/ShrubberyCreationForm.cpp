/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:15:22 by gipark            #+#    #+#             */
/*   Updated: 2021/05/18 19:30:25 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("shrubbery creation", 145, 137)
{
    this->target = target;
}

std::string ShrubberyCreationForm::getTarget(void) const
{
    return this->target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
        this->target = other.target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat & executor) const
{
	if (this->getSigned())
	{
		if (executor.getGrade() > this->gradeForExecute)
			throw Form::GradeTooHighException();
		else
        {
            std::string nameFile = this->target + "_shrubbery";
            std::ofstream file(nameFile.c_str());
            if (file)
            {
                file << "                                              .\n";
                file << "                                   .         ;\n";
                file << "      .              .              ;%     ;;\n";
                file << "        ,           ,                :;%  %;\n";
                file << "         :         ;                   :;%;'     .,\n";
                file << ",.        %;     %;            ;        %;'    ,;\n";
                file << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
                file << "   %;       %;%;      ,  ;       %;  ;%;   ,%;'\n";
                file << "    ;%;      %;        ;%;        % ;%;  ,%;'\n";
                file << "     `%;.     ;%;     %;'         `;%%;.%;'\n";
                file << "      `:;%.    ;%%. %@;        %; ;@%;%'\n";
                file << "         `:%;.  :;bd%;          %;@%;'\n";
                file << "           `@%:.  :;%.         ;@@%;'\n";
                file << "             `@%.  `;@%.      ;@@%;\n";
                file << "               `@%%. `@%%    ;@@%;\n";
                file << "                 ;@%. :@%%  %@@%;\n";
                file << "                   %@bd%%%bd%%:;\n";
                file << "                     #@%%%%%:;;\n";
                file << "                     %@@%%%::;\n";
                file << "                     %@@@%(o);  . '\n";
                file << "                     %@@@o%;:(.,'\n";
                file << "                 `.. %@@@o%::;\n";
                file << "                    `)@@@o%::;\n";
                file << "                     %@@(o)::;\n";
                file << "                    .%@@@@%::;\n";
                file << "                    ;%@@@@%::;.\n";
                file << "                   ;%@@@@%%:;;;.\n";
                file << "               ...;%@@@@@%%:;;;;,..";
                file.close();
                std::cout << "File " << nameFile << " created" << std::endl;
            }
            else
                std::cout << "Error: Can't create file " << nameFile << std::endl;
        }
    }
    else
        std::cout << "Can't execute. Form not signed" << std::endl;
}
