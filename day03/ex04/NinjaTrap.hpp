/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 16:42:24 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/22 16:42:25 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public virtual ClapTrap
{

public:

	NinjaTrap();
	NinjaTrap(std::string name);
	NinjaTrap( NinjaTrap const & src );
	~NinjaTrap();

	void		ninjaShoebox( NinjaTrap & src );
	void		ninjaShoebox( FragTrap & src );
	void		ninjaShoebox( ScavTrap & src );

	NinjaTrap	&operator=( NinjaTrap const & rhs );

};

#endif
