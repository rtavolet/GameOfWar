#ifndef WARMAIN_HEADER
#define WARMAIN_HEADER

#include <map>
#include <string>
#include "Player.h"

const int NUM_OF_PLAYERS = 2;
const int NUM_CARDS_IN_FULL_DECK = 52;
const int PLAYER_DECK_START_SIZE = NUM_CARDS_IN_FULL_DECK / NUM_OF_PLAYERS;
const int NUM_OF_CARDS_PER_SUIT = 13;
const int NUM_OF_SUITS_PER_DECK = 4;
const int LOWEST_CARD_IN_DECK = 2;

// WarMain class
class WarMain
{
public:
	void DisplayRules();                                             // Displays the rules to the game of `
	bool ManageWar(Player& humanPlayer, Player& computerPlayer);     // Manage a war
	void CheckSpeedMode();                                           // Check if we want to pause depending on speed mode

	bool slowMode;                                                   // Reflects what mode we are in (slow or fast)
};

#endif