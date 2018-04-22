
#include "Pila.h"

Pila::Pila ()
{
	cima = -1;
}

bool Pila::PilaVacia ()
{
	return (cima == -1);
}

bool Pila::Apilar (int x)
{
	bool ok;
	if (cima == MAX-1) //stack overflow
		ok = false;
	else
	{
		cima++;
		datos[cima] = x;
		ok = true;
	}
	return (ok);
}

bool Pila::Desapilar ()
{
	bool ok;
	if (cima == -1) //error si pila vacía
		ok = false;
	else
	{
		cima--;
		ok = true;
	}
	return (ok);
}

bool Pila::CimaPila (int & x)
{
	bool ok;
	if (cima == -1) //error si pila vacía
		ok = false;
	else
	{
		x = datos[cima]; //guarda el dato de la cima
		ok = true;
	}
	return (ok);
}
ostream& operator<< (ostream& out, const Pila& p)
{
	for(int i = 0 ; i < p.cima+1 ; i++)
    {
            out << "   ";
            out << p.datos[i];         
    }
 return out;
}

