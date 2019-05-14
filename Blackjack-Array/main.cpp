#include <iostream>
#include "Deck.h"
using namespace std;

void play(int& dollars, Deck& game);

int main()
{
	Deck playingDeck;
	playingDeck.newDeck();
	
	int choice = 0;
	bool quit =  false;
	int dollars = 10;
	
	cout << "******************************************************" << endl;
	cout << "******************WELCOME TO BLACKJACK****************" << endl;
	cout << "******************************************************" << endl << endl << endl;
	
	
	while(quit == false)
	{
		cout << "Please choose an option:" << endl;
		cout << "(1) New Deck" << endl;
		cout << "(2) Shuffle cards in Deck" << endl;
		cout << "(3) Display all cards remaining in the deck." << endl;
		cout << "(4) Play BlackJack" << endl;
		cout << "(5) Quit" << endl;
		cin >> choice;
		
		switch (choice)
		{
			case 1:
				playingDeck.clearHand();
				cout << "*******************************" << endl;
				cout << "******You have a new deck******" << endl;
				cout << "*******************************" << endl << endl;
				break;
			case 2:
				playingDeck.shuffle();
				cout << "*******************************" << endl;
				cout << "**Your deck has been shuffled**" << endl;
				cout << "*******************************" << endl << endl;
				break;
			case 3:
				playingDeck.printDeck();
				break;
			case 4:
				play(dollars, playingDeck);
				break;
			case 5:
				quit = true;
				cout << "Thank you for playing";
			default:
				cout << "Wrong selection, please try again" << endl << endl;
		}
		
	}
}

void play(int& dollars, Deck& game)
{
	Deck player, dealer;
	player.clearHand();
	dealer.clearHand();
	
	int bet = 0;
	char hit = 'Y';
	char anotherHand = 'Y';
	do
	{	
		if (dollars == 0)
		{
			cout << "Sorry you have no money....goodbye." << endl;
			return;
		}
		
		if (game.deckCount() < 4)
		{
			cout << "Sorry there are not enough cards to continue to play,\nplease make new deck in main menu and shuffle." << endl;
			return;
			
		}
		cout << "You have " << dollars << " dollars. How much do you want to bet? ";
		cin >> bet;
		while(bet > dollars)
		{
			cout << "Sorry you don't have enough money, bet less. "<< endl;
			cout << "You have " << dollars << " dollars. How much do you want to bet? ";
			cin>> bet;
		}
		cout << endl << endl;
		game.deal(dealer);
		game.deal(dealer);
		game.deal(player);
		game.deal(player);
		
		
		cout << "Dealer\t:\t ?? ????????" << endl;
		cout << "\t:\t" << dealer.printCardinHand(1) << endl << endl;
		
		cout << "Player\t:\t" << player.printCardinHand(0) << endl;
		cout << "\t:\t" << player.printCardinHand(1) << endl << endl;
		
		dealer.checkAce();
		player.checkAce();
		
		int count = 2;
		
		do
		{
			cout << "Do you want a card? [Y/N] ";
			cin >> hit;
			cout << endl;
			if( hit == 'Y' || hit == 'y')
			{
				game.deal(player);
				cout << "Player takes a card: " << player.printCardinHand(count++) << endl << endl;
				
				cout << "Dealer\t:\t" << dealer.printCardinHand(0) << endl;
				dealer.printResult();
				cout << endl << endl;
				cout << "Player\t:\t" << player.printCardinHand(0) << endl;
				player.printResult();
				cout << endl;
			
				player.checkAce();
				if (player.bust())
				{
					cout << "Results:" << endl << endl;
					cout << "Dealer\t:\t" << dealer.printCardinHand(0) << endl;
					dealer.printResult();
					cout << endl << endl;
					cout << "Player\t:\t" << player.printCardinHand(0) << endl;
					player.printResult();
					cout << "You busted!!!" << endl << endl;
					dollars -= bet;
					
					break;
				}
	
			}
		
		}while(hit == 'Y' || hit == 'y');
		
		if(!player.bust())
		{
			int card = 2;
			while (dealer.handTotal() < 17)
			{
				
				game.deal(dealer);
				cout << "Dealer takes a card: " << dealer.printCardinHand(card) << endl;
				dealer.checkAce();
			}
			cout << endl;
			cout << "Dealer stands..." << endl << endl;
			
			if (dealer.bust())
			{
				cout << "Results:" << endl << endl;
				cout << "Dealer\t:\t" << dealer.printCardinHand(0) << endl;
				dealer.printResult();
				cout << endl << endl;
				cout << "Player\t:\t" << player.printCardinHand(0) << endl;
				player.printResult();
			
				cout << "Dealer bust, YOU WIN!!!";
				dollars += bet;
			}
			
			cout << "Results:" << endl << endl;
			cout << "Dealer\t:\t" << dealer.printCardinHand(0) << endl;
			dealer.printResult();
			cout << endl << endl;
			cout << "Player\t:\t" << player.printCardinHand(0) << endl;
			player.printResult();
			
			if (dealer.bust())
			{	
				cout << endl;
				cout << "Dealer bust, YOU WIN!!!" << endl << endl;
				dollars += bet;
			}
			else if (dealer.handTotal() > player.handTotal() && player.handTotal() < 22)
			{
				cout << "Dealer Wins" << endl << endl;
				dollars -= bet;
			}
			else if (dealer.handTotal() < player.handTotal() && player.handTotal() < 22)
			{
				cout << "Player Wins" << endl << endl;
				dollars += bet;
			}
			else if (dealer.handTotal() == player.handTotal() && player.handTotal() < 22)
			{
				cout << "PUSH!!!" << endl << endl;
			}
		}
		
		
		if (dollars == 0)
		{
			cout << "Sorry you have no money....goodbye." << endl;
			return;
			
		}
		if (game.deckCount() < 4)
		{
			cout << "Sorry there are not enough cards to continue to play,\nplease make new deck in main menu and shuffle." << endl <<endl;
			return;
			
		}
		
		cout << "You have " << dollars << " dollars, wanny try again? [Y/N] ";
		cin >> anotherHand;
		
		cout << endl;
		player.clearHand();
		dealer.clearHand();
	}while (dollars > 0 && (anotherHand == 'Y' || anotherHand == 'y'));
	
}