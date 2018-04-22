/************************** HANOI.CPP ************************************/
/*          Implementacion de una clase para juegos Hanoi.               */
/*************************************************************************/
#include "Hanoi.h"
#include <Vector>
#include <cstdlib>
#include <ctime>
/*************** Hanoi::Hanoi (void) *****************************************
 *
 *  Descripcion:  Constructor por defecto de la clase.
 *                Inicia el objeto a unos atributos correctos.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  ninguno
 *
 *  Valor devuelto:
 *  Ninguno
 ****************************************************************************/
Hanoi::Hanoi()
{
	this->numero_jugadas = 0;
}

/*************** Hanoi::IniciarJuego (void) *****************************************
 *
 *  Descripcion:  Inicia un nuevo juego, vaciando las pilas y llenándolas con números
 *                aleatorios no repetidos.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  ninguno
 *
 *  Valor devuelto:
 *  Ninguno
 ****************************************************************************/
void Hanoi::IniciarJuego()
{
    srand(time(NULL));
	vector <int> vec;
	int num, tope=9;
	numero_jugadas=0;
	for(int k = 0; k<3;k++)
	{
		while(!mazos[k].PilaVacia())
			mazos[k].Desapilar();
	}
    for(int h=1; h<10 ; h++)
            vec.push_back(h);
    for(int i = 0; i<3;i++)
	{
		for(int j=0; j<3; j++)
		{
                num = rand() % tope;
                mazos[i].Apilar(vec[num]);
                vec[num] = vec[tope-1];
                vec.pop_back();
                tope--;
        }
    }
}

/*************** Hanoi::MoverCarta (int, int) **********************************************
 *
 *  Descripcion:  Mueve una carta de una pila a otra, si la jugada es correcta
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  pila_origen      int         E    Pila 1, 2, o 3, de donde se extrae la carta
 *  pila_destino     int         E    Pila 1, 2, o 3, donde se deposita la carta
 *
 *  Valor devuelto:
 *  ok               bool        S   True si jugada correcta, false de lo contrario
 *********************************************************************************/
bool Hanoi::MoverCarta (int pila_origen, int pila_destino)
{
	int x, y;
	bool ok; 
	mazos[pila_origen-1].CimaPila(x);
	mazos[pila_destino-1].CimaPila(y);
	/*if ( x > y )
		ok = false;
	else*/
	{
		mazos[pila_destino-1].Apilar(x);
		mazos[pila_origen-1].Desapilar();
		ok = true;
	}
	
	if ( ok )
		this->numero_jugadas+= 1;
		
	return ok;
}

/*************** Hanoi::JuegoFinalizado (void) **********************************************
 *
 *  Descripcion:  Devuelve true si se completa el juego situando todas las cartas en una pila
 *                devuelve false en caso contrario.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  ninguno
 *
 *  Valor devuelto:
 *  ok              bool         S   true si juego completado, false en caso contrario
 *********************************************************************************************/
bool Hanoi::JuegoFinalizado ()
{
	bool ok;
	if ((mazos[0].PilaVacia() && mazos[1].PilaVacia()) || (mazos[0].PilaVacia() && mazos[2].PilaVacia()) || (mazos[1].PilaVacia() && mazos[2].PilaVacia()))
		ok = true;
	else
		ok = false;
		
	return ok;
}

/*************** ostream& operator<< (ostream& out, Hanoi han) ***************
 *
 *  Descripcion:  Sobrecarga del operador <<
 *                Funcion 'friend' de la clase
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  out             ostream     E S  Flujo de salida donde se escribira la 
 *                                   informacion
 *  han             Hanoi       E    Hanoi a mostrar en el flujo de salida
 *
 *  Valor devuelto:
 *  ostream&   devuelve una referencia al propio flujo de salida
 *****************************************************************************/
ostream & operator << (ostream & out, const Hanoi& han)
{
	out << "Jugada numero: " << han.numero_jugadas << endl;
	out << "-----------------------------------------------" << endl;
	out << "Pila #1: " << han.mazos[0] << endl;
	out << "Pila #2: " << han.mazos[1] << endl;
	out << "Pila #3: " << han.mazos[2] << endl;
	out << "-----------------------------------------------" << endl;
	
	return out;	
}












