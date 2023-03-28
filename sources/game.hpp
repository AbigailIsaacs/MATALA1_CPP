#pragma once 
#include "player.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
namespace ariel{
class Game{
Player p1,p2;

    public:
        Game(Player player1,Player player2 ){
            p1=player1;
            p2=player2;
        }
        void printLastTurn(){}
        void playTurn(){}
        void playAll(){}
        void printWiner(){}
        void printLog(){}
        void printStats(){}
    };
}