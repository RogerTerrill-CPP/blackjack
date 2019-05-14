#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <vector>
using namespace std;

class Deck
{
public:
	Deck();
	void newDeck();
	void shuffle();
	void printDeck();
	string printCardinHand(int i);
	void deal(Deck& inputDeck);
	void clearHand();
	int handTotal();
	int valueOfCard(int i);
	bool bust();
	void checkAce();
	void printResult();
	bool emptyDeck();
	
private:
	vector<Card> vectorDeck;
};


#endif // DECK_H
