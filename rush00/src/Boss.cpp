/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 18:07:19 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/24 18:07:21 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Boss.hpp"

Boss::Boss()
{
	real = 0;
	up = 1;
}

Boss::Boss( Boss const &src )
{
	*this = src;
}

Boss::~Boss()
{
}

Boss		&Boss::operator=( Boss const &src )
{
	if (this != &src)
		this->xStartLeftUp = src.xStartLeftUp;
	return *this;
}

void		Boss::drawBoss( WINDOW *win )
{
	int		x;
	int		y;

	x = xStartLeftUp;
	y = yStartLeftUp;

	mvwprintw(win, y + 0, x + 0, "##");
	mvwprintw(win, y + 1, x + 1, "#");
	mvwprintw(win, y + 2, x + 0, "##  ##");
	mvwprintw(win, y + 3, x + 1, "####");
	mvwprintw(win, y + 4, x + 1, "## #");
	mvwprintw(win, y + 5, x + 1, "## #");
	mvwprintw(win, y + 6, x + 1, "####");
	mvwprintw(win, y + 7, x + 0, "##  ##");
	wattron(win, COLOR_PAIR(1) | A_BOLD);
	mvwprintw(win, y + 8, x + 4, "##");
	wattroff(win, COLOR_PAIR(1) | A_BOLD);
	mvwprintw(win, y + 9, x + 4, "##");
	mvwprintw(win, y + 10, x + 0, "##  ##");
	mvwprintw(win, y + 11, x + 1, "####");
	mvwprintw(win, y + 12, x + 1, "## #");
	mvwprintw(win, y + 13, x + 1, "## #");
	mvwprintw(win, y + 14, x + 1, "####");
	mvwprintw(win, y + 15, x + 0, "##  ##");
	mvwprintw(win, y + 16, x + 1, "#");
	mvwprintw(win, y + 17, x + 0, "##");
}

void		Boss::moveBoss()
{
	if (yStartLeftUp != 1 && up)
	{
		yStartLeftUp--;
	}
	else
	{
		up = 0;
		down = 1;
	}

	if (yStartLeftUp + 18 != (HEIGHT - 1) && down)
	{
		yStartLeftUp++;
	}
	else
	{
		down = 0;
		up = 1;
	}
}

void		Boss::showBoss( WINDOW *win, int y, int x )
{
	xStartLeftUp = x;
	yStartLeftUp = y;

	mvwprintw(win, y + 0, x + 0, "##");
	mvwprintw(win, y + 1, x + 1, "#");
	mvwprintw(win, y + 2, x + 0, "##  ##");
	mvwprintw(win, y + 3, x + 1, "####");
	mvwprintw(win, y + 4, x + 1, "## #");
	mvwprintw(win, y + 5, x + 1, "## #");
	mvwprintw(win, y + 6, x + 1, "####");
	mvwprintw(win, y + 7, x + 0, "##  ##");
	wattron(win, COLOR_PAIR(1) | A_BOLD);
	mvwprintw(win, y + 8, x + 4, "##");
	wattroff(win, COLOR_PAIR(1) | A_BOLD);
	mvwprintw(win, y + 9, x + 4, "##");
	mvwprintw(win, y + 10, x + 0, "##  ##");
	mvwprintw(win, y + 11, x + 1, "####");
	mvwprintw(win, y + 12, x + 1, "## #");
	mvwprintw(win, y + 13, x + 1, "## #");
	mvwprintw(win, y + 14, x + 1, "####");
	mvwprintw(win, y + 15, x + 0, "##  ##");
	mvwprintw(win, y + 16, x + 1, "#");
	mvwprintw(win, y + 17, x + 0, "##");
}
