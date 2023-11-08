#include "Field.h"

const std::string &Field::GetName() const
{
    return name;
}

Field::Field(const std::string &name) : name(name), owner(nullptr)
{

}

bool Field::IsOwnerExist() const
{
    return owner != nullptr;
}

void Field::SetOwner(Player *newOwner)
{
    owner = newOwner;
}

Player *Field::GetOwner() const
{
    return owner;
}

int FieldAuto::GetAmountOfMoneyForRenta() const
{
    return 250;
}

int FieldAuto::GetPriceForBuying() const
{
    return 500;
}

bool FieldAuto::IsPossibleToBuy() const
{
    return true;
}

int FieldFood::GetAmountOfMoneyForRenta() const
{
    return 250;
}

int FieldFood::GetPriceForBuying() const
{
    return 250;
}

bool FieldFood::IsPossibleToBuy() const
{
    return true;
}

int FieldTravel::GetAmountOfMoneyForRenta() const
{
    return 250;
}

int FieldTravel::GetPriceForBuying() const
{
    return 700;
}

bool FieldTravel::IsPossibleToBuy() const
{
    return true;
}

int FieldClothes::GetAmountOfMoneyForRenta() const
{
    return 250;
}

int FieldClothes::GetPriceForBuying() const
{
    return 100;
}

bool FieldClothes::IsPossibleToBuy() const
{
    return true;
}

int FieldPrison::GetAmountOfMoneyForRenta() const
{
    return 1000;
}

int FieldPrison::GetPriceForBuying() const
{
    return 0;
}

bool FieldPrison::IsPossibleToBuy() const
{
    return false;
}

int FieldBank::GetAmountOfMoneyForRenta() const
{
    return 700;
}

int FieldBank::GetPriceForBuying() const
{
    return 0;
}

bool FieldBank::IsPossibleToBuy() const
{
    return false;
}
