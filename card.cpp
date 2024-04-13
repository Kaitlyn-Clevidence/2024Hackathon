#include "card.h"
extern void dispCard(string,int,int);
Card::Card(){
    value = "none"; //n for none
    nextCard = nullptr;
}
Card::Card(string c){
    value = c;
}
Card::Card(const Card& rhs){
    value = rhs.value;
    if(rhs.nextCard != nullptr){
        nextCard = new Card(*(rhs.nextCard));
    }
    else{
        nextCard = nullptr;
    }
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
    if(this == &rhs){
        return *this;
    }
    value = rhs.value;
    if(rhs.nextCard != nullptr){
        nextCard = new Card(*(rhs.nextCard));
    }
    else{
        nextCard = nullptr;
    }
    return *this;
}