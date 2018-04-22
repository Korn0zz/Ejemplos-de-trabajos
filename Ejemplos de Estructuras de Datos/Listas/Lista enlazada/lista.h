#ifndef LISTA_H
#define LISTA_H
#include <string>
#include <iostream>
#include "Producto.h"
using namespace std;

/*******************************************************************/
/* Asignatura: Programacion                                        */
/* Curso 2012-2013                                                 */
/* Practica 8: Listas                                              */
/*                                                                 */
/* PROPOSITO: Clase Lista                                          */
/*                                                                 */
/*******************************************************************/


class  Lista
{
	
	public:
		

		Lista (); //Constructor
		Lista (const Lista &); //Constructor explícito
		
		~Lista (void); //Destructor		

		void Insertar (const Producto &);
		bool Eliminar ();
		bool ConsultarNombre (string &);
		bool ConsultarSeccion (string & n);
		bool ListaVacia ();
		void IrAInicio ();
		bool Avanzar ();
		bool FinalLista ();
		
		/***********************************************************
	    *  Descripcion:  Sobrecarga del operador = para asignar
	    *  la información al objeto
	    ***********************************************************/		
		const Lista& operator= (const Lista &);		
		/***********************************************************
	    *  Descripcion:  Sobrecarga del operador << para mostrar
	    *  la información del objeto
	    ***********************************************************/
		friend ostream& operator<<(ostream&, Producto);

	private:
		
		struct Nodo;
		typedef Nodo* Puntero;
		struct Nodo
		{
			Producto info;
			Puntero sig;
		};
		Puntero ini; //Puntero al inicio de la lista
		Puntero fin; //Puntero al último elemento de la lista
		Puntero pto; //Punto de interés
		
};
#endif
