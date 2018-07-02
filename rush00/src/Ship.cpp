/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ship.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 14:02:19 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/23 14:02:20 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ship.hpp"

Ship::Ship() {

}

Ship::Ship( Ship const & src ) {
	*this = src;
}

Ship::~Ship() {

}

Ship::Ship( int y_cord, int x_cord ) : Object::Object( y_cord, x_cord ) {
	live = 3;
	reload = 0;
	fire = 0;
}

Ship &	Ship::operator=( Ship const & src ) {
	if (this != &src)
		;
	return *this;
}

void	Ship::shipMove( int command )
{
	if (command == KEY_LEFT && this->x != 1)
		this->move(0, -1);
	if (command == KEY_RIGHT && this->x != WIDTH - 2)
		this->move(0, 1);
	if (command == KEY_UP && this->y != 1)
		this->move(-1, 0);
	if (command == KEY_DOWN && this->y != HEIGHT - 2)
		this->move(1, 0);
}

void	Ship::shoot( Projectile projectiles[] )
{
	Projectile::addProjectile(projectiles, y, x + 2, 0);
	fire++;
	if (fire == 10)
	{
		reload = 10;
		fire = 0;
	}
}
