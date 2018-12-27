#pragma once


class PlayerStats
{
public:
	void take_damage(int damage);
	void heal_damage(int damage);

private:
	int max_health;
	int health;
	int turn_number;
	int round_number;

};