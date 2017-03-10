#pragma once

#include <vector>
#include <map>

#include "City.h"
#include "Colour.h"
#include "Map.h"
#include "Observer.h"

class MapView
	: public Observer
{
public:
	MapView(Map& map);
	~MapView() override;
	void update() override;

private:
	Map& _subject;
};
