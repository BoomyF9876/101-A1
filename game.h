#pragma once
#pragma once
#include <vector>


/// <summary>
/// Shuffles the deck of cards.
/// </summary>
/// <param name="deck">A reference to the vector containing the deck of cards</param>
void shuffleDeck(std::vector<int>& deck);

/// <summary>
/// Deals a card from the back of the deck and removes it from the deck.
/// </summary>
/// <param name="deck">A reference to the vector containing the deck of cards</param>
/// <returns>The integer value of the dealt card</returns>
int dealCard(std::vector<int>& deck);

/// <summary>
/// Handles the player's turn, allowing the player to hit or stay, and returns their total score.
/// </summary>
/// <param name="deck">A reference to the vector containing the deck of cards</param>
/// <returns>The player's total score</returns>
int playerTurn(std::vector<int>& deck);

/// <summary>
/// Handles the dealer's turn, ensuring they draw cards until they reach a score of at least 17.
/// </summary>
/// <param name="deck">A reference to the vector containing the deck of cards</param>
/// <returns>The dealer's total score</returns>
int dealerTurn(std::vector<int>& deck);

/// <summary>
/// Compares the player's score and the dealer's score and prints the result (who won or if it's a tie).
/// </summary>
/// <param name="playerTotal">The player's total score</param>
/// <param name="dealerTotal">The dealer's total score</param>
void determineWinner(int playerTotal, int dealerTotal);

/// <summary>
/// Plays the entire Blackjack game loop, handling the game flow and prompting for replay.
/// </summary>
void playGame();
