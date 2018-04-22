
#ifndef _PILA_H
#define _PILA_H

#include <iostream>
using namespace std;

static const int MAX = 9;

class Pila
{
	public:
		Pila (); //constructor
		
		bool Apilar (int); //true=correcto, false=error
		bool Desapilar (); //true=correcto, false=error
		bool CimaPila (int  &); //true=correcto, false=error
		bool PilaVacia (); //true = vacia
		
		friend ostream& operator<< (ostream&, const Pila &); //Sobrecarga del operador de salida
				
	private:
		typedef int Vector[MAX]; //const int MAX = xxxx
		Vector datos; //array con los elementos
		int cima; //elemento de referencia de la pila
};
#endif
