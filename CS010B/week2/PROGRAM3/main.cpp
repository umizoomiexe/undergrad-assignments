#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>

using namespace std;

#include "Deck.h"
#include "Card.h"

// Returns true if vector of Cards passed in contains at least 2 Cards with the same rank.
bool hasPair(const vector<Card> &hand){

     // Implement the hasPair function to check for a pair in the hand.
    // You can use a loop to compare each card's rank with others in the hand.
    // If  find a pair, return true; otherwise, return false.
    // Make sure to handle the case where the hand is empty or has only one card.

    for (unsigned int i = 0; i < hand.size(); ++i) {
        for (unsigned int j = i + 1; j < hand.size(); ++j) {
            if (hand.at(i).getRank() == hand.at(j).getRank()) {
                return true; // Found a pair
            }
        }
    }
    
    return false;
}


// Sends  output stream a hand of Cards on a single line, 
// each Card separated by a comma
// If the vector is empty, do not output anything
// Example (vector size of 3): Ace of Spades, Two of Hearts, King of Clubs 
ostream & operator<<(ostream &os, const vector<Card> &hand) {
    for (unsigned int i = 0; i < hand.size(); ++i) {
        os << hand.at(i);
        if (i < hand.size() - 1) {
            os << ", ";
        }
    }
    return os;
}

int main() {
    srand(2222);
    string outputFileName;
    string outputFilebool;
    ofstream outputFile; 

    std::cout << "Do you want to output all hands to a file? (Yes/No) " << endl;
    cin >> outputFilebool;

    

    if (outputFilebool == "yes" || outputFilebool == "Yes") {

        std::cout << "Enter name of output file: " << endl;
        cin >> outputFileName;
        //std::cout << outputFileName;

       ofstream outputFile(outputFileName, std::ofstream::out); // ,jst use mode parameter to use this 
        
        //ofstream.open(outputFileName);  //.open fuction used commonly     
        
        if (!outputFile.is_open()) {
            std::cout << "Error opening output file." << endl;
            return 1;
        } 

    }

    int numCardsPerHand;
    int numDeals;

    std::cout << "Enter number of cards per hand: " << endl;
    cin >> numCardsPerHand;
    std::cout << "Enter number of deals (simulations): " << endl;
    cin >> numDeals;

    int pairCount = 0;
    Deck deck;

    for (int deal = 0; deal < numDeals; ++deal) {
        deck.shuffleDeck();
        vector<Card> hand;

        // Deal the specified number of cards
        for (int i = 0; i < numCardsPerHand; ++i) {
            hand.push_back(deck.dealCard());
        }

        // Check if the hand has a pair and output the hand
        if (hasPair(hand)) {
            pairCount = pairCount + 1;
            outputFile << "Found Pair!! ";
        }
        else{
            outputFile << "             "; /// QUESTION : do i need to cout as well as write into file?? (test case 7) 
        }

        if(outputFilebool == "Yes" || outputFilebool == "yes"){
          outputFile << hand << endl;
        }
    }

    // Calculate and display the percentage of times a pair is found
    double percent; 
    percent = (static_cast<double>(pairCount) / numDeals * 100.0); // maybe static casting to double will actually0 make it print??
    std::cout << "Chances of receiving a pair in a hand of " << numCardsPerHand << " cards is: " << percent << "%" << endl;

    if (outputFile.is_open()) {
        outputFile.close();
    }

    return 0;
        
    }
