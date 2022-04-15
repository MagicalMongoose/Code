#include <iostream>
#include <string>
#include "deck.h"
#include "table.h"
#include "player.h"
using namespace std;

int main()
{
    Table pokerTable;
    //cout << "What is your name?\n";
    //string name;
    //cin >> name;
    pokerTable.addPlayer("Drew");
    pokerTable.addBots(2);
    pokerTable.printTable();
    pokerTable.displayAllPlayersCards();
    pokerTable.playRound();
    pokerTable.roundWinner();
    return 0;
}