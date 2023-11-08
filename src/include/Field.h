#pragma once

#include <string>
#include "Player.h"

class Field
{
public:
    Field(const std::string& name);
    virtual ~Field(){};
    virtual int GetAmountOfMoneyForRenta() const = 0;
    virtual int GetPriceForBuying() const = 0;
    virtual bool IsPossibleToBuy() const = 0;
    virtual bool IsOwnerExist() const;

    const std::string& GetName() const;

    void SetOwner(Player* newOwner);
    Player* GetOwner() const;

protected:
    std::string name;
    Player* owner;
};

class FieldAuto : public Field
{
public:
    FieldAuto(const std::string &name): Field(name){};
    virtual ~FieldAuto(){};
    int GetAmountOfMoneyForRenta() const override;
    int GetPriceForBuying() const override;
    bool IsPossibleToBuy() const override;
};

class FieldFood : public Field
{
public:
    FieldFood(const std::string &name): Field(name){};
    virtual ~FieldFood(){};
    int GetAmountOfMoneyForRenta() const override;
    int GetPriceForBuying() const override;
    bool IsPossibleToBuy() const override;
};

class FieldTravel : public Field
{
public:
    FieldTravel(const std::string &name): Field(name){};
    virtual ~FieldTravel(){};
    int GetAmountOfMoneyForRenta() const override;
    int GetPriceForBuying() const override;
    bool IsPossibleToBuy() const override;
};

class FieldClothes : public Field
{
public:
    FieldClothes(const std::string &name): Field(name){};
    virtual ~FieldClothes(){};
    int GetAmountOfMoneyForRenta() const override;
    int GetPriceForBuying() const override;
    bool IsPossibleToBuy() const override;
};

class FieldPrison : public Field
{
public:
    FieldPrison(const std::string &name): Field(name){};
    virtual ~FieldPrison(){};
    int GetAmountOfMoneyForRenta() const override;
    int GetPriceForBuying() const override;
    bool IsPossibleToBuy() const override;
};

class FieldBank : public Field
{
public:
    FieldBank(const std::string &name): Field(name){};
    virtual ~FieldBank(){};
    int GetAmountOfMoneyForRenta() const override;
    int GetPriceForBuying() const override;
    bool IsPossibleToBuy() const override;
};