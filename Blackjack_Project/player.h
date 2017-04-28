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

    //Initializes the player
    Player(vector<int> cards)
    {
        //Sets the seed for the intial draw
        srand(time(0)+rand());
        newDeck = cards;
        for(int x=0;x<2;x++)
        {
            draw(newDeck);
        }
        bust = false;
        isBlackJack();
    }

    //Draws a random card from the deck
    void draw(vector<int> deck)
    {
        bool drawn = false;
        int card;

        while(drawn == false)
        {
            //Draws a random card then checks if there are enough cards
            card = (rand() % 13)+1;
            if(deck[card-1] > 0)
            {
                drawn = true;
                deck[card-1]--;
                newDeck = deck;
            }
        }

        //adds the card to the player's visible hand
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
            //If the card is an ace it adds it to the hand and initializes a position for the ace check
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

    //Start of a player's turn
    bool pass()
    {
        //sets the random seed
        srand(time(0));
        int acer = 0;
        int ans;
        vector<string> cards = getCards();

        if(hasBJ)
        {
            cout<<"You have Black Jack!";
        }

        //Prints the cards and the player's score
        cout<<"Your Cards are "<<cards[0]<<" ";
        for(unsigned int x=1;x<cards.size();x++)
        {
            cout<<cards[x]<<" ";
        }
        cout<<endl;
        cout<<"Your current score is: "<<score<<endl;

        //checks for an ace, if present then it calls ace chooser
        for(unsigned int x=0;x<playerCards.size();x++)
        {
            if(playerCards[x] == "Ace")
            {
                acer++;
                aceChoose(acer);
            }
        }
        isBust();

        //This starts the player's input, makes sure the player hasn't busted
        if(bust == false)
        {
            do
            {
                cout<<"Would you like to pass? (1 = Yes, 2 = no)";
                cin>>ans;
                cout<<endl;
            } while(ans != 1 && ans != 2);

            //returns for the main's use
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

    //returns the number of each card advailable after a draw
    vector<int> setNewDeck()
    {
        return newDeck;
    }

    //returns the player's hand
    vector<string> getCards()
    {
        return playerCards;
    }

    //checks if the player is bust, sets the global variable, and returns it
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

    //Checks for blackjack
    void isBlackJack()
    {
        bool ace;
        bool tenCard;

        //checks every card to see if the player has an ace and a 10 card
        for(unsigned int x=0; x<playerCards.size();x++)
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

        //If the player has both cards then the players has blackjack
        if(ace == true && tenCard == true)
        {
            hasBJ = true;
        }

        hasBJ = false;
    }

    //Gives the player's score
    int getScore()
    {
        return score;
    }

    //Used only for the house, adds the ace input to the score
    void setHouseScore(int ace)
    {
        score+=ace;
    }

    //Returns is the player has blackjack
    bool hasBlackJack()
    {
        return hasBJ;
    }

    //Prompts the user to choose a 1 or 11 for their ace
    void aceChoose(int aces)
    {
        int ans = 2;
        while(ans != 1 && ans != 11 && ans != 0 )
        {
            //If the player has not choosen for that ace it asks them
            if(aceUsed[aces-1] == false)
            {
                cout<<"Is this ace a 1 or 11? ";
                cin>>ans;
                cout<<endl;
            }
            else //If they have already choosen then it asks if they want to change it
            {
                cout<<"Would you like to change your ace? (9 = yes, 0 = no) ";
                cin>>ans;
                if(ans == 9)
                {
                    //Removes the score originally put in
                    score = score-lastAce[aces];
                    aceUsed[aces-1] = false;
                }
            }
        }

        //Adds the ace to the score and puts it in long term memory
        if(aceUsed[aces-1]==false)
        {
            score += ans;
            lastAce[aces] = ans;
        }
        aceUsed[aces-1] = true; //uses the ace
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
