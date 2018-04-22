/************************** LISTA.CPP ************************************/
/*          Implementacion de una clase para listas      .               */
/*************************************************************************/
#include "Lista.h"
#include <stdlib.h>
#include <vector> 
/*************** Lista::Lista () ***********************
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
 **********************************************************/
Lista::Lista ()
{
	ini = NULL;
	fin = NULL;
	pto = NULL;
}

/*************** Lista::~Lista () ***********************
 *
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  ninguno
 *
 *  Valor devuelto:
 *  Ninguno
 ********************************************************/
Lista::~Lista ()
{
	//Vaciar();
}

/*************** Lista::Lista (Lista) ***********************
 *
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  ninguno
 *
 *  Valor devuelto:
 *  Ninguno
 **********************************************************************************************************/
Lista::Lista (const Lista& orig)
{
	ini = NULL;
	fin = NULL;
	pto = NULL;
	//Copiar (orig);
}


/*************** Lista::Insertar (Producto) ***********************
 *
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  x				Producto	E	 Objeto de la clase producto
 *
 *  Valor devuelto:
 *  Ninguno
 *********************************************************************/
void Lista::Insertar (const Producto &x)
{
	Puntero p_aux, p_aux2;
	//Crear y dar valores al nuevo Nodo
	p_aux = new Nodo;
	p_aux->info = x;
	p_aux->sig = pto;
	//Caso particular, si se inserta al final, o la lista est� vac�a, ser� el nuevo fin.
	if (pto == NULL) 
		fin = p_aux;
	//Si la inserci�n es delante del inicio
	if (pto == ini)
		ini = p_aux;
	//En cualquier otra posici�n
	else
	{
		//situar p_aux2 en el anterior a pto
		p_aux2 = ini;
		while (p_aux2->sig != pto)
			p_aux2 = p_aux2->sig;
		//el nuevo Nodo p_aux se sit�a detr�s de p_aux2
		p_aux2->sig = p_aux;
	}
}

/*************** Lista::Eliminar () ***********************
 *
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  ninguno
 *
 *  Valor devuelto:
 *  Ninguno
 **************************************************************/
bool Lista::Eliminar ()
{
	Puntero aux;
	bool ok;
	//error si el pto est� m�s all� del final de la lista
	//esto ocurre tambi�n cuando la lista est� vac�a
	if ( (pto == NULL) )
		ok = false;
	//en cualquier otro caso, se puede eliminar
	else
	{
		ok = true;
		//si pto es el �ltimo elemento y no hay nada detr�s
		if (pto == fin)
		{
			//adem�s de ser el �ltimo tambi�n es �nico elemento
			if (pto == ini)
			{
				delete pto;
				ini = fin = pto = NULL;
			}
			else
			{
				aux = ini;
				//hay que buscar el anterior a fin
				while ( aux->sig != fin )
				aux = aux->sig;
				fin = aux;
				fin->sig = NULL;
				delete pto;
				pto = NULL;
			}
		}
		//caso en que pto NO es el �ltimo elemento
		else
		{
			aux = pto->sig; //guardar el nodo que va a desaparecer
			*pto = *aux; //copiar los datos del nodo en pto
			if (aux == fin) //si desaparece el �ltimo cambiar fin
				fin = pto;
			delete aux; //liberar memoria
		}
	}
	
return ok;
}

/*************** Lista::ConsultarNombre (string) ***********************
 *
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  n				string		E	 Nombre
 *
 *  Valor devuelto:
 *  ok
 ***********************************************************************/
bool Lista::ConsultarNombre (string & n)
{
	bool ok;
	if ( pto == NULL )
		ok = false;
	else
	{
		ok = true;
		n = pto->info.DevuelveNombre();
	}
	
return (ok);
}
/*************** Lista::ConsultarSeccion (string) ***********************
 *
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  n				string		E	 Seccion
 *
 *
 *  Valor devuelto:
 *  ok
 **********************************************************************************************************/
bool Lista::ConsultarSeccion (string & n)
{
	bool ok;
	if ( pto == NULL )
		ok = false;
	else
	{
		ok = true;
		n = pto->info.DevuelveSeccion();
	}
	
return (ok);
}

/*************** Lista::ConsultarObservaciones (string, string, string, string, int) ***********************
 *
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  n				string		E	 Observaciones				
 *
 *  Valor devuelto:
 *  ok
 **********************************************************************************************************/
bool Lista::ConsultarObservaciones (string & n)
{
	bool ok;
	if ( pto == NULL )
		ok = false;
	else
	{
		ok = true;
		n = pto->info.DevolverObservaciones();
	}
	
return (ok);
}

/*************** Lista::ConsultarCantidad (int) ***********************
 *
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  c			 	int			E	 Cantidad		
 *
 *  Valor devuelto:
 *  ok
 **********************************************************************************************************/
bool Lista::ConsultarCantidad (int & c)
{
	bool ok;
	if ( pto == NULL )
		ok = false;
	else
	{
		ok = true;
		c = pto->info.DevolverCantidad();
	}
	
return (ok);
}

/*************** Lista::ConsultarTienda (string) ***********************
 *
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  n				string		E	 Tienda				
 *
 *  Valor devuelto:
 *  ok
 **********************************************************************/
bool Lista::ConsultarTienda (string & n)
{
	bool ok;
	if ( pto == NULL )
		ok = false;
	else
	{
		ok = true;
		n = pto->info.DevuelveTienda();
	}
	
return (ok);
}

/*************** Lista::ListaVacia () ***********************
 *
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  ninguno
 *
 *  Valor devuelto:
 *  ini == NULL
 *************************************************************/
bool Lista::ListaVacia ()
{
	return (ini == NULL);
}

/*************** Lista::IrAInicio () ***********************
 *
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  ninguno
 *
 *  Valor devuelto:
 *  Ninguno
 ***********************************************************/
void Lista::IrAInicio ()
{
	pto = ini;
}

/*************** Lista::Avanzar () ***********************
 *
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  ninguno
 *
 *  Valor devuelto:
 *  ok
 ***********************************************************/
bool Lista::Avanzar ()
{
	bool ok;
	if (pto == NULL)
		ok = false; //no se puede avanzar
	else
	{
		ok = true;
		pto = pto->sig;
	}
	
return (ok);
}

/*************** Lista::FinalLista () ***********************
 * 
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  pto				Puntero		S	 Punto de interes
 *
 *  Valor devuelto:
 *  (pto == NULL)
 **************************************************************/
bool Lista::FinalLista ()
{
	return (pto == NULL);
}







