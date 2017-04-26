#include <iostream>


#include <player.h>

using namespace std;

int main(int argc, char *argv[])
{
    vector<int> deck;
    int players = 12;
    while(players <= 0 && players >= 9)
    {
        cout << "How many Players? (up to 8) ";
        cin >> players;
    }

    for(int x=0;x<13;x++)
    {
        deck[x] = 32;
    }

    Player* house = new Player(deck);
    deck = house->newDeck;

    Player* p1 = new Player(deck);
    deck = p1->newDeck;
    if(players > 1)
    {
        Player* p2 = new Player(deck);
        deck = p2->newDeck;
        if(players > 2)
        {
            Player* p3 = new Player(deck);
            deck = p3->newDeck;
            if(players > 3)
            {
                Player* p4 = new Player(deck);
                deck = p4->newDeck;
                if(players > 4)
                {
                    Player* p5 = new Player(deck);
                    deck = p5->newDeck;
                    if(players > 5)
                    {
                        Player* p6 = new Player(deck);
                        deck = p6->newDeck;
                        if(players > 6)
                        {
                            Player* p7 = new Player(deck);
                            deck = p7->newDeck;
                            if(players == 8)
                            {
                                Player* p8 = new Player(deck);
                                deck = p8->newDeck;
                            }
                        }
                    }
                }
            }
        }
    }


    return 0;
}
