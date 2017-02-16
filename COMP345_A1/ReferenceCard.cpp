#include "ReferenceCard.h"

static const std::string referenceCardDescription =
			"ACTIONS\n"
			"Drive/Ferry: Move to a city connected by a white line to the one you are in.\n"
			"Direct Flight: Discard a City card to move to the city names on the card.\n"
			"Charter Flight: Discard the City card that matches the city you are in to move to any city.\n"
			"Shuttle Flight: Move from a city with a research station to any other city that has a research station.\n"
			"Build a Research Station: Discard the City card that matches the city you are in to place a research "
			"station there. Take the research station from the pile next to the board. If all 6 research stations "
			"have been built, take a research station from anywhere on the board.\n"
			"Treat Disease: Remove 1 disease cube from the city you are in, placing it in the cube supply next to the board. "
			"If this disease colour has been cured (see Discover a Cure below), remove all cubes of that colour from the city "
			"you are in.\n"
			"If the last cube of a cured disease is removed from the board, this disease is eradicated. "
			"Flip its cure marker from it's \"vial\" side to its \"\u0444\" side.\n"
			"Share Knowledge: Either give the City card that matches the city you are in to another player or take the City card "
			"that matches the City you are in from another player. The other player must be in the same city with you.\n"
			"Discover Cure: At any research station, discard 5 City cards of the same colour from your hand to cure the disease of that colour.\n";

ReferenceCard::ReferenceCard()
	: Card{ "Reference Card", referenceCardDescription }
{
	// Empty
}

ReferenceCard::~ReferenceCard()
{
	// Empty
}
