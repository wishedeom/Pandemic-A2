#pragma once

#include <string>
#include <memory>

// Represents a single card in the game.
// Should be owned by a card collection or a player.
// Can be extended to represent
//	- Reference cards
//	- Role cards
//	- Player cards
//		- City cards
//		- Event cards
//		- Epidemic cards
//	- Infection cards
class Card
{
public:
	Card(const std::string& name, const std::string& description);	// Ctor
	virtual ~Card();	// Dtor
	
	// Accessors
	std::string name() const;			// The card's name
	std::string description() const;	// The card's decriptive text

	// Mutators
	Card& name(const std::string& name);				// Change the card's name
	Card& description(const std::string& description);	// Change the card's descriptive text

private:
	std::string _name;
	std::string _description;
};

// Makes a new reference card. They all have identical names and description text.
std::unique_ptr<Card> makeReferenceCard();
