#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

int const CARDS_IN_DECK = 52;
Deck::Deck()
{
}

void Deck::newDeck()
{
	string faces[] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
	string suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	int value[] = { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
	
	//vectorDeck.erase(vectorDeck.begin(), vectorDeck.end());
	for (int count = 0; count < CARDS_IN_DECK; count++)
		vectorDeck.push_back(Card(suits[count/13], faces[count%13], value[count%13]));
}

void Deck::shuffle()
{
	random_shuffle(vectorDeck.begin(), vectorDeck.end());
}

void Deck::printDeck()
{
	for(int i = 0; i < vectorDeck.size(); i++)
		cout << vectorDeck[i].printCard() << endl;
}

void Deck::deal(Deck& inputDeck)
{

	inputDeck.vectorDeck.push_back(vectorDeck[0]);
	vectorDeck.erase(vectorDeck.begin());
}

int Deck::handTotal()
{
	int total = 0;
	for (int i = 0; i < vectorDeck.size(); i++)
		total += vectorDeck[i].getValue();
	return total;
}

string Deck::printCardinHand(int i)
{
	return vectorDeck[i].printCard();
}

int Deck::valueOfCard(int i)
{
	return vectorDeck[i].getValue();
}

bool Deck::bust()
{
	if(handTotal() > 21)
		return true;
}

void Deck::checkAce()
{
	for (int i = 0; i < vectorDeck.size(); i++)
		if ((handTotal() > 21) && (vectorDeck[i].getValue() == 11))
			vectorDeck[i].setValue(1);
}

void Deck::printResult()
{
	for (int i = 1; i < vectorDeck.size(); i++)
		cout << "\t\t" << vectorDeck[i].printCard() << endl;
}

bool Deck::emptyDeck()
{
	if (vectorDeck.size() == 0)
		return true;
}

void Deck::clearHand()
{
	vectorDeck.erase(vectorDeck.begin(), vectorDeck.end());
}