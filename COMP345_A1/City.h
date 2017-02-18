#pragma once

#include <memory>
#include <string>
#include <vector>

class City
{
public:
	// Constructor
	City(const std::string& name = "", const std::string& colour = "");

	// Accessors
	std::string name() const;
	std::string colour() const;

	// Mutators
	City& name(const std::string& name);
	City& colour(const std::string& colour);

private:
	std::string _name;
	std::string _colour;
};
