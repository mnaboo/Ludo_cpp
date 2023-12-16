#include "Player.h"
#include <iostream>

void Player::MovePiece(int player, int pawn, int steps, sf::RectangleShape board[15][15], sf::CircleShape circle[4][4]) { // player to pierwsza wspolrzedna circle a pawn to druga
    int x_0 = px[0].x * 40;
    int y_0 = px[0].y * 40;
    // zrob petle ktora nie pozwala wyrzucic iles kostek pod rzad
    system("cls");
    std::cout << "Dice: " << steps << std::endl;
    switch (steps) {
    case 6:
        /*if (this->SixesLimit()) { // jezeli wyrzuci sie pod rzad
            break;
        }
        else*/ if (!IsPawnInPlay(player, pawn, circle)) {
            circle[player][pawn].setPosition(x_0, y_0); // wpuszczenie pionka do gry
            std::cout << "Wpuszczono pionka do gry" << std::endl;
        }
        else {
            Conditions(player, pawn, steps, circle);
        }
        // dodaj obsluge ponownego rzutu 
        break;
    default:
        if (!IsPawnInPlay(player, pawn, circle)) {

        }
        else {
            sixes = 0;
            Conditions(player, pawn, steps, circle);
            //sf::Vector2f currentPosition = circle[player][pawn].getPosition();
            //int x = currentPosition.x;
            //int y = currentPosition.y;
            //std::cout << "currentX: " << x/40 << "\t" << "currentY: " << y/40 << std::endl;
            //std::cout << "Dice: " << steps << std::endl;
            //int i = 0;
            //for (int j = 0; j < 61; j++) {
            //    if (p1[j].x * 40 == x && p1[j].y * 40 == y) {
            //        i = j;
            //    }
            //}
            //if (i == 60) {  // sprawdza czy skonczono gre, jak tak to nie mozna ruszyc pionkiem
            //    break;
            //}
            //if (i > 54 && i + steps > 60) { // sprawdza czy ruch przy mecie jest mozliwy
            //    break;
            //}
            //else {
            //    int x_1 = p1[i + steps].x * 40;
            //    int y_1 = p1[i + steps].y * 40;
            //    std::cout << "laterX: " << x_1 / 40 << "\t" << "laterY: " << y_1 / 40 << "\n" << std::endl;
            //    circle[player][pawn].setPosition(x_1, y_1);
            //    //circle[player][pawn].setPosition(  );
            //}
        }



    }
}



bool Player::IsPawnInPlay(int player, int pawn, sf::CircleShape circle[4][4]) // mozna to skrocic tym Cordsem w Board.h chyba
{
    sf::Vector2f position = circle[player][pawn].getPosition();
    switch (player) {
    case 0:
        switch (pawn) {
        case 0:
        case 1:
        case 2:
        case 3:
            if (position.x <= 120 && position.x >= 80 && position.y <= 480 && position.y >= 440) {
                return false;
            }
            else {
                return true;
            }
            break;
        }
        break;
    case 1:
        switch (pawn) {
        case 0:
        case 1:
        case 2:
        case 3:
            if (position.x <= 120 && position.x >= 80 && position.y <= 120 && position.y >= 80) {
                return false;
            }
            else {
                return true;
            }
            break;
        }
        break;
    case 2:
        switch (pawn) {
        case 0:
        case 1:
        case 2:
        case 3:
            if (position.x <= 480 && position.x >= 440 && position.y <= 120 && position.y >= 80) {
                return false;
            }
            else {
                return true;
            }
            break;
        }
        break;
    case 3:
        switch (pawn) {
        case 0:
        case 1:
        case 2:
        case 3:
            if (position.x <= 480 && position.x >= 440 && position.y <= 480 && position.y >= 440) {
                return false;
            }
            else {
                return true;
            }
            break;
        }
        break;
    }
}

bool Player::Conditions(int player, int pawn, int steps, sf::CircleShape circle[4][4])
{
    system("cls");
    sf::Vector2f currentPosition = circle[player][pawn].getPosition();
    int x = currentPosition.x;
    int y = currentPosition.y;
    std::cout << "previousX: " << x / 40 << "\t" << "previousY: " << y / 40 << std::endl;
    std::cout << "Dice: " << steps << std::endl;
    int i = 0;
    for (int j = 0; j < 61; j++) {
        if (px[j].x * 40 == x && px[j].y * 40 == y) {
            i = j;
        }
    }
    if (i == 60) {  // sprawdza czy skonczono gre, jak tak to nie mozna ruszyc pionkiem
        return false;
    }
    if (i > 54 && i + steps > 60) { // sprawdza czy ruch przy mecie jest mozliwy
        return false;
    }
    else {
        int x_1 = px[i + steps].x * 40;
        int y_1 = px[i + steps].y * 40;
        std::cout << "currentX: " << x_1 / 40 << "\t" << "currentY: " << y_1 / 40 << "\n" << std::endl;
        Checkmate(player, x_1, y_1, circle);
        bool check = Checkmate(player, x_1, y_1, circle);
        if (check) {
            return true;
        }
        circle[player][pawn].setPosition(x_1, y_1);
        return false;
        //circle[player][pawn].setPosition(  );
    }
}


bool Player::SixesLimit()
{
    this->sixes ++;
    if (sixes >= 3) {
        std::cout << "Wyrzucono 3 szostki pod rzad" << std::endl;
        return true;
    }
    else {
        return false;
    }
}

bool Player::Checkmate(int player , int x, int y, sf::CircleShape circle[4][4])
{   
    //moze jakajs zmienna do liczenia ile jes pionkow na jednym polu

    Board board;
    Cords enemyStartCords;
    sf::Vector2f enemyPostion;

    int enemyNum = 0;

    int player_enemy = 0;
    int pawn_enemy = 0;
    
    for (int i = 0; i < 61; i++) {
        
        if (px[i].x == x/40 && px[i].y == y/40) { //sprawdza czy pole na ktore sie rusza jest safe
            if (px[i].safe) {
                //std::cout << "Nie ma skucia";
                return false; //nie ma skucia //ten bool przyda sie pozniej przy wyswietlaniu komentarzy na ekranie o tym czy bylo jakiejs skucie
                
            }
            else {
                
                for (int p = 0; p < 4; p++) {

                    if (p == player) continue; // nie ma sensu sprawdzac czy na tym polu znajduja sie pionki tego samego gracza

                    for (int paw = 0; paw < 4; paw++) {
                        enemyPostion = circle[p][paw].getPosition();
                        if (enemyPostion.x == x && enemyPostion.y == y) {
                            player_enemy = p;
                            pawn_enemy = paw;
                            ++enemyNum;
                        }
                    }
               }
                if (enemyNum == 0) {
                    //std::cout << "Nie ma skucia";
                    return false; //nie ma skucia
                }
                else if (enemyNum > 1) {
                    //std::cout << "Nie ma skucia";
                    return false; //mozna cos tutaj wymyslic dla tego żeby pokazac na ekranie ile jakich pionkow jest na jednym polu
                                  //jesli nie bedzie mi sie chcialo bawic w zabawy z rozmiarami pionkow
                }
                else {
                    enemyStartCords = board.GetRespawnPoint(player_enemy, pawn_enemy);
                    circle[player_enemy][pawn_enemy].setPosition(enemyStartCords.x, enemyStartCords.y);
                    //std::cout << "Skucie";
                    return true;
                }

            }
        }
    }
    //jesli nie jest to sprawdza czy jest na nim jakijs przeciwnik
    //jesli jest 2 lub wiecej przeciwnikow to nic sie nie dzieje
}

void Player::InitiateSafeSpaces()
{
    px[0].safe = true;
    px[9].safe = true;
    px[14].safe = true;
    px[23].safe = true;
    px[28].safe = true;
    px[37].safe = true;
    px[42].safe = true;
    px[51].safe = true;
}

void Player::getRedCords() {
    Cords p1[61];
    int j = 0;
    InitiateSafeSpaces();
    for (int i = 0; i < 6; ++i) { // 0 - 5

        p1[i].x = 6;
        p1[i].y = 13 - j;
        j++;
    }
    j = 0;
    for (int i = 6; i < 12; ++i) { // 6 - 11

        p1[i].x = 5 - j;
        p1[i].y = 8;
        ++j;
    }
    j = 0;
    for (int i = 12; i < 14; ++i) { // 12 - 13

        p1[i].x = 0;
        p1[i].y = 7 - j;
        j++;
    }
    j = 0;
    for (int i = 14; i < 20; ++i) { // 14 - 19

        p1[i].x = 1 + j;
        p1[i].y = 6;
        j++;
    }
    j = 0;
    for (int i = 20; i < 26; ++i) { // 20 - 25

        p1[i].x = 6;
        p1[i].y = 5 - j;
        j++;
    }
    j = 0;
    for (int i = 26; i < 28; ++i) { // 26 - 27

        p1[i].x = 7 + j;
        p1[i].y = 0;
        j++;
    }
    j = 0;
    for (int i = 28; i < 34; ++i) { // 28 - 33

        p1[i].x = 8;
        p1[i].y = 1 + j;
        j++;
    }
    j = 0;
    for (int i = 34; i < 40; ++i) { // 34 - 39

        p1[i].x = 9 + j;
        p1[i].y = 6;
        j++;
    }
    j = 0;
    for (int i = 40; i < 42; ++i) { // 40 - 41

        p1[i].x = 14;
        p1[i].y = 7 + j;
        j++;
    }
    j = 0;
    for (int i = 42; i < 48; ++i) { // 42 - 47

        p1[i].x = 13 - j;
        p1[i].y = 8;
        j++;
    }
    j = 0;
    for (int i = 48; i < 54; ++i) { // 48 - 53

        p1[i].x = 8;
        p1[i].y = 9 + j;
        j++;
    }
    j = 0;
    for (int i = 54; i < 61; ++i) { // 54 - 62

        p1[i].x = 7;
        p1[i].y = 14 - j;
        j++;
    }
    j = 0;

    for (int i = 0; i < 61; ++i) {
        px[i] = p1[i];
    }
    /*
    for (int i = 0; i < 61; i++) {
        std::cout << i << " : " << "x: " << p1[i].x << "  y: " << p1[i].y << std::endl;
    }
    */
}

void Player::getGreenCords()
{
    Cords p2[61];
    int j = 0;
    InitiateSafeSpaces();
    for (int i = 0; i < 6; ++i) {
        p2[i].x = 1 + j;
        p2[i].y = 6;
        j++;
    }
    j = 0;
    for (int i = 6; i < 12; ++i) {
        p2[i].x = 6;
        p2[i].y = 5 - j;
        j++;
    }
    j = 0;
    for (int i = 12; i < 14; ++i) {
        p2[i].x = 7 + j;
        p2[i].y = 0;
        j++;
    }
    j = 0;
    for (int i = 14; i < 20; ++i) {
        p2[i].x = 8;
        p2[i].y = 1 + j;
        j++;
    }
    j = 0;
    for (int i = 20; i < 26; ++i) {
        p2[i].x = 9 + j;
        p2[i].y = 6;
        j++;
    }
    j = 0;
    for (int i = 26; i < 28; ++i) {
        p2[i].x = 14;
        p2[i].y = 6 + j;
        j++;
    }
    j = 0;
    for (int i = 28; i < 34; ++i) {
        p2[i].x = 13 - j;
        p2[i].y = 8;
        j++;
    }
    j = 0;
    for (int i = 34; i < 40; ++i) {
        p2[i].x = 8;
        p2[i].y = 9 + j;
        j++;
    }
    j = 0;
    for (int i = 40; i < 42; ++i) {
        p2[i].x = 7 - j;
        p2[i].y = 14;
        j++;
    }
    j = 0;
    for (int i = 42; i < 48; ++i) {
        p2[i].x = 6;
        p2[i].y = 13 - j;
        j++;
    }
    j = 0;
    for (int i = 48; i < 54; ++i) {
        p2[i].x = 5 - j;
        p2[i].y = 8;
        j++;
    }
    j = 0;
    for (int i = 54; i < 61; ++i) {
        p2[i].x = j;
        p2[i].y = 7;
        j++;
    }
    j = 0;

    for (int i = 0; i < 61; ++i) {
        px[i] = p2[i];
    }

}

void Player::getYellowCords()
{
    Cords p3[61];
    int j = 0;
    InitiateSafeSpaces();
    for (int i = 0; i < 6; ++i) { // 0 - 5

        p3[i].x = 8;
        p3[i].y = 1 + j;
        j++;
    }
    j = 0;
    for (int i = 6; i < 12; ++i) { // 6 - 11

        p3[i].x = 9 + j;
        p3[i].y = 6;
        ++j;
    }
    j = 0;
    for (int i = 12; i < 14; ++i) { // 12 - 13

        p3[i].x = 14;
        p3[i].y = 7 + j;
        j++;
    }
    j = 0;
    for (int i = 14; i < 20; ++i) { // 14 - 19

        p3[i].x = 13 - j;
        p3[i].y = 8;
        j++;
    }
    j = 0;
    for (int i = 20; i < 26; ++i) { // 20 - 25

        p3[i].x = 8;
        p3[i].y = 9 + j;
        j++;
    }
    j = 0;
    for (int i = 26; i < 28; ++i) { // 26 - 27

        p3[i].x = 7 - j;
        p3[i].y = 14;
        j++;
    }
    j = 0;
    for (int i = 28; i < 34; ++i) { // 28 - 33

        p3[i].x = 6;
        p3[i].y = 13 - j;
        j++;
    }
    j = 0;
    for (int i = 34; i < 40; ++i) { // 34 - 39

        p3[i].x = 5 - j;
        p3[i].y = 8;
        j++;
    }
    j = 0;
    for (int i = 40; i < 42; ++i) { // 40 - 41

        p3[i].x = 0;
        p3[i].y = 7 - j;
        j++;
    }
    j = 0;
    for (int i = 42; i < 48; ++i) { // 42 - 47

        p3[i].x = 1 + j;
        p3[i].y = 6;
        j++;
    }
    j = 0;
    for (int i = 48; i < 54; ++i) { // 48 - 53

        p3[i].x = 6;
        p3[i].y = 5 - j;
        j++;
    }
    j = 0;
    for (int i = 54; i < 61; ++i) { // 54 - 62

        p3[i].x = 7;
        p3[i].y = j;
        j++;
    }
    j = 0;

    for (int i = 0; i < 61; ++i) {
        px[i] = p3[i];
    }
}

void Player::getBlueCords()
{
    Cords p4[61];
    int j = 0;
    InitiateSafeSpaces();
    for (int i = 0; i < 6; ++i) { // 0 - 5

        p4[i].x = 13 - j;
        p4[i].y = 8;
        j++;
    }
    j = 0;
    for (int i = 6; i < 12; ++i) { // 6 - 11

        p4[i].x = 8;
        p4[i].y = 9 + j;
        ++j;
    }
    j = 0;
    for (int i = 12; i < 14; ++i) { // 12 - 13

        p4[i].x = 7 - j;
        p4[i].y = 14;
        j++;
    }
    j = 0;
    for (int i = 14; i < 20; ++i) { // 14 - 19

        p4[i].x = 6;
        p4[i].y = 13 - j;
        j++;
    }
    j = 0;
    for (int i = 20; i < 26; ++i) { // 20 - 25

        p4[i].x = 5 - j;
        p4[i].y = 8;
        j++;
    }
    j = 0;
    for (int i = 26; i < 28; ++i) { // 26 - 27

        p4[i].x = 0;
        p4[i].y = 7 - j;
        j++;
    }
    j = 0;
    for (int i = 28; i < 34; ++i) { // 28 - 33

        p4[i].x = 1 + j;
        p4[i].y = 6;
        j++;
    }
    j = 0;
    for (int i = 34; i < 40; ++i) { // 34 - 39

        p4[i].x = 6;
        p4[i].y = 5 - j;
        j++;
    }
    j = 0;
    for (int i = 40; i < 42; ++i) { // 40 - 41

        p4[i].x = 7 + j;
        p4[i].y = 0;
        j++;
    }
    j = 0;
    for (int i = 42; i < 48; ++i) { // 42 - 47

        p4[i].x = 8;
        p4[i].y = 1 + j;
        j++;
    }
    j = 0;
    for (int i = 48; i < 54; ++i) { // 48 - 53

        p4[i].x = 9 + j;
        p4[i].y = 6;
        j++;
    }
    j = 0;
    for (int i = 54; i < 61; ++i) { // 54 - 62

        p4[i].x = 14 - j;
        p4[i].y = 7;
        j++;
    }
    j = 0;

    for (int i = 0; i < 61; ++i) {
        px[i] = p4[i];
    }
}

bool Player::IfCheckmate(int player, int x, int y, sf::CircleShape circle[4][4])
{
    //moze jakajs zmienna do liczenia ile jes pionkow na jednym polu

    Board board;
    Cords enemyStartCords;
    sf::Vector2f enemyPostion;

    int enemyNum = 0;

    int player_enemy = 0;
    int pawn_enemy = 0;

    for (int i = 0; i < 61; i++) {

        if (px[i].x == x / 40 && px[i].y == y / 40) { //sprawdza czy pole na ktore sie rusza jest safe
            if (px[i].safe) {
                //std::cout << "Nie ma skucia";
                return false; //nie ma skucia //ten bool przyda sie pozniej przy wyswietlaniu komentarzy na ekranie o tym czy bylo jakiejs skucie

            }
            else {

                for (int p = 0; p < 4; p++) {

                    if (p == player) continue; // nie ma sensu sprawdzac czy na tym polu znajduja sie pionki tego samego gracza

                    for (int paw = 0; paw < 4; paw++) {
                        enemyPostion = circle[p][paw].getPosition();
                        if (enemyPostion.x == x && enemyPostion.y == y) {
                            player_enemy = p;
                            pawn_enemy = paw;
                            ++enemyNum;
                        }
                    }
                }
                if (enemyNum == 0) {
                    //std::cout << "Nie ma skucia";
                    return false; //nie ma skucia
                }
                else if (enemyNum > 1) {
                    //std::cout << "Nie ma skucia";
                    return false; //mozna cos tutaj wymyslic dla tego żeby pokazac na ekranie ile jakich pionkow jest na jednym polu
                    //jesli nie bedzie mi sie chcialo bawic w zabawy z rozmiarami pionkow
                }
                else {

                    //std::cout << "Skucie";
                    return true;
                }

            }
        }
    }
    //jesli nie jest to sprawdza czy jest na nim jakijs przeciwnik
    //jesli jest 2 lub wiecej przeciwnikow to nic sie nie dzieje
}











