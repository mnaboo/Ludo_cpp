#pragma once
#include <SFML/Graphics.hpp>
#include "Cords.h"
#include "Board.h"

class Player
{
	int sixes = 0;
	
public:
	void SetSixes(int steps);
	int GetSixes() const;

	Cords px[61];
	void MovePiece(int player, int pawn, int steps, sf::RectangleShape board[15][15], sf::CircleShape cirlce[4][4]);
	bool IsPawnInPlay(int player, int pawn, sf::CircleShape circle[4][4]);

	void getRedCords();
	void getGreenCords();
	void getYellowCords();
	void getBlueCords();

	bool Conditions(int player, int pawn, int steps, sf::CircleShape circle[4][4]);
	bool SixesLimit();
	bool Checkmate(int player, int x, int y, sf::CircleShape circle[4][4]);
	bool IfCheckmate(int player, int x, int y, sf::CircleShape circle[4][4]);
};

