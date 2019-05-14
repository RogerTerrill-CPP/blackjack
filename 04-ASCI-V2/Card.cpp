#include "Card.h"
#include <iostream>
#include <string>
using namespace std;

//Constants for the properties of each card
//string faces[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
//string suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
//int value[] = { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };

/**********************************************************************************
 * Name:			Card()
 * Arguments:		None
 * Returns:			None
 * Precondition:	None
 * Postcondition:	None
 **********************************************************************************/
Card::Card()
{
}

/**********************************************************************************
 * Name:			Card(string _suit, string _rank, int _value)
 * Arguments:		string _suit, string _rank, int _value
 * Returns:			Card
 * Precondition:	Variables delcared and initialized
 * Postcondition:	A card with values in arguements will be created
 **********************************************************************************/
Card::Card(string _suit, string _rank, int _value)
{
	suit = _suit;
	rank = _rank;
	value = _value;
}

//Setter
/**********************************************************************************
 * Name:			setSuit(string _suit)
 * Arguments:		string _suit
 * Returns:			Card
 * Precondition:	_suit passed by value
 * Postcondition:	Will set the suit to the value of _suit
 **********************************************************************************/
void Card::setSuit(string _suit)
{
	suit = _suit;
}
	
/**********************************************************************************
 * Name:			setSuit(string _suit)
 * Arguments:		string _suit
 * Returns:			None
 * Precondition:	_suit passed by value
 * Postcondition:	Will set the suit to the value of _suit
 **********************************************************************************/
void Card::setRank(string _rank)
{
	rank = _rank;
}

/**********************************************************************************
 * Name:			setValue(int _value)
 * Arguments:		int _value
 * Returns:			None
 * Precondition:	_value passed by value
 * Postcondition:	Will set the value to _value
 **********************************************************************************/
void Card::setValue(int _value)
{
	value = _value;
}

//Getter
/**********************************************************************************
 * Name:			getSuit()
 * Arguments:		None
 * Returns:			string suit
 * Precondition:	suit must have a value
 * Postcondition:	Will return suit
 **********************************************************************************/
string Card::getSuit()
{
	return suit;
}

/**********************************************************************************
 * Name:			getRank()
 * Arguments:		None
 * Returns:			string rank
 * Precondition:	rank must have a value
 * Postcondition:	Will return rank
 **********************************************************************************/
string Card::getRank()
{
	return rank;
}

/**********************************************************************************
 * Name:			getValue()
 * Arguments:		None
 * Returns:			int value
 * Precondition:	value must have a value
 * Postcondition:	Will return value
 **********************************************************************************/
int Card::getValue()
{
	return value;
}

/**********************************************************************************
 * Name:			displaySuit()
 * Arguments:		None
 * Returns:			string
 * Precondition:	Suit must be assigned
 * Postcondition:	Returns the correct string based on the suit that is called
 **********************************************************************************/
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

/**********************************************************************************
 * Name:			printCard()
 * Arguments:		None
 * Returns:			string
 * Precondition:	Rank and displaySuit() must be assigned
 * Postcondition:	Returns a full display of a playing card
 **********************************************************************************/
string Card::printCard()
{
	if (rank == "10")
		return("\n ____________________ \n|                    |\n|  " + rank + "                |\n" + displaySuit() + "|                 " + rank + " |\n|____________________|\n");
	return ("\n ____________________ \n|                    |\n|  " + rank + "                 |\n" + displaySuit() + "|                 " + rank + "  |\n|____________________|\n");
}
