/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 16:06:46 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/22 16:06:47 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _hitPoints(100), _maxHitPoints(100), _energyPoints(100),
_maxEnergyPoints(100), _level(1), _softAttackDamage(5), _meleeAttackDamage(30), _sprintAttackDamage(35),
_rangedAttackDamage(20), _nuclearAttackDamage(65), _armorDamageReduction(5)
{
	std::cout << std::endl << "ClapTrap was born !" << std::endl;
	_name = name;
}

ClapTrap::ClapTrap() : _hitPoints(100), _maxHitPoints(100), _energyPoints(100),
_maxEnergyPoints(100), _level(1), _softAttackDamage(5), _meleeAttackDamage(30), _sprintAttackDamage(35),
_rangedAttackDamage(20), _nuclearAttackDamage(65), _armorDamageReduction(5), _name("none")
{
	std::cout << std::endl << "ClapTrap was born !" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const &src )
{
	*this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout << std::endl << "ClapTrap was dead !" << std::endl;
}

void		ClapTrap::softAttack( std::string const & target )
{
	if (_energyPoints != 0 && _hitPoints != 0)
	{
		std::cout << std::endl << _name << " <" << _name << "> attacks <" << target << "> soft attack, causing <" << _softAttackDamage << "> points of damage !" << std::endl;
		_energyPoints -= 1;
	}
	else
	{
		if (_hitPoints == 0)
			std::cout << std::endl << "No hit points !" << std::endl;
		else
			std::cout << std::endl << "No energy points for soft attack!" << std::endl;
	}
}

void		ClapTrap::meleeAttack( std::string const & target )
{
	if (_energyPoints >= 20 && _hitPoints != 0)
	{
			std::cout << std::endl << _name << " <" << _name << "> attacks <" << target << "> at melee, causing <" << _meleeAttackDamage << "> points of damage !" << std::endl;
			_energyPoints -= 20;
	}
	else
	{
		if (_hitPoints == 0)
			std::cout << std::endl << "No hit points !" << std::endl;
		else
			std::cout << std::endl << "No energy points for melee attack!" << std::endl;
	}
}

void		ClapTrap::rangedAttack( std::string const & target )
{
	if (_energyPoints >= 10 && _hitPoints != 0)
	{
		std::cout << std::endl << _name << " <" << _name << "> attacks <" << target << "> at range, causing <" << _rangedAttackDamage << "> points of damage !" << std::endl;
		_energyPoints -= 10;
	}
	else
	{
		if (_hitPoints == 0)
			std::cout << std::endl << "No hit points !" << std::endl;
		else
			std::cout << std::endl << "No energy points for ranged attack!" << std::endl;
	}
}

void		ClapTrap::sprintAttack( std::string const & target )
{
	if (_energyPoints >= 25 && _hitPoints != 0)
	{
		std::cout << std::endl << _name << " <" << _name << "> attacks <" << target << "> sprint attack, causing <" << _sprintAttackDamage << "> points of damage !" << std::endl;
		_energyPoints -= 25;
	}
	else
	{
		if (_hitPoints == 0)
			std::cout << std::endl << "No hit points !" << std::endl;
		else
			std::cout << std::endl << "No energy points for sprint attack!" << std::endl;
	}
}

void		ClapTrap::nuclearAttack( std::string const & target )
{
	if (_energyPoints >= 90 && _hitPoints != 0)
	{
		std::cout << std::endl << _name << " <" << _name << "> attacks <" << target << "> nuclear attack, causing <" << _nuclearAttackDamage << "> points of damage !" << std::endl;
		_energyPoints -= 90;
	}
	else
	{
		if (_hitPoints == 0)
			std::cout << std::endl << "No hit points !" << std::endl;
		else
			std::cout << std::endl << "No energy points for nuclear attack!" << std::endl;
	}
}

void		ClapTrap::takeDamage( unsigned int amount )
{
	if ((int)amount > _armorDamageReduction)
	{
		amount -= _armorDamageReduction;
		if (_hitPoints - amount > 0)
		{
			std::cout << std::endl << _name << " take " << amount << "damage" << std::endl;
			_hitPoints -= amount;
			std::cout << _hitPoints << " hit points" << std::endl;
		}
		else
		{
			_hitPoints = 0;
			std::cout << std::endl << "0 hit points !" << std::endl;
		}
	}
}

void		ClapTrap::beRepaired( unsigned int amount )
{
	std::cout << std::endl << _name << " Repair" << std::endl;
	if (_hitPoints + (int)amount <= _maxHitPoints)
		_hitPoints += amount;
	else
		_hitPoints = _maxHitPoints;
	std::cout << _hitPoints << " hit points" << std::endl;
	if (_energyPoints + ((int)amount / 2) <= _maxEnergyPoints)
		_energyPoints += (amount / 2);
	else
		_energyPoints = _maxEnergyPoints;
	std::cout << _energyPoints << " energy points" << std::endl;
}

ClapTrap	&ClapTrap::operator=( ClapTrap const &rhs)
{
	if (this != &rhs)
	{
		_hitPoints = rhs._hitPoints;
		_maxHitPoints = rhs._maxHitPoints;
		_energyPoints = rhs._energyPoints;
		_maxEnergyPoints = rhs._maxEnergyPoints;
		_level = rhs._level;
		_softAttackDamage = rhs._softAttackDamage;
		_sprintAttackDamage = rhs._sprintAttackDamage;
		_nuclearAttackDamage = rhs._nuclearAttackDamage;
		_meleeAttackDamage = rhs._meleeAttackDamage;
		_rangedAttackDamage = rhs._rangedAttackDamage;
		_armorDamageReduction = rhs._armorDamageReduction;
		_name = rhs._name;
	}
	return *this;
}

int				ClapTrap::getHitPoints( void )
{
	return _hitPoints;
}

int				ClapTrap::getMaxHitPoints( void )
{
	return _maxHitPoints;
}

int				ClapTrap::getEnergyPoints( void )
{
	return _energyPoints;
}

int				ClapTrap::getMaxEnergyPoints( void )
{
	return _maxEnergyPoints;
}

int				ClapTrap::getLevel( void )
{
	return _level;
}

int				ClapTrap::getSoftAttackDamage( void )
{
	return _softAttackDamage;
}

int				ClapTrap::getMeleeAttackDamage( void )
{
	return _meleeAttackDamage;
}

int				ClapTrap::getSprintAttackDamage( void )
{
	return _sprintAttackDamage;
}

int				ClapTrap::getRangedAttackDamage( void )
{
	return _rangedAttackDamage;
}

int				ClapTrap::getNuclearAttackDamage( void )
{
	return _nuclearAttackDamage;
}

int				ClapTrap::getArmorDamageReduction( void )
{
	return _armorDamageReduction;
}

std::string		ClapTrap::getName( void )
{
	return _name;
}
