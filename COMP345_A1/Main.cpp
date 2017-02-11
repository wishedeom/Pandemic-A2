#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Card.h"
#include "City.h"
#include "Player.h"
#include "Map.h"
#include "MapSerialization.h"

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

	// Construct player
	std::cout << "Enter your name: ";
	std::string playerName;
	std::getline(std::cin >> std::ws, playerName);
	std::cout << "Welcome, " << playerName << "\n";

	map.addPlayer(playerName);
	const auto& player = *map.players().back();

	// Place pawn
	std::cout << "Cities of " << map.name() << ": \n";
	for (const auto& city : map.cities())
		std::cout << "    " << city->name() << "\n";
	
	std::cout << "Where would you like to place your pawn? ";
	do
	{
		try
		{
			std::string cityName;
			std::cin >> cityName;
			const auto& city = map.city(cityName);
			player.pawn().position(city);
		}
		catch (const std::out_of_range& e)
		{
			std::cout << e.what() << std::endl;
			continue;
		}
		break;
	}
	while (true);

	std::cout << player.name() << ", your pawn is in " << player.pawn().position().name() << "." << "\n";

	// Save game
	std::cout << "Where do you wish to save this game file? ";
	std::string saveFileName;
	std::getline(std::cin >> std::ws, saveFileName);
	writeMapToFile(map, saveFileName);
}
