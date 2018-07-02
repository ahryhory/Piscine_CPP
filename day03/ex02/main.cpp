/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:00:51 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/21 19:00:52 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
# include <ctime>

int		main( void )
{
	{
		ScavTrap	trap("ScavTrap");
		srand(time(NULL));
		trap.challengeNewcomer("none");
		trap.meleeAttack("none");
		trap.softAttack("none");
		trap.rangedAttack("none");
		trap.nuclearAttack("none");
		trap.challengeNewcomer("none");
		trap.beRepaired(50);
		trap.beRepaired(50);
		trap.beRepaired(50);
		trap.beRepaired(50);
		trap.beRepaired(50);
		trap.beRepaired(50);
		trap.challengeNewcomer("none");
		trap.beRepaired(50);
		trap.nuclearAttack("none");
		trap.nuclearAttack("none");
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	{
		FragTrap	trap("FragTrap");
		srand(time(NULL));
		trap.vaulthunter_dot_exe("none");
		trap.meleeAttack("none");
		trap.softAttack("none");
		trap.rangedAttack("none");
		trap.nuclearAttack("none");
		trap.vaulthunter_dot_exe("none");
		trap.beRepaired(50);
		trap.beRepaired(50);
		trap.beRepaired(50);
		trap.beRepaired(50);
		trap.beRepaired(50);
		trap.beRepaired(50);
		trap.vaulthunter_dot_exe("none");
		trap.beRepaired(50);
		trap.nuclearAttack("none");
		trap.nuclearAttack("none");
	}

	return 0;
}
