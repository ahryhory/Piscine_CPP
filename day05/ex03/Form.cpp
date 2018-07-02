/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 15:20:52 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/25 15:20:53 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("none"), _signGrade(1), _executeGrade(1)
{
	_indicator = false;
}

Form::Form(std::string name, int signGrade, int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
	_indicator = false;
	if (signGrade < 1 || executeGrade < 1)
	{
		throw Form::GradeTooHighException();
	}
	else if (signGrade > 150 || executeGrade > 150)
	{
		throw Form::GradeTooLowException();
	}
}

Form::Form( Form const & src ) : _name(src.getName()), _signGrade(src.getSignGrade()), _executeGrade(src.getExecuteGrade())
{
	*this = src;
}

Form::~Form()
{
}

const char* 		Form::GradeTooHighException::what() const throw()
{
	return "Form Too High";
}

const char* 		Form::GradeTooLowException::what() const throw()
{
	return "Form Too Low";
}

const char* 		Form::FormNotSigned::what() const throw()
{
	return "Form Not Signed";
}

Form				&Form::operator=( Form const & src )
{
	if (this != &src)
		_indicator = src.getIndicator();

	return *this;
}

void				Form::setTarget( std::string target )
{
	_target = target;
}


std::string			Form::getTarget() const
{
	return _target;
}

int					Form::getSignGrade() const
{
	return _signGrade;
}

int					Form::getExecuteGrade() const
{
	return _executeGrade;
}

std::string			Form::getName() const
{
	return _name;
}

bool				Form::getIndicator() const
{
	return _indicator;
}

void				Form::beSigned( Bureaucrat & bureaucrat )
{
	if (this->getIndicator())
		std::cout << "Form was signed" << std::endl;
	else if (bureaucrat.getGrade() > this->getSignGrade())
		throw Form::GradeTooLowException();
	else
		_indicator = true;
}

void				Form::execute(Bureaucrat const & executor) const
{
	if (!this->getIndicator())
		throw Form::FormNotSigned();
	else if (executor.getGrade() > this->getSignGrade())
		throw Form::GradeTooLowException();
}

std::ostream		&operator<<( std::ostream & o, Form const & src )
{
	o << "Form: " << src.getName() << std::endl;
	o << "Sign Grade: " << src.getSignGrade() << std::endl;
	o << "Execute Grade: " << src.getExecuteGrade() << std::endl;
	o << "Indicator: " << src.getIndicator() << std::endl;
	return o;
}

Form::GradeTooLowException::GradeTooLowException()
{
}

Form::GradeTooLowException::GradeTooLowException( Form::GradeTooLowException const & e )
{
	*this = e;
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
}

Form::GradeTooLowException	&Form::GradeTooLowException::operator=( Form::GradeTooLowException const & src )
{
	if (this != &src)
		;
	return *this;
}

Form::GradeTooHighException::GradeTooHighException()
{
}

Form::GradeTooHighException::GradeTooHighException( Form::GradeTooHighException const & e )
{
	*this = e;
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
}

Form::GradeTooHighException	&Form::GradeTooHighException::operator=( Form::GradeTooHighException const & src )
{
	if (this != &src)
		;
	return *this;
}

Form::FormNotSigned::FormNotSigned()
{
}

Form::FormNotSigned::FormNotSigned( Form::FormNotSigned const & e )
{
	*this = e;
}

Form::FormNotSigned::~FormNotSigned() throw()
{
}

Form::FormNotSigned	&Form::FormNotSigned::operator=( Form::FormNotSigned const & src )
{
	if (this != &src)
		;
	return *this;
}
