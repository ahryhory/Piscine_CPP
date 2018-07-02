/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWindow.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlinkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 13:16:33 by dlinkin           #+#    #+#             */
/*   Updated: 2018/06/23 13:16:35 by dlinkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWindow.hpp"

AWindow::AWindow( void ) :
	_width(0),
	_height(0),
	_start_h(0),
	_start_w(0)
{};

AWindow::~AWindow( void ){}

AWindow::AWindow( const AWindow & rhs ) {
	*this = rhs;
}

AWindow::AWindow( int width, int height, int start_w, int start_h ) {
	this->_width = width;
	this->_height = height;
	this->_start_w = start_w;
	this->_start_h = start_h;
}

AWindow &		AWindow::operator=( const AWindow & rhs ) {
	if (this != &rhs) {
		this->_width = rhs._width;
		this->_height = rhs._height;
		this->_start_w = rhs._start_w;
		this->_start_h = rhs._start_h;
	}
	return ( *this );
}

void			AWindow::pause( void ) {
	AWindow::state = 1;
}

void			AWindow::play( void ) {
	AWindow::state = 0;
}

int				AWindow::state = 0;

void			AWindow::setWidth( int width ) {	this->_width = width;	}
void			AWindow::setHeight( int height ) {	this->_height = height;	}
void			AWindow::setStartW( int start_w ) {	this->_start_w = start_w;	}
void			AWindow::setStartH( int start_h ) {	this->_start_h = start_h;	}
int				AWindow::getWidth( void ) {		return (this->_width);	}
int				AWindow::getHeight( void ) {	return (this->_height);	}
int				AWindow::getStartW( void ) {	return (this->_start_w);	}
int				AWindow::getStartH( void ) {	return (this->_start_h);	}
