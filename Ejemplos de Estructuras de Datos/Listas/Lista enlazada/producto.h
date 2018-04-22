#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>
#include <iostream>
using namespace std;

/*******************************************************************/
/* Asignatura: Programacion                                        */
/* Curso 2012-2013                                                 */
/* Practica 8: Listas                                              */
/*                                                                 */
/* PROPOSITO: Clase Producto                                       */
/*                                                                 */
/*******************************************************************/
class Producto
{
	public:
		Producto();
	
		Producto(string, string, string, string, int); //Constructor explícito
		
		//Asignadores
		void AsignaNombre(string);
		void AsignaTienda(string);
		void AsignaSeccion(string);
		void AsignaObservaciones(string);
		void AsignaCantidad(int);
		
		//Métodos de devolución
		string DevuelveNombre();
		string DevuelveTienda();
		string DevuelveSeccion();
		string DevuelveObservaciones();
		int DevuelveCantidad();
		
		
		/***********************************************************
	    *  Descripcion:  Sobrecarga del operador << para mostrar
	    *  la información del objeto
	    ***********************************************************/
	    
		friend ostream& operator<<(ostream&, Producto);

	private:
		string nombre, tienda, seccion, observaciones;
		int cantidad;
		
		
};
#endif

