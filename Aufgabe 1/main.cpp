#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
#include "Table.h"
#include "Team.h"

int main()
{
    ifstream inTabletennisFile("tabletennis.dta", ios::in | ios::binary);

    if (!inTabletennisFile) {
        cerr << "file could not be opened" << endl;
        exit(EXIT_FAILURE); // Falls Datei nicht geöffnet werden kann
    }

    Table table;
    Team team;

    while (team.read(inTabletennisFile)) table.addTeam(team);

    cout << table.toString(); // unsortiert
    table.sort();
    cout << "\n" << table.toString(); //sortiert
    inTabletennisFile.close();

    ofstream outTabletennisFile("tabletennis.txt", ios::out);	// erstelle neue .txt Datei in "oberen" Ordner
    outTabletennisFile << table.toString();
    outTabletennisFile.close();
}