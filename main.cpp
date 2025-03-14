#include "game.h"
#include <iostream>
#include <cstdlib> // for std::srand()
#include <ctime> // for std::time()

int main() {
    // This line ensure that a random seed is generated everytime we compile
    // This is needed for shuffling the deck of cards.
    std::srand(static_cast<unsigned int>(std::time(0))); 


    bool playAgain = true;
    char choice;

    std::cout << "Welcome to Blackjack!\n";

    while (playAgain) {
        // Play the game
        playGame();

        // Ask the player if they want to play again
        std::cout << "Play again? (y/n): ";
        std::cin >> choice;
        if (choice != 'y') {
            playAgain = false;
        }
    }

    // This will pause the program and wait for the user to press any key before closing.
    system("pause");
}

