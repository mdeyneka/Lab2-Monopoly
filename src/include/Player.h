#pragma once

#include <string>

class Player
{
public:
    Player(const std::string &name, int amountOfMoney);

    const std::string& GetName() const;
    int GetAmountOfMoney() const;
    void SubtractMoney(int value);
    void AddMoney(int value);

private:
	std::string name;
	int amountOfMoney;
};