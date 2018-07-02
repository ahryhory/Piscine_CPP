/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 14:02:39 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/23 14:02:39 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Projectile.hpp"

Projectile::Projectile(int y_cord, int x_cord)
{
	y = y_cord;
	x = x_cord;
	real = 0;
}

Projectile::Projectile()
{
	real = 0;
}

Projectile::Projectile( Projectile const & src )
{
	*this = src;
}

Projectile::~Projectile()
{
}

Projectile &	Projectile::operator=( Projectile const & src ) {
	if (this != &src )
		;
	return *this;
}

void		Projectile::addProjectile( Projectile projectiles[], int y, int x, int type )
{
	int		i;

	i = 0;
	while (projectiles[i].real && i < NUM_PRJCTLS)
		i++;
	projectiles[i].y = y;
	projectiles[i].x = x;
	projectiles[i].type = type;
	projectiles[i].real = 1;
}
