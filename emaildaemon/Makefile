CXX=g++ -Wall -g

all: test

test: test.o ../ccevent.o ../database.o ../student.o
	$(CXX) -o test ../ccevent.o ../database.o ../student.o test.o -lsqlite3

test.o: test.cpp ../ccevent.h ../database.h ../student.h
	$(CXX) -c test.cpp ../ccevent.h ../database.h ../student.h

../ccevent.o: ../ccevent.h ../ccevent.cpp
	cd .. && $(CXX) -c ccevent.cpp

../database.o: ../database.h ../database.cpp ../student.h
	cd .. && $(CXX) -c database.cpp student.cpp

../student.o: ../student.h ../student.cpp
	cd .. && $(CXX) -c student.cpp                                                  


.PHONY: clean
clean:
	rm -f *.o main
