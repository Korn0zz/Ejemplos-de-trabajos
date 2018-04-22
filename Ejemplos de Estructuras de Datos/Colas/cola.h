#ifndef COLA_H
#define COLA_H

#include "alumno.h"
#include <string>
#include <iostream>

using namespace std;

/*******************************************************************/
/* Asignatura: Programacion                                        */
/* Curso 20011-2012                                                */
/* Practica 7: Colas                                               */
/*                                                                 */
/* PROPOSITO:                                                      */
/*                                                                 */
/*******************************************************************/

class Cola
{
    public:
        /*************** Constructor por defecto **************************
         *  Descripcion:  inicializa todas las variables necesarioas para
         *                instanciar el objeto
         ******************************************************************/
         Cola();

        /*************** Destructor ***************************************
         *  Descripcion: Libera la memoria usada por el objeto
         ******************************************************************/
        ~Cola();                            	

        /******************************************************************
         *  Descripcion: Inserta un elemento en la cola
         *  Devuelve: true si funciona adecuadamente o false si hay un error            
         ******************************************************************/
        bool Encolar(Alumno);
        
        /******************************************************************
         *  Descripcion: Extrae un elemento de la cola
         *  Devuelve: true si extráe un elemento o false si la cola está 
         *            vacía
         ******************************************************************/
	    bool DesEncolar();
	
        /******************************************************************
         *  Descripcion: Devuelve el número de elementos encolados
         *  Devuelve: el número de elementos (0 si está vacía)
         ******************************************************************/
	    int Elementos();
	
        /******************************************************************
         *  Descripcion: Muestra el contenido de todos los elementos de la
         *               cola
	     *  Devuelve: nada             
         ******************************************************************/
	    void Mostrar();
	
         /******************************************************************
         *  Descripcion: Elimina todos los elementos de la cola
         *  Devuelve: Número de elementos eliminados.            
         ******************************************************************/
    	int Vaciar();

        /******************************************************************
         *  Descripcion: Devuelve el elemento en la cabeza de la cola
         *  Devuelve: true si hay un elemento o false si la cola está vacía.    
         ******************************************************************/
    	bool VerPrimero(Alumno &);

        /******************************************************************
         *  Descripcion: Devuelve el último elemento de la cola. 
         *  Devuelve: true si hay un elemento o false su la cola está vacía
         ******************************************************************/
	    bool VerUltimo(Alumno &);

        /******************************************************************
         *  Descripcion: Devuelve el elemento en la posición pos a contar
	     *               desde el comienzo de la cola.
         *  Devuelve: true si hay un elemento o false si la cola está vacía.
         ******************************************************************/
	   bool VerPosicion(int , Alumno &);

        /******************************************************************
         *  Descripcion: Operador =
         *              
         ******************************************************************/

        const Cola& operator= (const Cola& );
		
    private:
    	struct Nodo;
		typedef Nodo* Puntero;
		struct Nodo
		{
			Alumno info;
			Puntero sig;
		};
		Puntero inicio, fin;
		void Copiar (const Cola&);
};

#endif // COLA_H

