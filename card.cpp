#include "card.h"

Card::Card(){
    name = 'n'; //n for none
}
Card::Card(string c){
    name = c;
}
Card::Card(const Card& rhs){
    name = rhs.name;
}
void Card::setNextCard(Card* c){
    nextCard = c;
}
Card* Card::getNextCard(){
    return nextCard;
}
void Card::setName(string n){
    name = n;
}
string Card::getName(){
    return name;
}
void Card::displayCard(){
    // calls Oren's graphics 
}