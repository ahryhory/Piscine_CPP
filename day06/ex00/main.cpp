/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 16:26:19 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/26 16:26:21 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

static void	show_char(char c, double d)
{
	if (d != d || isinf(d))
		std::cout << "char: impossible" << std::endl;
	else if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

static void	show_int(int i, double d)
{
	if (d != d || d < INT_MIN || d > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
}

int			main(int ac, char **av)
{
	char	c;
	int		i;
	float	f;
	double	d;

	if (ac != 2)
		exit(0);

	d = atof(av[1]);
	i = static_cast<int>(d);
	c = static_cast<char>(d);
	f = static_cast<float>(d);

	show_char(c, d);
	show_int(i, d);
	std::cout << std::fixed;
	std::cout << "float: " << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::setprecision(1) << d << std::endl;

	return 0;
}
