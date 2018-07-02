/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:13:08 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/19 12:53:07 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

static void	wrong_command(std::string	command)
{
	std::cout << std::endl << "'" << command << "'" << " wrong command" << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
}

int			main(void)
{
	Phonebook	contacts[COUNT_CONTACTS];
	std::string	command;
	std::string	index;

	do
	{
		std::cout << std::endl << "Enter command: ";
		std::getline(std::cin, command);
		if (command == "ADD")
			Phonebook::add(contacts);
		else if (command == "SEARCH")
		{
			Phonebook::search(contacts);
			std::cout << std::endl << "Enter index: ";
			std::getline(std::cin, index);
			Phonebook::printContact(contacts, index);
		}
		else if (command != "EXIT")
			wrong_command(command);
	}
	while (command != "EXIT" && !std::cin.eof());
	return (0);
}
