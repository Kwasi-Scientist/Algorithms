
hw6: main.o graph.o random_generator.o 
	g++ -Wall -std=c++11 -ggdb main.o graph.o random_generator.o -o hw6

main.o: main.cpp
	g++ -c -std=c++11 -ggdb main.cpp

graph.o: graph.cpp graph.h
	g++ -c -std=c++11 -ggdb graph.cpp

random_generator.o: random_generator.cpp random_generator.h
	g++ -c -std=c++11 -ggdb random_generator.cpp

clean:
	rm *.o hw6