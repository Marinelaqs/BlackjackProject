#include <iostream>


#include <player.h>

using namespace std;

int main(int argc, char *argv[])
{
    vector<int> deck;
    int players = 12;
    while(players > 0 && players < 11)
    {
        cout << "How many Players? (up to 8) ";
        cin >> players;
    }

    for(int x=0;x<13;x++)
    {

    }







    Player* p1 = new Player(deck);
    if(players > 1)
    {
        Player* p2 = new Player(deck);
        if(players > 2)
        {
            Player* p3 = new Player(deck);
            if(players > 3)
            {
                Player* p4 = new Player(deck);
                if(players > 4)
                {
                    Player* p5 = new Player(deck);
                    if(players > 5)
                    {
                        Player* p6 = new Player(deck);
                        if(players > 6)
                        {
                            Player* p7 = new Player(deck);
                            if(players == 8)
                            {
                                Player* p8 = new Player(deck);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
