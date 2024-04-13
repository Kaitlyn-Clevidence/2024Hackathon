#include "helpers.cpp"

int main(){
    Hand available, discard, player, computer;
    int userChoice;
    
    cout << "UNO" << endl;
    do{
        cout << "Do you want to play a game (y/n)? " << endl;
        cin >> userChoice;
    }while(userChoice != 'y' && userChoice != 'n');

    //Populate the available hand
    int strings[108];
    int n=0;
    for(int i=0;i<1;i++){
        for(int j=0;j<4;j++){
            strings[n]=(i*4+j);n++;
        }
    }
    for(int i=1;i<11;i++){
        for(int j=0;j<4;j++){
            strings[n]=(i*4+j);strings[n+1]=(i*4+j);n+=2;
        }
    }
    for(int i=11;i<16;i++){
        for(int j=0;j<4;j++){
            strings[n]=(i*4+j);n++;
        }
    }
    RANDOIMIZE(strings,104);
    /*for(int i=0;i<27;i++){
        for(int j=0;j<4;j++){
            displayCard((strings[i*4+j]),5*j+2,5*i+2);
        }
    }*/
    cardStack(5,5,0);
    cout<<"\e[25;25H";

    //Add 7 cards to both the player and computer hands
    //Game logic and stuff
    do{
        if(turn%2==1){
            win = playerTurn(player, computer, discard, available, turn);
        }
        if(turn%2 == 0){
            win = computerTurn(computer, player, discard, available, turn);
        }
    }while(!win);
}
