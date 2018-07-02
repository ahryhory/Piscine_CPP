/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlinkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 12:31:46 by dlinkin           #+#    #+#             */
/*   Updated: 2018/06/23 12:31:47 by dlinkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Object.hpp"

class Projectile : public Object
{

public:

	Projectile();
	Projectile(int y_cord, int x_cord);
	Projectile( Projectile const & src );
	~Projectile();

	Projectile &	operator=( Projectile const & src );
	static void		addProjectile( Projectile projectiles[], int y, int x , int type );

	int				type;

};
