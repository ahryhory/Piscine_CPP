/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 12:30:09 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/24 12:30:10 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(int y_cord, int x_cord)
{
	y = y_cord;
	x = x_cord;
	real = 0;
}

Enemy::Enemy()
{
	real = 0;
}

Enemy::Enemy( Enemy const & src )
{
	*this = src;
}

Enemy::~Enemy()
{
}

Enemy &	Enemy::operator=( Enemy const & src ) {
	if (this != &src)
		;
	return (*this);
}

void		Enemy::addEnemy( Enemy enemies[], Boss *boss )
{
	int		i;

	i = 0;
	while (enemies[i].real && i < 500)
		i++;
	if (boss->real)
	{
		enemies[i].x = WIDTH - 6;
		if (std::rand() % 9 == 0)
			enemies[i].y = boss->yStartLeftUp + 6;
		else
			enemies[i].y = boss->yStartLeftUp + 11;
	}
	else
	{
		enemies[i].y = std::rand() % HEIGHT + 1;
		enemies[i].x = WIDTH;
	}
	enemies[i].real = 1;
	if (std::rand() % 9 == 0)
	{
		enemies[i].live = 2;
		enemies[i].speed = 1;
		enemies[i].shoot = 0;
	}
	else if (std::rand() % 15 == 0)
	{
		enemies[i].live = 1;
		enemies[i].speed = 2;
		enemies[i].shoot = 0;
	}
	else if (std::rand() % 7 == 0)
	{
		enemies[i].live = 1;
		enemies[i].speed = 1;
		enemies[i].shoot = 1;
	}
	else
	{
		enemies[i].live = 1;
		enemies[i].speed = 1;
		enemies[i].shoot = 0;
	}
}
