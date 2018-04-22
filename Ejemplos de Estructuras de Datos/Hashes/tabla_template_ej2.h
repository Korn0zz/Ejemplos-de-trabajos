/**
 * Implementation of a hash table
 * Curso 2017/2018
 * 
 */
#ifndef _TABLA_T_H
#define _TABLA_T_H

#include <string>
#include <vector>
#include <iostream>
#include "alumno.h"

using std::string;
using std::vector;

template<typename TipoClave, typename TipoDato>
class Tabla2
{
public:
    
    struct Celda 
    {
        TipoClave clave;
        TipoDato dato;
    };
        
    Tabla2(unsigned); 
    bool buscar(TipoClave, TipoDato&) ; 
    void insertar(TipoClave, const TipoDato&); 
    unsigned hash(TipoClave) const;
    void mostrar(std::ostream & sal) const;

private:
    typedef vector<Celda> ListaDatos; 
    vector<ListaDatos> t;
};

/**
 * Constructor of class
 * @param tam Size of table. Must be double of the number of elements.
 */
template<typename TipoClave, typename TipoDato>
Tabla2<TipoClave, TipoDato>::Tabla2(unsigned tam)
{
    t.resize(tam);
}

/**
 * Insert an element
 * @param clave Key of the element
 * @param valor Value to be stored
 */
template<typename TipoClave, typename TipoDato>
void Tabla2<TipoClave, TipoDato>::insertar(TipoClave clave, const TipoDato & valor)
{
    unsigned i;
    i = hash(clave);
    t[i].push_back(Celda{clave,valor} );
}

/**
 * Search for an element
 * @param clave Key of the element
 * @param valor Value founded with key "clave"
 * @return true if element founded, false otherwise
 */
template<typename TipoClave, typename TipoDato>
bool Tabla2<TipoClave, TipoDato>::buscar(TipoClave clave, TipoDato & valor) 
{
    unsigned i;
    i = hash(clave);
    for(unsigned j=0; j < t[i].size(); j++)
    {
       if(t[i][j].clave == clave) 
       {
           valor = t[i][j].dato;
           return true;
       }
    }
    return false;
}

/**
 * Hash function for strings
 * @param clave Key
 */
template<typename TipoClave, typename TipoDato>
unsigned Tabla2<TipoClave, TipoDato>::hash(TipoClave clave) const
{
    unsigned long h = 5381;
    
    // Solo valido para strings
    for(unsigned i = 0; i < clave.size(); i++)
        h = ((h << 5) + h) + clave[i];
        
    return h % t.size();
}

/**
 * Write the hash table to a stream
 * @param sal output stream
 */
template<typename TipoClave, typename TipoDato>
void Tabla2<TipoClave, TipoDato>::mostrar(std::ostream & sal) const
{
    for(unsigned i = 0; i < t.size(); i++)
    {
        sal << i << ":" ;
        for(unsigned j = 0; j < t[i].size(); j++)
            sal << t[i][j].dato << " -> ";
        sal << std::endl;
    }
}

       
#endif
