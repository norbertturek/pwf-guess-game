#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include <string>
#include <fstream>
#include "Player.h"

class Achievement {
public:
    void savePlayerAchievement(const Player& player);
    void loadProgramAchievement();
    void saveProgramAchievement();

private:
    std::string programAchievementsFile = "program_achievements.txt";
};

#endif // ACHIEVEMENT_H
