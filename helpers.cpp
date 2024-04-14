#include "hand.h"
#include <random>
#include <ctime>

//randomizing functions
extern string* RANDOIMIZE(string value[],const int a);
extern int* RANDOIMIZE(int value[],const int a);
void RANDOIMIZE(Card* start){
    Card* temp = start;
    int num=0;
    string values[200];
    while(temp!=nullptr){
        values[num]=temp->getValue();
        num++;
        temp=temp->getNextCard();
    }
    RANDOIMIZE(values,num);
    num=0;
    
    while(temp!=nullptr){
        temp->setValue(values[num]);
        num++;
        temp=temp->getNextCard();
    }
    
}
void RANDOIMIZE(Hand& target){
    RANDOIMIZE(target.getFirstCard());
};

void drawCard(Hand& current, Hand& available){
    current.addCardToHand(*available.getFirstCard());
    available.deleteCardFromHand(0);
}

void displayPlayerHand(Hand& hand){
    //loop through player cards and display each of them side by side 
    Card* currentCard = hand.getFirstCard();
    int location=0;
    while(currentCard != nullptr){
        currentCard->displayACard(6,location*5+3);
        currentCard = currentCard->getNextCard();
        location++;
    }
    cout<<"\e[m\e[10;1H";
    for(int i = 0; i< hand.getNumCardsInHand(); i++){
        cout<<"    "<<i+1;
    }
    cout<<endl;
}
void wild(){
    //prompt for color 
    char choice;
    do{
        cout<<"What color would you like to pick? (R/B/G/Y) ";
        cin>>choice;
    }while(choice != 'r' && choice != 'R' && choice!= 'b' &&choice != 'B' && choice != 'g' && choice!= 'G' &&choice != 'Y' && choice != 'y');
    if(choice == 'r' || choice == 'R'){
        Card temp("R ");
        temp.displayACard(2, 3);
        //blank red card value 
    }
    if(choice == 'b' || choice == 'B'){
        Card temp("B ");
        temp.displayACard(2, 3);
        //blank blue card value 
    }
    if(choice == 'g' || choice == 'G'){
        Card temp("G ");
        temp.displayACard(2, 3);
        //blank green card value 
    }
    if(choice == 'y' || choice == 'Y'){
        Card temp("Y ");
        temp.displayACard(2, 3);
        //blank yellow card value 
    }
    //change validation 

}
int skip(int turn){
    return turn + 1;
}        
void plus2(Hand& h, Hand& a){
    drawCard(h, a );
    drawCard(h, a);
}
void wildPlus4(Hand& other, Hand& a){
    drawCard(other, a);
    drawCard(other, a);    
    drawCard(other, a);
    drawCard(other, a);
    wild();
}
void wildComputer(){
    random_device rd;
    mt19937 gen(rd());
    // Define the distribution
    uniform_int_distribution<> dis(1, 4);
    // Generate a random number
    int randomNumber = dis(gen);
            
    if(randomNumber == '1'){
        Card temp("R ");
        temp.displayACard(2, 3);
        //blank red card value 
    }
    if(randomNumber == '2'){
        Card temp("B ");
        temp.displayACard(2, 3);
        //blank blue card value 
    }
    if(randomNumber == '3'){
        Card temp("G ");
        temp.displayACard(2, 3);
        //blank green card value 
    }
    if(randomNumber == '4'){
        Card temp("Y ");
        temp.displayACard(2, 3);
        //blank yellow card value 
    }
}
void wildPlus4Computer(Hand& opposite, Hand& available){
    drawCard(opposite, available);
    drawCard(opposite, available);
    drawCard(opposite, available);
    drawCard(opposite, available);
    wildComputer();
}

void shuffleCards(Hand& target){
    RANDOIMIZE(target);
}

bool validateCard(Card* lastCard, Card* chosenCard){
    //make sure the card is either the number (in value), color (in value), or wild card (is a set of values)
    if(stoi(lastCard->getValue())%4 == stoi(chosenCard->getValue())%4){
        return true;
    }
    else if(stoi(lastCard->getValue())-stoi(lastCard->getValue())%4 == stoi(chosenCard->getValue())-stoi(chosenCard->getValue())%4){
        return true;
    }
    else if(stoi(lastCard->getValue())-stoi(lastCard->getValue())%4 == stoi(chosenCard->getValue())-stoi(chosenCard->getValue())%4){
        return true;
    }
    else{
        return false;
    }
}

int getSecond(int a){
    return a/4;
}
int getSecond(string a){
    return stoi(a)/4;
}
//specialty cards 
bool checkSpecialtyCardsPlayer(Card c, Hand& opposite, Hand& available, int turn){
    if(getSecond(c.getValue()) == 14){
        wild();
        return true;
    }
    if(getSecond(c.getValue()) == 13 || getSecond(c.getValue()) == 10){
        skip(turn);
        return true;
    }
    if(getSecond(c.getValue()) == 11){
        plus2(opposite, available);
        return true;
    }
    if(getSecond(c.getValue()) == 12){
        wildPlus4(opposite, available);
        return true;
    }
    return false;
}

bool checkSpecialtyCardsComputer(Card c, Hand& opposite, Hand& available, int turn ){
    if(getSecond(c.getValue()) == 14){
        wildComputer();
        return true;
    }
    if(getSecond(c.getValue()) == 13 || getSecond(c.getValue()) == 10){
        skip(turn);
        return true;
    }
    if(getSecond(c.getValue()) == 11){
        plus2(opposite, available);
        return true;
    }
    if(getSecond(c.getValue()) == 12){
        wildPlus4Computer(opposite, available);
        return true;
    }
    return false;
}

void playCard(Hand& hand, Hand& discard, int choice){
    discard.addCardToHand(hand.getCardAtIndex(choice - 1));
    hand.deleteCardFromHand(choice - 1);
}

bool playerTurn(Hand& p, Hand& np, Hand& discard, Hand& available, int turn){
    Card* temp = p.getFirstCard();
    Card* test = discard.getLastCard();
    bool playedCard = false, specialty;
    for(int i = 0; i < p.getNumCardsInHand(); i++){
        //update temp as you go 
        if(validateCard(test, temp)){//test if any cards in the hand are valid 
            int choice;
            displayPlayerHand(p);
            do{
                cout<<endl<<"Which card would you like to play? ";
                cin>>choice;
            }while(choice<1 || choice>p.getNumCardsInHand());
            Card merp = p.getCardAtIndex(choice-1);
            Card* merpTwo = &merp;
            if(validateCard(test, merpTwo)){
                checkSpecialtyCardsPlayer(*merpTwo, np, available, turn);
                playCard(p, discard, choice);
                playedCard = true;
            }
            if(p.getNumCardsInHand() == 0){
                return true;
            }
            return false;
            break;
        }
        temp = temp->getNextCard();
    }
    
    if(!playedCard){
        drawCard(p, available);
    }
    return false;
}

bool computerTurn(Hand& c, Hand& nc, Hand& discard, Hand& available, int turn){
    Card* temp = c.getFirstCard();
    Card* test = discard.getLastCard();
    for(int i = 0; i < c.getNumCardsInHand(); i++){
        if(validateCard(test, temp)){//test if any cards in the hand are valid 
            //random from 1-getnumcardsinhand 
            // Seed for random number generation
            random_device rd;
            mt19937 gen(rd());
            // Define the distribution
            uniform_int_distribution<> dis(1, c.getNumCardsInHand());
            // Generate a random number
            int randomNumber = dis(gen);
            
            Card merp = c.getCardAtIndex(randomNumber-1);
            Card* merpTwo = &merp;
            if(validateCard(test, merpTwo)){
                if(!checkSpecialtyCardsComputer(*merpTwo, nc, available, turn)){
                    playCard(c, discard, randomNumber);
                }
            }
            if(c.getNumCardsInHand() == 0){
                return true;
            }
            if(c.getNumCardsInHand() == 1){
                cout<<"Your opponent has Uno!!"<<endl;
            }
            return false;
            break;
        }
        temp = temp->getNextCard();
    }
    drawCard(c, available);
    return false;
}  

bool checkDeck(Hand& available, Hand& discard){
    // check if cards are left in available hand
    // if empty shuffle display hand
    // display hand becomes available hand
    if(available.getNumCardsInHand() == 0){
        shuffleCards(discard);
        available = discard;
        return false;
    }
    return true;
}

bool unoCalled(int numCards, bool isUnoCalled, Hand& p, Hand& available){
    if(numCards == 1){
        clock_t start = clock();
        while ((clock() - start) / CLOCKS_PER_SEC < 10 && !isUnoCalled){
            char uno;
            cin >> uno; 
            if(uno = '0'){
                isUnoCalled = true; 
            }
        }
        if(numCards == 1 && !isUnoCalled){
            isUnoCalled = true;
            cout << "You didn't say you have uno!!" << endl;
            for (int i = 0; i < 4; i++) {
                drawCard(p, available);
            }
        }
    }
    return isUnoCalled; 
}