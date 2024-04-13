#include <iostream>
using namespace std; 

class Card{
    string name;
    Card* nextCard;

    public:
        Card();
        Card(string);
        Card(const Card&);
        
        void setNextCard(Card*);
        Card* getNextCard();

        void setName(string);
        string getName();

        void displayCard(); // calls Oren's graphics 
};