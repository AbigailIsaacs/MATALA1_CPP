#pragma once 
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
namespace ariel{
      enum CardNumber {
            TWO=1,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,JACK,QUEEN,KING,ACE
        };

        enum CardShape {
            HEARTS=1,DIAMONDS,CLUBS,SPADES
        };

    class Card{
        public:
            CardNumber num ;
            CardShape shape ;
            std::string print();
            Card(CardNumber CardNumber,CardShape CardShape);

    };
}