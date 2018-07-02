/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 18:31:56 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/19 18:31:57 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP
# include "Brain.hpp"

class Human
{

public:

	Human();
	~Human();

	const Brain		&getBrain( void );

	std::string	identify( void );

private:

	const Brain	_brain;

};

#endif
