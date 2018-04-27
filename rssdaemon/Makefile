all: parser

parser: parser.o database.o sqlite3.o
	g++ -pthread -Wall -g -o parser parser.o sqlite3.o database.o -lpugixml -ldl

database.o: ../database.cpp ../database.h ../sqlite3.h
	g++ -Wall -g -c ../database.cpp

parser.o: parser.cpp ../database.h
	g++ -Wall -g -c parser.cpp

sqlite3.o: ../sqlite3.h ../sqlite3.c
	gcc -Wall -g -c ../sqlite3.c

.PHONY: clean
clean:
	rm -f *.o parser
