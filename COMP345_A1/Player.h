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
	std::string name() const;
	const Map& map() const;
	Pawn& pawn() const;
	Card& referenceCard() const;
	Card& roleCard() const;

	// Mutators
	Player& roleCard(CardPtr roleCard);

	// Mutable accessors
	CardCollection& hand();

private:
	std::string _name;		// The player's name
	const Map& _map;		// The map the player belongs to - immutable
	PawnPtr _pawn;			// The player's pawn on the game board
	CardPtr _referenceCard;	// The player's reference card, describing the action rules
	CardPtr _roleCard;		// The player's role card
	CardCollection _hand;	// The player's player cards
};
