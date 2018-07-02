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

	bool		operator>( Fixed const &rhs);
	bool		operator<( Fixed const &rhs);
	bool		operator>=( Fixed const &rhs);
	bool		operator<=( Fixed const &rhs);
	bool		operator==( Fixed const &rhs);
	bool		operator!=( Fixed const &rhs);

	Fixed		operator+( Fixed const &rhs);
	Fixed		operator-( Fixed const &rhs);
	Fixed		operator*( Fixed const &rhs);
	Fixed		operator/( Fixed const &rhs);

	Fixed		operator++( void );
	Fixed		operator++( int );
	Fixed		operator--( int );
	Fixed		operator--( void );

	static Fixed const	&min( Fixed const &rhs1, Fixed const &rhs2 );
	static Fixed		&min( Fixed &rhs1, Fixed &rhs2 );
	static Fixed const	&max( Fixed const &rhs1, Fixed const &rhs2 );
	static Fixed		&max( Fixed &rhs1, Fixed &rhs2 );

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
