#pragma once

#include <string>

class Card
{
public:
	Card(const std::string& name, const std::string& description);
	~Card();
	std::string name() const;
	std::string description() const;
	Card& name(const std::string& newName);

private:
	std::string _name;
	std::string _description;
};
