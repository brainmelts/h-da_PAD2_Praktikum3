#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
using namespace std;
#include "Table.h"

Table::Table() {}

void Table::addTeam(Team _t) {
    teams.push_back(_t);
}

string Table::toString() const {
    stringstream _s;

    _s << left
        << setw(25) << "Team Name"
        << setw(6) << "Games"
        << setw(6) << "Win"
        << setw(6) << "Lose"
        << setw(6) << "pW"
        << setw(6) << "pL"
        << endl;

    for (unsigned i = 0; i < 55; i++) _s << "-";

    _s << endl;

    for (unsigned i = 0; i < teams.size(); i++) _s << teams[i].toString();

    return _s.str();
}

void Table::sort() {
    std::sort(teams.rbegin(), teams.rend());
}