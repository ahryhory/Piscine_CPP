/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 15:20:56 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/25 15:20:57 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"

class Form
{

public:

	Form();
	Form(std::string name, int signGrade, int executeGrade);
	Form( Form const & src );
	~Form();

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

	class FormNotSigned : public std::exception
	{

	public:

		FormNotSigned();
		FormNotSigned( FormNotSigned const & e );
		~FormNotSigned() throw();

		FormNotSigned	&operator=( FormNotSigned const & src );

		virtual const char* 	what() const throw();

	};

	Form				&operator=( Form const & src );


	void				setTarget( std::string const target );

	int					getSignGrade() const;
	int					getExecuteGrade() const;
	std::string			getName() const;
	std::string			getTarget() const;
	bool				getIndicator() const;

	void				beSigned( Bureaucrat & bureaucrat );
	virtual void		execute(Bureaucrat const & executor) const = 0;

private:

	std::string	const	_name;
	int			const	_signGrade;
	int			const	_executeGrade;
	bool				_indicator;
	std::string 		_target;

};

std::ostream			&operator<<( std::ostream & o, Form const & src );

#endif
