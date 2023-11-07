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
    vector<Field> expectedCompanies {
        {"Ford",Field::Type::AUTO},
        {"MCDonald",Field::Type::FOOD},
        {"Lamoda",Field::Type::CLOTHER},
        {"Air Baltic",Field::Type::TRAVEL},
        {"Nordavia",Field::Type::TRAVEL},
        {"Prison",Field::Type::PRISON},
        {"MCDonald",Field::Type::FOOD},
        {"TESLA",Field::Type::AUTO}
    };
    string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);
   auto actualCompanies = monopoly.GetFields();
   int i = 0;
   for (auto x : *actualCompanies)
   {
       ASSERT_EQ(x, expectedCompanies[i++]);
   }
   ASSERT_TRUE(i);   
}

TEST(LAB2, PlayerBuyNoOwnedCompanies)
{
    string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);
    auto x = monopoly.GetFieldByName("Ford");
    monopoly.Buy(1, x);

    auto player = monopoly.GetPlayer(1);
    ASSERT_EQ(player->GetAmountOfMoney(), 5500);
    x = monopoly.GetFieldByName("Ford");
    ASSERT_TRUE(x->IsOwnerExist() == true);
}

TEST(LAB2, RentaShouldBeCorrectTransferMoney)
{
    string players[]{ "Peter","Ekaterina","Alexander" };
    Monopoly monopoly(players, 3);
    auto x = monopoly.GetFieldByName("Ford");
    monopoly.Buy(1, x);

    x = monopoly.GetFieldByName("Ford");
    monopoly.Renta(2, x);
    auto player1 = monopoly.GetPlayer(1);
    ASSERT_EQ(player1->GetAmountOfMoney(), 5750);

    auto player2 = monopoly.GetPlayer(2);
    ASSERT_EQ(player2->GetAmountOfMoney(), 5750);    
}

bool operator== (const Field &a , const Field& b)
{
    return a.GetName() == b.GetName() && a.GetType() == b.GetType() && a.GetOwner() == b.GetOwner();
}