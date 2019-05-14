#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
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

	for (int count = 0; count < CARDS_IN_DECK; count++)
	{
		playDeck[count].setRank(faces[count % 13]);
		playDeck[count].setSuit(suits[count / 13]);
		playDeck[count].setValue(value[count % 13]);
		playDeck[count].setDealt(false);
	}
}

void Deck::shuffle()
{
	for (int i = 0; i < 52; i++)
	{
		if (playDeck[i].getDealt() == false)
		{
			int second = (rand() + time(0)) % CARDS_IN_DECK;
			Card temp = playDeck[i];
			playDeck[i] = playDeck[second];
			playDeck[second] = temp;
		}
	}
}

string Deck::printCardinHand(int i)
{
	return playDeck[i].printCard();
}
void Deck::printHand()
{
	for (int i = 0; i < CARDS_IN_DECK; i++)
	{
		if (playDeck[i].getDealt() == true)
		{
			cout << playDeck[i].printCard() << endl;
		}
		
	}
}

void Deck::printDeck()
{
	for (int i = 0; i < CARDS_IN_DECK; i++)
	{
		if (playDeck[i].getDealt() == false)
		{
			cout << playDeck[i].printCard() << endl;
		}
		
	}
}

void Deck::clearHand()
{
	for (int i = 0; i < CARDS_IN_DECK; i++)
	{
		playDeck[i].setDealt(false);
	}
}
void Deck::deal(Deck& inputDeck)
{
	for(int i = 0; i < CARDS_IN_DECK; i++)
	{
		if (playDeck[i].getDealt() == false)
		{
			for (int j = 0; j < CARDS_IN_DECK; j++)
			{
				if(inputDeck.playDeck[j].getDealt() == false)
				{
					inputDeck.playDeck[j] = playDeck[i];
					playDeck[i].setDealt(true);
					inputDeck.playDeck[j].setDealt(true);
				break;
				}
			}
			break;
		}
	}
}

int Deck::handTotal()
{
	int total = 0;
	for (int i = 0; i < CARDS_IN_DECK; i++)
	{
		if (playDeck[i].getDealt() == true)
		{
			total += playDeck[i].getValue();
		}		
	}
	return total;
}

void Deck::printValueOfCard(int i)
{
	cout << playDeck[i].getValue();
}

bool Deck::getCardDealt(int i)
{
	return playDeck[i].getDealt();
}

bool Deck::bust()
{
	if(handTotal() > 21)
		return true;
}
void Deck::checkAce()
{
	for (int i = 0; i < CARDS_IN_DECK; i++)
	{
		if (playDeck[i].getDealt() == true && (handTotal() > 21) && (playDeck[i].getValue() == 11))
		{
			playDeck[i].setValue(1);
		}
	}
}

void Deck::printResult()
{
	for (int i = 1; i < CARDS_IN_DECK; i++)
	{
		if (playDeck[i].getDealt() == true)
		{
			cout << "\t\t" << playDeck[i].printCard() << endl;
		}
		
	}
}

int Deck::deckCount()
{
	int count = 0;
	for (int i = 0; i < CARDS_IN_DECK; i++)
	{
		if (playDeck[i].getDealt() == false)
		{
			count++;
		}		
	}
	return count;
}