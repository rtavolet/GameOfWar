#include "Player.h"

using namespace std;

// Constructor
Player::Player()
{
	ClearSideDeck();
}

// Clears player's side deck
void Player::ClearSideDeck()
{
	playersSideDeck.clear();
}

//Gets first or second card, depending on numCardsToFlip. Both are added to the side deck and taken out of the main deck.
int Player::Flip(int numCardsToFlip)
{
	int card = 0;

	if (GetPlayerDeckSize() >= numCardsToFlip)
	{
		for (int i = 0; i < numCardsToFlip; i++)
		{
			// Get the new top card or second card and add it to your side deck and take out of main deck
			card = playersDeck.at(0);
			playersSideDeck.insert(playersSideDeck.end(), card);
			RemoveTop();
		}
		return card;
	}
	else
	{
		// Error returned
		return -1;
	}
}

// Erase first entry at beginning of playersDeck
void Player::RemoveTop()
{
	playersDeck.erase(playersDeck.begin());
}

// Insert entry passed in to end of playersDeck
void Player::InsertBottom(int card)
{
	playersDeck.insert(playersDeck.end(), card);
}

// Insert deck passed in at end of playersDeck
void Player::AddInSideDeck(std::vector <int> deck)
{
	playersDeck.insert(playersDeck.end(), deck.begin(), deck.end());
}

// Return the players deck size to the caller
int Player::GetPlayerDeckSize()
{
	return playersDeck.size();
}

// Return the players deck to the caller
void Player::SetPlayersDeck(std::vector <int> deck)
{
	playersDeck = deck;
}