/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 12:55:05 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/19 12:55:06 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void	ponyOnTheHeap( void )
{
	Pony *newPony = new Pony();

	std::cout << "On the heap" << std::endl;
	delete newPony;
}

void	ponyOnTheStack( void )
{
	Pony newPony = Pony();

	std::cout << "On the stack" << std::endl;
}

int		main( void )
{
	std::cout << "ponyOnTheHeap: start" << std::endl;
	ponyOnTheHeap();
	std::cout << std::endl << "ponyOnTheHeap: finish" << std::endl << std::endl;
	std::cout << "ponyOnTheStack: start" << std::endl;
	ponyOnTheStack();
	std::cout << std::endl << "ponyOnTheStack: finish" << std::endl;
	return (0);
}
