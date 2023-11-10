#pragma once
#include <SFML/Graphics.hpp>
#include "Cords.h"
#include "Board.h"

class Player
{
	int sixes = 0;
public:
	Cords px[61]; //mozna zrobic tablice 2d
	void MovePiece(int player, int pawn, int steps, sf::RectangleShape board[15][15], sf::CircleShape cirlce[4][4], Cords p1[61]);
	bool IsPawnInPlay(int player, int pawn, sf::CircleShape circle[4][4]);

	void getRedCords();
	void getGreenCords();
	void getYellowCords();
	void getBlueCords();

	void Conditions(int player, int pawn, int steps, sf::CircleShape circle[4][4], Cords p1[61]);
	bool SixesLimit();
	bool Checkmate(int player, int x, int y, sf::CircleShape circle[4][4], Cords p1[61]);
	void InitiateSafeSpaces(Cords px[61]);
};

