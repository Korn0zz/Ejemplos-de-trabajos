/************************** ALUMNO.CPP ************************************/
/*          Implementacion de una clase para alumnos      .               */
/**************************************************************************/
#include "alumno.h"
#include <stdlib.h>
#include <vector> 

/*************** Alumno::Alumno (void) *****************************************
 *
 *  Descripcion:  Constructor por defecto de la clase.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  ninguno
 *
 *  Valor devuelto:
 *  Ninguno
 ******************************************************************************/
Alumno::Alumno()
{
	nombre = " ";  
	
    cod = 0;        
}

/*************** Alumno::Alumno (int, string) *****************************************
 *
 *  Descripcion:  Constructor explícito.
 *                Inicia el objeto a unos atributos concretos.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  c				int			E	 Codigo del alumno
 *  n				string		E	 Nombre del alumno
 *
 *  Valor devuelto:
 *  Ninguno
 ******************************************************************************/	
Alumno::Alumno(int c, string n)
{
	this->nombre = n;  
	
    this->cod = c;  
}

/*************** ostream& operator<< (ostream&, Alumno) ***************
 *
 *  Descripcion:  Sobrecarga del operador <<
 *                Funcion 'friend' de la clase
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  out             ostream     E S  Flujo de salida donde se escribira la 
 *                                   informacion
 *  a               Hanoi       E    Alumno a mostrar en el flujo de salida
 *
 *  Valor devuelto:
 *  ostream&   devuelve una referencia al propio flujo de salida
 *****************************************************************************/	
ostream& operator<< (ostream &out, Alumno &a)
{
	string n = a.dameNombre();
	
	int c = a.dameCodigo();
	
	out << "El nombre del alumno es: " << n << endl;
	
	out << "El codigo del alumno es: " << c << endl;
	    	
	return out;
}

/*************** Alumno::dameCodigo (void) *****************************************
 *
 *  Descripcion:  Devuelve el codigo.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  ninguno
 *
 *  Valor devuelto:
 *  cod				int			S	 Codigo del alumno
 ******************************************************************************/	        
int Alumno::dameCodigo()
{
	return (this->cod);
}

/*************** Alumno::dameNombre (void) *****************************************
 *
 *  Descripcion:  Devuelve el codigo.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  ninguno
 *
 *  Valor devuelto:
 *  nombre			string		S	 Nombre del alumno
 ******************************************************************************/
string Alumno::dameNombre()
{
	return (this->nombre);
}


	    

