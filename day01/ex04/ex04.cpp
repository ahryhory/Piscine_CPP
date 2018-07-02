/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 18:26:39 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/19 18:26:40 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		main( void )
{
	std::string		hiBrain = "HI THIS IS BRAIN";
	std::string		*hiBrainPoint = &hiBrain;
	std::string		&hiBrainRef = hiBrain;

	std::cout << *hiBrainPoint << std::endl;
	std::cout << hiBrainRef << std::endl;
}
