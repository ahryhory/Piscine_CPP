/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 20:37:32 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/19 20:37:32 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"

class HumanA
{

public:

	HumanA(std::string name, Weapon &weapon);
	~HumanA();

	Weapon			getWeapon( void );
	std::string		getName( void );
	void			setName( std::string name );

	void			attack( void );

private:

	Weapon			&_weapon;
	std::string		_name;

};

#endif
