/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 12:22:59 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/25 12:23:00 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int		main()
{
	try
	{
		Form		form("1", 10, 1);
		Bureaucrat	b("1", 1);

		std::cout << form << std::endl;
		std::cout << b << std::endl;
		b.signForm(form);
		std::cout << "form1" << std::endl;
		form.beSigned(b);
		std::cout << form.getIndicator() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	try
	{
		Form		form("2", 10, 1);
		Bureaucrat	b("2", 10);

		std::cout << form << std::endl;
		std::cout << b << std::endl;
		b.signForm(form);
		std::cout << "form2" << std::endl;
		form.beSigned(b);
		std::cout << form.getIndicator() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	try
	{
		Form		form("3", 10, 1);
		Bureaucrat	b("3", 120);

		std::cout << form << std::endl;
		std::cout << b << std::endl;
		std::cout << "form3" << std::endl;
		form.beSigned(b);
		std::cout << form.getIndicator() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	try
	{
		Form		form("4", 10, 1);
		Bureaucrat	b("4", 120);

		std::cout << form << std::endl;
		std::cout << b << std::endl;
		b.signForm(form);
		std::cout << "form4" << std::endl;
		form.beSigned(b);
		std::cout << form.getIndicator() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
