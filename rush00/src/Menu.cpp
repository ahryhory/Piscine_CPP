/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Menu.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlinkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 19:23:06 by dlinkin           #+#    #+#             */
/*   Updated: 2018/06/23 19:23:07 by dlinkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Menu.hpp"
#include "ft_retro.h"

Menu::Menu() {}

Menu::Menu( const char ** array, int arrsize, const char *word ) {
	this->setHeight(7);
	this->setWidth(12);
	this->setStartH(5);
	this->setStartW(8);
	this->current = 0;
	this->menu = array;
	this->size = arrsize;
	this->name = word;
	drawColumn();
	win = newwin(this->getHeight(), this->getWidth(),
		this->getStartH(), this->getStartW());
	box(win, ' ', ' ');
	wbkgd(win, COLOR_BLACK);
	wrefresh(win);
}

Menu::Menu( Menu const & rhs ) {
	*this = rhs;
}

Menu::~Menu() {
	wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(win);
	refresh();
	delwin(win);
}

Menu &		Menu::operator=( const Menu & rhs ) {
	if (this != &rhs) {
		this->menu = rhs.menu;
		this->size = rhs.size;
	}
	return *this;
}

void		Menu::redraw( int command ) {
	if ( command == -1 )
	{
		if (current == 0)
			current = size;
		current--;
	}
	else if ( command == -2 )
	{
		if (current == size - 1)
			current = -1;
		current++;
	}
	box(win, ' ', ' ');
	wbkgd(win, COLOR_BLACK);
	wattron(win, A_UNDERLINE);
	mvwprintw(win, 1, 2, name);
	wattroff(win, A_UNDERLINE);
	for ( int i = 0; i < size; i++) {
		if (i == current)
			wattron(win, A_REVERSE);
		mvwprintw(win, 3 + i, 2, menu[i]);
		wattroff(win, A_REVERSE);
	}
	wrefresh(win);
}

int			Menu::getItem() {
	int c;

	this->redraw(0);
	timeout(-1);
	while((c = getch()))
	{
		if (c == KEY_UP || c == KEY_DOWN)
			return (c - 260);
		else if (c == 10)
			return (current + 1);
	}
	return (0);
}

void		drawColumn(void)
{
	int i = 0;

	while (i < 25) {
		mvwprintw(stdscr, i, 10, "||####||");
		i++;
	}
	refresh();
}
