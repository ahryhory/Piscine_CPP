/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:00:25 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/21 19:00:26 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

public:

	FragTrap();
	FragTrap(std::string name);
	FragTrap( FragTrap const & src );
	~FragTrap();

	FragTrap	&operator=( FragTrap const & rhs );

	void	vaulthunter_dot_exe(std::string const & target);

};

#endif
