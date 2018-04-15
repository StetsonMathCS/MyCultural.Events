all: parser

parser: parser.o
	g++ -Wall -g -o parser parser.o -lpugixml

parser.o: parser.cpp
	g++ -Wall -g -c parser.cpp

.PHONY: clean
clean:
	rm -f *.o parser
