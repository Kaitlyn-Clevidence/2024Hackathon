#include "helpers.cpp"

int main(){
    Hand available, discard, player, computer;
    int turn =0;
    bool win;
    char userChoice;

    int numCards = 1;
    bool isUnoCalled = false;
    Hand playerHand;
    Hand availableCards;
    
    cout << "UNO" << endl;
    do{
        cout << "Do you want to play a game (y/n)? " << endl;
        cin >> userChoice;
    }while(userChoice != 'y' && userChoice != 'Y' && userChoice != 'N' && userChoice != 'n');
    if(userChoice == 'n' || userChoice == 'N'){
        return 0;
    }

    cout<<"1"<<endl;
    //Populate the available hand
    int strings[108];
    cout<<"2"<<endl;
    int n=0;
    cout<<"3"<<endl;
    for(int i=0;i<1;i++){
        cout<<"4"<<endl;
        for(int j=0;j<4;j++){
            cout<<"5"<<endl;
            strings[n]=(i*4+j);n++;
        }
    }
    cout<<"6"<<endl;
    for(int i=1;i<11;i++){
            cout<<"7"<<endl;

        for(int j=0;j<4;j++){
                cout<<"8"<<endl;

            strings[n]=(i*4+j);strings[n+1]=(i*4+j);n+=2;
        }
    }
        cout<<"9"<<endl;

    for(int i=11;i<16;i++){
            cout<<"10"<<endl;

        for(int j=0;j<4;j++){
                cout<<"11"<<endl;

            strings[n]=(i*4+j);n++;
        }
    }
        cout<<"12"<<endl;

    RANDOIMIZE(strings,104);
    cout<<"ugh"<<endl;
    //actually input into the hand 
    for(int i = 0; i < 104; i++){
        Card temp(to_string(strings[i]));
        available.addCardToHand(temp);
    }
    //Add 7 cards to both the player and computer hands
    for(int j = 0; j<7;j++){
        drawCard(player, available);
        drawCard(computer, available);
    }
    //Game logic and stuff
    do{
        isUnoCalled = unoCalled(numCards, isUnoCalled, playerHand, availableCards);
        if(turn%2==1){
            win = playerTurn(player, computer, discard, available, turn);
        }
        if(turn%2 == 0){
            win = computerTurn(computer, player, discard, available, turn);
        }
    }while(!win);
}
