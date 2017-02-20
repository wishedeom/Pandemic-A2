#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Card.h"
#include "CardCollection.h"
#include "Pawn.h"

class Map;
class Pawn;


// Represents a single player
class Player
{
	using PawnPtr = std::unique_ptr<Pawn>;
	using CardPtr = std::unique_ptr<Card>;

public:
	// Constructs a player with a given name, living in a given map
	Player(const std::string& name, const Map& map);

	// Accessors
	std::string name() const;		// The player's name
	const Map& map() const;			// The map the player belongs to - immutable
	Pawn& pawn() const;				// The player's pawn on the game board
	Card& referenceCard() const;	// The player's reference card, describing the action rules
	Card& roleCard() const;			// The player's role card
	CardCollection& hand();			// The player's player cards

	// Mutators
	Player& roleCard(CardPtr roleCard);	// Changes the players role card

private:
	std::string _name;
	const Map& _map;		
	PawnPtr _pawn;			
	CardPtr _referenceCard;	
	CardPtr _roleCard;		
	CardCollection _hand;
};
