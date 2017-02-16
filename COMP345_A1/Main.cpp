#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Card.h"
#include "City.h"
#include "Player.h"
#include "Map.h"
#include "MapSerialization.h"

constexpr size_t numPlayers = 2;

void solicitPlayerName(Map& map, const size_t number);

void main()
{
	// Load map
	std::string fileName;
	bool exists = false;
	while (!exists)
	{
		std::cout << "Load map file to start new game: ";
		std::cin >> fileName;
		if (!(exists = fileExists(fileName)))
		{
			std::cout << "File not found.\n";
		}
	}
	std::cout << "\nLoading map \"" << fileName << "\"...\n";
	Map map = readMapFromFile(fileName);
	std::cout << "Map \"" << fileName << "\" loaded!\n\n";

	// Construct players
	for (auto i = 1; i <= numPlayers; ++i)
		solicitPlayerName(map, i);

	// Place pawn
	std::cout << "Cities of " << map.name() << ": \n";
	for (const auto& city : map.cities())
		std::cout << "    " << city->name() << "\n";
	
	std::cout << "Where would you like to place your pawn? ";
	std::string cityName;
	do
	{
		try
		{
			
			std::cin >> cityName;
		}
		catch (const std::out_of_range& e)
		{
			std::cout << e.what() << std::endl;
			continue;
		}
		break;
	}
	while (true);

	const auto& city = map.city(cityName);
	Player* p;
	for (const auto& player : map.players())
	{
		player->pawn().position(city);
		p = player.get();
	}

	std::cout << "Your pawns are in " << p->pawn().position().name() << "." << "\n";

	// Save game
	std::cout << "Where do you wish to save this game file? ";
	std::string saveFileName;
	std::getline(std::cin >> std::ws, saveFileName);
	writeMapToFile(map, saveFileName);
}

void solicitPlayerName(Map& map, const size_t number)
{
	std::cout << "Enter the name of player " << number << ": ";
	std::string playerName;
	std::getline(std::cin >> std::ws, playerName);
	std::cout << "Welcome, " << playerName << "\n";
	map.addPlayer(playerName);
}
