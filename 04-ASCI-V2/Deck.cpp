#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

//Constant for the amount of cards in a deck
int const CARDS_IN_DECK = 52;

/**********************************************************************************
 * Name:			Deck()
 * Arguments:		None
 * Returns:			None
 * Precondition:	None
 * Postcondition:	None
 **********************************************************************************/
Deck::Deck()
{
}

/**********************************************************************************
 * Name:			newDeck()
 * Arguments:		int count
 * Returns:			None
 * Precondition:	None
 * Postcondition:	Creates a deck of 52 different card objects through vectors
 **********************************************************************************/
void Deck::newDeck()
{
	string faces[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	string suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	int value[] = { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
	
	for (int count = 0; count < CARDS_IN_DECK; count++)
		vectorDeck.push_back(Card(suits[count/13], faces[count%13], value[count%13]));
}

/**********************************************************************************
 * Name:			shuffle()
 * Arguments:		None
 * Returns:			None
 * Precondition:	None
 * Postcondition:	Will shuffle a vector of any size
 **********************************************************************************/
void Deck::shuffle()
{
	random_shuffle(vectorDeck.begin(), vectorDeck.end());
}

/**********************************************************************************
 * Name:			printDeck()
 * Arguments:		int i
 * Returns:			None
 * Precondition:	Deck must be created
 * Postcondition:	Displays a deck vector and of any size
 **********************************************************************************/
void Deck::printDeck()
{
	for(int i = 0; i < vectorDeck.size(); i++)
		cout << vectorDeck[i].printCard() << endl;
}

/**********************************************************************************
 * Name:			deal(Deck& inputDeck)
 * Arguments:		None
 * Returns:			None
 * Precondition:	Deck must be created and two deck objects
 * Postcondition:	Copies current 0 element to passed by reference deck
 * 					Erases 0 element of deck
 **********************************************************************************/
void Deck::deal(Deck& inputDeck)
{

	inputDeck.vectorDeck.push_back(vectorDeck[0]);
	vectorDeck.erase(vectorDeck.begin());
}

/**********************************************************************************
 * Name:			handTotal()
 * Arguments:		int total, i
 * Returns:			int total
 * Precondition:	Deck must be created
 * Postcondition:	Returns total value for any given hand size
 **********************************************************************************/
int Deck::handTotal()
{
	int total = 0;
	for (int i = 0; i < vectorDeck.size(); i++)
		total += vectorDeck[i].getValue();
	return total;
}

/**********************************************************************************
 * Name:			printCardinHand(int i)
 * Arguments:		int i
 * Returns:			string
 * Precondition:	Deck must be created
 * Postcondition:	Returns a given card of element i
 **********************************************************************************/
string Deck::printCardinHand(int i)
{
	return vectorDeck[i].printCard();
}

/**********************************************************************************
 * Name:			valueOfCard(int i)
 * Arguments:		int i
 * Returns:			int
 * Precondition:	Deck must be created
 * Postcondition:	Returns a given card value of element i
 **********************************************************************************/
int Deck::valueOfCard(int i)
{
	return vectorDeck[i].getValue();
}

/**********************************************************************************
 * Name:			bust()
 * Arguments:		None
 * Returns:			bool
 * Precondition:	Deck must be created
 * Postcondition:	Returns a bool after checking if hand total is greater than 21
 **********************************************************************************/
bool Deck::bust()
{
	if(handTotal() > 21)
		return true;
}

/**********************************************************************************
 * Name:			checkAce()
 * Arguments:		None
 * Returns:			None
 * Precondition:	Deck must be created
 * Postcondition:	Changes value of Ace depending on situation to 1
 **********************************************************************************/
void Deck::checkAce()
{
	for (int i = 0; i < vectorDeck.size(); i++)
		if ((handTotal() > 21) && (vectorDeck[i].getValue() == 11))
			vectorDeck[i].setValue(1);
}

/**********************************************************************************
 * Name:			printResult()
 * Arguments:		int i
 * Returns:			None
 * Precondition:	Deck must be created
 * Postcondition:	Displays all cards in vector array
 **********************************************************************************/
void Deck::printResult()
{
	for (int i = 1; i < vectorDeck.size(); i++)
		cout << "\t\t" << vectorDeck[i].printCard() << endl;
}

/**********************************************************************************
 * Name:			emptyDeck()
 * Arguments:		None
 * Returns:			bool
 * Precondition:	None
 * Postcondition:	Returns a bool to determine if the vector has zero elements
 **********************************************************************************/
bool Deck::emptyDeck()
{
	if (vectorDeck.size() == 0)
		return true;
}

/**********************************************************************************
 * Name:			clearHand()
 * Arguments:		None
 * Returns:			None
 * Precondition:	None
 * Postcondition:	Erases all elements in a vector object
 **********************************************************************************/
void Deck::clearHand()
{
	vectorDeck.erase(vectorDeck.begin(), vectorDeck.end());
}