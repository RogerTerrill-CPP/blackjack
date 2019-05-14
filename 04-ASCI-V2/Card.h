#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

class Card
{
public:
	//Constructor
	Card();
	//Overloaded constructor to create card object
	Card(string _suit, string _rank, int _value);
	
	//Setters
	void setSuit(string _suit);
	void setRank(string _rank);
	void setValue(int _value);

	//Getters
	string getSuit();
	string getRank();
	int getValue();
	
	//Other Functions
	string displaySuit(); //Displays ASCI graphic of each card suit
	string printCard(); //Displays card with Rank and ASCI graphics
private:
	//Declare variabls for properties of card
	string suit;
	string rank;
	int value;
};

#endif // CARD_H
