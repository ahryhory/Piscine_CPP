/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ship.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlinkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 12:31:33 by dlinkin           #+#    #+#             */
/*   Updated: 2018/06/23 12:31:43 by dlinkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ft_retro.h"
#include "Object.hpp"
#include "Projectile.hpp"

class Ship : public Object
{

public:

	Ship();
	Ship( int y_cord, int x_cord );
	Ship( Ship const & src );
	~Ship();

	Ship &	operator=( Ship const & src );
	void	shipMove( int command );
	void	shoot( Projectile projectiles[] );

	int		live;
	int		fire;
	int		reload;

};
