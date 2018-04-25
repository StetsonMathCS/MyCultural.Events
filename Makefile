all: demo.cgi completedemo.cgi

demo.cgi: demo.o
	g++ -Wall -o demo.cgi demo.o -lcgicc

demo.o: demo.cpp
	g++ -Wall -c demo.cpp

completedemo.cgi: completedemo.o
	g++ -Wall -o completedemo.cgi completedemo.o -lcgicc

completedemo.o: completedemo.cpp
	g++ -Wall -c completedemo.cpp
