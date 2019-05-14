#include "Card.h"
#include <iostream>
#include <string>
using namespace std;


string faces[] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
string suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
int value[] = { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };

Card::Card()
{
}

Card::Card(string _suit, string _rank, int _value)
{
	suit = _suit;
	rank = _rank;
	value = _value;
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

	string Card::printCard()
	{
	//return the way the card will be displayed
		return (rank + " of " + suit);
	}
