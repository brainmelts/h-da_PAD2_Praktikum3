#include <iostream>
#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;
#include "Team.h"

Team::Team(const char* _teamName, int _matchesPlayed, int _gamesWon, int _gamesLost, int _pointsWon, int _pointsLost)
    : matchesPlayed(_matchesPlayed), gamesWon(_gamesWon), gamesLost(_gamesLost), pointsWon(_pointsWon), pointsLost(_pointsLost) {
    strncpy_s(teamName, _teamName, 20);
}

string Team::toString() const {
    stringstream _s;

    _s << left
        << setw(25) << teamName
        << setw(6) << matchesPlayed
        << setw(6) << gamesWon
        << setw(6) << gamesLost
        << setw(6) << pointsWon
        << setw(6) << pointsLost
        << endl;

    return _s.str();
}

istream& Team::read(istream& _is) {
    _is.read(reinterpret_cast<char *>(this), sizeof(Team));

    return _is;
}

bool Team::operator<(const Team& _t) const {
    if (pointsWon < _t.pointsWon) {
        return true;

    } else {
        if (pointsLost > _t.pointsLost) return true;
        else if ((gamesWon - gamesLost) < (_t.gamesWon - _t.gamesLost)) return true;
    }

    return false;
}