#ifndef TABLE_H
#define TABLE_H
#include <vector>
#include "player.h"
#include "deck.h"
using namespace std;
class Table
{
    private:
        int playerCount = 0;
        vector<Player> tablePlayers;
        Deck tableDeck;
        string currency = "$";
        int highestBet = 0;
        int betIncrement = 1;
        int minBet = betIncrement;
        int pot = 0;
        int entryFee = 1;
        int startingCards = 2;
        int round = 0;

        int playMenu()
        {
            int choice;
            cout << "\n<====================>\n";
            cout << "[0] End game\n";
            cout << "[1] Check (pass turn)\n";
            cout << "[2] Raise (increase the bet)\n";
            cout << "[3] Call  (match the bet)\n";
            cout << "[4] Fold  (give up this round)\n";
            cout << "<====================>\n";
            cin >> choice;
            cout << endl;
            if (choice < 0 || choice > 4)
            {return 0;}
            return choice;
        };

    public:
        //Constructor
        Table()
        {
            tableDeck.shuffle();
            tableDeck.printDeck();
        };

        void addPlayer(string name)
        {
            Player *newPlayer = new Player(name);
            tablePlayers.push_back(*newPlayer);
            playerCount++;
            cout << name << " has joined the game.\n";
        };

        void removePlayer(string name)
        {
            //Linear search through table to find name
            for (int i = 0; i < playerCount; i++)
            {
                if (tablePlayers[i].getPlayerName() == name)
                {
                    cout << name << " has left the game.\n";
                    tablePlayers.erase(tablePlayers.begin() + i);
                    playerCount--;
                }
            }
        };

        void addBots(int num)
        {
            string name = "Bot";
            for (int i = 1; i <= num; i++)
            {
                name = name + to_string(i);
                addPlayer(name);
                name = "Bot";    
            }
        }

        void printTable()
        {
            cout << "Current players:\n";
            for (int i = 0; i < playerCount; i++)
            {
                cout <<tablePlayers[i].printPlayerName() << endl;
            }
        };

        void printDeck()
        {
            //For debug purposes
            tableDeck.printDeck();
        };

        void dealAll(int num)
        {
            for (int i = 0; i < playerCount; i++)
            {
                for (int j = 0; j < num; j++)
                {
                    if (tableDeck.getSize() > 0)
                    {
                        tablePlayers[i].drawCard(tableDeck.drawFromDeck());
                    }
                }
            }
        };

        void displayAllPlayersCards()
        {
            for (int i = 0; i < playerCount; i++)
            {
                cout << tablePlayers[i].printPlayerName() << "'s hand:\n";
                tablePlayers[i].displayHand();
                cout << endl << endl;
            }
        };
        /*Debug function to create cards
        void magicSummon(int playerNum, int value, int suit)
        {
            Card newCard(value, suit);
            tablePlayers[playerNum].drawCard(newCard);
        };
        */

        //This doesn't work right if multiple players have the same handType, need to fix
        void roundWinner()
        {
            
            string winner = "?";
            int winnerNum = 0;
            int highScore = -1;
            for (int i = 0; i < tablePlayers.size(); i++)
            {
                if (tablePlayers[i].handType() > highScore)
                {
                    highScore = tablePlayers[i].handType();
                    winner = tablePlayers[i].getPlayerName();
                    winnerNum = i;
                }
            }
            if (tablePlayers[0].getHandSize() == 5)
            {
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << "The winner is " << winner << " with: ";
                tablePlayers[winnerNum].displayHand();
                cout << "!" << endl;
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            }
        };

        
        void addToPot(int money)
        {
            if (money > 0)
            {
                pot += money;  
            }
        }

        void printInfo(Player p)
        {
            cout << p.getPlayerName() << endl;
            cout << "Your hand: "; p.displayHand(); cout << endl;
            cout << "Your money: " << currency << p.getMoney() << endl;
            cout << "You are currently betting: " << currency << p.getBet() << endl;
            cout << "Highest bet at table: " << currency << highestBet << endl;
            cout << "Minimum raise: " << currency << minBet << endl;
            cout << "Current pot: " << currency << pot << endl;
        }

        void playRound()
        {
            bool playing = true;
            int choice = 0;

            if (round == 0)
            {
                dealAll(startingCards);

                for (int i = 0; i < tablePlayers.size(); i++)
                {
                    if (entryFee > highestBet)
                    {
                        highestBet += entryFee;
                        minBet = highestBet+betIncrement;
                    }
                    //All players start with the starting bet
                    tablePlayers[i].addToBet(entryFee);
                    addToPot(entryFee);
                }
            }

            for (int i = 0; i < tablePlayers.size(); i++)
            {
                //Unfold people
                //tablePlayers[i].setPlaying(true);
            }    

            while (playing)
            {
                for (int i = 0; i < tablePlayers.size(); i++)
                {

                    if (tablePlayers[i].isPlaying())
                    {
                        printInfo(tablePlayers[i]);
                        choice = playMenu(); 
                        if (choice == 0) //End game
                        {playing = false;break;}
                        if (choice == 1) //Check
                        {
                            if (tablePlayers[i].getBet() < highestBet)
                            {
                                cout << "You must Raise, Call, or Fold!\n";
                                i--; //redo their turn
                            }
                        }
                        if (choice == 2) //Raise
                        {
                            int newBet = 0;
                            cout << "How much will you increase your bet by? $"; cin >> newBet; cout << endl;
                            if (newBet <= tablePlayers[i].getMoney() && newBet > 0)
                            {
                                if (tablePlayers[i].getBet()+newBet > highestBet)
                                {
                                    highestBet = tablePlayers[i].getBet()+newBet;
                                    minBet = highestBet+betIncrement;
                                }
                                tablePlayers[i].addToBet(newBet);
                                addToPot(newBet);
                            }
                            else
                            {
                                cout << "Your bet is invalid! Try again.\n";
                                i--; //Redo turn
                            }
                        }
                        if (choice == 3) //Call
                        {
                            if (tablePlayers[i].getBet() != highestBet)
                            {
                                addToPot(highestBet-tablePlayers[i].getBet());
                                tablePlayers[i].addToBet(highestBet-tablePlayers[i].getBet());
                            }
                            else
                            {
                                cout << "You are already at the highest bet,\n you can Check, Raise, or Fold.\n";
                                i--; //Redo turn
                            }
                        }
                        if (choice == 4) //Fold
                        {
                            tablePlayers[i].fold();
                        }
                    }    

                    if (i < 0)
                    {i = 0;}

                    if (tablePlayers[i].isPlaying() && tablePlayers[i].getHandSize() < 5)
                    {tablePlayers[i].drawCard(tableDeck.drawFromDeck());}

                    //End condition
                    if (i == tablePlayers.size()-1 && round == 5-startingCards)
                    {playing = false;}   
                }
                round++;
            }
        };
};

#endif 