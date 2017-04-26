#include <iostream>


#include <player.h>

using namespace std;

int main(int argc, char *argv[])
{
    cout<<"Here";
    vector<int> deck = {32,32,32,32,32,32,32,32,32,32,32,32,32};
    int players = 12;

    while(players <= 0 && players >= 9)
    {
        cout << "How many Players? (up to 8) ";
        cin >> players;
    }

    cout<<"here";
    Player* house = new Player(deck);
    deck = house->setNewDeck();

    Player* p1 = new Player(deck);
    Player* p2 = new Player(deck);
    Player* p3 = new Player(deck);
    Player* p4 = new Player(deck);
    Player* p5 = new Player(deck);
    Player* p6 = new Player(deck);
    Player* p7 = new Player(deck);
    Player* p8 = new Player(deck);

    deck = p1->newDeck;
    if(players > 1)
    {
        deck = p2->newDeck;
        if(players > 2)
        {
            deck = p3->newDeck;
            if(players > 3)
            {
                deck = p4->newDeck;
                if(players > 4)
                {
                    deck = p5->newDeck;
                    if(players > 5)
                    {
                        deck = p6->newDeck;
                        if(players > 6)
                        {
                            deck = p7->newDeck;
                            if(players == 8)
                            {
                                deck = p8->newDeck;
                            }
                        }
                    }
                }
            }
        }
    }


    for (int x = 0; x<players; x++)
    {
        bool pass = false;
        while( pass == false)
        {

            if(x==0)
            {
                pass= p1->pass();
            }
            else if (x==1)
            {
                pass = p2->pass();
            }
            else if (x==2)
            {
                pass = p3->pass();
            }
            else if (x==3)
            {
                pass = p4->pass();
            }
            else if (x==4)
            {
                pass = p5->pass();
            }
            else if (x==5)
            {
                pass = p6->pass();}
            else if (x==6)
            {
                pass = p7->pass();
            }
            else
            {
                pass = p8->pass();
            }
        }
    }

    vector<string> houseHand = house->getCards();
    cout<<"The House has: "<<houseHand[0]<<houseHand[1];


    return 0;
}
