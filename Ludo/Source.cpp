#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Dice.h"
#include "Game.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Player.h"



int main() {
    
    Game game;
    game.Init();

    
    //const int WINDOW_WIDTH = 1000;
    //const int WINDOW_HEIGHT = 600;

    //sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Wietnamczyk");
    //sf::CircleShape circle[4][4];
    //sf::RectangleShape board[15][15];
    //Board board1;
    //board1.InitializeBoard(board, circle);

    //std::srand(std::time(0));
    //Dice dice;
    //int result = dice.Roll();

    //Player player1;
    //Player player2;
    //Player player3;
    //Player player4;

    //player1.getRedCords();
    //player2.getGreenCords();
    //player3.getYellowCords();
    //player4.getBlueCords();
    ////sf::Vector2f position = circle[0][0].getPosition();
    ////std::cout << position.x << "  " << position.y << std::endl;
    ////std::cout << board1.IsPawnInPlay(3, 0, circle);

    //player1.MovePiece(0, 0, 6, board, circle, player1.px);
    ///*sf::Vector2f currentPosition = circle[0][0].getPosition();
    //std::cout << currentPosition.x << "\t" << currentPosition.y;*/
    //player2.MovePiece(1, 0, 6, board, circle, player2.px);
    //player3.MovePiece(2, 0, 6, board, circle, player3.px);
    //player4.MovePiece(3, 0, 6, board, circle, player4.px);
   
    //sf::Font font;
    //if (!font.loadFromFile("C:/Users/macie/Desktop/SFML/SFML-2.6.0/fontt.ttf")) {
    //    //bedzie error jak nie zaladuje czcionki
    //    return -1;
    //}

    //sf::Text text("L U D O", font, 30);
    //text.setPosition(715, 10);
    //text.setFillColor(sf::Color::White);
    //text.setStyle(sf::Text::Bold);



    //while (window.isOpen()) {
    //    sf::Event event;
    //    while (window.pollEvent(event)) {
    //        
    //        switch (event.type) {
    //            case sf::Event::Closed:
    //                window.close();
    //                break;
    //            case sf::Event::KeyPressed:
    //                if (event.key.code == sf::Keyboard::Escape) { //mozna wyjsc za pomoca escape
    //                    window.close();
    //                }
    //                if (event.key.code == sf::Keyboard::Num1) { 
    //                    player1.MovePiece(0, 0, dice.Roll(), board, circle, player1.px);
    //                }
    //                if (event.key.code == sf::Keyboard::Num2) { 
    //                    player2.MovePiece(1, 0, dice.Roll(), board, circle, player2.px);
    //                }
    //                if (event.key.code == sf::Keyboard::Num3) {
    //                    player3.MovePiece(2, 0, dice.Roll(), board, circle, player3.px);
    //                }
    //                if (event.key.code == sf::Keyboard::Num4) {
    //                    player4.MovePiece(3, 0, dice.Roll(), board, circle, player4.px);
    //                }
    //                break;
    //            //trzeba bedzie tutaj napisac jakiejs instrukcje do eventow
    //        }
    //    }

    //    window.clear();
    //    //rysowanie planszy
    //    for (int row = 0; row < 15; ++row) {
    //        for (int col = 0; col < 15; ++col) {
    //            window.draw(board[row][col]);
    //        }
    //    }
    //    window.draw(text);
    //    //rysowanie pionkow
    //    for (int player = 0; player < 4; ++player) {
    //        for (int pin = 0; pin < 4; ++pin) {
    //            window.draw(circle[player][pin]);
    //        }
    //    }
    //    window.display();
    //    
    //}
   
    return 0;
}