//Deck.cpp file

#include "Deck.h"
#include "Card.h" // I FORGOT TO INCLUDE
#include <algorithm>


   /* Constructs a Deck of 52 cards:
       Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King of each suit.
       Cards should start off in this order with the order of suits being:
       Clubs, Diamonds, Hearts, Spades. So, the Card at the top of the
       Deck should be the Ace of Clubs.
    

       top of deck/ BACK OF VECTOR = Ace of Clubs
    */
Deck::Deck(){ 

    vector<char> suitletter = { 's', 'h', 'd', 'c'};

    for (unsigned int suit = 0; suit < suitletter.size(); ++suit) {
        for (int rank = 13; rank > 0; --rank) {
            theDeck.push_back(Card(suitletter.at(suit), rank));  // made silly mistajke here - remember to figure out your value type (you were passing in int instead of letter)
        }
    }
            
}
    

    /* Deals (returns) the top card of the deck. 
       Removes this card from theDeck and places it in dealtCards
       for best efficiency, the top card should come from the 
       back end of vector.
    */
    Card Deck::dealCard(){ 

        Card topcard = theDeck.at(theDeck.size()-1); // Get the top card (back of the vector)
        dealtCards.push_back(topcard); // Add it to dealtCards
        theDeck.pop_back(); // Remove the top card from theDeck
        
        return topcard;

    }


    /* Places all cards back into theDeck and shuffles them into random order.
       Use random_shuffle function from algorithm library.
       To pass test harness, this function must go forward through dealtCards
       pushing each Card onto the back end of theDeck, then clear dealtCards.
       Do not use pop_back on dealtCards.
    */
    void Deck::shuffleDeck(){
        
        for(unsigned int i = 0; i < dealtCards.size(); ++i){
            theDeck.push_back(dealtCards.at(i));
        }

        random_shuffle(theDeck.begin(), theDeck.end());

        dealtCards.clear();
    }


    /* returns the size of the Deck (how many cards have not yet been dealt).
    */
    unsigned Deck::deckSize() const{
        return theDeck.size();
    }