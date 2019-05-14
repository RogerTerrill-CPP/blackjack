#include "Card.h"
#include <iostream>
using namespace std;

Card::Card()
{
}

//Setter
	void Card::setSuit(string _suit)
	{
		suit = _suit;
	}
	
	void Card::setRank(string _rank)
	{
		rank = _rank;
	}
	
	void Card::setValue(int _value)
	{
		value = _value;
	}
	
	void Card::setDealt(bool _dealt)
	{
		dealt = _dealt;
	}

	//Getter
	string Card::getSuit()
	{
		return suit;
	}
	
	string Card::getRank()
	{
		return rank;
	}
	
	int Card::getValue()
	{
		return value;
	}
	
	bool Card::getDealt()
	{
		return dealt;
	}

	string Card::printCard()
	{
	//return the way the card will be displayed
		return (rank + " of " + suit);
	}
