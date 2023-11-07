#include "Player.h"

Player::Player(const std::string &name, int amountOfMoney) : name(name), amountOfMoney(amountOfMoney)
{
}

const std::string &Player::GetName() const
{
    return name;
}

int Player::GetAmountOfMoney() const
{
    return amountOfMoney;
}

void Player::SubtractMoney(int value)
{
    amountOfMoney = amountOfMoney - value;
}

void Player::AddMoney(int value)
{
    amountOfMoney = amountOfMoney + value;
}
