/**
 * Implementacion de los objetivos de la práctica 6
 * Programación Avanzada
 * Curso 2017/2018
 * 
 * @author Alvaro Bech, Javier Pascual
 */

#include <iostream>
#include "lista.h"
#include <unordered_set>
#include <vector>
#include "alumno.h"
#include "tabla_t.h"

using namespace std;

template <typename It>
void Display_Anything(It start, It end) 
{
    cout << "Mostrando elementos" << endl;
    for( ; start != end; start++)
    {
        cout << *start << " " ;
    }
    cout << endl;
}

int main()
{
	/* Ejercicios 1 y 2 */
    std::unordered_set<int> coll;
    Lista<int> l;
    vector<int> v(3);

    
    l.push_front(1);
    l.push_front(2);
    l.push_front(3);
    
    l.mostrar();
    
    cout << "------------------------------------" << endl;
    
    Lista<int>::iterator it;
    it = l.begin();
    
    *it = 5;
    ++it;
    *it = 10;
    l.mostrar();
    cout << endl;
    
    Display_Anything(l.begin(), l.end());
    
    std::copy ( l.begin(), l.end(), v.begin() );
    
    Display_Anything(v.begin(), v.end());
    
    /* Ejercicio 3 */
    Tabla2<string, Alumno>t(400);
    Alumno a;
    
    for (int i = 0; i < 200; i++)
    {
        Alumno a(1);
        string clave = to_string(i);
        t.insertar(clave,a);
    }    
    
    Alumno test;
    for (int i = 0; i < 10; i++)
    {
        if (t.buscar(to_string(i), test))
            cout << test << endl;
    }
    
    cout << "--------------------------------------" << endl;
    
    Tabla2<string, Alumno>::iterator it;
    it = t.begin();
    /* El acceso a los elementos no funciona
    cout << *it << endl;
    */
    
    return 0;
}
