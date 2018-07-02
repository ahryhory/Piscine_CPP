/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:53:36 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/19 14:53:37 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void memoryLeak()
{
	std::string *panthere = new std::string("String panthere");
	std::cout << *panthere << std::endl;
	delete panthere;
}
