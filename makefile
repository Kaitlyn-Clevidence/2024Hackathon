game: main.o hand.o card.o DrawCard.o
	g++ -o game main.o hand.o card.o DrawCard.o -g

main.o: hand.h card.h main.cpp
	g++ -c main.cpp -g

DrawCard.o: DrawCard.cpp
	g++ -c DrawCard.cpp

hand.o: hand.cpp hand.h card.h
	g++ -c hand.cpp -g

helpers.o: helpers.cpp hand.h
	g++ -c helpers.cpp -g

card.o: card.cpp card.h
	g++ -c card.cpp -g

clean:
	rm *.o game