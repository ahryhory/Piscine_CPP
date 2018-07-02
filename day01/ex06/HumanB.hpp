/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 20:37:41 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/19 20:37:42 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"

class HumanB
{

public:

	HumanB(std::string name);
	HumanB();
	~HumanB();

	Weapon			getWeapon( void );
	void			setWeapon( Weapon &weapon );
	std::string		getName( void );
	void			setName( std::string name );

	void			attack( void );

private:

	Weapon			*_weapon;
	std::string		_name;

};

#endif
