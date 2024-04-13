#include "hand.h"
/*
drawCard()
    //take first card of the availible hand and add it to the hand of who ever needs to draw the card 
    //reset the first card in the availible hand to the next card
    //delete the previous first card in the availible hand 
    //decrement the number of cards in the availible hand 
playCard()
    //
displayPlayerHand()
shuffleCards()
playerTurn() 
    //show player their hand
    //prompt for choice of card
    //validate card
    - show the player their hand and allow them to pick one of their cards (ask for input of a character relating to each card) 
    - calls displayplayerhand and validate card and deletecardfromhand
computerTurn() - loop through computer hand until a valid (validateCard) is found, then play that card. remove the card from the array (dma may be necessary here so we have a first card and last card pointer)
validateCard(lastCard)
    //make sure the card is either the number, color, or wild card

*/