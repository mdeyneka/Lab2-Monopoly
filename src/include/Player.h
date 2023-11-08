#pragma once

#include <string>

class Player
{
public:
    Player(const std::string &name, int amountOfMoney);

    virtual const std::string& GetName() const;
    virtual int GetAmountOfMoney() const;
    virtual void SubtractMoney(int value);
    virtual void AddMoney(int value);

private:
	std::string name;
	int amountOfMoney;
};