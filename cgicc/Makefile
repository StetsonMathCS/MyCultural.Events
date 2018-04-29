#all: main completedemo.cgi

#main: main.o sqlite3.o database.o
#	g++ -pthread -o main main.o sqlite3.o database.o -ldl

#main.o: main.cpp database.h
#	g++ -c main.cpp

#database.o: database.h sqlite3.h database.cpp
#	g++ -c database.cpp

# Use gcc to compile this C code
#sqtlite3.o: sqlite3.h sqlite3.c
#	gcc -c sqlite3.c

#completedemo.cgi: completedemo.o database.o sqlite3.o
#	g++ -Wall -o completedemo.cgi completedemo.o database.o sqlite3.o -lcgicc

#completedemo.o: completedemo.cpp 
#	g++ -Wall -c completedemo.cpp 

all: demo.cgi completedemo.cgi

demo.cgi: demo.o
	g++ -Wall -o demo.cgi demo.o -lcgicc

demo.o: demo.cpp
	g++ -Wall -c demo.cpp

completedemo.cgi: completedemo.o
	g++ -pthread -Wall -o completedemo.cgi completedemo.o database.o sqlite3.o -ldl -lcgicc

completedemo.o: completedemo.cpp
	g++ -Wall -c completedemo.cpp
