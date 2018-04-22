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
#include <type_traits>
#include <typeinfo>
#include "alumno.h"

using std::string;
using std::vector;

template<typename TipoClave, typename TipoDato, template <typename Celda, typename Alloc = std::allocator<Celda>> class ListaDatos>
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
    unsigned hash(string) const;
    unsigned hash(int) const;
    void mostrar(std::ostream & sal) const;

private:
    vector<ListaDatos<Celda>> t;
};

/**
 * Constructor of class
 * @param tam Size of table. Must be double of the number of elements.
 */
template<typename TipoClave, typename TipoDato, template <typename Celda, typename Alloc = std::allocator<Celda>> class ListaDatos>
Tabla2<TipoClave, TipoDato, ListaDatos>::Tabla2(unsigned tam)
{
    t.resize(tam);
}

/**
 * Insert an element
 * @param clave Key of the element
 * @param valor Value to be stored
 */
template<typename TipoClave, typename TipoDato, template <typename Celda, typename Alloc = std::allocator<Celda>> class ListaDatos>
void Tabla2<TipoClave, TipoDato, ListaDatos>::insertar(TipoClave clave, const TipoDato & valor)
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
template<typename TipoClave, typename TipoDato, template <typename Celda, typename Alloc = std::allocator<Celda>> class ListaDatos>
bool Tabla2<TipoClave, TipoDato, ListaDatos>::buscar(TipoClave clave, TipoDato & valor) 
{
    unsigned i;
    i = hash(clave);
    for(auto j= t[i].begin() ; j != t[i].end(); ++j)
    {
       if(j->clave == clave) 
       {
           valor = j->dato;
           return true;
       }
    }
    return false;
}

/**
 * Hash function for all
 * @param clave Key
 */
template<typename TipoClave, typename TipoDato, template <typename Celda, typename Alloc = std::allocator<Celda>> class ListaDatos>
unsigned Tabla2<TipoClave, TipoDato, ListaDatos>::hash(TipoClave clave) const
{
    unsigned long h = 5381;
    
        
    return h % t.size();
}

/**
 * Hash function for strings
 * @param clave Key
 */
template<typename TipoClave, typename TipoDato, template <typename Celda, typename Alloc = std::allocator<Celda>> class ListaDatos>
unsigned Tabla2<string, TipoDato, ListaDatos>::hash(string clave) const
{
    unsigned long h = 5381;
    
    for(unsigned i = 0; i < clave.size(); i++)
        h = ((h << 5) + h) + clave[i];

        
    return h % t.size();
}

/**
 * Hash function for ints
 * @param clave Key
 */
template<typename TipoClave, typename TipoDato, template <typename Celda, typename Alloc = std::allocator<Celda>> class ListaDatos>
unsigned Tabla2<int, TipoDato, ListaDatos>::hash(int clave) const
{
    unsigned long h = 5381;
    
    h = h * clave;

        
    return h % t.size();
}

/**
 * Write the hash table to a stream
 * @param sal output stream
 */
template<typename TipoClave, typename TipoDato, template <typename Celda, typename Alloc = std::allocator<Celda>> class ListaDatos>
void Tabla2<TipoClave, TipoDato, ListaDatos>::mostrar(std::ostream & sal) const
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
