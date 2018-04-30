CXX=g++ -Wall -g

all: test

test: test.o ../ccevent.o ../database.o
	$(CXX) -o test ../ccevent.o ../database.o test.o -lsqlite3

test.o: test.cpp ../ccevent.h
	$(CXX) -c test.cpp

../ccevent.o: ../ccevent.h ../ccevent.cpp
	cd .. && $(CXX) -c ccevent.cpp

../database.o: ../database.h ../database.cpp
	cd .. && $(CXX) -c database.cpp

.PHONY: clean
clean:
	rm -f *.o main
