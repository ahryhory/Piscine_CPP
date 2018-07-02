/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 13:15:33 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/29 13:15:34 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>

Span::Span() : _size(0)
{
}

Span::Span( unsigned int count ) : _size(count)
{
}

Span::Span( Span const & src )
{
	*this = src;
}

Span::~Span()
{
}

Span			&Span::operator=( Span const & src )
{
	if (this != &src)
	{
		_size = src._size;
		_arr = src._arr;
	}

	return *this;
}

void			Span::addNumber( unsigned int num )
{
	if (_arr.size() == _size)
		throw std::range_error("range_error");
	_arr.push_front(num);
}

unsigned int	Span::shortestSpan()
{
	std::list<int>		tmp_sort;
	std::list<int>		tmp_count;
	int					tmp;

	tmp_sort = _arr;
	tmp_sort.sort();

	for (std::list<int>::iterator it = tmp_sort.begin(); it != tmp_sort.end(); ++it)
	{
		if (it != tmp_sort.begin())
			tmp_count.push_front(*it - tmp);
		tmp = *it;
	}

	return (*std::min_element(tmp_count.begin(), tmp_count.end()));
}

unsigned int	Span::longestSpan()
{
	return (*std::max_element(_arr.begin(), _arr.end()) - *std::min_element(_arr.begin(), _arr.end()));
}
