all: demo.cgi completedemo.cgi

demo.cgi: demo.o
	g++ -Wall -o demo.cgi demo.o -lcgicc

demo.o: demo.cpp
	g++ -Wall -c demo.cpp

completedemo.cgi: completedemo.o
	g++ -Wall -o completedemo.cgi completedemo.o -lcgicc

completedemo.o: completedemo.cpp
	g++ -Wall -c completedemo.cpp


# Use this syntax to compile main that use database, order matters at least for some of it
# g++ -pthread -o main main.o sqlite3.o database.o -ldl 

database.o: database.h sqlite3.h database.cpp
	g++ -c database.cpp

# Use gcc to compile this C code
sqtlite3.o: sqlite3.h sqlite3.c
        gcc -c sqlite3.c

