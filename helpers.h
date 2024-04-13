#ifndef HELPERS_H
#define HELPERS_H
#include "hand.h"
#include <random>

void drawCard(Hand current, Hand available);
bool validateCard(Card* lastCard, Card* chosenCard);
bool checkSpecialtyCardsPlayer(Card c, Hand opposite, Hand available, int turn);
void wildPlus4Computer(Hand opposite, Hand available);
bool checkSpecialtyCardsComputer(Card c, Hand opposite, Hand available, int turn );
void wild();
void plus2(Hand h, Hand a);
void wildPlus4(Hand other, Hand a);
void playCard(Hand hand, Hand discard, int choice);
void playerTurn(Hand p,Hand np, Hand discard, Hand available, int turn);
void computerTurn(Hand c, Hand nc, Hand discard, Hand available);
int skip(int turn);     
void shuffleCards();
bool checkDeck(Hand available, Hand discard);
void displayPlayerHand(Hand hand);

#endif