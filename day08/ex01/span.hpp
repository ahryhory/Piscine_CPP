/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 13:15:38 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/29 13:15:39 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <algorithm>
# include <list>

class Span
{

public:

	Span();
	Span( unsigned int count );
	Span( Span const & src );
	~Span();

	Span			&operator=( Span const & src );

	void			addNumber( unsigned int num );
	unsigned int	shortestSpan();
	unsigned int	longestSpan();

public:

	std::list<int>	_arr;
	unsigned int	_size;

};

#endif
