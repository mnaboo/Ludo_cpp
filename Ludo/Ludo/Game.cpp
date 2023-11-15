#include "Game.h"
#include <iostream>
#include <thread>
#include <chrono>

int Game::Init()
{
    const int WINDOW_WIDTH = 1000;
    const int WINDOW_HEIGHT = 600;

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Wietnamczyk");
    sf::CircleShape circle[4][4];
    sf::RectangleShape board[15][15];
    Board board1;
    board1.InitializeBoard(board, circle);
    
    std::srand(std::time(0));
    Dice dice;
    int result = dice.Roll();
    
    Player player1;
    Player player2;
    Player player3;
    Player player4;
    
    

    player1.getRedCords();
    player2.getGreenCords();
    player3.getYellowCords();
    player4.getBlueCords();

    Player players[4] = { player1, player2, player3, player4 };
    player1.MovePiece(0, 0, 6, board, circle, player1.px);
    player1.MovePiece(0, 0, 50, board, circle, player1.px);
   
    //player1.MovePiece(0, 0, 58, board, circle, player1.px);
    sf::Font font;
    if (!font.loadFromFile("C:/Users/macie/Desktop/SFML/SFML-2.6.0/fontt.ttf")) {
        //bedzie error jak nie zaladuje czcionki
        return -1;
    }
    
    sf::Text text("L U D O", font, 30);
    text.setPosition(715, 10);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    
    bool GameStarted = false;
    int diceCount = 0;
    int currentPlayer = 0;
    bool diceThrown = false;
    std::string playersColors[] = {"Red","Green","Yellow","Blue"};

    bool first, second, third, fourth;

    sf::Clock blinkClock;
    bool isBlinking = false;
    const sf::Time blinkInterval = sf::seconds(0.5f);
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape) { //mozna wyjsc za pomoca escape
                        window.close();
                    }

                    if (event.key.code == sf::Keyboard::S && !GameStarted) {
                        GameStarted = true;
                    }
                    if (GameStarted && event.key.code == sf::Keyboard::D && GameStarted && !diceThrown) {
                        std::srand(std::time(0));
                        Dice dice;
                        diceCount = 6;//dice.Roll();
                        diceThrown = true;
                    }
                    break;
            }
        }
        if (GameStarted) {
            window.clear();
            // Obsluga ruchu gracza

            if (diceThrown) {
                std::string dicetext = std::to_string(diceCount) + " points were rolled for " + playersColors[currentPlayer] + "\n\n \t\tChoose a pawn";
                sf::Text diceText(dicetext, font, 15);
                diceText.setPosition(620, 100);
                diceText.setFillColor(sf::Color::White);
                diceText.setStyle(sf::Text::Bold);

                window.draw(diceText);

                //z tym "Choose a pawn" mozna mysle wypisac wtedy kiedy jest cos do wybrania a jak nie ma to wyswietlic cos w stylu No matches

                //std::vector<int> pawnPlacementOnBoard = board1.GetMovablePawns(currentPlayer, diceCount, players[currentPlayer].px ,circle);
                
                    first = board1.isPawnMovable(currentPlayer, 0, diceCount, players[currentPlayer].px, circle);
                    second = board1.isPawnMovable(currentPlayer, 1, diceCount, players[currentPlayer].px, circle);
                    third = board1.isPawnMovable(currentPlayer, 2, diceCount, players[currentPlayer].px, circle);
                    fourth = board1.isPawnMovable(currentPlayer, 3, diceCount, players[currentPlayer].px, circle);
                    std::cout << first << "\t" << second << "\t" << third << "\t" << fourth << std::endl;
                    //std::cout << first << std::endl;
                /*if (!isBlinking) {
                    for (int pawnIndex : pawnPlacementOnBoard) {
                        sf::CircleShape& selectedPawn = circle[currentPlayer][pawnIndex];
                        selectedPawn.setOutlineThickness(3.f);
                        selectedPawn.setOutlineColor(sf::Color::White);
                    }
                    isBlinking = true;
                    blinkClock.restart();
                }

                
                sf::Time elapsed = blinkClock.getElapsedTime();
                if (elapsed > blinkInterval) {
                    for (int pawnIndex : pawnPlacementOnBoard) {
                        sf::CircleShape& selectedPawn = circle[currentPlayer][pawnIndex];
                        sf::Color currentOutlineColor = selectedPawn.getOutlineColor();
                        if (currentOutlineColor == sf::Color::White) {
                            selectedPawn.setOutlineColor(sf::Color::Black);
                        }
                        else {
                            selectedPawn.setOutlineColor(sf::Color::White);
                        }
                    }
                    isBlinking = false;
                }*/
            }
            else {
                std::string dicetext = "Throw a dice for " + playersColors[currentPlayer];
                sf::Text diceText(dicetext, font, 20);
                diceText.setPosition(620, 100);
                diceText.setFillColor(sf::Color::White);
                diceText.setStyle(sf::Text::Bold);

                window.draw(diceText);
                //cos z czasem do wyrzutu trzeba bedzie zrobic 
            }
            
            //std::cout << "Ruch gracza " << currentPlayer + 1 << ": Wyrzucono " << diceCount << " oczek." << std::endl;
            // Tutaj dodaj kod do obslugi ruchu gracza, np. podswietlanie pionkow, klikniecie itp.
            // ...

            // Przelaczenie do następnego gracza
           // currentPlayer = (currentPlayer + 1) % 4;

            // Rysowanie planszy w trakcie gry
            for (int row = 0; row < 15; ++row) {
                for (int col = 0; col < 15; ++col) {
                    window.draw(board[row][col]);
                }
            }
            window.draw(text);
            
            // Rysowanie pionkow
            for (int player = 0; player < 4; ++player) {
                for (int pin = 0; pin < 4; ++pin) {
                    window.draw(circle[player][pin]);
                }
            }
            window.display();
        }
    }
        //window.clear();
        ////rysowanie planszy
        //for (int row = 0; row < 15; ++row) {
        //    for (int col = 0; col < 15; ++col) {
        //        window.draw(board[row][col]);
        //    }
        //}
        //window.draw(text);
        ////rysowanie pionkow
        //for (int player = 0; player < 4; ++player) {
        //    for (int pin = 0; pin < 4; ++pin) {
        //        window.draw(circle[player][pin]);
        //    }
        //}
        //window.display();
        
}
    