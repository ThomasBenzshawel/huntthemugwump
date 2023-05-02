//New code!
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "character.h"
#include "player.h"
using namespace std;



int isWumpNear(map* mainMap,character* wumpus,player* mainPlayer){
int wump = mainMap->WumpusNear();
 if(wump != -1){
        string response;
        cout<<"THE WUMPUS IS NEAR, GET HIM"<<endl;
        cout<<"Action: N)orth, S)outh, E)ast, W)est"<<endl;
        cin >> response;
        char res = response[0];
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
                    cout<<"YOU DIE"<<endl;
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

int main(){

//make map
map *mainMap = new map();
mainMap->load(7, 7);

  /* initialize random seed: */
srand (time(NULL));
//make a random starting location
int random_x = rand() % HEIGHT + 1;
int random_y = rand() % WIDTH + 1;
int random_y2 = rand() % HEIGHT + 1;
int random_x2 = rand() % WIDTH + 1;
cout<<"DDDDDDDDDDDDDDDDDDDDDd";
while(random_y2==random_y||random_x==random_x2){
    random_y2 = rand() % HEIGHT + 1;
    random_x2 = rand() % WIDTH + 1;
}
int bombX;
int bombY;
int isBombPresent=0;
int possibleBombs=3;
player *mainPlayer = new player(mainMap, random_x, random_y,'P');
character * wumpus = new player(mainMap,random_x2,random_y2,'W');
bool isAlive=true;
bool win = false;
 cout<<"AAAAAAAAAAAA";
while (isAlive&&!win){
    if(isBombPresent<=0){
        cout << " Action: N)orth, S)outh, E)ast, W)est, drop B)omb, H)elp, Q)uit:"<<endl;
    }else{
         cout << " Action: N)orth, S)outh, E)ast, W)est, H)elp, Q)uit:"<<endl;
    }
    string response;
    cin >> response;
    char res = response[0];
    if(tolower(res) == 'q'){
        exit(EXIT_SUCCESS);
    } else if(tolower(res) == 'h'){
        cout << "It's no use, GIVE UP!"<<endl;
    } else if (tolower(res) == 'p'){
        mainPlayer->occupiedMap->write();
    } else if(tolower(res) == 'b'){
        if(isBombPresent<=0){
        cout<<"Bomb has been planted NOW RUN!"<<endl;
        possibleBombs--;
        isBombPresent = 3;
        bombX=mainPlayer->current_x;
        bombY=mainPlayer->current_y;
        }else{
            cout<<"you wasted your turn stupid";
        }
    }else {
        mainPlayer->move(tolower(res),'p');
    }
    int status=isWumpNear(mainMap,wumpus,mainPlayer);
    if(status==-1){
        isAlive=false;
    }else if(status==1){
        win=true;
    }
    if(isAlive&&!win){
    wumpus->move();
    cout<<"The wumpus moves"<<endl;
    int status=isWumpNear(mainMap,wumpus,mainPlayer);
    if(status==-1){
        isAlive=false;
    }else if(status==1){
        win=true;
    }
    }
    if(isBombPresent!=0&&--isBombPresent==0){
        cout<<"you hear a rumbling form the bomb"<<endl;
        status = mainMap->blowUp(bombX,bombY);
        if(status==-1){
            cout<<"you blew yourself up"<<endl;
            isAlive=false;
        }else if(status==1){
            cout<<"you hear a bark in the distance that quickly turns into a wimper, You have successfully hunted the wumpus"<<endl;
            cout<<"YOU WIN"<<endl;
            win=true;
        }
    }

}
 cout<<"BAAAAAAAAAAAA";
return 0;
}