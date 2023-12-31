﻿#include "Board.h"
#include <SFML/Graphics.hpp>
#include "Cords.h"
#include <vector> //wydaje mi sie ze moze byc to nie potrzebne bo jest juz w iostream
#include <iostream>

void Board::InitializeBoard(sf::RectangleShape  board[15][15], sf::CircleShape  circle[4][4])
{
   

    
    /*
    circle[4][4].setRadius(20.0f); // Promien kola
    circle[4][4].setFillColor(sf::Color::Blue); // Kolor wypelnienia                  //dokonczyc to zeby renderowaly sie na planszy
    circle[4][4].setOutlineColor(sf::Color::Red); // Kolor konturu
    circle[4][4].setOutlineThickness(2.0f); // Grubosc konturu
    circle[4][4].setPosition(0.0f, 0.0f); // Pozycja kola (x, y)
    // Initialize the board, e.g., set colors and positions of the squares
    */
    for (int player = 0; player < 4; ++player) {
        for (int pin = 0; pin < 4; ++pin) {
            circle[player][pin].setRadius(20);
            circle[player][pin].setOutlineThickness(2);
            circle[player][pin].setOutlineColor(sf::Color::Black);

            if (player == 0) {

                circle[player][pin].setFillColor(sf::Color::Red);
            }
            else if (player == 1) {
                circle[player][pin].setFillColor(sf::Color::Green);
            }
            else if (player == 2) {
                circle[player][pin].setFillColor(sf::Color::Yellow);
            }
            else if (player == 3) {
                circle[player][pin].setFillColor(sf::Color::Blue);
            }

        }
    }

    circle[0][0].setPosition(80, 480); //lewy dolny
    circle[0][1].setPosition(80,440);
    circle[0][2].setPosition(120, 480);
    circle[0][3].setPosition(120, 440);

    circle[1][0].setPosition(80, 80); //lewy gorny
    circle[1][1].setPosition(80, 120);
    circle[1][2].setPosition(120, 80);
    circle[1][3].setPosition(120, 120);

    circle[2][0].setPosition(440, 80); //prawy gorny
    circle[2][1].setPosition(440, 120);
    circle[2][2].setPosition(480, 80);
    circle[2][3].setPosition(480, 120);

    circle[3][0].setPosition(440, 440); //prawy dolny
    circle[3][1].setPosition(440, 480);
    circle[3][2].setPosition(480, 440);
    circle[3][3].setPosition(480, 480);

    for (int row = 0; row < 15; ++row) {
        for (int col = 0; col < 15; ++col) {
            board[row][col].setSize(sf::Vector2f(40, 40));
            board[row][col].setPosition(col * 40, row * 40);
            board[row][col].setOutlineColor(sf::Color::Black); // obramowanie
            board[row][col].setOutlineThickness(1.0f);

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
        
}








void Board::SetSpawnPosition(int player,int pawn, sf::CircleShape  circle[4][4])
{
    if (player >= 0 && player < 4 && pawn >= 0 && pawn < 4) {
        circle[player][pawn].setPosition(spawnPositions[player][pawn].x, spawnPositions[player][pawn].y);
    }
    else {
        //moze jakajajs obsluga erroru
    }
}


Cords Board::GetRespawnPoint(int player, int pawn)
{
    return spawnPositions[player][pawn];
}


std::vector<int> Board::GetMovablePawns(int player, int steps, Cords px[61], sf::CircleShape circle[4][4]) {
    Player playerInstance;
    int x, y;
    std::vector<int> pawnPlacementOnBoard1;

    /*int lol[4] = { NULL,NULL,NULL,NULL };
    int cnt = 0;*/

    for (int pawn = 0; pawn < 4; pawn++) {
        sf::Vector2f currentPosition = circle[player][pawn].getPosition();
        x = currentPosition.x;
        y = currentPosition.y;
        std::cout << x << "\t" << y << std::endl;
        Cords currentCords = GetRespawnPoint(player, pawn);

        for (int j = 0; j < 61; j++) {
            
            if (px[j].x * 40 == x && px[j].y * 40 == y) {
                int i = j;
                //pawnPlacementOnBoard1.push_back(pawn);
                switch (steps) {
                case 6:
                    if (playerInstance.IsPawnInPlay(player, pawn, circle) && !((i == 60) || (i > 54 && i + steps > 60))) {
                        pawnPlacementOnBoard1.push_back(pawn);
                    }
                    else if (!((i == 60) || (i > 54 && i + steps > 60))) {
                        pawnPlacementOnBoard1.push_back(pawn);
                    }
                    break;
                default:
                    if (playerInstance.IsPawnInPlay(player, pawn, circle) && !((i == 60) || (i > 54 && i + steps > 60))) {
                        pawnPlacementOnBoard1.push_back(pawn);
                    }
                    break;
                }
            } else if (currentCords.x == x && currentCords.y == y) {
                switch (steps) {
                case 6:
                    if (!playerInstance.IsPawnInPlay(player, pawn, circle)) {
                        pawnPlacementOnBoard1.push_back(pawn);
                    }
                    break;
                default:
                    break;
                }
            }
        }
    }
    std::cout << pawnPlacementOnBoard1.size() << std::endl;
    return pawnPlacementOnBoard1;
}
    


bool Board::isPawnMovable(int player, int pawn, int steps, Cords px[61], sf::CircleShape circle[4][4])
{
    Player playerInstance;
    int x, y;

    
        sf::Vector2f currentPosition = circle[player][pawn].getPosition();
        x = currentPosition.x;
        y = currentPosition.y;
        /*std::cout << x << "\t" << y << std::endl;
        std::cout << px[0].x * 40 << "\t" << px[0].y * 40 << std::endl;*/
        Cords currentCords = GetRespawnPoint(player, pawn);

        for (int j = 0; j < 61; j++) {
            
            if (px[j].x * 40 == x && px[j].y * 40 == y) {

                int i = j;
                

                switch (steps) {
                case 6:
                    if (playerInstance.IsPawnInPlay(player, pawn, circle) && !((i == 60) || (i > 54 && i + steps > 60))) {
                        return true;
                    }
                    else if (!((i == 60) || (i > 54 && i + steps > 60))) {
                        return true;
                    }
                    break;
                default:
                    if (playerInstance.IsPawnInPlay(player, pawn, circle) && !((i == 60) || (i > 54 && i + steps > 60))) {
                        return true;
                    }
                    break;
                }
            }
        }
        if (currentCords.x == x && currentCords.y == y) { //to dla tych z respawn point
             switch (steps) {
                case 6:
                    if (!playerInstance.IsPawnInPlay(player, pawn, circle)) {
                        return true;
                    }
                    break;
                default:
                    break;
                }
            }
        
    
    return false;
}


