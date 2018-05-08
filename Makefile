all: demo.cgi completedemo.cgi parser main

demo.cgi: demo.o
	g++ -Wall -o demo.cgi demo.o -lcgicc

demo.o: demo.cpp
	g++ -Wall -c demo.cpp

completedemo.cgi: completedemo.o
	g++ -Wall -o completedemo.cgi completedemo.o -lcgicc

completedemo.o: completedemo.cpp
	g++ -Wall -c completedemo.cpp

student.o: student.cpp database.h
	g++ -Wall -c student.cpp

ccevent.o: ccevent.cpp database.h
	g++ -Wall -c ccevent.cpp

databaseTest.o: databaseTest.cpp database.h student.h ccevent.h
	g++ -Wall -c databaseTest.cpp database.cpp student.cpp ccevent.cpp

databaseTest: databaseTest.o database.o student.o ccevent.o sqlite3.o
	g++ -pthread -o databaseTest databaseTest.o student.o ccevent.o sqlite3.o database.o -ldl
# Use this syntax to compile main that use database, order matters at least for some of it
# g++ -pthread -o main main.o sqlite3.o database.o -ldl 

database.o: database.h sqlite3.h database.cpp student.h ccevent.h
	g++ -c database.cpp

# Use gcc to compile this C code
sqlite3.o: sqlite3.h sqlite3.c
	gcc -c sqlite3.c

# RSS parser files
parser: rssdaemon/parser.o database.o sqlite3.o ccevent.o student.o
	g++ -pthread -Wall -g -o rssdaemon/parser rssdaemon/parser.o sqlite3.o database.o ccevent.o student.o -lpugixml -ldl

parser.o: rssdaemon/parser.cpp database.h ccevent.h
	g++ -Wall -g -c rssdaemon/parser.cpp

# email daemon files
main: emaildaemon/main.o ccevent.o database.o student.o emaildaemon/makeemail.o
	g++ -Wall -g -o emaildaemon/main ccevent.o database.o student.o emaildaemon/makeemail.o emaildaemon/main.o -lsqlite3

main.o: emaildaemon/main.cpp ccevent.h database.h student.h emaildaemon/makeemail.h
	g++ -Wall -g -c emaildaemon/main.cpp ccevent.h database.h student.h emaildaemon/makeemail.h

makeemail.o: emaildaemon/makeemail.h emaildaemon/makeemail.cpp student.h ccevent.h
	g++ -Wall -g -c emaildaemon/makeemail.cpp student.cpp ccevent.cpp

# command that deletes .o files and binary files
.PHONY: clean
clean:
	rm -f *.o rssdaemon/*.o rssdaemon/parser cgicc/*.o emaildaemon/*.o emaildaemon/main
