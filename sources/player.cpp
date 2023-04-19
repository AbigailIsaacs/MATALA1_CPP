
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "player.hpp"
using namespace std;
namespace ariel{

    

    int Player::stacksize(){
        return sksize;
    }
    int Player::cardesTaken(){
        return csTaken;
    }
    Player::Player(){
        name = "player 1";
        isPlaying = false;
    }
    Player::Player(std::string n):name(n){
        isPlaying = false;
}

    
}