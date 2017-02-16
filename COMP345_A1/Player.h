#pragma once

#include <memory>
#include <string>
#include <vector>

#include "ReferenceCard.h"
#include "Pawn.h"

class Pawn;
class Map;

class Player
{

public:
	Player(const std::string& name, const Map& map);
	std::string name() const;
	const Map& map() const;
	Pawn& pawn() const;
	Card& referenceCard() const;

private:
	std::string _name;
	const Map& _map;
	std::unique_ptr<Pawn> _pawn;
	std::unique_ptr<ReferenceCard> _referenceCard;
};
