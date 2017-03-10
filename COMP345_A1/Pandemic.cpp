// Pandemic
//
// Authored by Michael Deom - 29549641
// Submitted 17/03/2017
//
// Assignment 2 for the course COMP 345 - Advanced Program Design with C++
// with Prof. Nora Houari at Concordia University.
//
// An implementation of the board game "Pandemic" by Z-Man Games.
// Added MapView observer.

//  ----    Inclusions    ----
// Standard library inclusions
#include <iostream>

// Project file inclusions
#include "City.h"
#include "GameState.h"
#include "Map.h"
#include "MapView.h"
#include "Serialization.h"

//	----    Program entry point    ----
void main()
{
	// Title display
	std::cout << "    --------    O B S E R V E R   P A T T E R N    --------\n\n\n";

	// Setup - Solicit map file name and load map, generate player cards from map, and print list of cities
	GameState game;
	game.setMap(std::make_unique<Map>(readMapFromFile("earth.map")));
	auto& map = game.map();

	// Construct MapView
	MapView mapView { map };

	// Add a city to show off my fancy MapView
	auto mke = std::make_unique<City>("Milwaukee", Colour::Yellow);
	mke->connectTo(map.city("London"));
	map.addCity(std::move(mke));

	std::cout << std::endl;
}
