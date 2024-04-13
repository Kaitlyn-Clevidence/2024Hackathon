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
    firstCard->setValue(temp->getValue());
    firstCard->setNextCard(nullptr);

    temp = temp->getNextCard();
    while(temp != nullptr){
        lastCard->setNextCard(new Card);
        lastCard = lastCard->getNextCard();
        lastCard->setValue(temp->getValue());
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
    firstCard->setValue(temp->getValue());
    firstCard->setNextCard(nullptr);

    temp = temp->getNextCard();
    while(temp != nullptr){
        lastCard->setNextCard(new Card);
        lastCard = lastCard->getNextCard();
        lastCard->setValue(temp->getValue());
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
void Hand::setNumCardsInHand(int n){
    numCardsInHand = n;
}
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

Card& Hand::getCardAtIndex(int i){
    Card* temp = firstCard;
    for(int j = 0; j < i; j++){
        temp = temp->getNextCard();
    }
    return *temp;
}

void Hand::deleteCardFromHand(int i){ 
    if(i < 0 || i>= numCardsInHand){
        cout<<"Index out of bounds"<<endl;
        return;
    }
    if(i == 0){
        if(firstCard==nullptr){
            return;
        }
        else if(firstCard->getNextCard() == nullptr){
            delete firstCard;
            firstCard = lastCard = nullptr;
            numCardsInHand--;
            return;
        }
        else{
            Card* temp = firstCard;
            firstCard = firstCard->getNextCard();
            delete temp;
            numCardsInHand--;
        }
        return;
    }

    Card oneBefore = getCardAtIndex(i-1);
    Card* remove = oneBefore.getNextCard();
    oneBefore.setNextCard(remove->getNextCard());
    lastCard->setNextCard(nullptr);
    remove = nullptr;
    delete remove;
    numCardsInHand--;
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
Hand Hand::operator=(const Hand& rhs){
    numCardsInHand =rhs.numCardsInHand;
    if(rhs.firstCard == nullptr){
        firstCard = lastCard = nullptr;
        return;
    }
    Card* temp = rhs.firstCard;
    firstCard = lastCard = new Card;
    firstCard->setValue(temp->getValue());
    firstCard->setNextCard(nullptr);

    temp = temp->getNextCard();
    while(temp != nullptr){
        lastCard->setNextCard(new Card);
        lastCard = lastCard->getNextCard();
        lastCard->setValue(temp->getValue());
        lastCard->setNextCard(nullptr);
        temp = temp->getNextCard();
    }

    return *this; 
}