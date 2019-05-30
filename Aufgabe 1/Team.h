#pragma once

#include <vector>
#include <string>

class Team {
public:
    Team(const char* = "", int = 0, int = 0, int = 0, int = 0, int = 0);

    std::string toString() const;

    bool operator<(const Team&) const;
    std::istream & read(std::istream &);

private:
    char teamName[20];
    int matchesPlayed;
    int gamesWon;
    int gamesLost;
    int pointsWon;
    int pointsLost;
};