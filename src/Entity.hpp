#pragma once

class Entity
{
public:
	Entity(int health, unsigned int attack)
	{
		_maxHealth = _health = health;
		_attack = attack;
	}

	void takeDamage(unsigned int damage) 
	{ 
		_health -= damage; 
	}

	void attack(Entity& enemy)
	{
		enemy.takeDamage(_attack);
	}

	bool isAlive() const
	{
		return _health > 0;
	}

	int getHealth() const { return _health; }
	int getMaxHealth() const { return _maxHealth; }
	int getAttack() const { return _attack; }

protected:
	int _health;
	int _maxHealth;
	unsigned int _attack;
};
