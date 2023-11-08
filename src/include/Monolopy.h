#pragma once

#include <vector>
#include <string>
#include <memory>
#include "Player.h"
#include <Field.h>

class Monopoly
{
public:
	Monopoly(const std::vector<std::string>& names);
	std::vector<std::shared_ptr<Player>>* GetPlayers();
	std::vector<std::shared_ptr<Field>>* GetFields();
	std::shared_ptr<Player> GetPlayer(int);
	bool Buy(int p, std::shared_ptr<Field> field);
	std::shared_ptr<Field> GetFieldByName(const std::string& name);	
	bool Renta(int p, std::shared_ptr<Field> field);

private:
	std::vector<std::shared_ptr<Field>> fields;
	std::vector<std::shared_ptr<Player>> players;
};

