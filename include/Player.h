#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <fstream>

using namespace std;

class Player
{
public:
    Player(string);
    virtual ~Player();
    void newPlayer();
    string getName();
    int getBestResult();
    int getWins();
    int getLosses();
    void setBestResult(int);
    void incrementWins();
    void incrementLosses();
    void setLastGameResult(bool win, int attempts);
    int getLastGameAttempts(); // New function
    void loadFromFile();
    void saveToFile();

private:
    string name;
    int bestResult;
    int wins;
    int losses;
    bool lastGameWin;
    int lastGameAttempts;

    // Helper function to write comments with labels
    void writeWithLabel(ofstream& file, const string& label, int value);
    void writeWithLabel(ofstream& file, const string& label, bool value);
    void ensureDirectoryExists(const string& directory); // Declaration added here
};

#endif // PLAYER_H
