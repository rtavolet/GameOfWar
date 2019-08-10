#include <algorithm>
#include "WarMain.h"
#include "Dealer.h"

using namespace std;

// Constructor.  Initialize our state for beginning of a game
Dealer::Dealer(void) {
	GameStartInitialize();
}

// Create our full deck of cards and create 2 smaller decks for 2 players
void Dealer::GameStartInitialize() {
	CreateFullDeck();
	CreatePlayerDecks();
}

// Creating a full deck of cards
void Dealer::CreateFullDeck()
{
	// Make sure our deck is empty prior to starting
	fullDeck.clear();
	

	// Create 52 cards, 4 of each starting at lowest card in the deck (2) through highest card in deck (ACE)
	for (int i = LOWEST_CARD_IN_DECK; i < NUM_OF_CARDS_PER_SUIT + LOWEST_CARD_IN_DECK; i++)
	{
		// Create 4 cards, 1 per suit
		for (int j = 0; j < NUM_OF_SUITS_PER_DECK; j++)
		{
			// Add card to full deck
			fullDeck.push_back(i);
		}
	}
}

// Using our full deck, create 2 smaller shuffled decks for the 2 players
void Dealer::CreatePlayerDecks()
{
	int size = fullDeck.size();
	int newSize = 0;

	// Clear both players decks prior to creating new decks
	player1Cards.clear();
	player2Cards.clear();

	// Randomly fill out player 1's deck and whatever is left goes to player 2
	while (newSize < PLAYER_DECK_START_SIZE)
	{
		int position = rand() % size;
		player1Cards.push_back(fullDeck[position]);
		fullDeck.erase(fullDeck.begin() + position);
		newSize++;
		size--;
	}

	// Player 1's cards are created and the remaining cards are player 2's cards
	player1Cards = player1Cards;
	player2Cards = fullDeck;

	// Make sure player decks are shuffled
	ShufflePlayerDecks();
}

// Shuffle the vectors containing the cards for both players
void Dealer::ShufflePlayerDecks()
{
	random_shuffle(player1Cards.begin(), player1Cards.end());
	random_shuffle(player2Cards.begin(), player2Cards.end());
}

// Return Player 1's deck of cards
std::vector <int> Dealer::GetPlayer1Deck() {
	return(player1Cards);
}

// Return Player 2's deck of cards
std::vector <int> Dealer::GetPlayer2Deck() {
	return(player2Cards);
}