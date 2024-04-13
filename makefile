game: main.o hand.o helpers.o card.o
	g++ -o game main.o hand.o helpers.o card.o -g

main.o: hand.h card.h main.cpp
	g++ -c main.cpp -g

hand.o: hand.cpp hand.h card.h
	g++ -c hand.cpp -g

helpers.o: helpers.cpp hand.h
	g++ -c helpers.cpp -g

card.o: card.cpp card.h
	g++ -c card.cpp -g

clean:
	rm *.o game