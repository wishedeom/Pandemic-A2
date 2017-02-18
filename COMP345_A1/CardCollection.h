#pragma once

#include <memory>
#include <vector>

#include "Card.h"

class CardCollection
{
	using CardPtr = std::unique_ptr<Card>;

public:
	CardCollection& add(CardPtr card);
	CardPtr draw();

private:
	std::vector<CardPtr> _cards;
};