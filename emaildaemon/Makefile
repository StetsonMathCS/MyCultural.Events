CXX=g++ -Wall -g

all: main

main: main.o ../ccevent.o ../database.o ../student.o makeemail.o
	$(CXX) -o main ../ccevent.o ../database.o ../student.o makeemail.o main.o -lsqlite3

main.o: main.cpp ../ccevent.h ../database.h ../student.h makeemail.h
	$(CXX) -c main.cpp ../ccevent.h ../database.h ../student.h makeemail.h

../ccevent.o: ../ccevent.h ../ccevent.cpp
	cd .. && $(CXX) -c ccevent.cpp

../database.o: ../database.h ../database.cpp ../student.h
	cd .. && $(CXX) -c database.cpp student.cpp

../student.o: ../student.h ../student.cpp
	cd .. && $(CXX) -c student.cpp                                        

makeemail.o: makeemail.h makeemail.cpp ../student.h ../ccevent.h
	$(CXX) -c makeemail.cpp ../student.cpp ../ccevent.cpp          


.PHONY: clean
clean:
	rm -f *.o main
