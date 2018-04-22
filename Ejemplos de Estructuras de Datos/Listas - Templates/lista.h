/**
 * Implementacion de una lista simplemente enlazada
 * Programación Avanzada
 * Curso 2015/2016
 * 
 * @author F. Barber
 */

//#ifndef _LISTA_H
//#define _LISTA_H

#include<iostream>

template<typename T>
class ListaIterator;

/**
 * Lista simplemente enlazada
 * @param T Tipo de los elementos de la lista
 */
template<typename T>
class Lista
{
    friend class ListaIterator<T>;
protected:
    struct Nodo
    {
        T valor;
        Nodo * sig;
    };
    
    typedef Nodo * PtrNodo;
     
    PtrNodo ptr;
public:
    typedef T value_type;
    typedef ListaIterator<T> iterator;
        
    Lista():ptr(nullptr) {}
    void push_front(const T &);
    void mostrar() const;
    
    /**
    * Devuelve el nodo
    */
    PtrNodo getPtrNodo()
    {
        return ptr;
    }
    
    /**
    * Iterador al principio de la lista
    */
    ListaIterator<T> begin()
    {
        PtrNodo aux = ptr;
        ListaIterator<T> it(aux);
        return it;
    }
    
    /**
    * Iterador al final de la lista
    */
    ListaIterator<T> end()
    {
        PtrNodo aux = nullptr;
        ListaIterator<T> it(aux);
        return it;
    }
};

/**
 * Añadir elemento al inicio de la lista
 * @param x elemento a añadir
 */
template<typename T>
void Lista<T>::push_front(const T & x)
{
    PtrNodo aux = new Nodo;
    aux->valor = x;
    aux->sig = ptr;
    ptr = aux;
}
/**
 * Muestra la lista por pantalla
 */
template<typename T>
void Lista<T>::mostrar() const
{
    PtrNodo aux = ptr;
    
    while(aux != nullptr)
    {
        std::cout << aux->valor << " ";
        aux = aux->sig;
    }
}


/**
 * Iterador de la lista simplemente enlazada
 * @param T Tipo de los elementos de la lista
 */
template<typename T>
class ListaIterator : public std::iterator <std::forward_iterator_tag, T>
{
    protected:
        typedef typename Lista<T>::PtrNodo PtrNodo;
        PtrNodo ptr;
        
    public:
        /**
        * Constructor sin argumentos
        */
        ListaIterator ()
        { 
            ptr = nullptr;
        }
        
        /**
        * Constructor con un argumento
        * @param p nodo al que apuntar
        */
        ListaIterator (PtrNodo p)
        { 
            ptr = p;
        }
        
        /**
        * Operador + para el acceso al valor del iterador
        */
        T& operator* () 
        {
            return ptr->valor; 
        }
        
        /**
        * Operador ++ prefix para el incremento del iterador
        */
        ListaIterator<T> operator++ () 
        { 
            ptr = ptr->sig;
            return *this;
        } 
        
        /**
        * Operador ++ postfix para el incremento del iterador
        */
        ListaIterator<T> operator++ (int) 
        {
            ListaIterator<T> copy = *this;
            ptr = ptr->sig;
            return copy;
        }
        
        /**
        * Operador == para la comparación
        * @param l elemento a comparar
        */
        bool operator== (ListaIterator<T> & l) 
        {
            return (ptr == l.ptr);             
        }
        
        /**
        * Operador != para la comparación
        * @param l elemento a comparar
        */
        bool operator!= (ListaIterator<T> & l) 
        {
            return (ptr != l.ptr);             
        }
};

//#endif
