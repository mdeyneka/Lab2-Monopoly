#include "Monolopy.h"
#include <algorithm>

using namespace ::std;

const int DefaultCountOfMonerPerUser = 6000;

Monopoly::Monopoly(const vector<string>& names)
{
	for(auto it = names.cbegin(); it != names.cend(); ++it)
	{
		players.emplace_back(new Player(*it, DefaultCountOfMonerPerUser));
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

std::vector<shared_ptr<Player>>* Monopoly::GetPlayers()
{
	return &players;
}

std::vector<std::shared_ptr<Field>>* Monopoly::GetFields()
{
	return &fields;
}

shared_ptr<Player> Monopoly::GetPlayer(int index)
{
	std::vector<shared_ptr<Player>>::iterator it = players.begin();
	advance(it, index - 1);
	return *it;
}

bool Monopoly::Buy(int playerIndex, std::shared_ptr<Field> field)
{
	if (field->IsOwnerExist() || !field->IsPossibleToBuy())
		return false;
	shared_ptr<Player> buyer = GetPlayer(playerIndex);
	buyer->SubtractMoney(field->GetPriceForBuying());
	field->SetOwner(buyer);
	return true;
}

std::shared_ptr<Field> Monopoly::GetFieldByName(const std::string& name)
{
	std::vector<std::shared_ptr<Field>>::iterator it = find_if(fields.begin(), fields.end(),[name] (std::shared_ptr<Field> field) {
		return field->GetName() == name;
	});
	return *it;
}

bool Monopoly::Renta(int playerIndex, std::shared_ptr<Field> field)
{
	if (!field->IsOwnerExist())
			return false;
	shared_ptr<Player> tenant = GetPlayer(playerIndex);
	field->GetOwner()->AddMoney(field->GetAmountOfMoneyForRenta());
	tenant->SubtractMoney(field->GetAmountOfMoneyForRenta());
	return true;
}