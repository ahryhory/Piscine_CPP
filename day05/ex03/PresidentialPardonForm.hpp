/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 19:58:47 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/25 19:58:48 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "Form.hpp"

class PresidentialPardonForm : public Form
{

public:

	PresidentialPardonForm();
	PresidentialPardonForm( std::string target );
	PresidentialPardonForm( PresidentialPardonForm const & form );
	~PresidentialPardonForm();

	PresidentialPardonForm		&operator=( PresidentialPardonForm const & src );

	void						execute(Bureaucrat const & executor) const;

private:

	int static const	_sign;
	int static const	_exec;

};

#endif
