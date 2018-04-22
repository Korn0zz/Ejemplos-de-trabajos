/*
 * Clase Graph
 * Implementación de la clase Graph de la práctica 8
 * Javier Pascual Roca, Alvaro Bech Rubio
 */
#include <stdexcept>
#include <random>
#include <ctime>

#ifndef _GRAPH_H
#define _GRAPH_H


/**  
 *   Clase Graph
**/
template<typename TEW, int Nodes>
class Graph{
    private:   
        friend class GraphRow;
        TEW&   pget(int x, int y) { return adj[x][y]; }
    public:
		TEW adj[Nodes][Nodes];
        typedef TEW value_type;
        std::mt19937 mt_rand;
        std::default_random_engine generator;
		
		/**  
		 *   Subclase GraphRow
		 *   Esta clase es necesaria para poder lanzar la excepción out of range si se da el caso.
		 * 
		**/
        class GraphRow
        {
           Graph& parent;
           int x;
           int s;
           public:
				/**  
				*   GraphRow
				*   Constructor
				*
				*   @param[in] p Grafo
				*   @param[in] theX Posición X
				*   @param[in] size Tamaño de la linea
				* 
				**/
				GraphRow(Graph& p, int theX, int size) : parent(p), x(theX), s(size) {}     // Just init the temp object
				TEW& operator[](int y)  const 
				{
                    if(y >= s)
                        throw std::out_of_range("out of range");
                    return parent.pget(x,y);
				}
        };

		/**  
		*   Graph
		*   Constructor
		* 
		**/
        Graph()
		{
            std::cout << "Grafo de tamaño " << Nodes << " x " << Nodes << " creado" << std::endl;
            for(auto i = 0; i < Nodes; i++){
                for (auto j = 0; j < Nodes; j++){
                    adj[i][j] = 0;
                }
            }
        }
        
		/**  
		*   show
		*   Muestra por pantalla los valores del grafo.
		* 
		**/		
        void show() const
		{
            for(auto i = 0; i < Nodes; i++){
                for (auto j = 0; j < Nodes; j++){
                    std::cout << adj[i][j] << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }

		/**  
		*   getSize
		*   Devuelve el tamaño de las lineas y columnas del grafo (AxA, matriz cuadrada, devuelve A).
		* 
		**/
        int getSize() const
		{
            return Nodes;
        }
        
		/**  
		*   operator[]
		*   Overload del operador[] Donde utilizaremos la clase GraphRow establecida previamente.
		* 
		**/		
        GraphRow operator[](int x)
		{ 
            if (x >= Nodes)
                throw std::out_of_range("out of	range");
            return GraphRow(*this, x, Nodes);            
        }
};



/**  
*   makeRandom
*   Version con enable_if para ints para hacer números aleatorios dentro de la matriz adj.
*
*   @param[in] g Grafo
*   @param[in] min número mínimo
*   @param[in] max número máximo
* 
**/
template <typename T>
typename std::enable_if<std::is_integral<T>::value,void>::type
makeRandom(Graph<T,6>&g, int min, int max)
{
	std::cout << "Rellenando el grafo de valores aleatorios. Versión int" << std::endl;
	std::uniform_int_distribution<int> dis(min, max);
	
	for(auto i = 0; i < g.getSize(); i++)
	{
		for (auto j = 0; j < g.getSize(); j++)
		{
			g.adj[i][j] = dis(g.generator);
		}
	}
	std::cout << "Grafo rellenado de valores aleatorios. Versión int" << std::endl;
}

/**  
*   makeRandom
*   Version con enable_if para doubles para hacer números aleatorios dentro de la matriz adj.
*
*   @param[in] g Grafo
*   @param[in] min número mínimo
*   @param[in] max número máximo
* 
**/
template <typename T>
typename std::enable_if<std::is_floating_point<T>::value,void>::type
makeRandom(Graph<T,6>&g, int min, int max)
{
	std::cout << "Rellenando el grafo de valores aleatorios. Versión double" << std::endl;
	std::uniform_real_distribution<double> dis(min, max);
	
	for(auto i = 0; i < g.getSize(); i++)
	{
		for (auto j = 0; j < g.getSize(); j++)
		{
			g.adj[i][j] = dis(g.generator);
		}
	}
	std::cout << "Grafo rellenado de valores aleatorios. Versión double" << std::endl;
}

#endif
