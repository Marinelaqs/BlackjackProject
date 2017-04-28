#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <cstdlib>

using namespace std;

class Player
{
public:
    vector<int> newDeck = {0,0,0,0,0,0,0,0,0,0,0,0,0};

    Player(vector<int> cards)
    {
        newDeck = cards;
        for(int x=0;x<2;x++)
        {
            draw(newDeck);
        }
        bust = false;
        isBlackJack();
    }

    void draw(vector<int> deck)
    {
        bool drawn = false;
        int card;

        while(drawn == false)
        {
            card = (rand() % 13)+1;
            if(deck[card-1] > 0)
            {
                drawn = true;
                deck[card-1]--;
                newDeck = deck;
            }
        }

        if(card == 11)
        {
            playerCards.push_back("Joker");
            score += 10;
        }
        else if(card == 12)
        {
            playerCards.push_back("Queen");
            score += 10;
        }
        else if(card == 13)
        {
            playerCards.push_back("King");
            score += 10;
        }
        else if(card == 1)
        {
            playerCards.push_back("Ace");
            aceUsed.push_back(false);
            lastAce.push_back(1);
        }
        else
        {
            playerCards.push_back(to_string(card));
            score += card;
        }

        isBlackJack();

    }

    bool pass()
    {
        srand(time(0));
        int acer = 0;
        int ans;
        vector<string> cards = getCards();

        if(hasBJ)
        {
            cout<<"You have Black Jack!";
        }
        cout<<"Your Cards are "<<cards[0]<<" ";
        for(int x=1;x<cards.size();x++)
        {
            cout<<cards[x]<<" ";
        }
        cout<<endl;
        cout<<"Your current score is: "<<score<<endl;

        for(int x=0;x<playerCards.size();x++)
        {
            if(playerCards[x] == "Ace")
            {
                acer++;
                aceChoose(acer);
            }
        }
        isBust();

        if(bust == false)
        {
            do
            {
                cout<<"Would you like to pass? (1 = Yes, 2 = no)";
                cin>>ans;
                cout<<endl;
            } while(ans != 1 && ans != 2);

            if(ans == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            cout<<"You are over 21, You bust"<<endl;
            return true;
        }

    }

    vector<int> setNewDeck()
    {
        return newDeck;
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

    void isBlackJack()
    {
        bool ace;
        bool tenCard;

        for(int x=0; x<playerCards.size();x++)
        {
            if(playerCards[x] == "Ace")
            {
                ace = true;
            }
            else if(playerCards[x] == "Jack" || playerCards[x] == "Queen" || playerCards[x] == "King" || playerCards[x] == "10")
            {
                tenCard = true;
            }
        }

        if(ace == true && tenCard == true)
        {
            hasBJ = true;
        }

        hasBJ = false;
    }

    int getScore()
    {
        return score;
    }

    void setHouseScore(int ace)
    {
        score+=ace;
    }

    bool hasBlackJack()
    {
        return hasBJ;
    }

    void aceChoose(int aces)
    {
        int ans = 2;
        while(ans != 1 && ans != 11 && ans != 0 )
        {
            if(aceUsed[aces-1] == false)
            {
                cout<<"Is this ace a 1 or 11? ";
                cin>>ans;
                cout<<endl;
            }
            else
            {
                cout<<"Would you like to change your ace? (9 = yes, 0 = no) ";
                cin>>ans;
                if(ans == 9)
                {
                    score = score-lastAce[aces];
                    aceUsed[aces-1] = false;
                }
            }
        }

        if(aceUsed[aces-1]==false)
        {
            score += ans;
            lastAce[aces] = ans;
        }
        aceUsed[aces-1] = true;
    }

private:
    vector<int> lastAce = {0};
    vector<bool> aceUsed;
    vector<string> playerCards;
    bool hasBJ;
    bool bust;
    int score;
};

#endif // PLAYER_H
