#pragma once 
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
namespace ariel{
    class Player{
    
        public:
            std::string name;
            bool isPlaying = false;
            int csTaken=0 ;
            int sksize = 0;
            
            int stacksize();
            int cardesTaken();
            Player();
            Player(std::string n);

    };
}