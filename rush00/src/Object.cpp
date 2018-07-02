/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 14:02:29 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/23 14:02:30 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Object.hpp"

Object::Object(int y_cord, int x_cord)
{
	y = y_cord;
	x = x_cord;
	real = 0;
}

Object::Object()
{
	real = 0;
}

Object::Object( Object const & src )
{
	*this = src;
}

Object::~Object()
{
}

Object &	Object::operator=( const Object & src ) {
	if (this != &src)
		;
	return *this;
}

void	Object::move( int yDelta, int xDelta )
{
	y += yDelta;
	x += xDelta;
}
