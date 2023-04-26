//New code!
#include <iostream>
#include <string>
#include "map.h"
#include "character.h"
#include "player.h"
using namespace std;


void processResponse(char response, character* mainPlayer){
    if(tolower(response) == 'q'){
        exit(EXIT_SUCCESS);
    } else if(tolower(response) == 'h'){
        cout << "It's no use, GIVE UP!";
    } else {
        mainPlayer->move(tolower(response));
    }
}

int main(){

//make map
map *mainMap = new map();
mainMap->load();

//make a random starting location
int random_x = rand() % WIDTH;
int random_y = rand() % HEIGHT;
character *mainPlayer = new character(mainMap, random_x, random_y);



while (true){
    cout << " Action: N)orth, S)outh, E)ast, W)est, drop B)omb, H)elp, Q)uit:";
    string response;
    cin >> response;

    processResponse(response[0], mainPlayer);
}
return 0;
}