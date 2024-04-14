#include "hand.h"
#include <random>
#include <ctime>

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

void displayPlayerHand(Hand& hand){
    //loop through player cards and display each of them side by side 
    Card* currentCard = hand.getFirstCard();
    int location=0;
    while(currentCard != nullptr){
        currentCard->displayACard(25,location*5+3);
        currentCard = currentCard->getNextCard();
        location++;
    }
    cout<<"\e[m\e[31;1H";
}
void wild();
void plus2(Hand& h, Hand& a);
void wildPlus4(Hand& other, Hand& a);
int skip(int turn);

void shuffleCards(Hand& target){
    RANDOIMIZE(target);
}
void drawCard(Hand& current, Hand& available){
    current.addCardToHand(*available.getFirstCard());
    available.deleteCardFromHand(0);
}
bool validateCard(Card* lastCard, Card* chosenCard){
    //make sure the card is either the number (in value), color (in value), or wild card (is a set of values)
    if(stoi(lastCard->getValue())%4 == stoi(chosenCard->getValue())%4){
        return true;
    }
    else if(stoi(lastCard->getValue())-stoi(lastCard->getValue())%4 == stoi(chosenCard->getValue())-stoi(chosenCard->getValue())%4){
        return true;
    }
    else if(stoi(chosenCard->getValue())-stoi(chosenCard->getValue())%4==10||stoi(chosenCard->getValue())-stoi(chosenCard->getValue())%4==14){
        return true;
    }
    else{
        return false;
    }
    return false;
}
int getSecond(int a){
    return a/4;
}
int getSecond(string a){
    return stoi(a)/4;
}

//specialty cards 
bool checkSpecialtyCardsPlayer(Card c, Hand& opposite, Hand& available, int turn){
    if(getSecond(c.getValue()) ==14){
        wild();
        return true;
    }
    if(getSecond(c.getValue()) ==13 || getSecond(c.getValue()) ==10){
        skip(turn);
        return true;
    }
    if(getSecond(c.getValue()) ==11){
        plus2(opposite, available);
        return true;
    }
    if(getSecond(c.getValue()) ==12){
        wildPlus4(opposite, available);
        return true;
    }
    return false;
}
void wildComputer(){
    char choice;
    random_device rd;
    mt19937 gen(rd());
    // Define the distribution
    uniform_int_distribution<> dis(1, 4);
    // Generate a random number
    int randomNumber = dis(gen);
            
    if(choice == '1'){
        Card temp("R ");
        temp.displayACard(75, 18);
        //blank red card value 
    }
    if(choice == '2'){
        Card temp("B ");
        temp.displayACard(75, 18);
        //blank blue card value 
    }
    if(choice == '3'){
        Card temp("G ");
        temp.displayACard(75, 18);
        //blank green card value 
    }
    if(choice == '4'){
        Card temp("Y ");
        temp.displayACard(75, 18);
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
bool checkSpecialtyCardsComputer(Card c, Hand& opposite, Hand& available, int turn ){
    if(getSecond(c.getValue()) ==14){
        wildComputer();
        return true;
    }
    if(getSecond(c.getValue()) ==13 || getSecond(c.getValue()) ==10){
        skip(turn);
        return true;
    }
    if(getSecond(c.getValue()) ==11){
        plus2(opposite, available);
        return true;
    }
    if(getSecond(c.getValue()) ==12){
        wildPlus4Computer(opposite, available);
        return true;
    }
    return false;
}

void wild(){
    //prompt for color 
    char choice;
    do{
        cout<<"What color would you like to pick? (R/B/G/Y) ";
        cin>>choice;
    }while(choice != 'r' && choice != 'R' && choice!= 'b' &&choice != 'B' && choice != 'g' && choice!= 'G' &&choice != 'Y' && choice != 'y');
    if(choice ==10 || choice ==10){
        Card temp("R ");
        temp.displayACard(75, 18);
        //blank red card value 
    }
    if(choice == 'b' || choice == 'B'){
        Card temp("B ");
        temp.displayACard(75, 18);
        //blank blue card value 
    }
    if(choice == 'g' || choice == 'G'){
        Card temp("G ");
        temp.displayACard(75, 18);
        //blank green card value 
    }
    if(choice ==14 || choice ==14){
        Card temp("Y ");
        temp.displayACard(75, 18);
        //blank yellow card value 
    }
    //change validation 

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

void playCard(Hand& hand, Hand& discard, int choice){
    discard.addCardToHand(hand.getCardAtIndex(choice - 1));
    discard.getLastCard()->displayACard(75, 18);
    hand.deleteCardFromHand(choice - 1);
}

bool playerTurn(Hand& p, Hand& np, Hand& discard, Hand& available, int turn){
    cout<<"Player turn"<<endl;
    Card* temp = p.getFirstCard();
    Card* test = discard.getLastCard();

    Card* temp2=p.getFirstCard();
    displayPlayerHand(p);
    

    for(int i = 0; i < p.getNumCardsInHand(); i++){
        //update temp as you go 
        if(validateCard(test, temp)){//test if any cards in the hand are valid 
            cout <<"past validate card";
            int choice;
            displayPlayerHand(p);
            do{
                cout<<"Which card would you like to play? ";
                cin>>choice;
            }while(choice<1 || choice>p.getNumCardsInHand());
            Card merp = p.getCardAtIndex(choice-1);
            Card* merpTwo = &merp;
            if(validateCard(test, merpTwo)){
                if(!checkSpecialtyCardsPlayer(*merpTwo, np, available, turn)){
                    playCard(p, discard, choice);
                }
            }
            if(p.getNumCardsInHand() == 0){
                return true;
            }
            break;
        }
        temp = temp->getNextCard();
    }
    drawCard(p, available);
    return false;
}

bool computerTurn(Hand& c, Hand& nc, Hand& discard, Hand& available, int turn){
    cout<<"Computer Turn"<<endl;
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
            break;
        }
        temp = temp->getNextCard();
    }
    drawCard(c, available);
    return false;
}  

int skip(int turn){
    return turn + 1;
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
