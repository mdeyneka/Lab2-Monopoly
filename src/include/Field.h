#pragma once

#include <string>
#include "Player.h"

class Field
{
public:
    enum class Type
    {
        AUTO,
        FOOD,
        TRAVEL,
        CLOTHER,
        PRISON,
        BANK
	};

    Field(const std::string &name, Field::Type type);
    const std::string& GetName() const;
    Field::Type GetType() const;
    bool IsOwnerExist() const;

    void SetOwner(Player* newOwner);
    Player* GetOwner() const;

private:
    std::string name;
    Type type;
    Player* owner;
};