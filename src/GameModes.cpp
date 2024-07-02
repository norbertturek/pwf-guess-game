#include "GameModes.h"

void playerGuesses(Player& player, int maxRange) {
    int targetNumber = rand() % (maxRange + 1);
    int guess;
    int attempts = 0;

    cout << "Guess a number between 0 and " << maxRange << ": " << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > targetNumber) {
            cout << "Too high! Try again." << endl;
        } else if (guess < targetNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations " << player.getName() << "! You guessed the number in " << attempts << " attempts." << endl;
            player.setBestResult(attempts);
            player.setLastGameResult(true, attempts); // Set game outcome
            player.incrementWins(); // Increment wins
            return;
        }
    } while (guess != targetNumber);
}

void programGuesses(Player& player, int maxRange) {
    int low = 0;
    int high = maxRange;
    int guess;
    char feedback;
    int attempts = 0;

    cout << "Think of a number between 0 and " << maxRange << ", and I will try to guess it." << endl;

    do {
        guess = low + (high - low) / 2;
        cout << "Is your number " << guess << "? (h for higher, l for lower, c for correct): ";
        cin >> feedback;
        attempts++;

        if (feedback == 'h') {
            low = guess + 1;
        } else if (feedback == 'l') {
            high = guess - 1;
        } else if (feedback == 'c') {
            cout << "I guessed your number in " << attempts << " attempts!" << endl;
            player.setLastGameResult(false, attempts); // Set game outcome
            player.incrementLosses(); // Increment losses
            return;
        } else {
            cout << "Invalid feedback. Please enter 'h' for higher, 'l' for lower, or 'c' for correct." << endl;
        }
    } while (feedback != 'c');
}

void mixedGame(Player& player, int maxRange) {
    int playerTargetNumber;
    int programTargetNumber = rand() % (maxRange + 1);
    int playerGuess, programGuess;
    int low = 0, high = maxRange;
    int playerAttempts = 0, programAttempts = 0;
    char feedback;
    bool playerTurn;

    cout << "Think of a number for the program to guess between 0 and " << maxRange << ": ";
    cin >> playerTargetNumber;

    cout << "Coin toss! Enter 0 for tails (program starts) or 1 for heads (player starts): ";
    cin >> playerTurn;

    do {
        if (playerTurn) {
            cout << "Enter your guess: ";
            cin >> playerGuess;
            playerAttempts++;

            if (playerGuess > programTargetNumber) {
                cout << "Too high! Try again." << endl;
            } else if (playerGuess < programTargetNumber) {
                cout << "Too low! Try again." << endl;
            } else {
                cout << "Congratulations " << player.getName() << "! You guessed the number in " << playerAttempts << " attempts." << endl;
                player.incrementWins(); // Increment wins
                player.setLastGameResult(true, playerAttempts); // Set game outcome
                return;
            }

            playerTurn = false;
        } else {
            programGuess = low + (high - low) / 2;
            cout << "Is your number " << programGuess << "? (h for higher, l for lower, c for correct): ";
            cin >> feedback;
            programAttempts++;

            if (feedback == 'h') {
                low = programGuess + 1;
            } else if (feedback == 'l') {
                high = programGuess - 1;
            } else if (feedback == 'c') {
                cout << "I guessed your number in " << programAttempts << " attempts!" << endl;
                player.incrementLosses(); // Increment losses
                player.setLastGameResult(false, programAttempts); // Set game outcome
                return;
            } else {
                cout << "Invalid feedback. Please enter 'h' for higher, 'l' for lower, or 'c' for correct." << endl;
                continue;
            }

            playerTurn = true;
        }
    } while (true);
}
