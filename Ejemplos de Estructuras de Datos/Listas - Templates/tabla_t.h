/**
 * Implementation of a hash table
 * Curso 2017/2018
 * 
 */
//#ifndef _TABLA_T_H
//#define _TABLA_T_H

#include <string>
#include <vector>
#include <iostream>
#include "alumno.h"

using std::string;
using std::vector;

template<typename TipoClave, typename TipoDato>
class TablaIterator;


/**
 * Template de una clase Tabla con datos guardados con hashes
 * @param TipoClave Tipo de las claves hash del vector
 * @param TipoDato Tipo de los datos del vector
 */
template<typename TipoClave, typename TipoDato>
class Tabla2
{
    friend class TablaIterator<TipoClave, TipoDato>;
public:
    typedef TablaIterator<TipoClave, TipoDato> iterator;
    
    
    struct Celda 
    {
        typedef TipoDato value_type;
        TipoClave clave;
        TipoDato dato;
    };
    typedef Celda value_type;
    
    Tabla2(unsigned); 
    bool buscar(TipoClave, TipoDato&) ; 
    void insertar(TipoClave, const TipoDato&); 
    unsigned hash(TipoClave) const;
    void mostrar(std::ostream & sal) const;
    
    /**
    * End: crea un iterador que apunta al principio del vector de vectores.
    * @return it El iterador
    */
    TablaIterator<TipoClave, TipoDato> begin()
    {
        TablaIterator<TipoClave, TipoDato> it(&t);
        return it;
    }
    
    /**
    * End: crea un iterador que apunta al final del vector de vectores.
    * @return it El iterador
    */
    TablaIterator<TipoClave, TipoDato> end()
    {
        TablaIterator<TipoClave, TipoDato> it(&t, t.size() - 1, t[t.size() - 1].size() - 1);
        return it;
    }

protected:
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

//////////////////////////////////////////////////////////

/**
 * Iterador de la Tabla de alumnos
 * @param TipoClave Tipo de las claves hash del vector
 * @param TipoDato Tipo de los datos del vector
 */
template<typename TipoClave, typename TipoDato>
class TablaIterator : public std::iterator <std::forward_iterator_tag, TipoClave, TipoDato>
{
    protected:
        typedef typename Tabla2<TipoClave, TipoDato>::ListaDatos ListaDatos;
        int index1, index2;
        vector<ListaDatos> * t;
    
    public:
        
        /**
        * Constructor sin argumentos
        */
        TablaIterator ()
        { 
            index1 = 0;
            index2 = 0;
            t = nullptr;
        }
        
        /**
        * Constructor con un argumento
        * @param tabla tabla a que apuntar
        */
        TablaIterator (vector<ListaDatos> * tabla)
        { 
            index1 = 0;
            index2 = 0;
            t = tabla;
        }
        
        /**
        * Constructor con dos argumentos
        * @param index1 tamaño máximo del primer vector
        * @param index2 tamaño máximo del segundo vector
        */
        TablaIterator (vector<ListaDatos> * tabla, int i1, int i2)
        { 
            index1 = i1;
            index2 = i2;
            t = tabla;
        }
        
        /**
        * Operador + para el acceso al valor del iterador
        */
        TipoDato& operator* () 
        {
            return t[index1][index2]; 
        }
        
        /**
        * Operador ++ prefix para el incremento del iterador
        */
        TablaIterator<TipoClave, TipoDato> operator++ () 
        { 
            index2 ++;
            if(index2 >= t[index1].size())
            {
                index2 = 0;
                if(index1 < t.size())
                {
                    index1++;
                    std::cout << "Tope" << std::endl;
                }
            }
            return *this;
        } 
        
        /**
        * Operador ++ postfix para el incremento del iterador
        */
        TablaIterator<TipoClave, TipoDato> operator++ (int) 
        {
            TablaIterator<TipoClave, TipoDato> copy = *this;
            index2 ++;
            if(index2 >= t[index1].size())
            {
                index2 = 0;
                if(index1 < t.size())
                {
                    index1++;
                    std::cout << "Tope" << std::endl;
                }
            }
            return copy;
        }
        
        /**
        * Operador == para la comparación
        * @param l elemento a comparar
        */
        bool operator== (TablaIterator<TipoClave, TipoDato> & l) 
        {
            return (t == l.t);             
        }
        
        /**
        * Operador != para la comparación
        * @param l elemento a comparar
        */
        bool operator!= (TablaIterator<TipoClave, TipoDato> & l) 
        {
            return (t != l.t);             
        }
};

       
//#endif
