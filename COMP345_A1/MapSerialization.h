#pragma once

#include <map>
#include <vector>
#include <string>

#include "Map.h"

bool fileExists(const std::string& fileName);
Map readMapFromFile(const std::string& fileName);
void writeMapToFile(const Map& map, const std::string& fileName);
