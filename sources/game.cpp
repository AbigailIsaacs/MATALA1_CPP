
#include "player.hpp"
#include "card.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "game.hpp"

namespace ariel{

    Game::Game(Player& player1,Player& player2): p1(player1),p2(player2)
    {
        p1.sksize = 26;
        p2.sksize = 26;
        turns.emplace_back("game starst hear:");
       
        if (player1.isPlaying || player2.isPlaying){
            throw exception();
        }
     
        p1.isPlaying = true;
        p2.isPlaying = true;
        
        for (int shapeInt = HEARTS; shapeInt <= SPADES; shapeInt++) {
            CardShape shape = static_cast<CardShape>(shapeInt);            
            for (int numInt = TWO; numInt <= ACE; numInt++) {
                CardNumber num = static_cast<CardNumber>(numInt);
                Card card = { num, shape };
                deck.push_back(card);
            }
        
        }
        // Shuffle the deck
        std::srand(std::time(0));
        std::random_shuffle(deck.begin(), deck.end());
        
    }

    int Game::playTurn(){
        if(&p1 == &p2){
            throw exception();
        }
        if (gameover){
            throw exception();
        }
        if (deck.empty()){
            gameover = true; 
            p1.isPlaying = false;
            p2.isPlaying = false;
            return 0;
        }

        
        // Take out a random card
        Card p1Card = deck.back();
        deck.pop_back();

        Card p2Card = deck.back();
        deck.pop_back();

        p1.sksize = p1.sksize -1;
        p2.sksize = p2.sksize -1;

        if(p1Card.num > p2Card.num){
            if(p2Card.num == 1 && p1Card.num==13){
                p2.csTaken += 2;
                turns.emplace_back(p1.name +"s card is :" + p1Card.print() + "\n"+p2.name +"s card is :"+  p2Card.print() +"\n "+p2.name +" takes the cards\n");
            }
            else {
                p1.csTaken += 2;
                turns.emplace_back(p1.name +"s card is :" + p1Card.print() +"\n"+ p2.name +"s card is :"+ p2Card.print()  +"\n "+p1.name +" takes the cards\n");
            }
            return 1;
        }
        else if(p1Card.num < p2Card.num){
            if(p1Card.num == 1 && p2Card.num==13){
                p1.csTaken += 2;
                turns.emplace_back(p1.name +"s card is:" + p1Card.print() +"\n"+ p2.name +"s card is :"+ p2Card.print() +"\n"+p1.name +" takes the cards\n");

            }
            else{
                p2.csTaken += 2;
                turns.emplace_back(p1.name +"s card is:" + p1Card.print() +"\n"+ p2.name +"s cardis :"+p2Card.print()  +"\n"+p2.name +" takes the cards\n");
            }
            return 2;
        }
        else {

                turns.emplace_back(p1.name +"s card is:" + p1Card.print() +"\n"+ p2.name +"s cardis :"+p2Card.print()  +"\n there is a tie\n");
                numofties = numofties +1;
            if (deck.empty()){
                gameover = true; 
                p1.csTaken += 1;
                p2.csTaken += 1;
                p1.isPlaying = false;
                p2.isPlaying = false;
                return 0;
            }
            // Take out a random card
            Card p1Card = deck.back();
            deck.pop_back();

            Card p2Card = deck.back();
            deck.pop_back();

            p1.sksize = p1.sksize -1;
            p2.sksize = p2.sksize -1;

            if (deck.empty()){
                 gameover = true; 
                p1.csTaken += 1;
                p2.csTaken += 1;
                p1.isPlaying = false;
                p2.isPlaying = false;
            
                return 0;
            }
            int win = playTurn();
            if(win==1){
                p1.csTaken += 4;
            }
            else{
                p2.csTaken += 4;
            }  
        }
        return 0;
    }

    void Game::playAll(){
        while (!deck.empty()){
            playTurn();
        } 
        gameover= true;
        
    }

    void Game::printLog(){

        for (std::vector<std::string>::size_type i = 0; i < turns.size(); i++) {
        std::cout <<" \n"<< turns.at(i) << " \n";
         }
    }
    
    void Game::printLastTurn(){ 
        std::cout << turns.back();
    }

    void Game::printWiner(){
        if (p1.cardesTaken() > p2.cardesTaken())
            std::cout<< p1.name << " is the winner"<< endl;
        else if (p1.cardesTaken() < p2.cardesTaken())
            std::cout<< p2.name << " is the winner"<< endl;
        else 
            std::cout<< "there is a tie betwin player 1 and player 2";
    }

    void Game::printStats(){
        if (deck.empty()){
            printWiner();
        }
        else{
            std::cout<< "there are " << deck.size()<<" cards left in the deck";
            if (p1.cardesTaken() > p2.cardesTaken())
                std::cout<< p1.name << " is leading"<< endl;
            else if (p1.cardesTaken() < p2.cardesTaken())
                std::cout<< p2.name << " is leading"<< endl;
            else 
                std::cout<<  p1.name << " and " << p2.name << " have the same number of cards "<<endl;
        }
        std::cout << "number of cards that " << p1.name << " took is:" << p1.csTaken <<endl; 
        std::cout << "number of cards that " << p2.name << " took is:" << p2.csTaken <<endl; 
        std::cout << "number of ties in the game: "<< numofties<< endl;

        }
}

