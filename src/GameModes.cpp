#include "GameModes.h"

void playerGuesses(std::vector<Player>& players, int maxRange) {
    for (auto& player : players) {
        int targetNumber = rand() % (maxRange + 1);
        int guess;
        int attempts = 0;

        cout << player.getName() << ", guess a number between 0 and " << maxRange << ": " << endl;

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
                player.setLastGameResult(true, attempts);
                player.incrementWins();
                break;
            }
        } while (guess != targetNumber);
    }
}

void programGuesses(std::vector<Player>& players, int maxRange) {
    for (auto& player : players) {
        int low = 0;
        int high = maxRange;
        int guess;
        char feedback;
        int attempts = 0;

        cout << "Player " << player.getName() << ", think of a number between 0 and " << maxRange << ", and I will try to guess it." << endl;

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
                player.setLastGameResult(false, attempts);
                player.incrementLosses();
                break;
            } else {
                cout << "Invalid feedback. Please enter 'h' for higher, 'l' for lower, or 'c' for correct." << endl;
            }
        } while (feedback != 'c');
    }
}

void mixedGame(std::vector<Player>& players, int maxRange) {
    if (players.size() == 1) {
        cout << "Think of a number for the program to guess between 0 and " << maxRange << " and press enter to continue." << endl;
        cin.ignore();
        cin.get(); // Wait for user to press enter

        int low = 0, high = maxRange;
        int programGuess;
        int playerGuess;
        int programAttempts = 0, playerAttempts = 0;
        bool playerTurn;

        cout << "Coin toss! Enter 0 for tails (program starts) or 1 for heads (player starts): ";
        cin >> playerTurn;

        int playerTargetNumber = rand() % (maxRange + 1); // Random target for the player to guess

        while (true) {
            if (playerTurn) {
                cout << "Enter your guess: ";
                cin >> playerGuess;
                playerAttempts++;

                if (playerGuess > playerTargetNumber) {
                    cout << "Too high! Try again." << endl;
                } else if (playerGuess < playerTargetNumber) {
                    cout << "Too low! Try again." << endl;
                } else {
                    cout << "Congratulations! You guessed the number in " << playerAttempts << " attempts." << endl;
                    players[0].setBestResult(playerAttempts);
                    players[0].setLastGameResult(true, playerAttempts);
                    players[0].incrementWins();
                    break;
                }
            } else {
                programGuess = low + (high - low) / 2;
                cout << "Is your number " << programGuess << "? (h for higher, l for lower, c for correct): ";
                char feedback;
                cin >> feedback;
                programAttempts++;

                if (feedback == 'h') {
                    low = programGuess + 1;
                } else if (feedback == 'l') {
                    high = programGuess - 1;
                } else if (feedback == 'c') {
                    cout << "I guessed your number in " << programAttempts << " attempts!" << endl;
                    players[0].setLastGameResult(false, programAttempts);
                    players[0].incrementLosses();
                    break;
                } else {
                    cout << "Invalid feedback. Please enter 'h' for higher, 'l' for lower, or 'c' for correct." << endl;
                }
            }
            playerTurn = !playerTurn; // Switch turns
        }
    } else {
        int targetNumber = rand() % (maxRange + 1);
        int guess;
        int attempts = 0;
        bool numberGuessed = false;

        cout << "The program has chosen a number between 0 and " << maxRange << ". Players, take turns to guess the number!" << endl;
        cin.ignore(); // Ignore any leftover newline characters

        while (!numberGuessed) {
            for (auto& player : players) {
                cout << player.getName() << ", it's your turn. Enter your guess: ";
                cin >> guess;
                attempts++;

                if (guess > targetNumber) {
                    cout << "Too high! Try again." << endl;
                } else if (guess < targetNumber) {
                    cout << "Too low! Try again." << endl;
                } else {
                    cout << "Congratulations " << player.getName() << "! You guessed the number in " << attempts << " attempts." << endl;
                    player.setBestResult(attempts);
                    player.setLastGameResult(true, attempts);
                    player.incrementWins();
                    numberGuessed = true;
                    break;
                }
            }
        }
    }
}
