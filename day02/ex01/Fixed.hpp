/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:53:32 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/20 17:53:33 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H
# include <iostream>
# include <cmath>

class Fixed
{

public:

	Fixed();
	Fixed( int raw );
	Fixed( float raw );
	Fixed( Fixed const & copy);
	~Fixed();

	Fixed		&operator=( Fixed const &rhs);
	float		toFloat( void ) const;
	int			toInt( void ) const;
	int			getRawBits( void ) const;
	void		setRawBits( int const raw );

private:

	int						_rawBits;
	static const int		_numberFractionalBits;

};

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs);

#endif
