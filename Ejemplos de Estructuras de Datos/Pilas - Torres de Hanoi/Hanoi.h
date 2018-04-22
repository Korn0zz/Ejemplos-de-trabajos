/************************** HANOI.H ************************************/
/*          Declaracion de una clase para juegos Hanoi                 */
/***********************************************************************/
#ifndef _HANOI_H
#define _HANOI_H
#include "Pila.h"
#include <iostream>
using namespace std;

class Hanoi 
{ 
	public: 
		Hanoi(); //Constructor
		
		void IniciarJuego (); //Inicializa el juego
		bool MoverCarta (int, int); //True = jugada válida y jugadas +1, false = jugada inválida
 		bool JuegoFinalizado (); //True = juego completado, false = juego incompleto
 		
 		friend ostream & operator << (ostream &, const Hanoi& ); //Sobrecarga del operador de salida
 		
 	private: 
 		static const int MAX_PILAS = 3; 
 		int numero_jugadas; 
 		typedef Pila VectorMazos[MAX_PILAS]; 
 		VectorMazos mazos; 
};
#endif
