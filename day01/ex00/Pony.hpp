/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 12:54:57 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/19 12:54:58 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP
# include <iostream>

class Pony
{

public:

	Pony();
	~Pony();

	static Pony		*ponyOnTheHeap( void );
	static Pony		ponyOnTheStack( void );

	int				getAge( void ) const;
	std::string		getName( void ) const;
	void			setAge(int age);
	void			setName(std::string name);

private:

	int				_age;
	std::string		_name;

};

#endif
