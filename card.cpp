#include "card.h"
extern void dispCard(string,int,int);
Card::Card(){
    value = "none"; //n for none
    nextCard = nullptr;
}
Card::Card(string c, Card* n){
    value = c;
    nextCard = n;
}
Card::Card(string c){
    value = c;
}
Card::Card(const Card& rhs){
    value = rhs.value;
    nextCard = rhs.nextCard;
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
string& Card::getValue(){
    return value;
}
void Card::displayACard(int x, int y){
    dispCard(value,x,y);
}
Card Card::operator=(const Card& rhs){
    value = rhs.value;
    nextCard = rhs.nextCard;
    return *this;
}