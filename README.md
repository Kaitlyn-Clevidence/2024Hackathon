# 2024Hackathon

working - logic
Red
1 - 0, skip, reverse, +2
2 - 1, 2, 3, 4, 5, 6, 7, 8, 9
Blue
1 - 0, skip, reverse, +2
2 - 1, 2, 3, 4, 5, 6, 7, 8, 9
Yellow
1 - 0, skip, reverse, +2
2 - 1, 2, 3, 4, 5, 6, 7, 8, 9
Green
1 - 0, skip, reverse, +2
2 - 1, 2, 3, 4, 5, 6, 7, 8, 9

4 wild cards
4 +4 wild cards 

when a card is played, the next card either has to be the same number, color, or a wild card
1 player playing the game versus the computer 
one turn by the player, one turn by computer
loops until someone wins 
each player starts with 7 cards
win by num cards being 0 
if num cards = 1 for more than 10 seconds, computer outputs "You have uno!" and 4 cards are added to your hand
(what to do if numcards of computer = 1. )


variables necessary 
int numCardsPlayer, int numCardsComputer;
char playerHand[216], computerHand[216];
char availableCards[216] - double of original deck just in case 

methods necessary
drawCard()
addCardToHand
displayPlayerHand()
shuffleCards()
playerTurn() - show the player their hand and allow them to pick one of their cards (ask for input of a character relating to each card) - calls displayplayerhand and validate card 
computerTurn() - loop through computer hand until a valid (validateCard) is found, then play that card. remove the card from the array (dma may be necessary here so we have a first card and last card pointer)
validateCard() - make sure the card is either the number, color, or wild card 
