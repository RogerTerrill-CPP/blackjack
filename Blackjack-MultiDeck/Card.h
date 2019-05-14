#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

class Card
{
public:
	Card();
	Card(string _suit, string _rank, int _value);
	
	//Setter
	void setSuit(string _suit);
	void setRank(string _rank);
	void setValue(int _value);

	//Getter
	string getSuit();
	string getRank();
	int getValue();
	
	//Other Functions
	string printCard();
private:
	string suit;
	string rank;
	int value;
};

#endif // CARD_H
