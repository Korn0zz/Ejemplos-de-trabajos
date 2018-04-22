#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <random>
#include <list>
#include <string>
#include "tabla_template.h"
#include "alumno.h"
#include <typeinfo>

using namespace std;


void TestString()
{
    Tabla2<string, Alumno, list>t(400);
    
    for (int i = 0; i < 200; i++)
    {
        Alumno a(1);
        string clave = to_string(i);
        t.insertar(clave,a);
    }
    
    
    Alumno test;
    if (t.buscar("5", test))
        cout << test << endl;
    else cout << "Student does not exist" << endl;
    
    if (t.buscar("600", test))
        cout << test << endl;
    else cout << "Student does not exist" << endl;
    
    //t.mostrar(cout);
    
}

void TestInt()
{
    Tabla2<int, Alumno, list>t(400);
    
    for (int i = 0; i < 200; i++)
    {
        Alumno a(1);
        int clave = i;
        t.insertar(clave,a);
    }
    
    
    Alumno test;
    if (t.buscar(5, test))
        cout << test << endl;
    else cout << "Student does not exist" << endl;
    
    if (t.buscar(600, test))
        cout << test << endl;
    else cout << "Student does not exist" << endl;
}

int main()
{
	cout << "Test Int: \n";
    //TestInt();
	cout << "Test String: \n";
	TestString();
    return 0;
}
