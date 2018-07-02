/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 19:58:31 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/25 19:58:32 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

int const RobotomyRequestForm::_sign = 72;
int const RobotomyRequestForm::_exec = 45;

RobotomyRequestForm::RobotomyRequestForm::RobotomyRequestForm() : Form()
{
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : Form("robotomy request", RobotomyRequestForm::_sign, RobotomyRequestForm::_exec)
{
	this->setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & form )
{
	*this = form;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm		&RobotomyRequestForm::operator=( RobotomyRequestForm const & src )
{
	if (this != &src)
		;

	return *this;
}

void					RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);
	std::cout << "'some drilling noises'" << std::endl;
	std::cout << "'some drilling noises'" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->getTarget() << " has been robotomized successfully !" << std::endl;
	else
		std::cout << this->getTarget() << " has been not robotomized !" << std::endl;
}
