all: parser

parser: parser.o database.o sqlite3.o ccevent.o student.o
	g++ -pthread -Wall -g -o parser parser.o sqlite3.o database.o ccevent.o student.o -lpugixml -ldl

database.o: ../database.cpp ../database.h ../sqlite3.h
	g++ -Wall -g -c ../database.cpp

ccevent.o: ../ccevent.cpp ../ccevent.h
	g++ -Wall -g -c ../ccevent.cpp

student.o: ../student.cpp ../student.h
	g++ -Wall -g -c ../student.cpp

parser.o: parser.cpp ../database.h ../ccevent.h
	g++ -Wall -g -c parser.cpp

sqlite3.o: ../sqlite3.h ../sqlite3.c
	gcc -Wall -g -c ../sqlite3.c

.PHONY: clean
clean:
	rm -f *.o parser
