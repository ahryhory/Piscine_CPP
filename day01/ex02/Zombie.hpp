/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:10:12 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/19 15:10:12 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>

class Zombie
{

public:

	Zombie(std::string name, std::string type);
	Zombie();
	~Zombie();

	void			setType(std::string type);
	void			setName(std::string name);
	std::string		getType( void );
	std::string		getName( void );

	void			announce( void );

private:

	std::string		_type;
	std::string		_name;

};

#endif
