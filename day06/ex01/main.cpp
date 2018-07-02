/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 14:43:27 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/27 14:43:28 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

struct Data { std::string s1; int n; std::string s2; };

void	*serialize( void )
{
	Data		*p = new Data;
	std::string	char_arr = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	int			i;

	i = 0;
	while (i++ < 8)
		p->s1.append(sizeof(char), char_arr[std::rand() % char_arr.length()]);
	p->n  = std::rand() * (std::rand() % std::rand());
	i = 0;
	while (i++ < 8)
		p->s2.append(sizeof(char), char_arr[std::rand() % char_arr.length()]);
	return reinterpret_cast<void *>(p);
}

Data	*deserialize( void * raw )
{
	return reinterpret_cast<Data *>(raw);
}

int		main()
{
	void			*arr;
	Data			*data;

	std::srand(time(NULL));
	arr = serialize();
	data = deserialize(arr);
	std::cout << data->s1 << std::endl;
	std::cout << data->n << std::endl;
	std::cout << data->s2 << std::endl;
	return 0;
}
