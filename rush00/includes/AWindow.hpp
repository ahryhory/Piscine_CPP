/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWindow.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlinkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 13:10:18 by dlinkin           #+#    #+#             */
/*   Updated: 2018/06/23 13:10:19 by dlinkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class AWindow
{

private:
	int			_width;
	int			_height;
	int			_start_h;
	int			_start_w;

public:
	AWindow( void );
	virtual ~AWindow( void );
	AWindow( const AWindow & rhs );
	AWindow( int width, int height, int start_w, int start_h );

	AWindow &		operator=( const AWindow & rhs );
	void			pause( void );
	void			play( void );

	void			setWidth( int width );
	void			setHeight( int height );
	void			setStartW( int start_w );
	void			setStartH( int start_h );
	int				getWidth( void );
	int				getHeight( void );
	int				getStartW( void );
	int				getStartH( void );
	static int		state;

};