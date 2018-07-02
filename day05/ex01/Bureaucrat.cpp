/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 12:22:48 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/25 12:22:49 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("none"), _grade(150)
{
}

Bureaucrat::Bureaucrat( std::string const name, int grade ) : _name(name),  _grade(grade)
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) : _name(src.getName())
{
	*this = src;
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat			&Bureaucrat::operator=( Bureaucrat const & src )
{
	if (this != &src)
		_grade = src.getGrade();

	return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat Too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat Too Low";
}

std::string 		Bureaucrat::getName() const
{
	return _name;
}

int					Bureaucrat::getGrade() const
{
	return _grade;
}

void				Bureaucrat::incGrade()
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

void				Bureaucrat::decGrade()
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

void				Bureaucrat::signForm( Form form )
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signs " << form.getName() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << this->getName() << " cannot sign " << form.getName() <<
		" because " << e.what() << std::endl;
	}
}

std::ostream		&operator<<( std::ostream & o, Bureaucrat const & src )
{
	o << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;

	return o;
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException( Bureaucrat::GradeTooLowException const & e )
{
	*this = e;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
}

Bureaucrat::GradeTooLowException	&Bureaucrat::GradeTooLowException::operator=( Bureaucrat::GradeTooLowException const & src )
{
	if (this != &src)
		;
	return *this;
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
{
}

Bureaucrat::GradeTooHighException::GradeTooHighException( Bureaucrat::GradeTooHighException const & e )
{
	*this = e;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
}

Bureaucrat::GradeTooHighException	&Bureaucrat::GradeTooHighException::operator=( Bureaucrat::GradeTooHighException const & src )
{
	if (this != &src)
		;
	return *this;
}
