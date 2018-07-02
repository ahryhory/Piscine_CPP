/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:10:19 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/19 15:10:20 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent()
{
	this->_zombieType = "unknown";
}

ZombieEvent::~ZombieEvent()
{
}

void			ZombieEvent::randomChump( void )
{
	std::string	textArray[119] = {"BITERS", "COLD BODIES", "CREEPER", "DEAD ONES", "Danny Elfman", "SKIN EATER", "Dr. Jack’s Dad", "Hellspawn",
	"Reanimated Marshall", "Jawbone", "Unknown Zombie", "Mr. Dead", "St. Jimmy", "Stormcrow", "Mr. Dead", "St. Jimmy", "Stormcrow",
	"CREEPER", "Spent Kent", "Hello Gimpy", "Drew Blood", "GEEK", "SKIN EATER", "WALKER", "Hellspawn", "Mr. Dead", "St. Jimmy",
	"Rotten Robbie", "Moaning Jaeyaena", "The Worm King", "CREEPER", "GEEK", "SKIN EATER", "Price Albert", "Hellspawn", "Buttered Brains", "Keening McShean",
	"Reanimated Marshall", "Jawbone", "Unknown Zombie", "Mr. Dead", "St. Jimmy", "Stormcrow", "Mr. Dead", "St. Jimmy", "Stormcrow",
	"Tyler Chain Link", "Trent Reznor", "Spaceman Skull", "Marion Carrion", "Milky Stare", "SKIN EATER", "WALKER", "Hellspawn", "Mr. Dead",
	"The Duke", "DEAD ONES", "Triage Terry", "Melter", "GEEK", "Limp", "WALKER", "Hellspawn", "Son-Goku", "CREEPER",
	"Reanimated Marshall", "Jawbone", "Unknown Zombie", "Mr. Dead", "St. Jimmy", "Stormcrow", "Mr. Dead", "St. Jimmy", "Stormcrow",
	"Cannibal", "DEAD ONES", "Alex Murphy", "Shambler", "Ol’ Green Scalp", "Triage Terry", "WALKER", "Hellspawn", "Mr. Dead", "St. Jimmy",
	"Stinker", "Determined Zhi", "Scar", "Crawler", "Bloodthirsty Phoebe", "The Dank Yank", "Pincher", "Hellspawn", "The Screech", "CREEPER",
	"Reanimated Marshall", "Jawbone", "Unknown Zombie", "Mr. Dead", "St. Jimmy", "Stormcrow", "Mr. Dead", "St. Jimmy", "Stormcrow",
	"Crier", "Dangling Chad", "Dancing Qualia", "Stinker", "The Tumor King", "SKIN EATER", "Drew Blood", "Hellspawn", "Mr. Dead",
	"Felicia Mentor", "DEAD ONES", "Pinin’ for the Fjords", "Principal Skinned", "Crier", "SKIN EATER", "Revenant William "};
	Zombie		randomZombie = Zombie(textArray[rand() % 119], "unknown");
	randomZombie.announce();
}

void			ZombieEvent::setZombieType(std::string type)
{
	this->_zombieType = type;
}

std::string		ZombieEvent::getZombieType( void )
{
	return (this->_zombieType);
}

Zombie			*ZombieEvent::newZombie(std::string name)
{
	Zombie		*zombie = new Zombie(name, this->_zombieType);
	return (zombie);
}
