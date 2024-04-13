#include "hand.h"

Hand::Hand(){
    firstCard = nullptr;
    lastCard = nullptr;
    numCardsInHand = 0; 
}
Hand::Hand(Card* f, Card* l, int n){
    numCardsInHand =n;
    if(f == nullptr){
        firstCard = lastCard = nullptr;
        return;
    }
    Card* temp = f;
    firstCard = lastCard = new Card;
    firstCard->setName(temp->getName());
    firstCard->setNextCard(nullptr);

    temp = temp->getNextCard();
    while(temp != nullptr){
        lastCard->setNextCard(new Card);
        lastCard = lastCard->getNextCard();
        lastCard->setName(temp->getName());
        lastCard->setNextCard(nullptr);
        temp = temp->getNextCard();
    }
}
Hand::Hand(const Hand& rhs){
    numCardsInHand =rhs.numCardsInHand;
    if(rhs.firstCard == nullptr){
        firstCard = lastCard = nullptr;
        return;
    }
    Card* temp = rhs.firstCard;
    firstCard = lastCard = new Card;
    firstCard->setName(temp->getName());
    firstCard->setNextCard(nullptr);

    temp = temp->getNextCard();
    while(temp != nullptr){
        lastCard->setNextCard(new Card);
        lastCard = lastCard->getNextCard();
        lastCard->setName(temp->getName());
        lastCard->setNextCard(nullptr);
        temp = temp->getNextCard();
    }
}

Card* Hand::getFirstCard() const{
    return firstCard;
}
Card* Hand::getLastCard() const{
    return lastCard;
}
int Hand::getNumCardsInHand() const{
    return numCardsInHand;
}

void Hand::setFirstCard(Card* f){
    firstCard = f;
}
void Hand::setLastCard(Card* l){
    lastCard = l; 
}
//no set num cards bc incremented in 
void Hand::addCardToHand(Card c){
    Card* temp = new Card(c);
    if(firstCard == nullptr){
        firstCard = lastCard = temp;
    }
    else{
        lastCard->setNextCard(temp);
        lastCard = temp;
    }
    lastCard->setNextCard(nullptr);
    numCardsInHand++;
}
void Hand::deleteCardFromHand(Card){ 
    //going to have to be at specific index of the card picked by the user 
    //issue with that is that i am not sure how to get the song at that index without truncating the playlist 

}

Hand::~Hand(){
    Card * temp = firstCard;
    while(temp!=nullptr){
        Card* remove = temp;
        temp->getNextCard();
        delete remove;
    }
    firstCard = lastCard = nullptr;
}
Hand* Hand::operator=(const Hand& rhs){
    numCardsInHand =rhs.numCardsInHand;
    if(rhs.firstCard == nullptr){
        firstCard = lastCard = nullptr;
        return;
    }
    Card* temp = rhs.firstCard;
    firstCard = lastCard = new Card;
    firstCard->setName(temp->getName());
    firstCard->setNextCard(nullptr);

    temp = temp->getNextCard();
    while(temp != nullptr){
        lastCard->setNextCard(new Card);
        lastCard = lastCard->getNextCard();
        lastCard->setName(temp->getName());
        lastCard->setNextCard(nullptr);
        temp = temp->getNextCard();
    }

    return *this; 
}