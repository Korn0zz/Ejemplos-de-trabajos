#include "alumno.h"
#include "cola.h"
#include <iostream>
#include <Vector>
#include <fstream>
#include <stdlib.h>
#include <queue>
using namespace std;
/*****************************************************************************
 ************************ Programa Principal *********************************
 *****************************************************************************/
int main()
{
	//
    // Operaciones con la clase Cola
    //
    
    // Creamos objetos alumno de prueba
	int e, b;
	
    Alumno a1(1,"Alumno 1");
    Alumno a2(2,"Alumno 2");
    Alumno a3(3,"Alumno 3");
    Alumno a4(4,"Alumno 4");
    Alumno a5(5,"Alumno 5");
    Alumno a6(6,"Alumno 6");
    Alumno a7(7,"Alumno 7");
    Alumno a8(8,"Alumno 8");
    
    Alumno a;

    cout << a1 << a2 << a3 << a4 << a5 << a6 << a7 << a8;
   
    // Creamos una cola
	Cola c;

    // Insertamos todos los objetos en la cola
	c.Encolar(a1);
	
	c.Encolar(a2);
	
	c.Encolar(a3);
	
	c.Encolar(a4);
	
	c.Encolar(a5);
	
	c.Encolar(a6);
	
	c.Encolar(a7);
	
	c.Encolar(a8);

    // Obtenemos el número de elementos
    e = c.Elementos();
    
    cout << "La cola contiene lo siguiente: " << e << endl;;

    // Mostramos el contenido de la cola
    c.Mostrar();

    // Extraemos un elemento y lo mostramos
    if ( c.VerPrimero( a ) )
    {
    	cout << "Se ha extraido el siguiente elemento: " << a << endl;
    }
    
	c.DesEncolar();
	
    // Mostramos el contenido de la cola 
    c.Mostrar();

    // Mostramos el primer elemento (sin extraerlo)
    if ( c.VerPrimero( a ) )
    {
    	cout << "El primer elemento de la cola es: " << a << endl;
    }

    // Mostramos el último elemento (sin extraerlo)
    if ( c.VerUltimo( a ) )
    {
    	cout << "El ultimo elemento de la cola es: " << a << endl;
    }

    // Mostramos el elemento en la posición 3 a partir del inicio (sin extraerlo)
    if ( c.VerPosicion( 2, a ) )
    {
    	cout << "El tercer elemento de la cola es: " << a << endl;
    }

    // Extraemos todos los elementos mostrando su valor
    while( c.Elementos() != 0 )
    {
    	c.VerPrimero( a );
    	
    	cout << a << endl;
    	
        c.DesEncolar();
    }

    // Insertamos 3 elementos (de los iniciales)
	c.Encolar(a1);
	
	c.Encolar(a2);
	
	c.Encolar(a3);

    // Vaciamos la cola
	c.Vaciar();
	

    // La volvemos a vaciar (¿qué devuelve el método?)
	b = c.Vaciar();
	
	cout << b << endl;
	
	c.Mostrar();  //true pese a estar vacia

    // Obtenemos el número de elementos
	e = c.Elementos();
	
	cout << "La cola contiene " << e << " elementos." << endl;

    //
    // Operaciones con la clase para colas de STD
    //
    // Repetir las mismas operaciones pero ahora con una cola creada con
    // un objeto de la biblioteca STL.
    // Usaremos los mismos objetos alumno definidos en la primera parte

    // Creamos una cola
    queue<Alumno> c2;

    // Insertamos todos los objetos en la cola
	c2.push(a1);
	
	c2.push(a2);
	
	c2.push(a3);
	
	c2.push(a4);
	
	c2.push(a5);
	
	c2.push(a6);
	
	c2.push(a7);
	
	c2.push(a8);

    // Obtenemos el número de elementos
    cout << "El tamanyo actual de la cola es: " << c2.size() << endl;

    // Mostramos el contenido de la cola
    queue<Alumno> c3;
    
	c3 = c2;
	
 	while( !c3.empty() ) 
 	{
	    a = c3.front();
	    
	    cout << "Numero de elementos: " << a << endl;
	    
	    c3.pop();
	}
	
    // Extraemos un elemento y lo mostramos
    a = c2.front();
    
    cout << endl << "El elemento extraido es: " << a << endl;
    
	c2.pop();

    // Mostramos el contenido de la cola 
    c3 = c2;
    
    cout << "El contenido de la cola es el siguiente; " << endl;
    
 	while(!c3.empty()) 
 	{
	    a = c3.front();
	    
	    cout << a << endl;
	    
	    c3.pop();
	}

    // Mostramos el primer elemento (sin extraerlo)
    cout << "El principio de la cola es: " << c2.front() << endl;

    // Mostramos el último elemento (sin extraerlo)
    cout << "El final de la cola es: " << c2.back() << endl;

    // Mostramos el elemento en la posición 3 a partir del inicio (sin extraerlo)
    c3 = c2;
    
    c3.pop();
    
    c3.pop();
    
    cout << "El elemento situado en la posicion 3 es: " << c3.front() << endl;

    // Extraemos todos los elementos mostrando su valor
    cout << "El contenido actual de la cola es el siguiente: " << endl;
    
 	while( !c2.empty() ) 
 	{
	    a = c2.front();
	    
	    cout << a << endl;
	    
	    c2.pop();
	}

    // Insertamos 3 elementos (de los iniciales)
	c2.push(a1);
	
	c2.push(a2);
	
	c2.push(a3);

    // Vaciamos la cola
    while( !c2.empty() ) 
 	{
	    c2.pop();
	}

    // La volvemos a vaciar (¿qué devuelve el método?)
    while( !c2.empty() ) 
 	{
	    c2.pop(); //No se devuelve nada
	}

    // Obtenemos el número de elementos
	cout << "En la cola hay " << c2.size() << " elementos." <<  endl;


    // Fin
    system("PAUSE");
    return 0;
}


