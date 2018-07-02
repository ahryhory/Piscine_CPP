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
#include "NinjaTrap.hpp"
#include "FragTrap.hpp"
# include <ctime>

int		main( void )
{
	{
		NinjaTrap	trap("NinjaTrap");
		ScavTrap	scaf("ScavTrap");
		FragTrap	frag("FragTrap");
		srand(time(NULL));
		trap.ninjaShoebox(scaf);
		trap.meleeAttack("none");
		trap.softAttack("none");
		trap.rangedAttack("none");
		trap.nuclearAttack("none");
		trap.ninjaShoebox(frag);
		trap.beRepaired(50);
		trap.beRepaired(50);
		trap.beRepaired(50);
		trap.beRepaired(50);
		trap.beRepaired(50);
		trap.beRepaired(50);
		trap.ninjaShoebox(trap);
		trap.beRepaired(50);
		trap.nuclearAttack("none");
		trap.nuclearAttack("none");
	}

	return 0;
}
