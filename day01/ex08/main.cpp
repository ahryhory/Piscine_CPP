/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:38:16 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/20 14:38:17 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int		main( void )
{
	Human human;

	human.action("meleeAttack", "none");
	human.action("rangedAttack", "none");
	human.action("intimidatingShout", "none");
	human.action("intimidatingShout", "none");
	human.action("rangedAttack", "none");
	human.action("meleeAttack", "none");
	return 0;
}
