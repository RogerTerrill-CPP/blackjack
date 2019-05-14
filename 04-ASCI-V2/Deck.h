#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <vector>
using namespace std;

class Deck
{
public:
	//Constructor
	Deck();
	
	//Creates a new deck of 52 cards
	void newDeck();
	
	//Shuffles deck of any size
	void shuffle();
	
	//Prints deck of any size
	void printDeck();
	
	//Returns specific card of element i
	string printCardinHand(int i);
	
	//Deals a card to object passed by reference
	void deal(Deck& inputDeck);
	
	//Clears deck object of all cards
	void clearHand();
	
	//Returns the total value of hand
	int handTotal();
	
	//Returns the value of a single card at element i
	int valueOfCard(int i);
	
	//Checks to see of the hand is over 21
	bool bust();
	
	//Checks to see if hand is > 21 and change ace to 1
	void checkAce();
	
	//Print all cards in hand
	void printResult();
	
	//Check to see if the vector object is empty
	bool emptyDeck();
	
private:
	//Vector of object Card declaration
	vector<Card> vectorDeck;
};


#endif // DECK_H
