/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 20:35:00 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/19 20:35:01 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# include <string>

class Weapon
{

public:

	Weapon();
	Weapon(std::string type);
	~Weapon();

	void					setType(std::string type);
	const std::string		&getType( void );

private:

	std::string				_type;
	
};

#endif
