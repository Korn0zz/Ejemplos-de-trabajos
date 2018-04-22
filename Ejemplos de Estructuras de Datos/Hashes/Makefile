all: test_tabla

alumno.o: alumno.cpp alumno.h
	g++ -c -std=c++11 -Wall alumno.cpp
tabla.o: tabla.cpp tabla.h
	g++ -c -std=c++11 -Wall tabla.cpp
	
test_tabla: test_tabla.cpp alumno.o tabla.o
	g++ -std=c++11 -Wall test_tabla.cpp alumno.o tabla.o -o test_tabla 
