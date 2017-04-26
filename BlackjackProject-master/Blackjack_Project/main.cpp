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
 int x = 0

for (x = 0; x<players; x++){
   bool pass = false;
    while( pass == false){

        if(x==0){
            pass= p1.pass;}
            else if (x==1){
                pass = p2.pass;}
            else if (x==2){
                pass = p3.pass;}
            else if (x==3){
                pass = p4.pass;}
            else if (x==4){
                pass = p5.pass;}
            else if (x==5){
                pass = p6.pass;}
            else if (x==6){
                pass = p7.pass;}
            else{
                pass = p8.pass}
    }
}










    return 0;










}
