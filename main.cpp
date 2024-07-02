#include "Common.h"
#include "GameModes.h"

int main() {
    srand(static_cast<unsigned int>(time(0)));
    bool playAgain = true;

    while (playAgain) {
        int gameMode;
        cout << "Choose game mode:" << endl;
        cout << "1. You guess the number" << endl;
        cout << "2. Program guesses the number" << endl;
        cout << "3. Mixed game" << endl;
        cin >> gameMode;

        int maxRange = 100; // Default range
        std::vector<Player> players;

        if (gameMode == 1 || gameMode == 2) {
            int difficulty;
            cout << "Choose difficulty level:" << endl;
            cout << "1. Easy (0-100)" << endl;
            cout << "2. Normal (0-10000)" << endl;
            cout << "3. Difficult (0-1000000)" << endl;
            cin >> difficulty;

            switch (difficulty) {
                case 1:
                    maxRange = 100;
                    break;
                case 2:
                    maxRange = 10000;
                    break;
                case 3:
                    maxRange = 1000000;
                    break;
                default:
                    cout << "Invalid difficulty level selected. Defaulting to Easy." << endl;
                    maxRange = 100;
                    break;
            }

            string name;
            cout << "Enter your name: ";
            cin >> name;
            players.emplace_back(name);
            players.back().newPlayer();

            if (gameMode == 1) {
                playerGuesses(players, maxRange);
            } else if (gameMode == 2) {
                programGuesses(players, maxRange);
            }
        } else if (gameMode == 3) {
            int numPlayers;
            cout << "Enter number of players: ";
            cin >> numPlayers;

            for (int i = 0; i < numPlayers; ++i) {
                string name;
                cout << "Enter player " << i + 1 << "'s name: ";
                cin >> name;
                players.emplace_back(name);
                players.back().newPlayer();
            }
            mixedGame(players, maxRange);
        } else {
            cout << "Invalid game mode selected." << endl;
            continue; // Restart the loop for correct input
        }

        // Ask if the players want to play again
        char playAgainChoice;
        cout << "Do you want to play another game? (y/n): ";
        cin >> playAgainChoice;
        if (tolower(playAgainChoice) != 'y') {
            playAgain = false;
        }
    }

    return 0;
}
