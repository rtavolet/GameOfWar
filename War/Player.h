#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include <vector>

// Player class
class Player
{
public:
	Player(void);								     // Constructor
	int Flip(int cardNnumCardsToFlip);				 // Gets first or second card, depending on numCardsToFlip. 
													 // Both are added to the side deck and taken out of the main deck.
	void RemoveTop();                                // Erase first entry at beginning of playersDeck
	void InsertBottom(int card);                     // Insert entry passed in to end of playersDeck
	void SetPlayersDeck(std::vector <int> deck);     // Return the players deck to the caller
	void AddInSideDeck(std::vector <int> deck);      // Insert deck passed in at end of playersDeck
	int GetPlayerDeckSize();						 // Return the players deck size to the caller
	void ClearSideDeck();							 // Clears player's side deck

	std::vector <int> playersDeck;                   // Players deck storage
	std::vector <int> playersSideDeck;               // Players side deck for cards that have been played but not won yet.
};

#endif