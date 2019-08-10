#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstdlib>
#include <iterator>
#include <ctime>
#include "WarMain.h"
#include "Player.h"
#include "Dealer.h"

using namespace std;

map<int, std::string> cardNames;

void WarMain::DisplayRules()
{
	cout << "~ The objective of the game is to win all of the cards. Each" << endl;
	cout << "~ player recieves half of the  deck (26 cards), facing down." << endl;
	cout << "~ In unison, each  player reveals the top card of their deck" << endl;
	cout << "~ and the player  with the higher card takes both cards.  If" << endl;
	cout << "~ the two cards played are of equal value, then it's WAR!!!!" << endl << endl;
	cout << "~   During WAR, both players place the next card of their" << endl;
	cout << "~   pile face - down and then another card face - up. The" << endl;
	cout << "~   owner of the higher  face - up card wins  the war and" << endl;
	cout << "~   adds all  of the cards  to the bottom  of their deck." << endl << endl;
	cout << "~   If the  face - up  cards are  again  equal, then  the" << endl;
	cout << "~   battle  repeats with  another set of face - down / up" << endl;
	cout << "~   cards. This repeats until  one player's  face-up card" << endl;
	cout << "~   is higher than their opponent's." << endl << endl;
	cout << "~ If either  player runs  out of cards, the  game is over" << endl;
	cout << "~ and the player who ran out of cards loses the game.  If" << endl;
	cout << "~ both  players  run out of cards  at the  same time, the" << endl;
	cout << "~ game ends in a tie!" << endl << endl;
	cout << "~ The game can be played in fast mode or slow mode!!" << endl << endl;
}

// Check if we need to pause or just keep going depending on slowMod flag
void WarMain::CheckSpeedMode() {
	if (slowMode == true) {
		system("pause");
	}
}

// Manage what happens when player's flipped cards were equal and War is to begin
bool WarMain::ManageWar(Player& humanPlayer, Player& computerPlayer)
{
	bool inWar = true;
	bool gameOver = false;
	int humanPlayerCard;
	int computerPlayerCard;

	cout << "Both cards are equal! This means war!" << endl;
	CheckSpeedMode();

	// Keep looping while we are in war and the game is not yet over
	while ((inWar == true) && (gameOver == false))
	{
		// For war, there needs to be at least 2 cards.  One face down and one face up.
		if (humanPlayer.GetPlayerDeckSize() < 2 || computerPlayer.GetPlayerDeckSize() < 2)
		{
			cout << "You can't war with 1 card. Skipping war, we have a WINNER!" << endl;
			gameOver = true;
		}
		else
		{
			cout << "~ Dealing 2 cards for you and the Computer ~" << endl;
			cout << "~ Comparing card 2 ~" << endl;

			// Get 2 cards each and flip over second one for both players
			humanPlayerCard = humanPlayer.Flip(2);
			computerPlayerCard = computerPlayer.Flip(2);

			cout << "Your Card: " << cardNames[humanPlayerCard] << endl;
			cout << "The Computer's Card: " << cardNames[computerPlayerCard] << endl;

			// Check if we have a winner
			if (humanPlayerCard > computerPlayerCard)
			{
				humanPlayer.AddInSideDeck(computerPlayer.playersSideDeck);
				humanPlayer.AddInSideDeck(humanPlayer.playersSideDeck);
				humanPlayer.playersSideDeck.clear();
				computerPlayer.playersSideDeck.clear();
				cout << "You win the War! You get all cards! You now have " << humanPlayer.GetPlayerDeckSize() << " cards!" << endl;
				inWar = false;
			}
			else if (computerPlayerCard > humanPlayerCard)
			{
				computerPlayer.AddInSideDeck(humanPlayer.playersSideDeck);
				computerPlayer.AddInSideDeck(computerPlayer.playersSideDeck);
				humanPlayer.playersSideDeck.clear();
				computerPlayer.playersSideDeck.clear();
				cout << "The computer won the War! The computer get all cards!  You now have " << humanPlayer.GetPlayerDeckSize() << " cards!" << endl;
				inWar = false;
			}

			CheckSpeedMode();
		}
	}

	return gameOver;
}

int main()
{
	bool gameOver = false;
	char input;
	int round = 1;
	bool playAgain = true;
	srand(static_cast<unsigned int>(time(NULL)));

	// Initalize the card names to go along with the card number
	cardNames[2] = "Two";
	cardNames[3] = "Three";
	cardNames[4] = "Four";
	cardNames[5] = "Five";
	cardNames[6] = "Six";
	cardNames[7] = "Seven";
	cardNames[8] = "Eight";
	cardNames[9] = "Nine";
	cardNames[10] = "Ten";
	cardNames[11] = "Jack";
	cardNames[12] = "Queen";
	cardNames[13] = "King";
	cardNames[14] = "Ace";

	// Create all of our game objects
	WarMain ourGameOfWar;
	Dealer dealer;
	Player humanPlayer;
	Player computerPlayer;

	// Loop while we are still playing
	while (playAgain == true)
	{
		cout << "Welcome to the Game of War!" << endl;
		cout << "Press 'R' to see rules or press anything else' to continue!" << endl;
		cin >> input;

		if (input == 'R' || input == 'r')
		{
			ourGameOfWar.DisplayRules();
			system("pause");
		}

		cout << "Press 'F' to play in Fast Mode or press anything else to play in Slow Mode!" << endl;
		cin >> input;

		if (input == 'F' || input == 'f')
		{
			ourGameOfWar.slowMode = false;
		}
		else 
		{
			ourGameOfWar.slowMode = true;
		}

		cout << "Let's play!" << endl;
		cout << "~ Generating a deck and giving each player half of the cards ~" << endl;

		// Have our dealer setup our initial deck and the decks for each player. Clear the side decks.  
		dealer.GameStartInitialize();
		humanPlayer.SetPlayersDeck(dealer.GetPlayer1Deck());
		computerPlayer.SetPlayersDeck(dealer.GetPlayer2Deck());
		humanPlayer.ClearSideDeck();
		computerPlayer.ClearSideDeck();

		// Make sure both players have enough cards to continue playing (at least 1 card)
		while (gameOver == false)
		{
			cout << "Round " << round << endl;
			cout << "~ Dealing top card for you and the Computer ~" << endl;

			// Each player flips over 1 card off top of their deck (maintain side cards already flipped in side deck)
			int humansCard = humanPlayer.Flip(1);
			int computersCard = computerPlayer.Flip(1);

			// Check if game is over. If so, skip checking the flip.
			if (gameOver == false)
			{
				cout << "Your Card: " << cardNames[humansCard] << endl;
				cout << "The Computer's Card: " << cardNames[computersCard] << endl;

				// Check who won the flip
				if (humansCard > computersCard)
				{
					humanPlayer.AddInSideDeck(computerPlayer.playersSideDeck);
					humanPlayer.AddInSideDeck(humanPlayer.playersSideDeck);
					humanPlayer.playersSideDeck.clear();
					computerPlayer.playersSideDeck.clear();
					cout << "You win! You get both cards! You now have " << humanPlayer.GetPlayerDeckSize() << " cards!" << endl;
					ourGameOfWar.CheckSpeedMode();
				}
				else if (computersCard > humansCard)
				{
					computerPlayer.AddInSideDeck(humanPlayer.playersSideDeck);
					computerPlayer.AddInSideDeck(computerPlayer.playersSideDeck);
					humanPlayer.playersSideDeck.clear();
					computerPlayer.playersSideDeck.clear();
					cout << "The Computer wins! It takes both cards! You now have " << humanPlayer.GetPlayerDeckSize() << " cards!" << endl;
					ourGameOfWar.CheckSpeedMode();
				}
				else if (humansCard == computersCard)
				{
					// We are now at war!!!
					gameOver = ourGameOfWar.ManageWar(humanPlayer, computerPlayer);
				}
			}

			// Check if we have a winner (someone has all cards) or we went to War and game is over during war
			if ((humanPlayer.GetPlayerDeckSize() == 52) ||
				((gameOver == true) && (humanPlayer.GetPlayerDeckSize() > computerPlayer.GetPlayerDeckSize())))
			{
				cout << "You've won! Congratulations!" << endl;
				gameOver = true;
				ourGameOfWar.CheckSpeedMode();
			}
			else if ((computerPlayer.GetPlayerDeckSize() == 52) ||
				((gameOver == true) && (computerPlayer.GetPlayerDeckSize() > humanPlayer.GetPlayerDeckSize())))
			{
				cout << "The computer has won! Better luck next time!" << endl;
				gameOver = true;
				ourGameOfWar.CheckSpeedMode();
			}

			round++;
			cout << endl;
		}

		cout << "Would you like to play again? (Press 'Y' for yes or 'N' for no)";
		cin >> input;

		if (input == 'Y' || input == 'y')
		{
			round = 1;
			playAgain = true;
			gameOver = false;
			humanPlayer.ClearSideDeck();
			computerPlayer.ClearSideDeck();
		}

		else if (input == 'N' || input == 'n')
		{
			cout << "Thanks for playing!" << endl;
			break;
		}
	}
}