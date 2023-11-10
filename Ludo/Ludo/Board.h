#pragma once
#include <SFML/Graphics.hpp>
#include "Cords.h"

class Board
{
    Cords spawnPositions[4][4] = {
        // Dla gracza 0
        {{80, 480}, {80, 440}, {120, 480}, {120, 440}},

        // Dla gracza 1
        {{80, 80}, {80, 120}, {120, 80}, {120, 120}},

        // Dla gracza 2
        {{440, 80}, {440, 120}, {480, 80}, {480, 120}},

        // Dla gracza 3
        {{440, 440}, {440, 480}, {480, 440}, {480, 480}}
    };

public:
	void InitializeBoard(sf::RectangleShape  board[15][15], sf::CircleShape  circle[4][4]);
	void DisplayMovablePawns();
	void SetSpawnPosition(int player, int pawn, sf::CircleShape  circle[4][4]);
    Cords GetRespawnPoint(int player, int pawn);
};

