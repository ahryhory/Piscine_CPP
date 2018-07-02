/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 17:50:41 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/27 17:50:41 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>

class Base
{

public:

	virtual ~Base(){}

};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

Base	*generate(void)
{
	if (std::rand() % 2 == 0)
		return new A;
	else if (std::rand() % 3 == 0)
		return new B;
	else
		return new C;
}

void identify_from_pointer( Base * p )
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B" << std::endl;
	else
		std::cout << "C" << std::endl;
}

void identify_from_reference( Base & p )
{
	if (dynamic_cast<A *>(&p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(&p) != NULL)
		std::cout << "B" << std::endl;
	else
		std::cout << "C" << std::endl;
}

int		main()
{
	Base	*b;

	std::srand(std::time(NULL));
	b = generate();
	identify_from_pointer(b);
	identify_from_reference(*b);
	return 0;
}
