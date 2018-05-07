all: completedemo.cgi

completedemo.cgi: completedemo.o ../database.o ../ccevent.o ../student.o
	g++ -pthread -Wall -o completedemo.cgi completedemo.o ../database.o ../ccevent.o ../student.o -ldl -lcgicc -lsqlite3

completedemo.o: completedemo.cpp ../database.h ../ccevent.h ../student.h
	g++ -Wall -c completedemo.cpp

