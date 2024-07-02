#ifndef GAMEMODES_H
#define GAMEMODES_H

#include "Common.h"

// Function prototypes
void playerGuesses(std::vector<Player>& players, int maxRange);
void programGuesses(std::vector<Player>& players, int maxRange);
void mixedGame(std::vector<Player>& players, int maxRange);

#endif // GAMEMODES_H