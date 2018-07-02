/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:38:06 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/20 14:38:08 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

void Human::meleeAttack(std::string const & target)
{
	std::cout << "meleeAttack         target: " << target << std::endl;
}

void Human::rangedAttack(std::string const & target)
{
	std::cout << "rangedAttack        target: " << target << std::endl;
}

void Human::intimidatingShout(std::string const & target)
{
	std::cout << "intimidatingShout   target: " << target << std::endl;
}

void Human::action(std::string const & action_name, std::string const & target)
{
	typedef void (Human::*Act)(std::string const & target);
	Act act[3] = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};
	std::string actName[] = {"meleeAttack", "rangedAttack", "intimidatingShout"};

	int	i;
	i = 0;
	while (i < 3)
	{
		if (actName[i] == action_name)
		{
			(this->*(act[i]))(target);
			break ;
		}
		i++;
	}
}
