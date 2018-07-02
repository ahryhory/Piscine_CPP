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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int		main()
{
	try
	{
		ShrubberyCreationForm  form = ShrubberyCreationForm("home");
		Bureaucrat b("b1", 1);

		std::cout << "executeForm:" << std::endl;
		b.executeForm(form);
		std::cout << std::endl;
		std::cout << "beSigned" << std::endl;
		form.beSigned(b);
		std::cout << std::endl;
		std::cout << "executeForm:" << std::endl;
		b.executeForm(form);
		std::cout << std::endl;
		form.execute(b);
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
		std::srand(std::time(NULL));
		RobotomyRequestForm  form = RobotomyRequestForm("Marvin");
		Bureaucrat b("b1", 1);

		b.executeForm(form);
		std::cout << std::endl;
		form.beSigned(b);
		std::cout << std::endl;
		b.executeForm(form);
		std::cout << std::endl;
		form.execute(b);
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
		PresidentialPardonForm  form = PresidentialPardonForm("ARTHUR");
		Bureaucrat b("b1", 1);

		form.beSigned(b);
		std::cout << std::endl;
		form.execute(b);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
