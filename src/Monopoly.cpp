#include "Monolopy.h"
#include <algorithm>

using namespace ::std;

Monopoly::Monopoly(string names[10],int countPlaers)
{
	for (int i = 0; i < countPlaers; i++)
	{
		players.push_back({names[i], 6000});
	}
	fields.emplace_back(new FieldAuto("Ford"));
	fields.emplace_back(new FieldFood("MCDonald"));
	fields.emplace_back(new FieldClothes("Lamoda"));
	fields.emplace_back(new FieldTravel("Air Baltic"));
	fields.emplace_back(new FieldTravel("Nordavia"));
	fields.emplace_back(new FieldPrison("Prison"));
	fields.emplace_back(new FieldFood("MCDonald"));
	fields.emplace_back(new FieldAuto("TESLA"));
}

std::vector<Player>* Monopoly::GetPlayers()
{
	return &players;
}

std::vector<Field*>* Monopoly::GetFields()
{
	return &fields;
}

Player* Monopoly::GetPlayer(int m)
{
	std::vector<Player>::iterator i = players.begin();
	advance(i, m - 1);
	return &*i;
}

bool Monopoly::Buy(int playerIndex, Field* field)
{
	Player* buyer = GetPlayer(playerIndex);
	if (field->IsOwnerExist() || !field->IsPossibleToBuy())
		return false;
	buyer->SubtractMoney(field->GetPriceForBuying());
	field->SetOwner(buyer);
	return true;
}

Field* Monopoly::GetFieldByName(const std::string& name)
{
	std::vector<Field*>::iterator i = find_if(fields.begin(), fields.end(),[name] (Field* x) {
		return x->GetName() == name;
	});
	return *i;
}

bool Monopoly::Renta(int playerIndex, Field* field)
{
	Player* tenant = GetPlayer(playerIndex);
	if (!field->IsOwnerExist())
			return false;
	field->GetOwner()->AddMoney(field->GetAmountOfMoneyForRenta());
	tenant->SubtractMoney(field->GetAmountOfMoneyForRenta());
	return true;
}



