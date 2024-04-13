#include "card.h"

Card::Card(){
    value = 'n'; //n for none
}
Card::Card(string c){
    value = c;
}
Card::Card(const Card& rhs){
    value = rhs.value;
}
void Card::setNextCard(Card* c){
    nextCard = c;
}
Card* Card::getNextCard(){
    return nextCard;
}
void Card::setValue(string n){
    value = n;
}
string Card::getValue(){
    return value;
}
void Card::displayCard(){
    // calls Oren's graphics 
}