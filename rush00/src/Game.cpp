/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlinkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 15:27:03 by dlinkin           #+#    #+#             */
/*   Updated: 2018/06/23 15:27:04 by dlinkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "Scene.hpp"
#include "Menu.hpp"
#include "ft_retro.h"

short		Game::r = 0;
short		Game::g = 0;
short		Game::b = 0;
std::string Game::records[NUM_RECORDS];

Game::Game( void ){}
Game::~Game( void ){}
Game::Game( const Game & rhs ) {
	*this = rhs;
}

Game &		Game::operator=( const Game & rhs ) {
	if ( this != &rhs )
		;
	return ( *this );
}

void		Game::addRecord( std::string newOne ) {
	int		len;

	for (len = 0; len < NUM_RECORDS; len++) {
		if (records[len].empty())
			break;
	}
	if (len < NUM_RECORDS)
		records[len] = newOne;
	else {
		for(int i = 0; i < NUM_RECORDS - 1; i++) {
			records[i] = records[i + 1];
		}
		records[NUM_RECORDS - 1] = newOne;
	}
}

void		Game::showRecords(void) {
	WINDOW	*win = newwin(HEIGHT, WIDTH, 0, 0);
	int		i;

	mvwprintw(win, 5, WIDTH / 2 - 10, "LAST RECORDS");
	for (i = 0; i < NUM_RECORDS; i++) {
		if (records[i].empty())
			break;
		mvwprintw(win, 7 + i, WIDTH / 2 - 10, records[i].c_str());
	}
	curs_set(1);
	mvwprintw(win, 8 + i, WIDTH / 2 - 10, "PRESS ANY KEY");
	wrefresh(win);
	sleep(1);
	flushinp();
	timeout(-1);
	getch();
	curs_set(0);
	erase();
	wrefresh(win);
	refresh();
	delwin(win);
}

void		Game::newGame( void ) {
	Scene	win;
	int 	c = 0;

	while (1)
	{
		if (AWindow::state == 1 && Game::pauseMenu() == 0)
			break;
		timeout(0);
		c = getch();
		flushinp();
		usleep(SPEED);
		if ( c == 27 && Game::pauseMenu() == 0 )
			break;
		if (win.redraw(c) == 0)
		{
			Game::addRecord(win.getResult());
			break;
		}
	}
}

void		Game::menu( void ) {
	const char	*array[3] = {
		"New Game",
	 	"Records",
	 	"Exit"
	};
	Menu	*mn = new Menu(array, 3, "##MENU");
	int		i;

	while ((i = mn->getItem())) {
		if (i == 3)
			break;
		else if (i == 2) {
			Game::showRecords();
			mn->redraw(0);
			drawColumn();
		}
		else if (i == 1) {
			Game::newGame();
			Menu::Menu(array, 3, "##MENU");
		}
		if (i == -1 || i == -2)
			mn->redraw(i);
	}
	delete mn;
}

int			Game::pauseMenu( void ) {
	const char	*array[2] = {
		"Continue",
	 	"Exit"
	};
	Menu	*mn = new Menu(array, 2, "##PAUSE");
	int		i;

	while ((i = mn->getItem())) {
		if (i == 2)
		{
			delete mn;
			return (0);
		}
		else if (i == 1)
			break;
		else if (i == -1 || i == -2)
			mn->redraw(i);
	}
	delete mn;
	return (1);
}

void	sigWinch(int signo) {
	struct winsize wn;

	if (signo != 28)
		return;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &wn);
	if (wn.ws_row < 25 || wn.ws_col < 80) {
		if (AWindow::state == 0) {
			AWindow::state = 1;
			def_prog_mode();
			endwin();
			std::cerr << "\e[31mWindow is too small, please resize it\e[0m" << std::endl;
		}
	}
	else
	{
		if (AWindow::state == 1) {
			AWindow::state = 0;
			reset_prog_mode();
			refresh();
		}
	}
}

void			Game::start( void ) {
	initscr();
	noecho();
	srand(time(NULL));
	curs_set(0);
	keypad(stdscr, TRUE);
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_BLACK, COLOR_YELLOW);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_GREEN, COLOR_BLACK);
	refresh();
	Game::saveColor();
	attron(COLOR_PAIR(1));
	signal(SIGWINCH, sigWinch);
}

void			Game::end( void ) {
	Game::restoreColor();
	attroff(COLOR_PAIR(1));
	endwin();
}

void			Game::saveColor(void) {
	short	er;
	short	ji;
	short	be;

	color_content(COLOR_GREEN, &er, &ji, &be);
	Game::r = er;
	Game::g = ji;
	Game::b = be;
	init_color(COLOR_GREEN, 150, 150, 150);
}

void			Game::restoreColor(void) {
	init_color(COLOR_GREEN, Game::r, Game::g, Game::b);
}

///RESULT

