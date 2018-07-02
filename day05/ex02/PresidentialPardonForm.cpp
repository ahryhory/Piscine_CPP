/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 19:58:43 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/25 19:58:44 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

int const PresidentialPardonForm::_sign = 25;
int const PresidentialPardonForm::_exec = 5;

PresidentialPardonForm::PresidentialPardonForm::PresidentialPardonForm() : Form()
{
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : Form("presidential pardon", PresidentialPardonForm::_sign, PresidentialPardonForm::_exec)
{
	this->setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & form )
{
	*this = form;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm		&PresidentialPardonForm::operator=( PresidentialPardonForm const & src )
{
	if (this != &src)
		;

	return *this;
}

void						PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox !" << std::endl;
}
