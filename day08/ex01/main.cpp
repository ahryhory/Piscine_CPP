/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 13:15:44 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/29 13:15:45 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>

// sp.addNumber(5);
// sp.addNumber(3);
// sp.addNumber(17);
// sp.addNumber(9);
// sp.addNumber(11);

int main()
{
	Span sp = Span(10000);
	srand(time(NULL));

	for (int i = 0; i < 10000; i++)
	{
		sp.addNumber(rand() % 2000000000);
	}

	std::cout << std::endl << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl << std::endl;

	return 0;
}
