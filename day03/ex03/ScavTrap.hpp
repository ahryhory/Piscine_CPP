/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:43:51 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/22 13:43:51 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

public:

	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap( ScavTrap const & src );
	~ScavTrap();

	ScavTrap	&operator=( ScavTrap const & rhs );

	void	challengeNewcomer(std::string const & target);

};

#endif
