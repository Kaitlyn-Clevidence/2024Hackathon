#include "hand.h"
#include "hand.h"
/*
*
drawCard()
    //take first card of the availible hand and add it to the hand of who ever needs to draw the card 
    //reset the first card in the availible hand to the next card
    //delete the previous first card in the availible hand 
    //decrement the number of cards in the availible hand 
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
    //make sure the card is either the number, color, or wild card


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
wild()
    prompt for color 
    change display card to just a solid color card of their choice 
    change validation 
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
