#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
	Player()
	{
		money = 0;
	}
	Player(int money)
	{
		this->money = money;
	}
	void setMoney(int amount)
	{
		money = amount;
	}
	int getMoney(void)
	{
		return money;
	}
	//Returns new money value
	int addMoney(int amount)
	{
		money += amount;
		return money;
	}
private:
	int money;
};


#endif