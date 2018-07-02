/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlinkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 12:31:27 by dlinkin           #+#    #+#             */
/*   Updated: 2018/06/23 12:31:28 by dlinkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ft_retro.h"

class Object
{

public:

	Object();
	Object(int y_cord, int x_cord);
	Object( Object const & src );
	~Object();

	void	move( int yDelta, int xDelta );
	Object &	operator=( const Object & src );

	int		x;
	int		y;
	int		real;

};
