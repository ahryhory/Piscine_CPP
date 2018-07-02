/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 19:58:22 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/25 19:58:23 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

int const ShrubberyCreationForm::_sign = 145;
int const ShrubberyCreationForm::_exec = 137;

ShrubberyCreationForm::ShrubberyCreationForm::ShrubberyCreationForm() : Form()
{
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : Form("shrubbery creation", ShrubberyCreationForm::_sign, ShrubberyCreationForm::_exec)
{
	this->setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & form )
{
	*this = form;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm		&ShrubberyCreationForm::operator=( ShrubberyCreationForm const & src )
{
	if (this != &src)
		;

	return *this;
}

void						ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);
	std::ofstream	file_out(this->getTarget().append("_shrubbery"));
	if (file_out.is_open())
	{
		file_out << "/\\  /\\  /\\" << std::endl;
		file_out << "/\\  /\\  /\\" << std::endl;
		file_out << "/\\  /\\  /\\" << std::endl;
		file_out << "/\\  /\\  /\\" << std::endl;
		file_out << " |   |   |" << std::endl;
		file_out.close();
	}
}
