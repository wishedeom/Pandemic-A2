#pragma once

#include <string>
#include <memory>

class Card
{
public:
	Card(const std::string& name, const std::string& description);
	~Card();
	
	// Accessors
	std::string name() const;
	std::string description() const;

	// Mutators
	Card& name(const std::string& name);
	Card& description(const std::string& description);

private:
	std::string _name;
	std::string _description;
};

std::unique_ptr<Card> makeReferenceCard();
