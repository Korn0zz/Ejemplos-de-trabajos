#ifndef ALUMNO_H
#define ALUMNO_H

#include <string>
#include <iostream>

using namespace std;

/*******************************************************************/
/* Asignatura: Programacion                                        */
/* Curso 2012-2013                                                 */
/* Practica 7: Colas                                               */
/*                                                                 */
/* PROPOSITO: Clase Alumno.                                        */
/*                                                                 */
/*******************************************************************/
class Alumno
{
    public:
	    /*************** Constructor por defecto *******************
	     *  Descripcion:  inicializa todas las variables necesarias 
	     *                para instanciar el objeto
	     ***********************************************************/
	    Alumno();
	
	    /*************** Constructor con parametros ****************
	     *  Descripcion:  inicializa código y nombre con los 
	     *                valores proporcionados
	     ***********************************************************/
	    Alumno(int, string);
	        
	    /*************** dameCodigo() ******************************
	     *  Descripcion:  Devuelve el atributo codigo
	     *  Valor devuelto:
	     *  int, código del alumno
	     ***********************************************************/
	    int dameCodigo(void);
	       
	    /*************** dameNombre() ******************************
	     *  Descripcion:  Devuelve el atributo nombre
	     *  Valor devuelto:
	     *  string, nombre del alumno
	     ***********************************************************/
	    string dameNombre(void);
	
	    /***********************************************************
	     *  Descripcion:  Sobrecarga del operador << para mostrar
	     *  la información del objeto
	     ***********************************************************/
	    friend ostream& operator<< (ostream &, Alumno &);

private:
    string nombre;  //Nombre del alumno
    int cod;        //Codigo del alumno

};

#endif // ALUMNO_H

