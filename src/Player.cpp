#include "Player.h"
#include <sys/stat.h> // For mkdir function

Player::Player(string _name) : name(_name), bestResult(-1), wins(0), losses(0), lastGameWin(false), lastGameAttempts(0) {
    loadFromFile();
}

Player::~Player() {
    saveToFile();
}

void Player::newPlayer() {
    cout << "Hello " << name << "!" << endl;
}

string Player::getName() {
    return name;
}

int Player::getBestResult() {
    return bestResult;
}

int Player::getWins() {
    return wins;
}

int Player::getLosses() {
    return losses;
}

void Player::setBestResult(int result) {
    if (bestResult == -1 || result < bestResult) {
        bestResult = result;
    }
}

void Player::incrementWins() {
    wins++;
}

void Player::incrementLosses() {
    losses++;
}

void Player::setLastGameResult(bool win, int attempts) {
    lastGameWin = win;
    lastGameAttempts = attempts;
}

int Player::getLastGameAttempts() {
    return lastGameAttempts;
}

void Player::loadFromFile() {
    ifstream file(name + ".txt");
    if (file.is_open()) {
        string label;
        while (file >> label) {
            if (label == "BestResult:") {
                file >> bestResult;
            } else if (label == "Wins:") {
                file >> wins;
            } else if (label == "Losses:") {
                file >> losses;
            } else if (label == "LastGameWin:") {
                file >> lastGameWin;
            } else if (label == "LastGameAttempts:") {
                file >> lastGameAttempts;
            } else {
                // Handle unrecognized label or skip
                string dummy;
                getline(file, dummy); // Read the rest of the line
            }
        }
        file.close();
    }
}

void Player::saveToFile() {
    ensureDirectoryExists("program_achivements"); // Ensure directory exists
    ofstream file("program_achivements/" + name + ".txt");
    if (file.is_open()) {
        writeWithLabel(file, "BestResult:", bestResult);
        writeWithLabel(file, "Wins:", wins);
        writeWithLabel(file, "Losses:", losses);
        writeWithLabel(file, "LastGameWin:", lastGameWin);
        writeWithLabel(file, "LastGameAttempts:", lastGameAttempts);
        file.close();
    }
}

void Player::writeWithLabel(ofstream& file, const string& label, int value) {
    file << label << " " << value << endl;
}

void Player::writeWithLabel(ofstream& file, const string& label, bool value) {
    file << label << " " << (value ? "true" : "false") << endl;
}

void Player::ensureDirectoryExists(const string& directory) {
    // Create the directory if it doesn't exist
    struct stat info;
    if (stat(directory.c_str(), &info) != 0) {
        mkdir(directory.c_str(), 0777);
    }
}