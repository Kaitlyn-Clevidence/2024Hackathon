#include "hand.h"
#include <random>

void drawCard(Hand current, Hand available){
    current.addCardToHand(*available.getFirstCard());
    available.deleteCardFromHand(0);
}

//specialty cards 
bool checkSpecialtyCardsPlayer(Card c, Hand opposite, Hand available){
    if(c.getValue()[2] == 'Y'){
        wild();
        return true;
    }
    if(c.getValue()[2] == 'S' || c.getValue()[2] == 'R'){
        skip(opposite);
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
bool checkSpecialtyCardsComputer(Card c, Hand opposite, Hand available){
    if(c.getValue()[2] == 'Y'){
        wildComputer();
        return true;
    }
    if(c.getValue()[2] == 'S' || c.getValue()[2] == 'R'){
        skip(opposite);
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
        //displayCard()//blank red card value 
    }
    if(choice == 'b' || choice == 'B'){
        //displayCard()//blank blue card value 
    }
    if(choice == 'g' || choice == 'G'){
        //displayCard()//blank green card value 
    }
    if(choice == 'y' || choice == 'Y'){
        //displayCard()//blank yellow card value 
    }
    //change validation 

}
 
//wildComputer()//must pick random color;

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

void playerTurn(Hand p,Hand np, Hand discard, Hand available){
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
            temp = p.getCardAtIndex(choice-1);
            if(validateCard(test, temp)){
                if(!checkSpecialtyCardsPlayer(*temp, np, available)){
                    playCard(temp);
                }
            }
            break;
        }
    }
    drawCard(p, available);
}

void computerTurn(Hand c, Hand nc, Hand discard, Hand available){
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
            
            temp = c.getCardAtIndex(randomNumber-1);
            if(validateCard(test, temp)){
                if(!checkSpecialtyCardsComputer(*temp, nc, available)){
                    playCard(temp);
                }
            }
            break;
        }
    }
    drawCard(c, available);
}  

/*
displayPlayerHand()
    //loop through player cards and display each of them side by side - need values 
shuffleCards()
    //oren is working on it 

bool validateCard(lastCard, chosenCard)
    //make sure the card is either the number (in value), color (in value), or wild card (is a set of values)

skip()
    whoever is playing plays again

*/

void skip(opposite){

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
        //displayCard()//blank red card value 
    }
    if(choice == '2'){
        //displayCard()//blank blue card value 
    }
    if(choice == '3'){
        //displayCard()//blank green card value 
    }
    if(choice == '4'){
        //displayCard()//blank yellow card value 
    }
}
void wildPlus4Computer(Hand opposite, Hand available){
    drawCard(opposite, available);
    drawCard(opposite, available);
    drawCard(opposite, available);
    drawCard(opposite, available);
    wildComputer();

}
bool validateCard(Card lastCard, Card chosenCard)
    //make sure the card is either the number (in value), color (in value), or wild card (is a set of values)
    if(lastCard.getValue()[1] == chosenCard.getValue()[1] || lastCard.getValue()[2] == chosenCard.getValue()[2] || chosenCard.getValue()[2] == 'W' || chosenCard.getValue()[2] == 'Y'){
        return true;
    }
    return false;

void shuffleCards(){
    //oren has implementation
}
bool checkDeck(){

}




void playCard(Hand hand, Hand discard, int choice){
    //display chosen card

    discard.addCardToHand(hand.getCardatIndex(choice - 1));
    hand.deleteCardFromHand(hand.getCardatIndex(choice - 1));
}

void displayPlayerHand(Hand hand){
    //loop through player cards and display each of them side by side 
    Card* currentCard = hand.getFirstCard();
    while(currentCard != nullptr){
        currentCard -> displayCard();
        currentCard = currentCard -> getNextCard();
    }
}