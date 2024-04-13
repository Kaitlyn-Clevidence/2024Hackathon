#include "hand.h"

void drawCard(Hand current, Hand available){
    current.addCardToHand(*available.getFirstCard());
    available.deleteCardFromHand(0);
}

//specialty cards 
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
    //change display card to just a solid color card of their choice 
    //change validation 

}

void plus2(Hand h, Hand a){
    drawCard(h, a );
    drawCard(h, a);
}
void wildPlus4(Hand c, Hand a, Hand other){
    drawCard(other, a);
    drawCard(other, a);    
    drawCard(other, a);
    drawCard(other, a);
    wild();
}

/*
playCard()
    //display chosen card
    //add chosen card to end of discard hand 
    //delete chosen card from the hand played from 
displayPlayerHand()
    //loop through player cards and display each of them side by side 
shuffleCards()
    //oren is working on it 
playerTurn() 
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
bool validateCard(lastCard)
    //make sure the card is either the number (in value), color (in value), or wild card (is a set of values)


specialCards(Card){
    if Card == wild values
        wild()        
    if card == skip or reverse values
        skip()
    if card == plus 2 values
        plus 2()
    if card == wildPlus4 values
}
some functionality for specialty cards

skip()
    whoever is playing plays again
plus2() 
    drawCard(other player hand)
    drawCard(other player hand)
wildPlus4()
    drawCard(other player hand)
    drawCard(other player hand)
    drawCard(other player hand)
    drawCard(other player hand)
    wild()

*/