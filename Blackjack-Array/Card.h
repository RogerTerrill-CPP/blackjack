#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

class Card
{
public:
	Card();
	
	//Setter
	void setSuit(string _suit);
	void setRank(string _rank);
	void setValue(int _value);
	void setDealt(bool _dealt);

	//Getter
	string getSuit();
	string getRank();
	int getValue();
	bool getDealt();
	
	//Other Functions
	string printCard();
private:
	string suit;
	string rank;
	int value;
	bool dealt;
};

#endif // CARD_H
