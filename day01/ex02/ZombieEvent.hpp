/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:10:26 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/19 15:10:27 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP
# include <iostream>
# include <string>
# include "Zombie.hpp"

class ZombieEvent
{

public:

	ZombieEvent();
	~ZombieEvent();

	void			setZombieType(std::string type);
	std::string		getZombieType( void );
	void			randomChump( void );
	Zombie			*newZombie(std::string name);

private:

	std::string		_zombieType;

};

#endif
