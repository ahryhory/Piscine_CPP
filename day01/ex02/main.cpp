/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:10:33 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/19 15:10:34 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int			main( void )
{
	Zombie			*zombie1;
	Zombie			*zombie2;
	ZombieEvent		event;

	event.setZombieType("N-47");
	zombie1 = event.newZombie("Carl");
	zombie2 = event.newZombie("Dead meat");
	zombie1->announce();
	zombie2->announce();
	srand(time(NULL));
	event.randomChump();
	event.randomChump();
	event.randomChump();
	delete zombie1;
	delete zombie2;
	return (0);
}
