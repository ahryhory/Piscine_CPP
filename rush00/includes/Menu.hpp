/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Menu.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlinkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 19:23:09 by dlinkin           #+#    #+#             */
/*   Updated: 2018/06/23 19:23:10 by dlinkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AWindow.hpp"
#include "ft_retro.h"

class Menu : public AWindow
{

public:

	Menu();
	Menu( const char ** array, int arrsize, const char *word );
	Menu( Menu const &src );
	~Menu();

	Menu &		operator=( Menu const &rhs );
	void		redraw( int command );
	int			getItem(void);

private:

	WINDOW		*win;
	const char	**menu;
	const char	*name;
	int			current;
	int			size;

};

void		drawColumn();
