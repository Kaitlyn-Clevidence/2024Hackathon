#include "hand.h"

void drawCard(Hand current, Hand available){
    current.addCardToHand(*available.getFirstCard());
    available.deleteCardFromHand(0);
}

//specialty cards 
void checkSpecialtyCards(Card c, Hand opposite, Hand available){
    if(c == wildvalues){
        wild();
    }
    if(c == skipvalues || c == reversevalues){
        skip(opposite);
    }
    if(c = p2values){
        plus2(opposite, available);
    }
    if(c == wildp4values){
        wildPlus4(opposite, available);
    }
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

void playerTurn(Hand p, Hand discard, Hand available){
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
            //getCardatIndex
            if(validateCard())
            break;

        }
    }
    drawCard(p, available);
}
    //validate card
        //if invalid, prompt again
    //check if special card
        //if special call according special function (skip&reverse have same function)
    //playCard()
    //show the player their hand and allow them to pick one of their cards (ask for input of a character relating to each card) 
    //calls displayplayerhand and validate card and deletecardfromhand
void playCard(Hand hand, Hand discard){
    //display chosen card
    //add chosen card to end of discard hand 
    //delete chosen card from the hand played from
    int cardChoice;
    displayPlayerHand(hand);
    do{
        cout << "Pick one of your cards to play: " << endl;
        cin >> cardChoice;

        if(validateCard(discard.getLastCard() ,hand.getCardatIndex(userChoice - 1))){
        discard.addCardToHand(hand.getCardatIndex(userChoice - 1));
        hand.deleteCardFromHand(hand.getCardatIndex(userChoice - 1));
        }
        else{
        cout << "Invalid card. Choose again." << endl;
        }
    }while(cardChoice < 0 && cardChoice > hand.getNumCardsInHand());
    
}

void displayPlayerHand(Hand hand){
    //loop through player cards and display each of them side by side 
    Card* currentCard = hand.getFirstCard();
    while(currentCard != nullptr){
        currentCard -> displayCard();
        currentCard = currentCard -> getNextCard();
    }
}


/*
shuffleCards()
    //oren is working on it 
//playerTurn() 
    for(int i )
    //check if player has any valid cards (loop)
        //if not, draw 1 card and switch to computer turn 
    //show player their hand
    //prompt for choice of card
    //validate card
        //if invalid, prompt again
    //check if special card
        //if special call according special function (skip&reverse have same function)
    //playCard()
    - show the player their hand and allow them to pick one of their cards (ask for input of a character relating to each card) 
    - calls displayplayerhand and validate card and deletecardfromhand
computerTurn() - 
    //loop through computer hand until a valid (validateCard) is found,
    //check if the card is special
        //if so, call according function
    //playFunction() 
    //remove the card from the array
    //if no valid card is found, draw 1 card and switch turns 

*/
bool validateCard(lastCard, chosenCard){
    //make sure the card is either the number (in value), color (in value), or wild card (is a set of values)
    if(lastCard.getValue()[1] == chosenCard.getValue[1] || lastCard.getValue()[2] == chosenCard.getValue()[2] || chosenCard.getValue()[2] == 'W' || chosenCard.getValue()[2] == 'Y'){
        return true;
    }
    return false;
}
/*
specialCards(Card){
    if Card == wild values
        wild()        
    if card == skip or reverse values
        skip()
    if card == plus 2 values
        plus 2()
    if card == wildPlus4 values
}

skip()
    whoever is playing plays again

*/