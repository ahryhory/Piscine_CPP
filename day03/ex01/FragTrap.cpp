/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:00:15 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/21 19:00:16 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : _hitPoints(100), _maxHitPoints(100), _energyPoints(100),
_maxEnergyPoints(100), _level(1), _softAttackDamage(5), _meleeAttackDamage(30), _sprintAttackDamage(35),
_rangedAttackDamage(20), _nuclearAttackDamage(65), _armorDamageReduction(5)
{
	std::cout << std::endl << "FR4G-TP was born !" << std::endl;
	_name = name;
}

FragTrap::FragTrap() : _hitPoints(100), _maxHitPoints(100), _energyPoints(100),
_maxEnergyPoints(100), _level(1), _softAttackDamage(5), _meleeAttackDamage(30), _sprintAttackDamage(35),
_rangedAttackDamage(20), _nuclearAttackDamage(65), _armorDamageReduction(5), _name("none")
{
	std::cout << std::endl << "FR4G-TP was born !" << std::endl;
}

FragTrap::FragTrap( FragTrap const &src )
{
	*this = src;
}

FragTrap::~FragTrap()
{
	std::cout << std::endl << "FR4G-TP was dead !" << std::endl;
}

void		FragTrap::softAttack( std::string const & target )
{
	if (_energyPoints != 0 && _hitPoints != 0)
	{
		std::cout << std::endl << "FR4G-TP <" << _name << "> attacks <" << target << "> soft attack, causing <" << _softAttackDamage << "> points of damage !" << std::endl;
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

void		FragTrap::meleeAttack( std::string const & target )
{
	if (_energyPoints >= 20 && _hitPoints != 0)
	{
			std::cout << std::endl << "FR4G-TP <" << _name << "> attacks <" << target << "> at melee, causing <" << _meleeAttackDamage << "> points of damage !" << std::endl;
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

void		FragTrap::rangedAttack( std::string const & target )
{
	if (_energyPoints >= 10 && _hitPoints != 0)
	{
		std::cout << std::endl << "FR4G-TP <" << _name << "> attacks <" << target << "> at range, causing <" << _rangedAttackDamage << "> points of damage !" << std::endl;
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

void		FragTrap::sprintAttack( std::string const & target )
{
	if (_energyPoints >= 25 && _hitPoints != 0)
	{
		std::cout << std::endl << "FR4G-TP <" << _name << "> attacks <" << target << "> sprint attack, causing <" << _sprintAttackDamage << "> points of damage !" << std::endl;
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

void		FragTrap::nuclearAttack( std::string const & target )
{
	if (_energyPoints >= 90 && _hitPoints != 0)
	{
		std::cout << std::endl << "FR4G-TP <" << _name << "> attacks <" << target << "> nuclear attack, causing <" << _nuclearAttackDamage << "> points of damage !" << std::endl;
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

void		FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	typedef void (FragTrap::*Attack)(std::string const & target);
	Attack	attack[5] = {&FragTrap::softAttack, &FragTrap::meleeAttack, &FragTrap::sprintAttack, &FragTrap::rangedAttack, &FragTrap::nuclearAttack};
	int		attackEnergy[5] = {1, 20, 25, 10, 90};
	int		randAttack;

	if (_energyPoints >= 25 && _hitPoints != 0)
	{
		std::cout << std::endl << "Random  attack ! ! !" << std::endl;
		randAttack = rand() % 5;
		_energyPoints += attackEnergy[randAttack];
		_energyPoints -= 25;
		(this->*(attack[randAttack]))(target);
		if (attackEnergy[randAttack] >= 25)
			std::cout << std::endl << "Good  random ) ! ! !" << std::endl;
		if (attackEnergy[randAttack] < 25)
			std::cout << std::endl << "Bad  random ( ! ! !" << std::endl;
	}
	else
	{
		if (_hitPoints == 0)
			std::cout << std::endl << "No hit points !" << std::endl;
		else
			std::cout << std::endl << "No energy points for random attack!" << std::endl;
	}
}

void		FragTrap::takeDamage( unsigned int amount )
{
	if ((int)amount > _armorDamageReduction)
	{
		amount -= _armorDamageReduction;
		if (_hitPoints - amount > 0)
		{
			std::cout << std::endl << "FR4G-TP take " << amount << "damage" << std::endl;
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

void		FragTrap::beRepaired( unsigned int amount )
{
	std::cout << std::endl << "FR4G-TP Repair" << std::endl;
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

FragTrap	&FragTrap::operator=( FragTrap const &rhs)
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

int				FragTrap::getHitPoints( void )
{
	return _hitPoints;
}

int				FragTrap::getMaxHitPoints( void )
{
	return _maxHitPoints;
}

int				FragTrap::getEnergyPoints( void )
{
	return _energyPoints;
}

int				FragTrap::getMaxEnergyPoints( void )
{
	return _maxEnergyPoints;
}

int				FragTrap::getLevel( void )
{
	return _level;
}

int				FragTrap::getSoftAttackDamage( void )
{
	return _softAttackDamage;
}

int				FragTrap::getMeleeAttackDamage( void )
{
	return _meleeAttackDamage;
}

int				FragTrap::getSprintAttackDamage( void )
{
	return _sprintAttackDamage;
}

int				FragTrap::getRangedAttackDamage( void )
{
	return _rangedAttackDamage;
}

int				FragTrap::getNuclearAttackDamage( void )
{
	return _nuclearAttackDamage;
}

int				FragTrap::getArmorDamageReduction( void )
{
	return _armorDamageReduction;
}

std::string		FragTrap::getName( void )
{
	return _name;
}
