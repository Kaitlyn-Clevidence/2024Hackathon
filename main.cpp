#include "helpers.cpp"
#include "DrawCard.cpp"
//extern string getIntString(int);

int main(){
    Hand available, discard, player, computer;
    int turn = 0;
    bool win;
    char userChoice;

    int numCards = 1;
    bool isUnoCalled = false;
    Hand playerHand;
    Hand availableCards;
    
    cout << "UNO" << endl;
    do{
        cout << "Do you want to play a game (y/n)? ";
        cin >> userChoice;
    }while(userChoice != 'y' && userChoice != 'Y' && userChoice != 'N' && userChoice != 'n');
    if(userChoice == 'n' || userChoice == 'N'){
        return 0;
    }

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
    //actually input into the hand 
    for(int i = 0; i < 104; i++){
        //string values = getIntString(strings[i]);

        Card temp(to_string(strings[i]));
        available.addCardToHand(temp);
        //available.getLastCard()->setValue(*getIntString(strings[i]));
    }
    //Add 7 cards to both the player and computer hands
    for(int j = 0; j<7;j++){
        cout<<"player"<<endl;
        drawCard(player, available);
        cout<<"Computer"<<endl;
        drawCard(computer, available);
    }

    drawCard(discard, available);
    //Game logic and stuff
    system("clear");
    cout<<"Rules: "<<endl;

    do{
        //isUnoCalled = unoCalled(numCards, isUnoCalled, playerHand, availableCards);
        if(turn%2==0){
            win = playerTurn(player, computer, discard, available, turn);
            turn++;
        }
        else{
            win = computerTurn(computer, player, discard, available, turn);
            turn++;
        }
    }while(!win);
    if(turn%2 == 1){
        cout<<"You won! Would you like to play again? ";
        cin>>userChoice;
        if(userChoice != 'y' || userChoice != 'Y'){
            return 0;
        }
    }
}
