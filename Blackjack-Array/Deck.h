#ifndef DECK_H
#define DECK_H
#include "Card.h"

class Deck
{
public:
	Deck();
	void newDeck();
	void shuffle();
	void printHand();
	void printDeck();
	string printCardinHand(int i);
	void deal(Deck& inputDeck);
	void clearHand();
	int handTotal();
	void printValueOfCard(int i);
	bool getCardDealt(int i);
	bool bust();
	void checkAce();
	void printResult();
	int deckCount();
private:
	Card playDeck[52];
};


#endif // DECK_H
