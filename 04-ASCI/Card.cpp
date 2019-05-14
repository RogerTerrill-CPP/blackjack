#include "Card.h"
#include <iostream>
#include <string>
using namespace std;


string faces[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
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

	string Card::displaySuit()
	{
		if(suit == "Hearts")
		{
			return ("|                    |\n|                    |\n|                    |\n|     $$$   $$$      |\n|    $$$$$ $$$$$     |\n|   $$$$$$$$$$$$$    |\n|    $$$$$$$$$$$     |\n|       $$$$$        |\n|         $          |\n|                    |\n|                    |\n|                    |\n");
		}
		else if (suit == "Diamonds")
		{
			return ("|                    |\n|                    |\n|         $$         |\n|       $$$$$$       |\n|     $$$$$$$$$$     |\n|   $$$$$$$$$$$$$$   |\n|     $$$$$$$$$$     |\n|       $$$$$$       |\n|         $$         |\n|                    |\n|                    |\n|                    |\n");
		}
		else if (suit == "Spades")
		{
			return ("|                    |\n|                    |\n|         $$         |\n|       $$$$$$       |\n|     $$$$$$$$$$     |\n|    $$$$$$$$$$$$    |\n|   $$$$$$  $$$$$$   |\n|    $$$$ $$ $$$$    |\n|        $$$$        |\n|      $$$$$$$$      |\n|                    |\n|                    |\n");
		}
		else if ( suit == "Clubs")
		{
			return ("|                    |\n|                    |\n|         $$         |\n|       $$$$$$       |\n|         $$         |\n|    $$        $$    |\n|  $$$$$$    $$$$$$  |\n|    $$   $$   $$    |\n|       $$$$$$       |\n|     $$$$$$$$$$     |\n|                    |\n|                    |\n");
		}
	}
	
	string Card::printCard()
	{
		if (rank == "10")
			return("\n ____________________ \n|                    |\n|  " + rank + "                |\n" + displaySuit() + "|                 " + rank + " |\n|____________________|\n");
		return ("\n ____________________ \n|                    |\n|  " + rank + "                 |\n" + displaySuit() + "|                 " + rank + "  |\n|____________________|\n");
	}
