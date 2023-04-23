//New code!
#include <iostream>
#include <string>
using namespace std;


void processResponse(char response){
    if(tolower(response) == 'q'){
        exit(EXIT_SUCCESS);
    }
}

int main(){
cout << " Action: N)orth, S)outh, E)ast, W)est, shoot A)rrow, H)elp, Q)uit:";
string response;
cin >> response;
processResponse(response[0]);

return 0;
}