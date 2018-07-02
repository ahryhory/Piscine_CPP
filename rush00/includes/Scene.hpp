/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scene.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 12:25:36 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/23 12:25:37 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ft_retro.h"
#include "Ship.hpp"
#include "Object.hpp"
#include "Projectile.hpp"
#include "Enemy.hpp"
#include "AWindow.hpp"

class Scene : public AWindow
{

public:

	Scene();
	Scene( Scene const &src );
	~Scene();

	Scene		&operator=( Scene const &src );

	int			redraw( int command );
	std::string	getResult();
	void		drawProjectiles();
	void		drawEnemy();
	void		drawGift();
	void		addGift();
	void		tickTock();
	void		check();
	void		showBoss( int yStartLeftUp, int xStartLeftUp );
	void		drawSpace( void );
	void		makeSpace( void );

private:

	WINDOW		*win;
	Object		*gift;
	Ship		*ship;
	Boss		*boss;
	Enemy		*enemies;
	Projectile	*projectiles;
	Object		*particles;
	int			score;
	int			step;
	int			time;

};
