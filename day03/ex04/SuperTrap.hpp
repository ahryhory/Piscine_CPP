/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 20:29:21 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/22 20:29:22 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP
# include <iostream>
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap : public NinjaTrap, public FragTrap
{

public:

	SuperTrap();
	SuperTrap(std::string name);
	SuperTrap( SuperTrap const & src );
	~SuperTrap();

	SuperTrap	&operator=( SuperTrap const & rhs );

	void			rangedAttack( std::string const & target );
	void			meleeAttack( std::string const & target );

};

#endif
