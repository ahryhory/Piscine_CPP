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
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int raw )
{
	// std::cout << "Int constructor called" << std::endl;
	_rawBits = raw << _numberFractionalBits;
}

Fixed::Fixed( float raw )
{
	// std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf((raw * (1 << _numberFractionalBits)));
}

Fixed::Fixed( Fixed const &copy )
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
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
		_rawBits = rhs._rawBits;

	return *this;
}

bool		Fixed::operator>( Fixed const &rhs)
{
	if (_rawBits > rhs._rawBits)
		return true;
	return false;
}

bool		Fixed::operator<( Fixed const &rhs)
{
	if (_rawBits < rhs._rawBits)
		return true;
	return false;
}

bool		Fixed::operator>=( Fixed const &rhs)
{
	if (_rawBits >= rhs._rawBits)
		return true;
	return false;
}

bool		Fixed::operator<=( Fixed const &rhs)
{
	if (_rawBits <= rhs._rawBits)
		return true;
	return false;
}

bool		Fixed::operator==( Fixed const &rhs)
{
	if (_rawBits == rhs._rawBits)
		return true;
	return false;
}

bool		Fixed::operator!=( Fixed const &rhs)
{
	if (_rawBits != rhs._rawBits)
		return true;
	return false;
}

Fixed		Fixed::operator+( Fixed const &rhs)
{
	Fixed	newFixNum;

	newFixNum._rawBits = _rawBits + rhs._rawBits;
	return newFixNum;
}

Fixed		Fixed::operator-( Fixed const &rhs)
{
	Fixed	newFixNum;

	newFixNum._rawBits = _rawBits - rhs._rawBits;
	return newFixNum;
}

Fixed		Fixed::operator*( Fixed const &rhs)
{
	Fixed	newFixNum(this->toFloat() * rhs.toFloat());
	return newFixNum;
}

Fixed		Fixed::operator/( Fixed const &rhs)
{
	Fixed	newFixNum(this->toFloat() / rhs.toFloat());
	return newFixNum;
}

Fixed		Fixed::operator++( void )
{
	Fixed	newFixNum;

	newFixNum._rawBits = _rawBits + 1;
	this->_rawBits = _rawBits + 1;
	return newFixNum;
}

Fixed		Fixed::operator++( int )
{
	Fixed	newFixNum;

	newFixNum._rawBits = _rawBits;
	this->_rawBits = _rawBits + 1;
	return newFixNum;
}

Fixed		Fixed::operator--( int )
{
	Fixed	newFixNum;

	newFixNum._rawBits = _rawBits;
	this->_rawBits = _rawBits - 1;
	return newFixNum;
}

Fixed		Fixed::operator--( void )
{
	Fixed	newFixNum;

	newFixNum._rawBits = _rawBits - 1;
	this->_rawBits = _rawBits - 1;
	return newFixNum;
}

Fixed const	&Fixed::min( Fixed const &rhs1, Fixed const &rhs2 )
{
	if (rhs1._rawBits < rhs2._rawBits)
		return rhs1;
	return rhs2;
}

Fixed		&Fixed::min( Fixed &rhs1, Fixed &rhs2 )
{
	if (rhs1._rawBits < rhs2._rawBits)
		return rhs1;
	return rhs2;
}

Fixed const	&Fixed::max( Fixed const &rhs1, Fixed const &rhs2 )
{
	if (rhs1._rawBits > rhs2._rawBits)
		return rhs1;
	return rhs2;
}

Fixed		&Fixed::max( Fixed &rhs1, Fixed &rhs2 )
{
	if (rhs1._rawBits > rhs2._rawBits)
		return rhs1;
	return rhs2;
}

int			Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _rawBits;
}

void		Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	_rawBits = raw;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}

int	const Fixed::_numberFractionalBits = 8;
