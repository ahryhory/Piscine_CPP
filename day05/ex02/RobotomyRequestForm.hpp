/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 19:58:35 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/25 19:58:36 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "Form.hpp"

class RobotomyRequestForm : public Form
{

public:

	RobotomyRequestForm();
	RobotomyRequestForm( std::string target );
	RobotomyRequestForm( RobotomyRequestForm const & form );
	~RobotomyRequestForm();

	RobotomyRequestForm		&operator=( RobotomyRequestForm const & src );

	void						execute(Bureaucrat const & executor) const;

private:

	int static const	_sign;
	int static const	_exec;

};

#endif
