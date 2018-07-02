/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 12:29:59 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/24 12:30:00 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Object.hpp"
#include "Boss.hpp"
#include "ft_retro.h"

class Enemy : public Object
{

public:

	Enemy();
	Enemy(int y_cord, int x_cord);
	Enemy( Enemy const & src );
	~Enemy();

	static void		addEnemy( Enemy enemies[], Boss *boss );
	Enemy &			operator=( const Enemy & src );

	int			live;
	int			speed;
	int			shoot;

};
