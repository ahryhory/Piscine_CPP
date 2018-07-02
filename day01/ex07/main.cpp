/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 11:26:42 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/20 11:26:43 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void	ft_usage( void )
{
	std::cout << "usage: ./replace file_name s1 s2" << std::endl;
	exit(1);
}

void	find_and_replace(std::string *line, std::string oldS, std::string newS)
{
	std::size_t		pos;
	std::size_t		size;

	pos = 0;
	while ((size = line->find(oldS, pos)) != std::string::npos)
	{
		line->replace(size, oldS.size(), newS);
		pos = newS.length() + size;
	}
}

int		main(int ac, char **av)
{
	if (ac != 4)
		ft_usage();
	std::ifstream	file_in(av[1]);
	std::string		fileOutName = av[1];
	std::string		fileLine;

	if (file_in.is_open())
	{
		std::ofstream	file_out(fileOutName.append(".replace"));
		if (file_out.is_open())
		{
			while (getline(file_in, fileLine))
			{
				find_and_replace(&fileLine, av[2], av[3]);
				file_out << fileLine;
				if (!file_in.eof())
					file_out << '\n';
			}
			file_out.close();
		}
		file_in.close();
	}
	return (0);
}
