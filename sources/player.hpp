#pragma once 
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
namespace ariel{
    class Player{
    
        public:
            string name;
            int stacksize(){
                return 0;
            }
            int cardesTaken(){
                return 0;
            }
            Player(){}
            Player(string n){
                name =n;
        }

    };
}