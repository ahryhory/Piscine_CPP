/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:43:43 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/22 13:43:44 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : _hitPoints(100), _maxHitPoints(100), _energyPoints(50),
_maxEnergyPoints(50), _level(1), _softAttackDamage(5), _meleeAttackDamage(20), _sprintAttackDamage(30),
_rangedAttackDamage(15), _nuclearAttackDamage(65), _armorDamageReduction(3)
{
	std::cout << std::endl << "SC5G-TP was born !" << std::endl;
	_name = name;
}

ScavTrap::ScavTrap() : _hitPoints(100), _maxHitPoints(100), _energyPoints(50),
_maxEnergyPoints(50), _level(1), _softAttackDamage(5), _meleeAttackDamage(20), _sprintAttackDamage(30),
_rangedAttackDamage(15), _nuclearAttackDamage(65), _armorDamageReduction(3), _name("none")
{
	std::cout << std::endl << "SC5G-TP was born !" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const &src )
{
	*this = src;
}

ScavTrap::~ScavTrap()
{
	std::cout << std::endl << "SC5G-TP was dead !" << std::endl;
}

void		ScavTrap::softAttack( std::string const & target )
{
	if (_energyPoints != 0)
	{
		std::cout << std::endl << "SC5G-TP <" << _name << "> attacks <" << target << "> soft attack, causing <" << _softAttackDamage << "> points of damage !" << std::endl;
		_energyPoints -= 1;
	}
	else
		std::cout << std::endl << "No energy points for soft attack!" << std::endl;
}

void		ScavTrap::meleeAttack( std::string const & target )
{
	if (_energyPoints >= 20)
	{
			std::cout << std::endl << "SC5G-TP <" << _name << "> attacks <" << target << "> at melee, causing <" << _meleeAttackDamage << "> points of damage !" << std::endl;
			_energyPoints -= 20;
	}
	else
		std::cout << std::endl << "No energy points for melee attack!" << std::endl;
}

void		ScavTrap::sprintAttack( std::string const & target )
{
	if (_energyPoints >= 25)
	{
		std::cout << std::endl << "SC5G-TP <" << _name << "> attacks <" << target << "> sprint attack, causing <" << _sprintAttackDamage << "> points of damage !" << std::endl;
		_energyPoints -= 25;
	}
	else
		std::cout << std::endl << "No energy points for sprint attack!" << std::endl;
}

void		ScavTrap::rangedAttack( std::string const & target )
{
	if (_energyPoints >= 50)
	{
		std::cout << std::endl << "SC5G-TP <" << _name << "> attacks <" << target << "> at range, causing <" << _rangedAttackDamage << "> points of damage !" << std::endl;
		_energyPoints -= 50;
	}
	else
		std::cout << std::endl << "No energy points for ranged attack!" << std::endl;
}

void		ScavTrap::nuclearAttack( std::string const & target )
{
	if (_energyPoints >= 90)
	{
		std::cout << std::endl << "SC5G-TP <" << _name << "> attacks <" << target << "> nuclear attack, causing <" << _nuclearAttackDamage << "> points of damage !" << std::endl;
		_energyPoints -= 90;
	}
	else
		std::cout << std::endl << "No energy points for nuclear attack!" << std::endl;
}

void		ScavTrap::challengeNewcomer(std::string const & target)
{
	std::string		challenge[4] = {"Do something with ", "Do anything with ", "Do anything with ", "Do something with "};

	std::cout << std::endl << challenge[rand() % 4] << target << std::endl;
}

void		ScavTrap::takeDamage( unsigned int amount )
{
	if ((int)amount > _armorDamageReduction)
	{
		amount -= _armorDamageReduction;
		if (_hitPoints - amount > 0)
		{
			std::cout << std::endl << "SC5G-TP take " << amount << "damage" << std::endl;
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

void		ScavTrap::beRepaired( unsigned int amount )
{
	std::cout << std::endl << "SC5G-TP Repair" << std::endl;
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

ScavTrap	&ScavTrap::operator=( ScavTrap const &rhs)
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

int				ScavTrap::getHitPoints( void )
{
	return _hitPoints;
}

int				ScavTrap::getMaxHitPoints( void )
{
	return _maxHitPoints;
}

int				ScavTrap::getEnergyPoints( void )
{
	return _energyPoints;
}

int				ScavTrap::getMaxEnergyPoints( void )
{
	return _maxEnergyPoints;
}

int				ScavTrap::getLevel( void )
{
	return _level;
}

int				ScavTrap::getSoftAttackDamage( void )
{
	return _softAttackDamage;
}

int				ScavTrap::getMeleeAttackDamage( void )
{
	return _meleeAttackDamage;
}

int				ScavTrap::getSprintAttackDamage( void )
{
	return _sprintAttackDamage;
}

int				ScavTrap::getRangedAttackDamage( void )
{
	return _rangedAttackDamage;
}

int				ScavTrap::getNuclearAttackDamage( void )
{
	return _nuclearAttackDamage;
}

int				ScavTrap::getArmorDamageReduction( void )
{
	return _armorDamageReduction;
}

std::string		ScavTrap::getName( void )
{
	return _name;
}
