/************************** COLA.CPP ************************************/
/*          Implementacion de una clase para colas.               */
/*************************************************************************/
#include "cola.h"
#include "alumno.h"
#include <stdlib.h>
#include <vector> 
	
/*************** Cola::Cola (void) *****************************************
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
Cola::Cola()
{
    inicio = NULL;
    
    fin = NULL;
}

/*************** Cola::Cola (void) *****************************************
 *
 *  Descripcion:  Libera la memoria usada por el objeto
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  ninguno
 *
 *  Valor devuelto:
 *  Ninguno
 ****************************************************************************/
Cola::~Cola()
{
	Vaciar();
}
                         	
/*************** Cola::Copiar (const Cola&) *****************************************
 *
 *  Descripcion:  Copia una cola.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  c				Cola		E	 Objeto de la clase Cola
 *
 *  Valor devuelto:
 *  Ninguno
 ****************************************************************************/
void Cola::Copiar (const Cola& c)
{
	Puntero paux, bias;
	paux = c.inicio;
	
	while ( (paux != NULL) )
	{
		bias = new Nodo;
		
		bias->info = paux->info;
		
		bias->sig = NULL;
		
		if (inicio == NULL)
			inicio = bias;
		else
			fin->sig = bias;
			
		fin = bias;
		
		paux = paux->sig;
	}
}

/*************** Cola::DesEncolar (void) *****************************************
 *
 *  Descripcion:  Extrae un elemento de la cola
 *                true si extráe un elemento o false si la cola está vacía
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  ninguno
 *
 *  Valor devuelto:
 *  ok
 ****************************************************************************/        
bool  Cola::DesEncolar()
{
	bool ok;
	
	Puntero pau;
		
	if ( ( inicio == NULL ) )
		ok = false;
	else
	{
		pau = inicio;
		
		inicio = inicio->sig;
		
		if (inicio == NULL)
			fin = NULL;
			
		delete pau;
		ok = true;
	}
	
	return ok;
}

/*************** Cola::Elementos (void) *****************************************
 *
 *  Descripcion:  evuelve el número de elementos encolados.
 *                0 si está vacía.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  ninguno
 *
 *  Valor devuelto:
 *  Ninguno
 ****************************************************************************/	
int  Cola::Elementos()
{
	int e;
	
	e = 0;
	
	Puntero pau;
	
	pau = inicio;
	
	while ( ( pau != NULL ) )
	{
		
		pau = pau -> sig;
		e++;
		
	}
	
	return e;
}

/*************** Cola::Encolar (Alumno) *****************************************
 *
 *  Descripcion:  Inserta un elemento en la cola
 *                true si funciona adecuadamente o false si hay un error 
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  a				Alumno		E	 Objeto de la clase Alumno
 *
 *  Valor devuelto:
 *  ok
 ****************************************************************************/
bool Cola::Encolar(Alumno a)
{
    Puntero pau;
    
    bool ok;
    
	ok = false;
    	
	pau = new Nodo;
	
	pau->info = a;
	
	pau->sig = NULL;
		
	if (inicio == NULL)
		inicio = pau;
	else
		fin->sig = pau;
		
	fin = pau;
	
	ok = true;
		
	return ok;
}
/*************** Cola::Mostrar (void) *****************************************
 *
 *  Descripcion:  Muestra el contenido de todos los elementos de la cola.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  ninguno
 *
 *  Valor devuelto:
 *  Ninguno
 ****************************************************************************/
void Cola::Mostrar()
{	
       Puntero pau;
       
	   pau = inicio;
	   
       if ( ( inicio == NULL ) )
           cout << "La cola esta vacia. " << endl;
        
       else
       {
       	
       	cout << "La cola contiene lo siguiente: " << endl;
       	
           do
           {
           	
           	cout << pau -> info << endl;
               pau = pau -> sig;
               
           } while ( pau != NULL );
           
       }
}

/*************** Cola::Vaciar (void) *****************************************
 *
 *  Descripcion:  Elimina todos los elementos de la cola
 *                Devuelve el numero de elementos eliminados.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  ninguno
 *
 *  Valor devuelto:
 *  c
 ****************************************************************************/
int Cola::Vaciar()
{
	int c;
	
	c = 0;
	
	while (DesEncolar());
		c++;
		
	return c;
}



/*************** Cola::VerUltimo (Alumno) *****************************************
 *
 *  Descripcion:  Devuelve el último elemento de la cola.
 *                True si hay un elemento o false si la cola está vacía.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  a				Alumno		E	 Objeto de la clase Alumno
 *
 *  Valor devuelto:
 *  ok
 ****************************************************************************/
bool  Cola::VerUltimo(Alumno &a)
{   
	bool ok;
	
	ok = VerPosicion( Elementos()-1, a );      
	
	return ok;
}

/*************** Cola::VerPosicion (int, Alumno) *****************************************
 *
 *  Descripcion:  Devuelve el elemento en la posición pos a contar
 *                desde el comienzo de la cola.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  pos				int			E	 Posición
 *	a				Alumno		E	 Objeto de la clase Alumno
 *
 *  Valor devuelto:
 *  ok
 ****************************************************************************/
bool Cola::VerPosicion(int pos, Alumno &a)
{
	Puntero p = inicio;
	
    int c = 0;
    
    bool ok;
    
	ok = false;

    if ( Elementos() > pos )
	{
    	while( ( p != NULL ) )
        {
          	if ( c == pos )
           	{
		        a = p -> info;
	            ok = true;
	      	}
	        	
	        p = p -> sig;
	        c++;
        }
    } 
    return ok;  

}

/*************** Cola::VerPrimero (Alumno) *****************************************
 *
 *  Descripcion:  Devuelve el elemento en la cabeza de la cola
 *                True si hay un elemento o false si la cola está vacía.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  a				Alumno		E	 Objeto de la clase Alumno
 *
 *  Valor devuelto:
 *  ok
 ****************************************************************************/
bool  Cola::VerPrimero(Alumno &a)
{
	int p;
	
	bool ok;
	
	p = 0;
	
	ok = VerPosicion(p, a);
	
    return ok;
}
/*************** Cola::operator= (const Cola&) *****************************************
 *
 *  Descripcion:  Sobrecarga del operador de asignación.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  c				Cola		E	 Objeto de la clase Cola
 *
 *  Valor devuelto:
 *  *this
 ****************************************************************************/
const Cola& Cola::operator= (const Cola& c)
{
	Vaciar();
	
	Copiar(c);
	
	return (*this);
}


