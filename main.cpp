#include "Common.h"
#include "GameModes.h"

int main() {
    srand(static_cast<unsigned int>(time(0)));

    string name;
    cout << "What is your name: " << endl;
    cin >> name;

    Player player(name);
    player.newPlayer();

    int gameMode;
    cout << "Choose game mode:" << endl;
    cout << "1. You guess the number" << endl;
    cout << "2. Program guesses the number" << endl;
    cout << "3. Mixed game" << endl;
    cin >> gameMode;

    int difficulty;
    cout << "Choose difficulty level:" << endl;
    cout << "1. Easy (0-100)" << endl;
    cout << "2. Normal (0-10000)" << endl;
    cout << "3. Difficult (0-1000000)" << endl;
    cin >> difficulty;

    int maxRange;
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

    if (gameMode == 1) {
        playerGuesses(player, maxRange);
    } else if (gameMode == 2) {
        programGuesses(player, maxRange);
    } else if (gameMode == 3) {
        mixedGame(player, maxRange);
    } else {
        cout << "Invalid game mode selected." << endl;
    }

    return 0;
}
