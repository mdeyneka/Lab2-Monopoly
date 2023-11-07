#include "Field.h"

Field::Field(const std::string &name, Field::Type type)  : name(name), type(type), owner(nullptr)
{
}

const std::string &Field::GetName() const
{
    return name;
}

Field::Type Field::GetType() const
{
    return type;
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
