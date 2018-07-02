/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:06:19 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/29 16:06:20 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:

		MutantStack(void) {}
		MutantStack(MutantStack const & o): std::stack<T>(o) {}
		~MutantStack(void) {}

		typedef typename std::stack<T>::container_type::iterator iterator;

		using		std::stack<T>::operator=;

		iterator	begin() { return std::stack<T>::c.begin(); }
		iterator	end() { return std::stack<T>::c.end() ; }
};

#endif
