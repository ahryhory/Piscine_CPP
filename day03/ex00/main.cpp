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

#include "FragTrap.hpp"
# include <ctime>

int		main( void )
{
	FragTrap	trap("1");
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

	return 0;
}
