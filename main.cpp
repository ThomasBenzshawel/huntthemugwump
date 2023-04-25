//New code!
#include <iostream>
#include <string>
#include <map.h>
#include <character.h>
#include <player.h>
using namespace std;


void processResponse(char response, player* mainPlayer){
    if(tolower(response) == 'q'){
        exit(EXIT_SUCCESS);
    } else if(tolower(response) == 'h'){
        cout << "It's no use, GIVE UP!";
    } else {
        mainPlayer->move(tolower(response));
    }
}

int main(){
cout << " Action: N)orth, S)outh, E)ast, W)est, drop B)omb, H)elp, Q)uit:";
string response;
cin >> response;

//make map
map *mainMap = new map();
mainMap->load();

//make a random starting location
int random_x = rand() % WIDTH;
int random_y = rand() % HEIGHT;
player *mainPlayer = new player(mainMap, random_x, random_y);

processResponse(response[0], mainPlayer);

return 0;
}