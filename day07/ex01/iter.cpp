/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 13:40:24 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/28 13:40:26 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void iter (T * arr, int length, void(*p)(T))
{
	for (int i = 0; i < length; i++)
	{
		p(arr[i]);
	}
}

void i_show (int arg)
{
	std::cout << arg << std::endl;
}

void s_show (std::string arg)
{
	std::cout << arg << std::endl;
}

int		main()
{
	int				i_arr[5] = {1, 2, 3, 4, 5};
	std::string		s_arr[5] = {"1qwe", "2qwdsa", "3vcvc", "4vx", "5cbvbdf"};

	iter(i_arr, 5, &i_show);
	std::cout << std::endl << std::endl;
	iter(s_arr, 5, &s_show);
	return 0;
}
