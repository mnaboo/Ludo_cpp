#include <SFML/Graphics.hpp>
#include "Board.h"

int main() {
    sf::RectangleShape board[15][15];
    Board board1;
    board1.InitializeBoard(board);
    return 0;
}