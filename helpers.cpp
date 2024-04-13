#include "helpers.h"
#include "hand.h"
#include <random>
extern string* RANDOIMIZE(string value[],const int a);
extern int* RANDOIMIZE(int value[],const int a);
void RANDOIMIZE(Hand& target){
    RANDOIMIZE(target.getFirstCard());
};
void RANDOIMIZE(const Card* start){
    Card* temp=start;
    int num=0;
    string values[200];
    while(temp!=nullptr){
        values[num]=temp->getValue();
        num++;
        temp=temp->getNextCard();
    }
    RANDOIMIZE(values,num);
    num=0;
    string values[200];
    while(temp!=nullptr){
        temp->setValue(values[num]);
        num++;
        temp=temp->getNextCard();
    }
    
}
void shuffleCards(Hand& target){
    RANDOIMIZE(target);
}
void drawCard(Hand current, Hand available){
    current.addCardToHand(*available.getFirstCard());
    available.deleteCardFromHand(0);
}
bool validateCard(Card* lastCard, Card* chosenCard){
    //make sure the card is either the number (in value), color (in value), or wild card (is a set of values)
    if(lastCard->getValue()[1] == chosenCard->getValue()[1] || lastCard->getValue()[2] == chosenCard->getValue()[2] || chosenCard->getValue()[2] == 'W' || chosenCard->getValue()[2] == 'Y'){
        return true;
    }
    return false;
}

//specialty cards 
bool checkSpecialtyCardsPlayer(Card c, Hand opposite, Hand available, int turn){
    if(c.getValue()[2] == 'Y'){
        wild();
        return true;
    }
    if(c.getValue()[2] == 'S' || c.getValue()[2] == 'R'){
        skip(turn);
        return true;
    }
    if(c.getValue()[2] = '+'){
        plus2(opposite, available);
        return true;
    }
    if(c.getValue()[2] == 'W'){
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
        displayCard(temp);
        //blank red card value 
    }
    if(choice == '2'){
        Card temp("B ");
        displayCard(temp);
        //blank blue card value 
    }
    if(choice == '3'){
        Card temp("G ");
        displayCard(temp);
        //blank green card value 
    }
    if(choice == '4'){
        Card temp("Y ");
        displayCard(temp);
        //blank yellow card value 
    }
}
void wildPlus4Computer(Hand opposite, Hand available){
    drawCard(opposite, available);
    drawCard(opposite, available);
    drawCard(opposite, available);
    drawCard(opposite, available);
    wildComputer();
}
bool checkSpecialtyCardsComputer(Card c, Hand opposite, Hand available, int turn ){
    if(c.getValue()[2] == 'Y'){
        wildComputer();
        return true;
    }
    if(c.getValue()[2] == 'S' || c.getValue()[2] == 'R'){
        skip(turn);
        return true;
    }
    if(c.getValue()[2] = '+'){
        plus2(opposite, available);
        return true;
    }
    if(c.getValue()[2] == 'W'){
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
    if(choice == 'r' || choice == 'R'){
        Card temp("R ");
        displayCard(temp);
        //blank red card value 
    }
    if(choice == 'b' || choice == 'B'){
        Card temp("B ");
        displayCard(temp);
        //blank blue card value 
    }
    if(choice == 'g' || choice == 'G'){
        Card temp("G ");
        displayCard(temp);
        //blank green card value 
    }
    if(choice == 'y' || choice == 'Y'){
        Card temp("Y ");
        displayCard(temp);
        //blank yellow card value 
    }
    //change validation 

}
 
void plus2(Hand h, Hand a){
    drawCard(h, a );
    drawCard(h, a);
}
void wildPlus4(Hand other, Hand a){
    drawCard(other, a);
    drawCard(other, a);    
    drawCard(other, a);
    drawCard(other, a);
    wild();
}

void playCard(Hand hand, Hand discard, int choice){
    //display chosen card
    discard.addCardToHand(hand.getCardatIndex(choice - 1));
    hand.deleteCardFromHand(hand.getCardatIndex(choice - 1));
}

bool playerTurn(Hand p,Hand np, Hand discard, Hand available, int turn){
    Card* temp = p.getFirstCard();
    Card* test = discard.getLastCard();
    for(int i = 0; i < p.getNumCardsInHand(); i++){
        if(validateCard(test, temp)){//test if any cards in the hand are valid 
            int choice;
            //displayplayerHand
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
            turn++;
            if(p.getNumCardsInHand() == 0){
                return true;
            }
            break;
        }
    }
    drawCard(p, available);
    turn++;
    return false;
}

bool computerTurn(Hand c, Hand nc, Hand discard, Hand available, int turn){
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
            turn++;
            break;
        }
    }
    drawCard(c, available);
    turn++;
    return false;
}  

int skip(int turn){
    return turn + 1;
}        

bool checkDeck(Hand available, Hand discard){
    // check if cards are left in available hand
    // if empty shuffle display hand
    // display hand becomes available hand
    if(available.getNumCardsInHand() == 0){
        discard = discard.shuffleCards();
        available = discard;
        return false;
    }
    return true;
}



void displayPlayerHand(Hand hand){
    //loop through player cards and display each of them side by side 
    Card* currentCard = hand.getFirstCard();
    while(currentCard != nullptr){
        currentCard -> displayCard();
        currentCard = currentCard -> getNextCard();
    }
}
