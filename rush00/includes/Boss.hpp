/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 17:13:42 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/24 17:13:42 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ft_retro.h"
#include "Ship.hpp"
#include "Object.hpp"
#include "Projectile.hpp"

class Boss
{

public:

	Boss();
	Boss( Boss const &src );
	~Boss();

	Boss		&operator=( Boss const &src );

	void		showBoss( WINDOW *win, int y, int x );
	void		moveBoss();
	void		drawBoss( WINDOW *win );

	int			real;

	int			xStartLeftUp;
	int			yStartLeftUp;

	int			up;
	int			down;

};
