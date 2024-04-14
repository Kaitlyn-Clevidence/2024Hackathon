#include "helpers.cpp"
#include "DrawCard.cpp"

int main(){
    Hand available, discard, player, computer;
    int turn = 0;
    bool win;
    char userChoice;

    int numCards = 1;
    bool isUnoCalled = false;
    Hand playerHand;
    Hand availableCards;
    
    system("clear");
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

    RANDOIMIZE(strings,100);
    //actually input into the hand 
    for(int i = 0; i < 100; i++){
        //string values = to_string(strings[i]);

        Card temp(to_string(strings[i]));
        available.addCardToHand(temp);
    }
    //Add 7 cards to both the player and computer hands
    for(int j = 0; j<7;j++){
        drawCard(player, available);
        drawCard(computer, available);
    }

    drawCard(discard, available);
    //Game logic and stuff
    system("clear");
    cout<<"Rules: "<<endl;
    cout<<"1. Play a card that is either the same number or color as the one before"<<endl;
    cout<<"2. If you cannot play a card draw one from the draw pile"<<endl;
    cout<<"3. Once you have one card in your hand type 0 to 'yell' uno"<<endl;
    cout<<"Are you ready to start('y' for yes 'n' for no): ";
    char ready; 
    cin>>ready; 
    if(ready == 'y' || ready =='Y'){
        do{
            //isUnoCalled = unoCalled(numCards, isUnoCalled, playerHand, availableCards);
            system("clear");
            discard.getLastCard()->displayACard(2,3);
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
    else if(ready == 'n' || ready == 'N'){
        return 0;
    }
}