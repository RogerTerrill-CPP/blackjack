/*************************************************************************************
 * File:		Blackjack.cpp
 * Project:		CSCI 123, Hanley Williams, Spring 2016, Final Project
 * Authors:		Elisha Rivera, Roger Chicas-Terrill
 * Date:		5/16/2016
 * 
 * 	This file contains a blackjack game with a Cards Class
 * 	and a Deck class that will display cards and keep track
 * 	of the players money and cards in deck even if they exit
 * 	to the main menu.
**************************************************************************************/

#include <iostream>
#include "Deck.h"
using namespace std;

//The play funcion prototype
void play(int& dollars, Deck& game);

int main()
{
	//An Deck object is created forthe playing deck.
	Deck playingDeck;
	
	//Initial values are created for multiple variables
	int choice = 0;
	bool quit =  false;
	int dollars = 10;
	int numDecks = 0;
	
	//Display a welcome screen for the player
	cout << "******************************************************" << endl;
	cout << "******************WELCOME TO BLACKJACK****************" << endl;
	cout << "******************************************************" << endl << endl << endl;
	
	//The game is live until user chooses quit 
	while(quit == false)
	{
		//Menu displays options as well as number of cards currently in deck
		cout << "*************************************************" << endl;
		cout << "**********The number of decks is: (" << numDecks << ") ***********" << endl;
		cout << "*************************************************" << endl;
		cout << "Please choose an option:" << endl;
		cout << "(1) New Deck" << endl;
		cout << "(2) Erase Deck" << endl;
		cout << "(3) Shuffle cards in Deck" << endl;
		cout << "(4) Display all cards remaining in the deck." << endl;
		cout << "(5) Play BlackJack" << endl;
		cout << "(6) Quit" << endl;
		cin >> choice;
		
		//A switch to run function based on choise provided by player
		switch (choice)
		{
			case 1:
				playingDeck.newDeck();
				cout << "*******************************" << endl;
				cout << "******You have a new deck******" << endl;
				cout << "*******************************" << endl << endl;
				numDecks++;
				break;
			case 2:
				playingDeck.clearHand();
				numDecks = 0;
				cout << "*******************************" << endl;
				cout << "***Your deck has been erased***" << endl;
				cout << "*******************************" << endl << endl;
				break;
			case 3:
				playingDeck.shuffle();
				cout << "*******************************" << endl;
				cout << "**Your deck has been shuffled**" << endl;
				cout << "*******************************" << endl << endl;
				break;
			case 4:
				if(numDecks == 0)
					cout << "You don't have any decks in the game.\nPlease add one or more decks with option (1)" << endl;
				playingDeck.printDeck();
				cout << endl << endl;
				break;
			case 5:
				play(dollars, playingDeck);
				break;
			case 6:
				quit = true;
				cout << "Thank you for playing";
			default:
				cout << "Wrong selection, please try again" << endl << endl;
		}
	}
}

/**********************************************************************************
 * Name:			play(int& dollars, Deck& game)
 * Arguements:		int& dollars, Deck& game
 * Returns:			None
 * Precondition:	Deck object, int dollars
 * Post Condition:	Play a game of blackjack and return to main the dollars and 
 * 					cards in a deck
************************************************************************************/
void play(int& dollars, Deck& game)
{
	//Deck for player and dealer are created
	Deck player, dealer;
	
	//Both player and dealer have there hands wiped
	player.clearHand();
	dealer.clearHand();
	
	//Declare and initialize variables
	int bet = 0;
	char hit = 'Y';
	char anotherHand = 'Y';
	
	//Begin loop as long as there is money and player wants to continue
	do
	{	
		//Display to player if money is zero
		if (dollars == 0)
		{
			cout << "Sorry you have no money....goodbye." << endl << endl;
			return;
		}
		
		//Check to see if the playingDeck is empty and display message if it is.
		if (game.emptyDeck())
		{
			cout << "Sorry there are not enough cards to continue to play,\nplease make new deck in main menu and shuffle." << endl << endl;
			return;
		}
		
		//Display dollars left and how much to bet
		cout << "You have " << dollars << " dollars. How much do you want to bet? ";
		cin >> bet;
		
		//Confirms that the bet is no more than what the player has
		while(bet > dollars)
		{
			cout << "Sorry you don't have enough money, bet less. "<< endl;
			cout << "You have " << dollars << " dollars. How much do you want to bet? ";
			cin>> bet;
		}
		
		cout << endl << endl;
		
		//Deal both to dealer and player, the first two cards each.
		game.deal(dealer);
		game.deal(dealer);
		game.deal(player);
		game.deal(player);
		
		//Display first uknown card and 2nd known dealer card as well as two player cards
		cout << "|>>>>>>>>>>>>>>>>>Dealer's Hand<<<<<<<<<<<<<<<<|" << endl;
		cout << "\n ____________________\n|                    |\n|  ?                 |\n|                    |\n|                    |\n|        $$$         |\n|      $$   $$       |\n|           $$       |\n|          $$        |\n|         $$         |\n|         $$         |\n|                    |\n|         $$         |\n|                    |\n|                    |\n|                 ?  |\n|____________________|\n" << endl;
		cout << dealer.printCardinHand(1) << endl << endl;
		cout << "|>>>>>>>>>>>>>>>>>Player's Hand<<<<<<<<<<<<<<<<|" << endl;
		cout << player.printCardinHand(0) << endl;
		cout << player.printCardinHand(1) << endl << endl;
		
		//Check to see if the Ace needs to change from value=11 to value=1
		dealer.checkAce();
		player.checkAce();
		
		//Declare and initialize the card count for displaying card dealt to player
		int count = 2;
		
		cout << "Do you want a card? [Y/N] ";
		cin >> hit;
		while(hit == 'Y' || hit == 'y')
		{			
			cout << endl;

			game.deal(player);
			cout << "Player takes a card: " << player.printCardinHand(count++) << endl << endl;
			cout << "|>>>>>>>>>>>>>>>>>Dealer's Hand<<<<<<<<<<<<<<<<|" << endl;
			cout << "\n ____________________\n|                    |\n|  ?                 |\n|                    |\n|                    |\n|        $$$         |\n|      $$   $$       |\n|           $$       |\n|          $$        |\n|         $$         |\n|         $$         |\n|                    |\n|         $$         |\n|                    |\n|                    |\n|                 ?  |\n|____________________|\n" << endl;
			cout << dealer.printCardinHand(1) << endl << endl;
			cout << endl << endl;;
			cout << "|>>>>>>>>>>>>>>>>>Player's Hand<<<<<<<<<<<<<<<<|" << endl;
			cout << player.printCardinHand(0) << endl;
			player.printResult();
			cout << endl;
			player.checkAce();
				
			//If player bust, then round over and player loses money
			if (player.bust())
			{
				cout << "Results:" << endl << endl;
				cout << "|>>>>>>>>>>>>>>>>>Dealer's Hand<<<<<<<<<<<<<<<<|" << endl;
				cout << dealer.printCardinHand(0) << endl;
				dealer.printResult();
				cout << endl << endl;;
				cout << "|>>>>>>>>>>>>>>>>>Dealer's Hand<<<<<<<<<<<<<<<<|" << endl;
				cout << player.printCardinHand(0) << endl;
				player.printResult();
				cout << "You busted!!!" << endl << endl;
				dollars -= bet;
				break;
			}
			cout << "Do you want a card? [Y/N] ";
			cin >> hit;
		
		}
		
		//If player did not bust
		if(!player.bust())
		{
			//Declare and initialize card count for dealer
			int card = 2;
			//Deal a card to dealer as long as count is under 17
			while (dealer.handTotal() < 17)
			{
				game.deal(dealer);
				cout << "Dealer takes a card: " << dealer.printCardinHand(card++) << endl;
				dealer.checkAce();
			}
			
			//Display the results when done
			cout << endl;
			cout << "Dealer stands..." << endl << endl;
			cout << "Results:" << endl << endl;
			cout << "|>>>>>>>>>>>>>>>>>Dealer's Hand<<<<<<<<<<<<<<<<|" << endl;
			cout << dealer.printCardinHand(0) << endl;
			dealer.printResult();
			cout << endl << endl;
			cout << "|>>>>>>>>>>>>>>>>>Player's Hand<<<<<<<<<<<<<<<<|" << endl;
			cout << player.printCardinHand(0) << endl;
			player.printResult();
			
			//Check if dealer bust and display message as well as award player money
			if (dealer.bust())
			{	
				cout << endl;
				cout << "Dealer bust, YOU WIN!!!" << endl << endl;
				dollars += bet;
			}
			//Else check the value of player vs dealer to determine winner and display message
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
		
		//Display if money is zero
		if (dollars == 0)
		{
			cout << "Sorry you have no money....goodbye." << endl << endl;
			return;
		}
		
		//Check if deck is empty and instructing player to add another deck
		if (game.emptyDeck())
		{
			cout << "Sorry there are not enough cards to continue to play,\nplease make new deck in main menu and shuffle." << endl <<endl;
			return;
		}
		
		//Display money left over
		cout << "You have " << dollars << " dollars, wanny try again? [Y/N] ";
		cin >> anotherHand;
		cout << endl;
		//Clear player and dealers hand.
		player.clearHand();
		dealer.clearHand();
	}while (dollars > 0 && (anotherHand == 'Y' || anotherHand == 'y'));
	
}