#pragma once 
#include "player.hpp"
#include "card.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
namespace ariel{
    class Game{
  
        public:
            std::vector<ariel::Card> deck;
            std::vector<std::string> turns;
            Player& p1;
            Player& p2;
            int stacksize;
            int numofties =0 ;
            bool gameover = false;
            Game(Player& player1,Player& player2 );
            void printLastTurn();
            int playTurn();
            void playAll();
            void printWiner();
            void printLog();
            void printStats();
        };
}