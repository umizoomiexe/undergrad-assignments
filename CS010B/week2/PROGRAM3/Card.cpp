
// card.cpp file

#include <iostream>
#include <vector> 
#include <cctype> //tolower function
#include "Card.h"

const vector<string> suits = {"Clubs", "Diamonds", "Hearts", "Spades"};
const vector<string> ranks = {"Invalid", "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
   
Card::Card() {

    // Assigns a default value of 2 of Clubs
    suit = 'c';
    rank = 2;

}

Card::Card(char card_suit, int card_rank) {

    //Accepts lower or upper case characters for suit
    //Assigns the Card the suit provided.
    suit = tolower(card_suit);
    
    // If an invalid suit is provided, sets the suit to Clubs
    if (suit != 'c' && suit != 'd' && suit != 'h' && suit != 's') {
        suit = 'c'; 
        }
    //If an invalid rank is provided, sets the rank to 2
    if (card_rank < 1 || card_rank > 13) {
        rank = 2; 
        } 
    else {
        rank = card_rank; // and rank 
        }

}
    
char Card::getSuit() const{
        
    // Returns the Card's suit
    return suit;

}
    
int Card::getRank() const{
         
    // Returns the Card's rank as an integer
    return rank;

}
    
    /* Outputs a Card in the following format: Rank of Suit
       For example, if the rank is 3 and the suit is h: 3 of Hearts
       Or, if the rank is 1 and the suit is d: Ace of Diamonds
       Or, if the rank is 12 and the suit is c: Queen of Clubs
       etc.
    */

   // stream insertion operator 
ostream& operator<<(ostream& ops, const Card & card){

    ops << ranks.at(card.rank) << " of ";

    if(tolower(card.suit) == 'c'){
        ops << suits.at(0);
     
    }
    else if(tolower(card.suit) == 'd'){
        ops << suits.at(1);
       
    }
    else if(tolower(card.suit) == 'h'){
        ops << suits.at(2);
     
    }
    else if(tolower(card.suit) == 's'){
        ops << suits.at(3);
        
    }
    //ok this dot operator means you are using suit member variable and card object, its used when you are working with variables in card class
    return ops;
    
}


