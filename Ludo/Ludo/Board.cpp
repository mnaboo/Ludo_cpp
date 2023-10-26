#include "Board.h"
#include <SFML/Graphics.hpp>

void Board::InitializeBoard(sf::RectangleShape board[15][15])
{
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 800;

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Wietnamczyk");

    sf::CircleShape circle;
    circle.setRadius(20.0f); // Promien kola
    circle.setFillColor(sf::Color::Blue); // Kolor wypelnienia
    circle.setOutlineColor(sf::Color::Red); // Kolor konturu
    circle.setOutlineThickness(2.0f); // Grubosc konturu
    circle.setPosition(0.0f, 0.0f); // Pozycja kola (x, y)
    // Initialize the board, e.g., set colors and positions of the squares
    for (int row = 0; row < 15; ++row) {
        for (int col = 0; col < 15; ++col) {
            board[row][col].setSize(sf::Vector2f(40, 40));
            board[row][col].setPosition(col * 40, row * 40);
            board[row][col].setOutlineColor(sf::Color::Black); // obramowanie
            board[row][col].setOutlineThickness(0.5f);

            // Example colors for different areas on the board
            if ((row < 6 && col < 6) || (row < 6 && col > 8) || (row > 8 && col < 6) || (row > 8 && col > 8)) {
                board[row][col].setFillColor(sf::Color::Cyan);
            }
            else {
                board[row][col].setFillColor(sf::Color::White);
            }

            if ((row == 1 && col > 0 && col < 5) || (row == 4 && col > 0 && col < 5) || (row > 1 && row < 4 && (col == 1 || col == 4))) { // lewy gorny
                board[row][col].setFillColor(sf::Color::Green);
            }
            else if ((row == 10 && col > 0 && col < 5) || (row == 13 && col > 0 && col < 5) || (row > 10 && row < 13 && (col == 1 || col == 4))) { // lewy dolny
                board[row][col].setFillColor(sf::Color::Red);
            }
            else if ((row == 1 && col > 9 && col < 14) || (row == 4 && col > 9 && col < 14) || (row > 1 && row < 4 && (col == 10 || col == 13))) { // prawy gorny
                board[row][col].setFillColor(sf::Color::Yellow);
            }
            else if ((row == 10 && col > 9 && col < 14) || (row == 13 && col > 9 && col < 14) || (row > 10 && row < 13 && (col == 10 || col == 13))) { // prawy dolny
                board[row][col].setFillColor(sf::Color::Blue);
            }


            if ((row == 6 && col == 1) || (row == 7 && col > 0 && col < 7)) { // lewy gorny
                board[row][col].setFillColor(sf::Color::Green);
            }
            else if ((row == 13 && (col == 6 || col == 7)) || (row > 7 && row < 14 && col == 7)) { //lewy dolny
                board[row][col].setFillColor(sf::Color::Red);
            }
            else if ((row == 1 && (col == 7 || col == 8)) || (row > 1 && row < 7 && col == 7)) { // prawy gorny
                board[row][col].setFillColor(sf::Color::Yellow);
            }
            else if ((row == 8 && col == 13) || (row == 7 && col > 7 && col < 14)) { // prawy dolny
                board[row][col].setFillColor(sf::Color::Blue);
            }


            if ((row == 2 || row == 3) && ((col == 2 || col == 3) || (col == 11 || col == 12))) {
                board[row][col].setFillColor(sf::Color::White);
            }
            else if ((row == 11 || row == 12) && ((col == 2 || col == 3) || (col == 11 || col == 12))) { //wypelnienie
                board[row][col].setFillColor(sf::Color::White);
            }


            if (row == 8 && col == 2) {
                board[row][col].setFillColor(sf::Color::Color(128, 128, 128, 255));
            }
            else if (row == 2 && col == 6) {
                board[row][col].setFillColor(sf::Color::Color(128, 128, 128, 255));
            }
            else if (row == 6 && col == 12) {
                board[row][col].setFillColor(sf::Color::Color(128, 128, 128, 255));
            }
            else if (row == 12 && col == 8) {
                board[row][col].setFillColor(sf::Color::Color(128, 128, 128, 255));
            }
        }
    }
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            window.clear();

            for (int row = 0; row < 15; ++row) {
                for (int col = 0; col < 15; ++col) {
                    window.draw(board[row][col]);
                }
            }
            window.display();
        }
}
