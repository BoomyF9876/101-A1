#include "game.h"
#include <iostream>
#include <cstdlib> // for the rand() function
using namespace std;

// Global variables to keep track of the game statistics 
int playerWins = 0;
int dealerWins = 0;
int ties = 0;

void shuffleDeck(vector<int>& deck) {
    for (size_t i = 0; i < deck.size(); ++i) {
        size_t randomIndex = rand() % deck.size();
        swap(deck[i], deck[randomIndex]);
    }

    // A bit of info about the "rand()" function.
    // Let's say we have this line of code:
    //       int randomChoice = rand() % 3;
    // 
    // This will give us back a random number between 0 and 2. But why?
    // rand() is a function that returns a random int between 0 and the maximum positive int 
    // avaiable (which is 4294967295). To ensure we get a rand number between 0 and a value,
    // we use the mod (%) operator. This is the logic:
    // rand() -> rand() % 3
    //    0   ->  0 % 3 = 0
    //    1   ->  1 % 3 = 1
    //    2   ->  2 % 3 = 2
    //    3   ->  3 % 3 = 0
    //    4   ->  4 % 3 = 1
    //    5   ->  5 % 3 = 2
    //    6   ->  6 % 3 = 0
    //     ............
    //  2542 ->  2542 % 3 = 1
    //  2543 ->  2543 % 3 = 2
    //  2544 ->  2542 % 3 = 0
    //  Do you see the pattern?
}

// TODO (1): Complete the following function 
// (the description is in the header file)
int dealCard(vector<int>& deck) {
    // HINT: look up vector methods
    int next_card = deck[deck.size() - 1];
    deck.pop_back();

    return next_card;
}


int playerTurn(vector<int>& deck) {
    int playerTotal = 0;
    char choice = ' ';

    cout << "Your turn!" << endl;

    // Deal two cards initially
    playerTotal += dealCard(deck);
    cout << "You drew a " << playerTotal << ". Your total: " << playerTotal << endl;
    
    int newCard = dealCard(deck);
    playerTotal += newCard;
    cout << "You drew a " << newCard << ". Your total: " << playerTotal << endl;
   
    // In the very rare case of drawing two aces (11) 
    if (playerTotal > 21) {
        return playerTotal;
    }

    // Inside the loop, the player should be asked to 
    // either "hit" (draw a card) or "stay" (keep their current hand).
    // The input for hit is 'h' and for stay is 's'
    
    // The loop continues until the player chooses to stay by entering 's' 
    // or until the player's total exceeds 21 (bust). 

    while (choice != 's') {
        cout<<"Should you choose to draw a card (type h) or keep your current hand (type s)?\n";
        cin>>choice;

        if (choice == 'h') {
            newCard = dealCard(deck);
            playerTotal += newCard;
            cout << "You drew a " << newCard << ". Your total: " << playerTotal << endl;
        }

        if (playerTotal > 21) {
            return playerTotal;
        }
    }

    return playerTotal;
}


// TODO (3) : Complete the following function
// (the description is in the header file)
int dealerTurn(vector<int>& deck) {
   
    // HINT: Complete the previous function first. 
    // The content of this function is very similar to the previous one.

    int dealerTotal = 0;
    cout << "Dealer's turn!" << endl;

    // Deal two cards initially
    dealerTotal += dealCard(deck);
    cout << "Dealer drew a " << dealerTotal << ". Dealer's total: " << dealerTotal << endl;
    
    int newCard = dealCard(deck);
    dealerTotal += newCard;
    cout << "Dealer drew a " << newCard << ". Dealer's total: " << dealerTotal << endl;
   
    // In the very rare case of drawing two aces (11) 
    if (dealerTotal > 21) {
        return dealerTotal;
    }

    while (dealerTotal < 17) {
        cout << "Dealer drew a " << newCard << ". Dealer's total: " << dealerTotal << endl;
        newCard = dealCard(deck);
        dealerTotal += newCard;
    }

    return dealerTotal; // You may want to change this return value 
}

// TODO (4): Complete the following function
void determineWinner(int playerTotal, int dealerTotal) {

    // - If the player has busted (gone over 21), they lose automatically, 
    //   regardless of the dealer's score.
    if (playerTotal > 21) {
        dealerWins++;
    }
    
    // - If the dealer has busted, the player wins, unless the player also busted.
    else if (dealerTotal > 21) {
        playerWins++;
    } 
    
    // - If neither player nor dealer busts, the total closest to 21 wins.
    else if (playerTotal > dealerTotal) {
        playerWins++;
    }
    else if (playerTotal < dealerTotal) {
        dealerWins++;
    }
    // - If both have the same total, it is a tie.
    // Update the global variables at the top accordingly 
    else {
        ties++;
    }
}

void playGame() {
    // Vector representing the deck with numbers
    vector<int> deck = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,  // First set
                              2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11 }; // Second set (simulating two decks)


    // TODO (5): do the main game functionality by calling the previous functions
    // 5.1 Shuffle the deck
    shuffleDeck(deck);
    // 5.2 Make the player play, followed by the dealer
    int player = playerTurn(deck);
    int dealer = dealerTurn(deck);

    // 5.3 Determine the winner
    determineWinner(player, dealer);


    // Prints the game stats
    cout << "Stats: Player Wins: " << playerWins << ". Dealer Wins: " << dealerWins << ". Ties: " << ties << endl;
    
}