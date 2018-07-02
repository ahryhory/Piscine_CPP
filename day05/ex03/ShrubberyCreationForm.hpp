/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 19:58:18 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/25 19:58:18 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form
{

public:

	ShrubberyCreationForm();
	ShrubberyCreationForm( std::string target );
	ShrubberyCreationForm( ShrubberyCreationForm const & form );
	~ShrubberyCreationForm();

	ShrubberyCreationForm		&operator=( ShrubberyCreationForm const & src );

	void						execute(Bureaucrat const & executor) const;

private:

	int static const	_sign;
	int static const	_exec;

};

#endif
