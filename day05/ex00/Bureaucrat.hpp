/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 12:22:43 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/25 12:22:45 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>

class Bureaucrat
{

public:

	Bureaucrat();
	Bureaucrat( std::string const name, int grade );
	Bureaucrat( Bureaucrat const & src );
	~Bureaucrat();

	class GradeTooHighException : public std::exception
	{

	public:

		GradeTooHighException();
		GradeTooHighException( GradeTooHighException const & e );
		~GradeTooHighException() throw();

		GradeTooHighException	&operator=( GradeTooHighException const & src );

		virtual const char* 	what() const throw();

	};

	class GradeTooLowException : public std::exception
	{

	public:

		GradeTooLowException();
		GradeTooLowException( GradeTooLowException const & e );
		~GradeTooLowException() throw();

		GradeTooLowException	&operator=( GradeTooLowException const & src );

		virtual const char* 	what() const throw();

	};

	Bureaucrat			&operator=( Bureaucrat const & src );

	std::string 		getName() const;
	int					getGrade() const;

	void				incGrade();
	void				decGrade();

private:

	std::string const	_name;
	int					_grade;

};

std::ostream			&operator<<( std::ostream & o, Bureaucrat const & src );

#endif
