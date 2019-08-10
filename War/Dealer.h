#ifndef DEALER_HEADER
#define DEALER_HEADER

#include <vector>

// Card Dealer class
class Dealer
{
private:
	void ShufflePlayerDecks();                  // Shuffle the cards in each players deck.
	void CreateFullDeck();                      // Creates a full deck of cards containing 13 cards of 4 suits
	void CreatePlayerDecks();                   // Takes full deck and splits cards into 2 small stacks for 2 players

	std::vector <int> fullDeck;                 // The full deck of cards storage
	std::vector <int> player1Cards;             // Player 1 cards storage
	std::vector <int> player2Cards;             // Player 2 cards storage

public:
	Dealer(void);                               // Constructor
	void GameStartInitialize();                 // Initialize a new deck and 2 players decks
	std::vector <int> GetPlayer1Deck();         // Get player #1s deck of cards and return to caller
	std::vector <int> GetPlayer2Deck();         // Get player #2s deck of cards and return to caller
};

#endif