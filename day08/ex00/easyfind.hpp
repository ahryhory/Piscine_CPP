/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 12:15:25 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/29 12:15:26 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>

template<typename T>
bool	easyfind(T const & container, int const & p)
{
	if (std::find(container.begin(), container.end(), p) == container.end())
		return false;
	return true;
}

#endif
