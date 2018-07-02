/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:00:25 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/21 19:00:26 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>

class FragTrap
{

public:

	FragTrap();
	FragTrap(std::string name);
	FragTrap( FragTrap const & src );
	~FragTrap();

	FragTrap	&operator=( FragTrap const & rhs );

	void	meleeAttack( std::string const & target );
	void	rangedAttack( std::string const & target );
	void	softAttack( std::string const & target );
	void	nuclearAttack( std::string const & target );
	void	sprintAttack( std::string const & target );

	void	vaulthunter_dot_exe(std::string const & target);

	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );

	int				getHitPoints( void );
	int				getMaxHitPoints( void );
	int				getEnergyPoints( void );
	int				getMaxEnergyPoints( void );
	int				getLevel( void );
	int				getSoftAttackDamage( void );
	int				getMeleeAttackDamage( void );
	int				getSprintAttackDamage( void );
	int				getRangedAttackDamage( void );
	int				getNuclearAttackDamage( void );
	int				getArmorDamageReduction( void );
	std::string		getName( void );

private:

	int				_hitPoints;
	int				_maxHitPoints;
	int				_energyPoints;
	int				_maxEnergyPoints;
	int				_level;
	int				_softAttackDamage;
	int				_meleeAttackDamage;
	int				_sprintAttackDamage;
	int				_rangedAttackDamage;
	int				_nuclearAttackDamage;
	int				_armorDamageReduction;
	std::string		_name;

};

#endif
