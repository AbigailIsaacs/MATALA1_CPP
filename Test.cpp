#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;

TEST_CASE("A player cant play with himself"){
    Player p1("Abi");
   CHECK_THROWS_AS(Game game(p1,p1),exception); 
   
}
TEST_CASE("A player cant play in 2 games"){
    Player p1("Abi");
    Player p2("Eli");
    Player p3("Orly");
    Game game(p1,p2);
    CHECK_THROWS_AS(Game game(p1,p3),exception); 
   
}
TEST_CASE("When a game is finished you cant keep on playing"){
    Player p1("Abi");
    Player p2("Eli");
    Game game(p1,p2);
    CHECK_NOTHROW(game.playAll()); 
    CHECK_NOTHROW(game.playTurn()); 
    game.playAll();
    CHECK_THROWS(game.playAll()); 
    CHECK_THROWS(game.playTurn()); 
   
}

TEST_CASE("Stack size is 26 in the beginnig and 0 at the end "){
    Player p1("Abi");
    Player p2("Eli");
    Game game(p1,p2);
    CHECK(p1.stacksize()==26); 
    CHECK(p2.stacksize()==26); 
    for(int i=0;i<26;i++){
        if(p1.stacksize()==0){
            break;
        }
        game.playTurn();
        CHECK(p1.stacksize()<=25-i); 
        CHECK(p2.stacksize()<=25-i);
    }
    CHECK(p1.stacksize()==0); 
    CHECK(p2.stacksize()==0); 
}

TEST_CASE("cardesTaken is correct during the game"){
    Player p1("Abi");
    Player p2("Eli");
    Game game(p1,p2);
    CHECK(p1.cardesTaken()==0); 
    CHECK(p2.cardesTaken()==0); 
    for(int i=0;i<26;i++){
        game.playTurn();
        if (p1.stacksize()!=0){
            CHECK(p1.cardesTaken()%2==0);
            CHECK(p2.cardesTaken()%2==0);
            CHECK((p1.cardesTaken()+p2.cardesTaken())>=2*(i+1)); 
        }
        else{
            break;
        }
    }
    CHECK((p1.cardesTaken()+p2.cardesTaken())==52); 
    
}

TEST_CASE("printLastTurn(),printLog() and printStats() does not throw exeption"){
    Player p1("Abi");
    Player p2("Eli");
    Game game(p1,p2);
    CHECK_NOTHROW(game.printLastTurn()); 
    CHECK_NOTHROW(game.printLog()); 
    CHECK_NOTHROW(game.printStats()); 
    game.playAll();  
    CHECK_NOTHROW(game.printLastTurn()); 
    CHECK_NOTHROW(game.printLog()); 
    CHECK_NOTHROW(game.printStats()); 
}
TEST_CASE("printWiner() throes exeption if the game is not finished"){
    Player p1("Abi");
    Player p2("Eli");
    Game game(p1,p2);
     while(p1.stacksize()!=0){
        CHECK_THROWS(game.printWiner()); 
        game.playTurn();
     } 
     CHECK_NOTHROW(game.printWiner());  
}