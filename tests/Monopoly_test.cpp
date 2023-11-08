#include "Monolopy.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace ::std;

TEST(LAB2, GetPlayersListReturnCorrectList) {
    string players[]{ "Peter","Ekaterina","Alexander" };
   
    Monopoly monopoly(players,3);

    std::vector<Player>* x = monopoly.GetPlayers();
    int i = 0;
    for (auto c : *x) {
        ASSERT_STREQ(c.GetName().c_str(), players[i++].c_str());
        ASSERT_EQ(c.GetAmountOfMoney(), 6000);
    }
    ASSERT_TRUE(i);
}
TEST(LAB2, GetFieldsListReturnCorrectList) {
    vector<Field*> expectedCompanies {
        new FieldAuto("Ford"),
        new FieldFood("MCDonald"),
        new FieldClothes("Lamoda"),
        new FieldTravel("Air Baltic"),
        new FieldTravel("Nordavia"),
        new FieldPrison("Prison"),
        new FieldFood("MCDonald"),
        new FieldAuto("TESLA"),
    };
    string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);
    vector<Field*> *actualCompanies = monopoly.GetFields();
    int i = 0;
    for (auto x : *actualCompanies)
    {
       ASSERT_EQ(*x, *expectedCompanies[i++]);
    }
    ASSERT_TRUE(i);   
}

TEST(LAB2, PlayerBuyNoOwnedCompanies)
{
    string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);
    Field* field = monopoly.GetFieldByName("Ford");
    monopoly.Buy(1, field);

    auto player = monopoly.GetPlayer(1);
    ASSERT_EQ(player->GetAmountOfMoney(), 5500);
    field = monopoly.GetFieldByName("Ford");
    ASSERT_TRUE(field->IsOwnerExist() == true);
}

TEST(LAB2, RentaShouldBeCorrectTransferMoney)
{
    string players[]{ "Peter","Ekaterina","Alexander" };
    Monopoly monopoly(players, 3);
    Field* field = monopoly.GetFieldByName("Ford");
    monopoly.Buy(1, field);

    field = monopoly.GetFieldByName("Ford");
    monopoly.Renta(2, field);
    auto player1 = monopoly.GetPlayer(1);
    ASSERT_EQ(player1->GetAmountOfMoney(), 5750);

    auto player2 = monopoly.GetPlayer(2);
    ASSERT_EQ(player2->GetAmountOfMoney(), 5750);    
}

bool operator== (const Field& a , const Field& b)
{
    return a.GetName() == b.GetName() && a.GetOwner() == b.GetOwner();
}