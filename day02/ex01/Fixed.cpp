/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:53:23 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/20 17:53:24 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int raw )
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = raw << _numberFractionalBits;
}

Fixed::Fixed( float raw )
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf((raw * (1 << _numberFractionalBits)));
}

Fixed::Fixed( Fixed const &copy )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float		Fixed::toFloat( void ) const
{
	return ((float)_rawBits / (1 << _numberFractionalBits));
}

int			Fixed::toInt( void ) const
{
	return _rawBits >> _numberFractionalBits;
}

Fixed		&Fixed::operator=( Fixed const &rhs )
{
	std::cout << "Assignation operator called" << std::endl;

	if (this != &rhs)
		this->_rawBits = rhs._rawBits;

	return *this;
}

int			Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

void		Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}

int	const Fixed::_numberFractionalBits = 8;
