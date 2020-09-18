all: proj5.exe

main.o: main.cpp EventClass.o CustomerClass.o AttractionClass.o SimulationClass.o random.o
	g++ -std=c++98 -Wall -c main.cpp -o main.o

EventClass.o: EventClass.cpp EventClass.h constants.h
	g++ -std=c++98 -Wall -c EventClass.cpp -o EventClass.o

CustomerClass.o: CustomerClass.cpp CustomerClass.h random.h constants.h
	g++ -std=c++98 -Wall -c CustomerClass.cpp -o CustomerClass.o

AttractionClass.o: AttractionClass.cpp AttractionClass.h CustomerClass.h constants.h
	g++ -std=c++98 -Wall -c AttractionClass.cpp -o AttractionClass.o

SimulationClass.o: SimulationClass.cpp SimulationClass.h SortedListClass.h FIFOQueueClass.h LinkedNodeClass.h EventClass.h CustomerClass.h AttractionClass.h random.h constants.h
	g++ -std=c++98 -Wall -c SimulationClass.cpp -o SimulationClass.o

random.o: random.cpp random.h constants.h
	g++ -std=c++98 -Wall -c random.cpp -o random.o

proj5.exe: main.o EventClass.o CustomerClass.o AttractionClass.o SimulationClass.o random.o constants.h
	g++ main.o EventClass.o CustomerClass.o AttractionClass.o SimulationClass.o random.o -o proj5.exe

clean:
	rm -f *.o *.exe
