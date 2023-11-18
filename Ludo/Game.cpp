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
    player1.MovePiece(0, 0, 59, board, circle, player1.px);
    player2.MovePiece(1, 0, 6, board, circle, player2.px);
   
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

    bool first = false;
    bool second = false;
    bool third = false;
    bool fourth = false;

    bool enter[4] = { false, false , false, false };
    bool pushed = false; // jesli true to przycisk num jest wcisniety
    bool noMove = false;
    bool check = false;

    bool sixThrown = false;

    int score[4] = { 0, 0, 0, 0 };

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
                    
                    if (event.key.code == sf::Keyboard::Enter && (enter[0] || enter[1] || enter[2] || enter[3])) {
                        int j;
                        int x;
                        int y;
                        int g;
                        for (int i = 0; i < 4; i++) {
                            if (enter[i]) {
                                j = i;
                            }
                        }
                        sf::Vector2f currentPosition = circle[currentPlayer][j].getPosition();
                        x = currentPosition.x;
                        y = currentPosition.y;
                        if (players[currentPlayer].IsPawnInPlay(currentPlayer, j, circle)) { //bo bez sensu jest sprawdzanie czy pionek wychodzacy cos kuje
                            for (int h = 0; h < 61; h++) {
                                if (players[currentPlayer].px[h].x * 40 == x && players[currentPlayer].px[h].y * 40 == y) {
                                    g = h;
                                }
                            }

                            int x_1 = players[currentPlayer].px[g + diceCount].x * 40;
                            int y_1 = players[currentPlayer].px[g + diceCount].y * 40;
                            check = players[currentPlayer].IfCheckmate(currentPlayer, x_1, y_1, circle, players[currentPlayer].px);
                            if (g + diceCount == 60) {
                                ++score[currentPlayer];

                            }
                        }

                        players[currentPlayer].MovePiece(currentPlayer, j, diceCount, board, circle, players[currentPlayer].px);

                        

                        if (diceCount == 6) {
                            sixThrown = true;
                        }

                        if (check || sixThrown) {
                            pushed = false;
                            diceThrown = false;

                            for (int i = 0; i < 4; i++) {
                                circle[currentPlayer][i].setOutlineColor(sf::Color::Black);
                            }
                            for (int i = 0; i < 4; i++) {
                                enter[i] = false;
                            }
                        }
                        else if (!check) {
                            pushed = false;
                            diceThrown = false;

                            for (int i = 0; i < 4; i++) {
                                circle[currentPlayer][i].setOutlineColor(sf::Color::Black);
                            }
                            for (int i = 0; i < 4; i++) {
                                enter[i] = false;
                            }
                            ++currentPlayer;
                            if (currentPlayer == 4) {
                                currentPlayer = 0;
                            }
                        }
                        
                       
                        sixThrown = false;
                        check = false;
                    } else if (event.key.code == sf::Keyboard::Enter && noMove) {
                        noMove = false;
                        diceThrown = false;
                        ++currentPlayer;
                        if (currentPlayer == 4) {
                            currentPlayer = 0;
                        }
                    }
                    if (event.key.code == sf::Keyboard::Num1 && first ) { 
                        for (int i = 0; i < 4; i++) {
                            if (i == 0) {
                                enter[i] = true;
                            }
                            else {
                                enter[i] = false;
                            }
                        }
                        pushed = true;
                    }
                    if (event.key.code == sf::Keyboard::Num2 && second ) {
                        for (int i = 0; i < 4; i++) {
                            if (i == 1) {
                                enter[i] = true;
                            }
                            else {
                                enter[i] = false;
                            }
                        }
                        pushed = true;
                    }
                    if (event.key.code == sf::Keyboard::Num3 && third ) {
                        for (int i = 0; i < 4; i++) {
                            if (i == 2) {
                                enter[i] = true;
                            }
                            else {
                                enter[i] = false;
                            }
                        }
                        pushed = true;
                    }
                    if (event.key.code == sf::Keyboard::Num4 && fourth ) {
                        for (int i = 0; i < 4; i++) {
                            if (i == 3) {
                                enter[i] = true;
                            }
                            else {
                                enter[i] = false;
                            }
                        }
                        pushed = true;
                    }
                    if (event.key.code == sf::Keyboard::S && !GameStarted) {
                        GameStarted = true;
                    }
                    if (GameStarted && event.key.code == sf::Keyboard::D && GameStarted && !diceThrown) {
                        std::srand(std::time(0));
                        Dice dice;
                        diceCount = 1;// dice.Roll();
                        diceThrown = true;
                    }
                    break;
            }
        }
        if (GameStarted) {
            window.clear();
            // Obsluga ruchu gracza

            if (diceThrown) {
                std::string dicetext = std::to_string(diceCount) + " points were rolled for " + playersColors[currentPlayer] ;
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
                    
                    bool pins[4] = { first, second, third, fourth };
                    
                    
                    if (!(pins[0] || pins[1] || pins[2] || pins[3])) {
                        noMove = true;
                    }
                    else {
                        noMove = false;
                    }

                    if (noMove) {
                        std::string noMoveText = "No avaliable moves for " + playersColors[currentPlayer];
                        sf::Text nomoveText(noMoveText, font, 15);
                        nomoveText.setPosition(620, 150);
                        nomoveText.setFillColor(sf::Color::White);
                        nomoveText.setStyle(sf::Text::Bold);

                        window.draw(nomoveText);
                    }
                    else if (!noMove) {
                        std::string text;
                        for (int i = 0; i < 4; i++) {
                            if (i == 0 && pins[i]) {
                                text += "1\t";
                            }
                            if (i == 1 && pins[i]) {
                                text += "\t2\t";
                            }
                            if (i == 2 && pins[i]) {
                                text += "\t3\t";
                            }
                            if (i == 3 && pins[i]) {
                                text += "\t4\t";
                            }
                        }
                        std::string MoveText = "Move is avaliable for :\n\n" + text ;
                        sf::Text moveText(MoveText, font, 15);
                        moveText.setPosition(620, 150);
                        moveText.setFillColor(sf::Color::White);
                        moveText.setStyle(sf::Text::Bold);

                        window.draw(moveText);
                    } 
                    
                    if (pushed) {
                        for (int i = 0; i < 4; i++) {
                            if (enter[i]) {
                                circle[currentPlayer][i].setOutlineColor(sf::Color::White);
                            }
                            else {
                                circle[currentPlayer][i].setOutlineColor(sf::Color::Black);
                            }

                        }
                    }
                    else {
                        for (int i = 0; i < 4; i++) {
                            circle[currentPlayer][i].setOutlineColor(sf::Color::Black);
                        }
                    }
                    
                    //trzeba bedzie ogarnac to że jak wyrzuca sie 6 to rzuca sie koscia jeszcze raz, oraz wtedy kiedy sie kogos skuje
                    //oraz to że jak nie mozna ruszyc zadnym pionkiem to trzeba skipnac jakims przyciskiem
                    
               
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
    