/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 12:15:32 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/29 12:15:32 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

int		main()
{
	int myints[] = { 10, 20, 30, 40 };
	std::vector<int> myvector (myints, myints+4);

	if (easyfind(myvector, 10))
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	if (easyfind(myvector, 30))
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	if (easyfind(myvector, 23))
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	return 0;
}
