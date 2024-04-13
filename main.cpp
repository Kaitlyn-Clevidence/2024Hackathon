#include "helpers.cpp"
#include "DrawCard.cpp"

int main(){
    Hand available, discard, player, computer;
    int userChoice;
    cout << "UNO" << endl;
    do{
        cout << "Do you want to play a game (y/n)? " << endl;
        cin >> userChoice;
    }while(userChoice != 'y' && userChoice != 'n');

    //Populate the available hand
    //Add 7 cards to both the player and computer hands
    //Game logic and stuff
}