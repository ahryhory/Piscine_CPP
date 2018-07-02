/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlinkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 15:27:07 by dlinkin           #+#    #+#             */
/*   Updated: 2018/06/23 15:27:08 by dlinkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ft_retro.h"
#include "AWindow.hpp"

class Game
{
private:
	static short	r;
	static short	g;
	static short	b;
	static std::string		records[NUM_RECORDS];

public:
	Game( void );
	~Game( void );
	Game( const Game & rhs );

	Game &				operator=( const Game & rhs );
	static void			newGame( void );
	static void			menu( void );
	static int			pauseMenu( void );
	static void			start( void );
	static void			end( void );
	static void			saveColor( void );
	static void			restoreColor( void );
	static void			addRecord( std::string newOne);
	static void			showRecords( void );
	static void			eraseRecords( void );
};


void					sigWinch(int signo);
