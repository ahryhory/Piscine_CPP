/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 17:39:57 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/19 17:39:58 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde( int N )
{
	int		i;
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

	if (N > 0)
	{
		this->horde = new Zombie[N];
		this->countHorde = N;
		i = 0;
		while (i < N)
		{
			this->horde[i].setName(textArray[(rand() + i) % 119]);
			this->horde[i].setType("walker");
			i++;
		}
	}
	std::cout << "horde was born" << std::endl;
	this->announce();
}

ZombieHorde::~ZombieHorde()
{
	delete [] this->horde;
	std::cout << "horde was die" << std::endl;
}

void			ZombieHorde::announce( void )
{
	int		i;

	i = 0;
	while (i < this->countHorde)
	{
		this->horde[i].announce();
		i++;
	}
}
