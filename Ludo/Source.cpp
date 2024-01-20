#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Dice.h"
#include "Game.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Player.h"
#include <windows.h>

//int CALLBACK WinMain(
//    _In_ HINSTANCE hInstance,
//    _In_ HINSTANCE hPrevInstance,
//    _In_ LPSTR     lpCmdLine,
//    _In_ int       nCmdShow
//) {
//    Game game;
//    game.Init();
//
//    return 0;
//}
//WinMain, zeby nie wyswietlala sie konsola, zakomentowalem wszystkie cout i cls
int main() {
    
    Game game;
    game.Init();
   
    return 0;
}