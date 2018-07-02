/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:30:23 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/28 14:30:24 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <stdexcept>

template<typename T = int>
class Array
{

public:

	Array<T>() : _size(0), _arr(NULL)
	{
	}

	Array<T>( unsigned int n ) : _size(n), _arr(NULL)
	{
		if (n == 0)
			_arr = NULL;
		else
			_arr = new T[n];
	}

	Array<T>( Array<T> const & arr )
	{
		*this = arr;
	}

	~Array<T>()
	{
		if (_arr != NULL)
			delete [] _arr;
	}

	unsigned int	size()
	{
		return _size;
	}

	T				&operator[]( unsigned int index )
	{
		if (index >= _size)
			throw std::range_error("range_error");
		else
			return _arr[index];
	}

	Array<T>		&operator=( Array<T> const & arr )
	{
		if (this != &arr)
		{
			this->_size = arr._size;
			if (this->_arr != NULL)
				delete [] this->_arr;
			this->_arr = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++)
			{
				this->_arr[i] = arr._arr[i];
			}
		}

		return *this;
	}

private:

	unsigned int	_size;
	T				*_arr;

};

#endif
