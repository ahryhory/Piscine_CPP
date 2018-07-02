/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 13:14:32 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/18 13:14:34 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void	ft_exit()
{
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	exit(1);
}

int			main(int ac, char **av)
{
	if (ac < 2)
		ft_exit();
	av++;
	while (*av)
	{
		while (**av)
		{
			std::cout << (char)toupper(**av);
			(*av)++;
		}
		av++;
	}
	std::cout << std::endl;
	return (0);
}
