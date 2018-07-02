/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 13:42:21 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/26 13:42:21 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern( Intern const & src )
{
	*this = src;
}

Intern::~Intern()
{
}

Intern		&Intern::operator=( Intern const & src )
{
	if (this != &src)
		;

	return *this;
}

Form		*Intern::makeForm( std::string form_name, std::string target )
{
	if (form_name == "robotomy request")
	{
		std::cout << "Intern creates '" << form_name << "'"<< std::endl;
		return new RobotomyRequestForm(target);
	}
	else if (form_name == "shrubbery creation")
	{
		std::cout << "Intern creates '" << form_name << "'"<< std::endl;
		return new ShrubberyCreationForm(target);
	}
	else if (form_name == "presidential pardon")
	{
		std::cout << "Intern creates '" << form_name << "'"<< std::endl;
		return new PresidentialPardonForm(target);
	}
	else
	{
		std::cout << "Requested form is not known '" << form_name << "'!" << std::endl;
		return NULL;
	}
}
