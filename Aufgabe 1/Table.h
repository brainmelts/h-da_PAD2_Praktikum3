#pragma once

#include <vector>
#include <string>
#include "Team.h"

class Table {
public:
    Table();

    std::string toString() const;
    void addTeam(Team);
    void sort();

private:
    std::vector<Team> teams;
};