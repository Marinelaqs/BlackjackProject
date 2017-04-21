#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
using namespace std;

class Player
{
public:
    Player(vector<int> cards)
    {
        for(int x=0;x<2;x++)
        {
            draw(cards);
        }
        bust = false;
    }

    int aceChoose()
    {
        int ace = 0;

        do
        {
        cout<<"Is this ace a 1 or 11? ";
        cin>>ace;
        cout<<endl;
        } while(ace != 1 && ace != 11);

        return ace;
    }

    void draw(vector<int> deck)
    {
        bool drawn = false;
        int card;

        while(drawn == false)
        {
            card = rand() % 13+1;

            if(deck[card-1] > 0)
            {
                drawn = true;
            }
        }

        if(card == 11)
        {
            playerCards[playerCards.size()] = "Joker";
            score += 10;
        }
        else if(card == 12)
        {
            playerCards[playerCards.size()] = "Queen";
            score += 10;
        }
        else if(card == 13)
        {
            playerCards[playerCards.size()] = "King";
            score += 10;
        }
        else if(card == 1)
        {
            playerCards[playerCards.size()] = "Ace";
        }
        else
        {
            playerCards[playerCards.size()] = ""+card;
            score += card;
        }

    }

    bool pass()
    {
        int ans;
        vector<string> cards = getCards();

        cout<<"Your Cards are "<<cards[0]<<" ";
        for(unsigned x=1;x<cards.size();x++)
        {
            cout<<cards[x]<<" ";
        }
        cout<<endl;

        do
        {
            cout<<"Would you like to pass? (1 = Yes, 2 = no)";
            cin>>ans;
        } while(ans != 1 && ans != 2);

        if(ans == 1)
        {
            for(unsigned x=0;x<playerCards.size();x++)
            {
                if(playerCards[x] == "Ace")
                {
                    cout<<"You have an ace!"<<endl;
                    score += aceChoose();
                }
            }
            isBust();
            return true;
        }
        else
        {
            return false;
        }

    }

    vector<string> getCards()
    {
        return playerCards;
    }

    bool isBust()
    {
        if(score > 21)
        {
            bust = true;
        }
        else
        {
            bust = false;
        }

        return bust;
    }

private:
    vector<string> playerCards;
    bool bust;
    int score;
};

#endif // PLAYER_H
