//New code!
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
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

  /* initialize random seed: */
srand (time(NULL));
//make a random starting location
int random_x = rand() % 9 + 1;
int random_y = rand() % 9 + 1;
character *mainPlayer = new character(mainMap, random_x, random_y);



while (true){
    cout << " Action: N)orth, S)outh, E)ast, W)est, drop B)omb, H)elp, Q)uit:";
    string response;
    cin >> response;

    processResponse(response[0], mainPlayer);
}
return 0;
}