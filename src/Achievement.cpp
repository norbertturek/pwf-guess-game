#include "Achievement.h"
#include <iostream>

void Achievement::savePlayerAchievement(const Player& player) {
    std::ofstream file(player.getName() + "_achievements.txt");
    if (file.is_open()) {
        file << player.getName() << " score" << std::endl;
        file << "HighScore: " << player.getHighScore() << std::endl;
        file << "Wins: " << player.getWins() << std::endl;
        file << "Losses: " << player.getLosses() << std::endl;
        file << "LastGameAttempts: " << player.getLastGameAttempts() << std::endl;
        file.close();
    } else {
        std::cerr << "Unable to open file for saving player achievements: " << player.getName() << "_achievements.txt" << std::endl;
    }
}

// void Achievement::saveProgramAchievement() {
//     std::ofstream file(programAchievementsFile, std::ios_base::app);  // Append mode to add new player data
//
//     if (file.is_open()) {
//         file << std::endl;  // Separate previous data
//         file << "Your player name" << std::endl;  // Placeholder for actual player name
//         file << "- " << "Adam" << std::endl;  // Placeholder for actual player name
//
//         file << "Adam score" << std::endl;
//         file << "HighScore: " << 5 << std::endl;  // Placeholder for actual high score
//         file << "Wins: " << 1 << std::endl;  // Placeholder for actual wins
//         file << "Loses: " << 1 << std::endl;  // Placeholder for actual losses
//         file << "LastGameAttempts: " << 3 << std::endl;  // Placeholder for actual last game attempts
//
//         file << std::endl;
//         file << "----" << std::endl;
//         file << "**here we will have players history, for example before Adam was Marek**" << std::endl;
//
//         file << "Marek score" << std::endl;
//         file << "HighScore: " << 8 << std::endl;  // Placeholder for actual high score
//         file << "Wins: " << 2 << std::endl;  // Placeholder for actual wins
//         file << "Loses: " << 0 << std::endl;  // Placeholder for actual losses
//         file << "LastGameAttempts: " << 6 << std::endl;  // Placeholder for actual last game attempts
//
//         file.close();
//     } else {
//         std::cerr << "Unable to open file for saving program achievements: " << programAchievementsFile << std::endl;
//     }
// }
