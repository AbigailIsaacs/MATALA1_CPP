
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "card.hpp"
namespace ariel{
  
  
        Card::Card(CardNumber CardNumber,CardShape CardShape)  
        :num(CardNumber),shape(CardShape) 
        {   
            
        }

             
     
        std::string Card::print(){
            std::string sute;
            std::string number;
            switch (shape) {
                case HEARTS:
                    sute = "HEARTS";
                    break;
                case DIAMONDS:
                    sute = "DIAMONDS";
                    break;
                case CLUBS:
                    sute = "CLUBS";
                    break;
                case SPADES:
                    sute = "SPADES";
                    break;
        
            }

            switch (num) {
                case TWO:
                    number = "TWO";
                    break;
                case THREE:
                    number = "THREE";
                    break;
                case FOUR:
                    number = "FOUR";
                    break;
                case FIVE:
                    number = "FIVE";
                    break;
                case SIX:
                    number = "SIX";
                    break;
                case SEVEN:
                    number = "SEVEN";
                    break;
                case EIGHT:
                    number = "EIGHT";
                    break;
                case NINE:
                    number = "NINE";
                    break;
                case TEN:
                    number = "TEN";
                    break;
                case JACK:
                    number = "JACK";
                    break;
                case QUEEN:
                    number = "QUEEN";
                    break;
                case KING:
                    number = "KING";
                    break;
                case ACE:
                    number = "ACE";
                    break;
        
            }
            
            return ( number + " of " + sute);

        }
     
    
}