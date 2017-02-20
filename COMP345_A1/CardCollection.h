#pragma once

#include <memory>
#include <vector>

#include "Card.h"

// Represents a collection of cards which owns those cards
class CardCollection
{
	using CardPtr = std::unique_ptr<Card>;

public:
	CardCollection& add(CardPtr card);			// Add a card to the collection
	CardPtr draw();								// Draw a single card from the collection
	const std::vector<CardPtr>& cards() const;	// Exposes the card contents

private:
	std::vector<CardPtr> _cards;
};