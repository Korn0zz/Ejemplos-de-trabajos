/************************** PRODUCTO.CPP ************************************/
/*          Implementacion de una clase para productos      .               */
/****************************************************************************/
#include "Producto.h"
#include <stdlib.h>
#include <vector> 


Producto::Producto()
{
	
}


/*************** Producto::InicializarProducto (string, string, string, string, int) ***********************
 *
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  n				string		E	 Nombre
 *  t				string		E	 Tienda
 *  s				string		E	 Seccion
 *  o				string		E	 Observaciones
 *  c				int			E	 Cantidad
 *
 *  Valor devuelto:
 *  Ninguno
 **********************************************************************************************************/
Producto::Producto(string n, string t, string s, string o, int c)
{
	this->nombre = n;
	this->tienda = t;
	this->seccion = s;
	this->observaciones = o;
	this->cantidad = c;
}

/*************** Producto::AsignaNombre (string) ***********************
 *
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  n				string		E	 Nombre
 *
 *  Valor devuelto:
 *  Ninguno
 ****************************************************************/
void Producto::AsignaNombre(string n)
{
	this->nombre = n;
}

/*************** Producto::AsignaTienda (string) ***********************
 *
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  t				string 		E	 Tienda
 *
 *  Valor devuelto:
 *  t
 *****************************************************************/
void Producto::AsignaTienda(string t)
{
	this->tienda = t;
}

/*************** Producto::AsignaSeccion (string) ***********************
 *
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  s				string		E	 Seccion
 *
 *  Valor devuelto:
 *  s
 ************************************************************************/
void Producto::AsignaSeccion(string s)
{
	this->seccion = s;
}

/*************** Producto::AsignaObservaciones (string) ***********************
 *
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  o				string		E	 Observaciones
 *
 *  Valor devuelto:
 *  o
 ********************************************************************************/
void Producto::AsignaObservaciones(string o)
{
	this->observaciones = o;
}

/*************** Producto::AsignaCantidad (int) ***********************
 *
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  c				string   	E	 Cantidad
 *
 *  Valor devuelto:
 *  c
 ************************************************************************/
void Producto::AsignaCantidad(int c)
{
	this->cantidad = c;
}

/*************** Producto::DevuelveNombre () ***********************
 *
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  n				string		S	 Nombre
 *
 *  Valor devuelto:
 *  n
 **********************************************************************/	
string Producto::DevuelveNombre()
{
	string n;
	n = this->nombre;
	
	return n;
}

/*************** Producto::DevuelveTienda () ***********************
 *
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  t				string		S	 Tienda
 *
 *  Valor devuelto:
 *  t
 ***************************************************************/
string Producto::DevuelveTienda()
{
	string t;
	t = this->tienda;
	
	return t;
}

/*************** Producto::DevuelveSeccion () ***********************
 *
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  s				string		S	 Seccion
 *
 *  Valor devuelto:
 *  s
 **************************************************************************/
string Producto::DevuelveSeccion()
{
	string s;
	s = this->seccion;
	
	return s;
}

/*************** Producto::InicializarProducto (string, string, string, string, int) ***********************
 *
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  o				string		S	 Observaciones
 *
 *  Valor devuelto:
 *  o
 **********************************************************************************************************/
string Producto::DevuelveObservaciones()
{
	string o;
	o = this->observaciones;
	
	return o;
}

/*************** Producto::DevuelveCantidad () ***********************
 *
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  c				string		S	 Cantidad
 *
 *  Valor devuelto:
 *  c
 *****************************************************************/
int Producto::DevuelveCantidad()
{
	int c;
	c = this->cantidad;
	
	return c;
}

/*************** ostream& operator<< (ostream&, Producto) ********************
 *
 *  Descripcion:  Sobrecarga del operador <<
 *                Funcion 'friend' de la clase
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  out             ostream     E S  Flujo de salida donde se escribira la 
 *                                   informacion
 *  p               Producto    E    Producto a mostrar en el flujo de salida
 *
 *  Valor devuelto:
 *  ostream&   devuelve una referencia al propio flujo de salida
 *****************************************************************************/	
ostream& operator<< (ostream &out, Producto &p)
{

	    	
	return out;
}

