/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scene.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 12:27:54 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/23 12:27:55 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scene.hpp"

Scene::Scene() {
	erase();
	this->setHeight(HEIGHT);
	this->setWidth(WIDTH);
	this->setStartH(0);
	this->setStartW(0);
	win = newwin(this->getHeight(), this->getWidth(),
		this->getStartH(), this->getStartW());
	ship = new Ship( this->getHeight() / 2, 1 );
	projectiles = new Projectile[NUM_PRJCTLS];
	enemies = new Enemy[NUM_ENMS];
	this->makeSpace();
	gift = new Object;
	boss = new Boss;
	score = 0;
	step = 0;
	time = 0;
}

Scene::Scene( Scene const & src ) {
	*this = src;
}

Scene::~Scene() {
	delete ship;
	delete boss;
	delete gift;
	delete [] projectiles;
	delete [] enemies;
	delete [] particles;
	wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(win);
	delwin(win);
	erase();
	refresh();
}

Scene &		Scene::operator=( const Scene & rhs ) {
	if (this != &rhs)
		;
	return *this;
}

void		Scene::drawEnemy()
{
	for (int i = 0; i < NUM_ENMS; i++)
	{
		if (enemies[i].real)
		{
			if (enemies[i].shoot == 1)
				wattron(win, COLOR_PAIR(6) | A_BOLD);
			else if (enemies[i].speed == 2)
				wattron(win, COLOR_PAIR(5) | A_BOLD);
			else if (enemies[i].live == 1)
				wattron(win, COLOR_PAIR(1) | A_BOLD);
			else
				wattron(win, COLOR_PAIR(4) | A_BOLD);
			mvwprintw(win, enemies[i].y, enemies[i].x, "@");
			if (enemies[i].shoot == 1 && std::rand() % 23 == 0)
				Projectile::addProjectile(projectiles, enemies[i].y, enemies[i].x - 4, 1);
			if (enemies[i].shoot == 1)
				wattroff(win, COLOR_PAIR(6) | A_BOLD);
			else if (enemies[i].speed == 2)
				wattroff(win, COLOR_PAIR(5) | A_BOLD);
			else if (enemies[i].live == 1)
				wattroff(win, COLOR_PAIR(1) | A_BOLD);
			else
				wattroff(win, COLOR_PAIR(4) | A_BOLD);
			if (enemies[i].live == 2 && step % 3 == 0)
				enemies[i].move(0, -1);
			else if ((step % 2 == 0 || enemies[i].speed == 2) && enemies[i].live != 2)
				enemies[i].move(0, -1);
			if (enemies[i].x == -1)
				enemies[i].real = 0;
		}
	}
}

void		Scene::drawGift()
{
	wattron(win, COLOR_PAIR(2) | A_BOLD);
	mvwprintw(win, gift->y, gift->x, "*");
	if (step % 2 == 0)
		gift->move(0, -1);
	if (gift->x == -1)
		gift->real = 0;
	wattroff(win, COLOR_PAIR(2) | A_BOLD);
}


void		Scene::drawProjectiles()
{
	for (int i = 0; i < NUM_PRJCTLS; i++)
	{
		if (projectiles[i].real)
		{
			if (projectiles[i].type)
			{
				wattron(win, COLOR_PAIR(6) | A_BOLD);
				mvwprintw(win, projectiles[i].y, projectiles[i].x, "-");
				projectiles[i].move(0, -1);
				if (projectiles[i].x == -1)
					projectiles[i].real = 0;
				wattroff(win, COLOR_PAIR(6) | A_BOLD);
			}
			else
			{
				wattron(win, COLOR_PAIR(2) | A_BOLD);
				mvwprintw(win, projectiles[i].y, projectiles[i].x, "-");
				if (step % 2 == 0)
					projectiles[i].move(0, 1);
				if (projectiles[i].x == WIDTH)
					projectiles[i].real = 0;
				wattroff(win, COLOR_PAIR(2) | A_BOLD);
			}
		}
	}
}

void		Scene::addGift()
{
	gift->x = WIDTH;
	gift->y = std::rand() % HEIGHT;
	gift->real = 1;
}

void		Scene::tickTock()
{
	if (step == 50)
	{
		time++;
		if (ship->fire > 0)
			ship->fire--;
		if (ship->reload > 0)
			ship->reload--;
		step = 0;
	}
}

void		Scene::check()
{
	if ((gift->x == ship->x || gift->x == ship->x + 1) && gift->y == ship->y && gift->real)
	{
		ship->live++;
		gift->real = 0;
	}
	for (int i = 0; i < NUM_ENMS; i++)
	{
		if ((enemies[i].x == ship->x || enemies[i].x == ship->x + 1) && enemies[i].y == ship->y && enemies[i].real)
		{
			ship->live--;
			enemies[i].real = 0;
		}
		for (int j = 0; j < NUM_PRJCTLS; j++)
		{
			if ((projectiles[j].x == boss->xStartLeftUp + 4 || projectiles[j].x == boss->xStartLeftUp + 5) &&
				projectiles[j].y == boss->yStartLeftUp + 8 && boss->real)
			{
				score += 10000;
				boss->real = 0;
			}
			if ((projectiles[j].x == ship->x || projectiles[j].x == ship->x + 1) && projectiles[j].y == ship->y && projectiles[j].real)
			{
				ship->live--;
				projectiles[j].real = 0;
			}
			if (projectiles[j].y == enemies[i].y && (projectiles[j].x + 1 == enemies[i].x ||
				projectiles[j].x == enemies[i].x) && projectiles[j].real && enemies[i].real)
			{
				projectiles[j].real = 0;
				enemies[i].live--;
				if (enemies[i].live == 0)
				{
					enemies[i].real = 0;
					mvwprintw(win, enemies[i].y, enemies[i].x, "*");
				}
				score += 10;
				break ;
			}
		}
	}
}

int			Scene::redraw( int command )
{
	werase(win);
	this->drawSpace();
	step++;
	tickTock();
	ship->shipMove( command );
	if (command == 32 && !ship->reload)
		ship->shoot(projectiles);
	if (std::rand() % 9 == 0 && !boss->real)
		Enemy::addEnemy(enemies, boss);
	if (boss->real && step % 7 == 0)
		Enemy::addEnemy(enemies, boss);
	if (time && time % 20 == 0)
		addGift();
	check();
	if (score % 500 == 0 && !boss->real && score)
	{
		boss->showBoss(win, HEIGHT / 2, WIDTH - 8);
		boss->real = 1;
		boss->up = 1;
		boss->down = 0;
		score++;
	}
	if (step % 2 == 0)
		boss->moveBoss();
	if (boss->real)
		boss->drawBoss(win);
	if (ship->live <= 0)
		return 0;
	drawProjectiles();
	if (gift->real)
		drawGift();
	drawEnemy();
	mvwprintw(win, ship->y, ship->x, ">");
	box(win, 0, 0);
	mvwprintw(win, 1, 1, "Score: %d", score);
	mvwprintw(win, 2, 1, "Time: %d", time);
	mvwprintw(win, 3, 1, "Live: %d", ship->live);
	wrefresh(win);
	return 1;
}

void		Scene::makeSpace(void) {
	particles = new Object[NUM_PRTCLS];
	for (int i = 0; i < NUM_PRTCLS; i++)
	{
		particles[i].x = std::rand() % (WIDTH - 2) + 1;
		particles[i].y = std::rand() % (HEIGHT - 2) + 1;
		particles[i].real = std::rand() % 4;
	}
}

void		Scene::drawSpace(void) {
	const char *part[4] = {"-", ".", "__", "_"};

	wattron(win, COLOR_PAIR(7));
	for (int i = 0; i < NUM_PRTCLS; i++)
	{
		mvwprintw(win, particles[i].y, particles[i].x, part[particles[i].real]);
		if (particles[i].x-- == 0) {
			particles[i].x = WIDTH - 1;
			particles[i].y = std::rand() % (HEIGHT - 2) + 1;
		}
	}
	wattroff(win, COLOR_PAIR(7));
}

std::string		Scene::getResult()
{
	std::ostringstream	conv;
	char		input[11];

	conv << score;
	werase(win);
	mvwprintw(win, 5, WIDTH / 2 - 5, "GAME OVER");
	mvwprintw(win, 6, WIDTH / 2 - 9, "YOUR SCORE: ");
	mvwprintw(win, 6, WIDTH / 2 + 3, conv.str().c_str());
	mvwprintw(win, 8, WIDTH / 2 - 13, "ENTER YOUR NAME, PILOT!");
	wrefresh(win);
	sleep(1);
	timeout(-1);
	flushinp();
	curs_set(1);
	echo();
	mvwgetnstr(win, 8, WIDTH / 2 + 11, input, 10);
	input[10] = 0;
	noecho();
	curs_set(0);

	std::string out(input);
	return (out + " : " + conv.str());
}
