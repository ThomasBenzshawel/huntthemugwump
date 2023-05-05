//New code!
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "character.h"
#include "player.h"
using namespace std;


//does the event for if the wumpus is near
//return 0=nothing happens, wumpus leaves
//return 1=you win
//return -1 wumpus kills you
int isWumpNear(map* mainMap,character* wumpus,player* mainPlayer){
//checks if the wumpus is near
    int wump = mainMap->WumpusNear();
    if(wump != -1){
            string response;
            cout<<"You hear the wumpus close by! Which direction will you stab in?"<<endl;
            cout<<"Action: N)orth, S)outh, E)ast, W)est"<<endl;
            cin >> response;
            char res = response[0];

            //Attack with a sword instead of the bomb
            if((res=='n'||res=='N')&&(wump==3)){
                return 1;
            }else if((res=='e'||res=='E')&&(wump==2)){
                return 1;
            }else if((res=='w'||res=='W')&&(wump==1)){
                return 1;
            }else if((res=='s'||res=='S')&&(wump==4)){
                return 1;
            }else{
                if(!wumpus->move()){
                    if(mainPlayer->hasWumpSheild){
                        mainPlayer->hasWumpSheild=false;
                        cout<<"The Wumpus Attacks!"<<endl;
                        cout<<"You would of been dead but thanks to your sheild you survive!"<<endl;
                        return 0;
                    }else{
                        cout<<"The Wumpus Attacks!"<<endl;
                        cout<<"The Wumpus crushes you like an annoying bug."<<endl;
                        return -1;
                    }
                }else{
                    cout<<"The Wumpus escapes, but he is near!"<<endl;
                    return 0;
                }
            }
        }
        return 0;
}

int isTrapNear(map* mainMap, player* mainPlayer){
//checks if a trap is near 
    int trapNear = mainMap->trapNear(mainPlayer->current_x, mainPlayer->current_y);
    if(trapNear != -1){
            cout<<"You hear the creaking of an arrow or net trap nearby"<<endl;
        }
    return 0;
}


int main(){
//make map
map *mainMap = new map();
mainMap->load(7, 7);
  /* initialize random seed: */
srand (time(NULL));
//make a random starting location
int random_x = rand() % HEIGHT;
int random_y = rand() % WIDTH;
int random_y2 = rand() % HEIGHT;
int random_x2 = rand() % WIDTH;
while(random_y2==random_y||random_x==random_x2){
    random_y2 = rand() % HEIGHT;
    random_x2 = rand() % WIDTH;
}
//for location of the bomb
int bombX=-1;
int bombY=-1;
//counts how many turns till the bomb blows up 
int isBombPresent=0;
//number of bombs before you lose
int caveInCounter=3;
player *mainPlayer = new player(mainMap, random_x, random_y,'P');
character * wumpus = new player(mainMap,random_x2,random_y2,'W');
bool isAlive=true;
bool win = false;
bool turnLost = false;
int status;

isTrapNear(mainMap, mainPlayer);

while (isAlive&&!win){
    //if the turn is lost then skip your turn
    if(turnLost){
        mainPlayer->occupiedMap->write();
        turnLost=false;
    }else{
    //sequence for your turn
     if(isBombPresent<=0){
        mainPlayer->occupiedMap->write();
        cout << "Action: N)orth, S)outh, E)ast, W)est, drop B)omb, H)elp, Q)uit:"<<endl;
    }else{
        mainPlayer->occupiedMap->write();
         cout << "Action: N)orth, S)outh, E)ast, W)est, H)elp, Q)uit:"<<endl;
    }
    //get response
    string response;
    cin >> response;
    char res = response[0];
    if(tolower(res) == 'q'){
        exit(EXIT_SUCCESS);
    } else if(tolower(res) == 'h'){
        //TODO Actually make a help function
        cout << "You are an explosively inclined adventurer equiped with 3 bombs, that is hunting a terrifying wumpus that is made of stone." <<endl 
        << "You must hunt this creature in a dark cave laden with traps, explosives, and shields left from past hunters. " << endl
        << "The Wumpus will immediatly kill anything with light, so you must hunt your prey in the dark, using only your hearing to guide you " << endl
        << "Your prey can be killed with a well placed bomb, but be carefull! If you don't run far enough, you'll hurt youself with the explosion." << endl
        << "The explosives you came with will also destroy any traps or loot near it! Use them wisely though, you wouldn't want to cause a cave in, would you?" << endl
        << "You can also kill the wumpus with a precise stab in the eye with your trusty sword while it's close by. " << endl
        << "Finally, listen for the creaking of traps left from other adventurers (that are absolutely useless against the hulking behemoth)," << endl
        << "especially if you dont have a protective shield. Happy hunting!"<<endl;
    } else if(tolower(res) == 'b'){
        //planting the bomb
        if(isBombPresent<=0){
            if(mainPlayer->numBomb !=0){
                cout<<"Bomb has been planted, NOW RUN!"<<endl;
                caveInCounter--;
                mainPlayer->numBomb--;
                cout << "You have " << mainPlayer->numBomb << " bombs left!" << endl;

                isBombPresent = 3;
                bombX=mainPlayer->current_x;
                bombY=mainPlayer->current_y;
            } else {
                 cout<<"You don't have any bombs left! You wasted your turn"<<endl;
            }

        } else {
            //cant place multiple bombs, you would die otherwise 
            cout<<"you wasted your turn"<<endl;
        }
    } else if(tolower(res) == 'n' || tolower(res) == 's' || tolower(res) == 'e' || tolower(res) == 'w') {
        //moving the player
        status = mainPlayer->move(tolower(res),'P');
        //if status is 0 then net trap triggered
        if(status ==0){
            turnLost=true;
        }if(status ==-1){
            isAlive=false;
        }

        isTrapNear(mainMap, mainPlayer);

    } else {
        cout<<"you wasted your turn, please enter a valid input"<<endl;
    }

    //check if wumpus is near and trigger the event
    if(isAlive&&!win) {
    status=isWumpNear(mainMap,wumpus,mainPlayer);
    if(status==-1){
        isAlive=false;
    }else if(status==1){
        cout<<"You stab blindly into the darkness and stab the creature in the eye, felling the terrible beast!"<<endl;
        win=true;
    }
    }
    //sequence for the wumpus
    if(isAlive&&!win){
    wumpus->move();
    cout<<"You hear thumping as the Wumpus moves around in the cave"<<endl;
    //check if the wumpus is near
    int status= isWumpNear(mainMap,wumpus,mainPlayer);
    if(status==-1){
        isAlive=false;
    }else if(status==1){
        cout<<"You stab blindly into the darkness and stab the creature in the eye, felling the terrible beast!"<<endl;
        win=true;
    }
    }
    }
    //logic for triggering the bomb
    if(isBombPresent!=0&&--isBombPresent==0){
        cout<<"you hear a rumbling from the bomb"<<endl;
        status = mainMap->blowUp(bombX,bombY);

        if(caveInCounter == 1){
            cout<<"Rocks tumble down around you, the whole cave system shakes."<<endl;
        }

        if(caveInCounter == 0){
            cout<<"The roof collapses in on you, congrats you killed the Wumpus(and yourself) with a cave in!"<<endl;
            isAlive = false;
        }

        if(status==-1){
            cout<<"you blew yourself up"<<endl;
            isAlive=false;
        }else if(status==1){
            cout<<"you hear a roar in the distance that quickly turns into a crash followed by rumbling, You have successfully hunted the wumpus"<<endl;
        
            win=true;
        }
    }   
   

}
//ending sequence, checks if you won or not 
 if(win&&isAlive){
        cout<<"You Win!"<<endl;
}else{
        cout<<"You Lose!"<<endl;
}
return 0;
}