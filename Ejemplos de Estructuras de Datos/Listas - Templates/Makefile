all: pr6

alumno.o: alumno.cpp alumno.h
	g++ -c -std=c++11 -Wall alumno.cpp

pr6: pr6.cpp lista.h alumno.o
	g++ -std=c++11 -Wall pr6.cpp alumno.o -o pr6
