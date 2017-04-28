#include <iostream>
#include <string>

#include <player.h>

using namespace std;

int main(int argc, char *argv[])
{
    vector<int> deck = {32,32,32,32,32,32,32,32,32,32,32,32,32};
    int players = -12;

    while(players <= 0 || players >= 9)
    {
        cout << "How many Players? (up to 8) ";
        cin >> players;
        cout<<endl;
    }

    Player* house = new Player(deck);
    deck = house->setNewDeck();
    vector<string> houseHand = house->getCards();
    cout<<"This is the House's first card: "<< houseHand[0]<<endl;

    Player* p1 = new Player(deck);
    Player* p2 = new Player(deck);
    Player* p3 = new Player(deck);
    Player* p4 = new Player(deck);
    Player* p5 = new Player(deck);
    Player* p6 = new Player(deck);
    Player* p7 = new Player(deck);
    Player* p8 = new Player(deck);

    deck = p1->setNewDeck();
    if(players > 1)
    {
        deck = p2->setNewDeck();
        if(players > 2)
        {
            deck = p3->setNewDeck();
            if(players > 3)
            {
                deck = p4->setNewDeck();
                if(players > 4)
                {
                    deck = p5->setNewDeck();
                    if(players > 5)
                    {
                        deck = p6->setNewDeck();
                        if(players > 6)
                        {
                            deck = p7->setNewDeck();
                            if(players == 8)
                            {
                                deck = p8->setNewDeck();
                            }
                        }
                    }
                }
            }
        }
    }


    for (int x=0; x<players; x++)
    {
        bool pass = false;
        while(pass == false)
        {

            if(x==0)
            {
                cout<<endl<<endl<<endl;
                cout<<"Player 1 it is your turn."<<endl;
                pass= p1->pass();
                if(pass == false)
                {
                    p1->draw(deck);\
                    deck = p1->setNewDeck();
                }
            }
            else if (x==1)
            {
                cout<<endl<<endl<<endl;
                cout<<"Player 2 it is your turn."<<endl;
                pass = p2->pass();
                if(pass == false)
                {
                    p2->draw(deck);
                    deck = p2->setNewDeck();
                }
            }
            else if (x==2)
            {
                cout<<endl<<endl<<endl;
                cout<<"Player 3 it is your turn."<<endl;
                pass = p3->pass();
                if(pass == false)
                {
                    p3->draw(deck);
                    deck = p3->setNewDeck();
                }
            }
            else if (x==3)
            {
                cout<<endl<<endl<<endl;
                cout<<"Player 4 it is your turn."<<endl;
                pass = p4->pass();
                if(pass == false)
                {
                    p4->draw(deck);
                    deck = p4->setNewDeck();
                }
            }
            else if (x==4)
            {
                cout<<endl<<endl<<endl;
                cout<<"Player 5 it is your turn."<<endl;
                pass = p5->pass();
                if(pass == false)
                {
                    p5->draw(deck);
                    deck = p5->setNewDeck();
                }
            }
            else if (x==5)
            {
                cout<<endl<<endl<<endl;
                cout<<"Player 6 it is your turn."<<endl;
                pass = p6->pass();
                if(pass == false)
                {
                    p6->draw(deck);
                    deck = p6->setNewDeck();
                }
            }
            else if (x==6)
            {
                cout<<endl<<endl<<endl;
                cout<<"Player 7 it is your turn."<<endl;
                pass = p7->pass();
                if(pass == false)
                {
                    p7->draw(deck);
                    deck = p7->setNewDeck();
                }
            }
            else
            {
                cout<<endl<<endl<<endl;
                cout<<"Player 8 it is your turn."<<endl;
                pass = p8->pass();
                if(pass == false)
                {
                    p8->draw(deck);
                    deck = p8->setNewDeck();
                }
            }
        }
    }

    houseHand = house->getCards();
    cout<<"The House has: "<<houseHand[0]<<" "<<houseHand[1];
    vector<bool> hasUsed = {false,false};
    bool houseTurn = true;

    while(houseTurn == true)
    {
        cout<<endl<<endl;


        for(unsigned int x=0;x<houseHand.size();x++)
        {
            cout<<houseHand[x]<<" ";
            if(houseHand[x] == "Ace" && hasUsed[x] == false && house->getScore()+11<=21)
            {
                house->setHouseScore(11);
                hasUsed[x] = true;
            }
            else if(houseHand[x] == "Ace" && hasUsed[x] && house->getScore()+11 > 21)
            {
                house->setHouseScore(1);
                hasUsed[x] = true;
            }
        }


        if(house->getScore()<17)
        {
            house->draw(deck);
            houseHand = house->getCards();
            deck = house->setNewDeck();
            hasUsed.push_back(false);
        }
        else if(house->getScore()>=17 || house->isBust() == true)
        {
            if(house->hasBlackJack()==true)
            {
                cout<<"House has Black Jack!!!!";
            }
            if(house->isBust() == true)
            {
                cout<<"House has bust"<<endl;
            }
            //houseTurn = false;
            break;
        }
    }
    cout<<endl;

    for(int x=0;x<players;x++)
    {
        if(x==0)
        {
            if(p1->hasBlackJack() == true && house->hasBlackJack() == true && p1->isBust() == false)
            {
                cout<<"Player 1 has tied with the House (Both have Black Jack)"<<endl;
            }
            else if((p1->getScore()>house->getScore() || house->isBust() == true) && p1->isBust() == false)
            {
                cout<<"Player 1 has beaten the House!"<<endl;
            }
            else
            {
                cout<<"Player 1 has lost"<<endl;
            }
        }
        else if(x==1)
        {
            if(p2->hasBlackJack() == true && house->hasBlackJack() == true && p2->isBust() == false)
            {
                cout<<"Player 2 has tied with the House (Both have Black Jack)"<<endl;
            }
            else if((p2->getScore()>house->getScore() || house->isBust() == true) && p2->isBust() == false)
            {
                cout<<"Player 2 has beaten the House!"<<endl;
            }
            else
            {
                cout<<"Player 2 has lost"<<endl;
            }
        }
        else if(x==2)
        {
            if(p3->hasBlackJack() == true && house->hasBlackJack() == true && p3->isBust() == false)
            {
                cout<<"Player 3 has tied with the House (Both have Black Jack)"<<endl;
            }
            else if((p3->getScore()>house->getScore() || house->isBust() == true) && p3->isBust() == false)
            {
                cout<<"Player 3 has beaten the House!"<<endl;
            }
            else
            {
                cout<<"Player 3 has lost"<<endl;
            }
        }
        else if(x==3)
        {
            if(p4->hasBlackJack() == true && house->hasBlackJack() == true && p4->isBust() == false)
            {
                cout<<"Player 4 has tied with the House (Both have Black Jack)"<<endl;
            }
            else if((p4->getScore()>house->getScore() || house->isBust() == true) && p4->isBust() == false)
            {
                cout<<"Player 4 has beaten the House!"<<endl;
            }
            else
            {
                cout<<"Player 4 has lost"<<endl;
            }
        }
        else if(x==4)
        {
            if(p5->hasBlackJack() == true && house->hasBlackJack() == true && p5->isBust() == false)
            {
                cout<<"Player 5 has tied with the House (Both have Black Jack)"<<endl;
            }
            else if((p5->getScore()>house->getScore() || house->isBust() == true) && p5->isBust() == false)
            {
                cout<<"Player 5 has beaten the House!"<<endl;
            }
            else
            {
                cout<<"Player 5 has lost"<<endl;
            }
        }
        else if(x==5)
        {
            if(p6->hasBlackJack() == true && house->hasBlackJack() == true && p6->isBust() == false)
            {
                cout<<"Player 6 has tied with the House (Both have Black Jack)"<<endl;
            }
            else if((p6->getScore()>house->getScore() || house->isBust() == true) && p6->isBust() == false)
            {
                cout<<"Player 6 has beaten the House!"<<endl;
            }
            else
            {
                cout<<"Player 6 has lost"<<endl;
            }
        }
        else if(x==6)
        {
            if(p7->hasBlackJack() == true && house->hasBlackJack() == true && p7->isBust() == false)
            {
                cout<<"Player 7 has tied with the House (Both have Black Jack)"<<endl;
            }
            else if((p7->getScore()>house->getScore() || house->isBust() == true) && p7->isBust() == false)
            {
                cout<<"Player 7 has beaten the House!"<<endl;
            }
            else
            {
                cout<<"Player 7 has lost"<<endl;
            }
        }
        else if(x==7)
        {
            if(p8->hasBlackJack() == true && house->hasBlackJack() == true && p8->isBust() == false)
            {
                cout<<"Player 8 has tied with the House (Both have Black Jack)"<<endl;
            }
            else if((p8->getScore()>house->getScore() || house->isBust() == true) && p8->isBust() == false)
            {
                cout<<"Player 8 has beaten the House!"<<endl;
            }
            else
            {
                cout<<"Player 8 has lost"<<endl;
            }
        }
    }

    return 0;
}
