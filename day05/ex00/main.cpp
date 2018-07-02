/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 12:22:59 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/27 11:49:54 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int		main()
{
	try
	{
		Bureaucrat bureaucrat("1", 1);
		std::cout << bureaucrat;
		std::cout << "incGrade" << std::endl;
		bureaucrat.incGrade();
		std::cout << "incGrade" << std::endl;
		bureaucrat.incGrade();
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
		Bureaucrat bureaucrat("2", 149);
		std::cout << bureaucrat;
		std::cout << "decGrade" << std::endl;
		bureaucrat.decGrade();
		std::cout << "decGrade" << std::endl;
		bureaucrat.decGrade();
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
		std::cout << "Bureaucrat bureaucrat('3', 160);" << std::endl;
		Bureaucrat bureaucrat("3", 160);
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
		std::cout << "Bureaucrat bureaucrat('4', 0);" << std::endl;
		Bureaucrat bureaucrat("4", 0);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
