#include<iostream>
#include<algorithm>
#include <random>
#include "graph.h"
using namespace std;

/**  
 *   Floyd
 *   Ejecuta el algoritmo de Floyd en un Graph y lo devuelve
 *
 *   @param[in] g Grafo parámetro
 *	 @param[out]temp res Grafo resultante
 * 
**/

template <typename TEW, int Size>
Graph<TEW, Size> Floyd(Graph<TEW, Size> g){
    cout << "Ejecutando Floyd" << endl;
    Graph<TEW, Size> res;
    
    for(auto i = 1; i < Size; i++){
        for(auto j = 1; j < Size; j++){
            res[i][j] = g[i][j];
        }
    }
    
    for(auto k = 1; k < Size; k++){
        for(auto i = 1; i < Size; i++){
            for(auto j = 1; j < Size; j++){
                res[i][j] = std::min(res[i][j], res[i][k] + res[k][j]);
            }
        }
    }
    
    return res;
}

int main()
{

    Graph<int, 6> g;

    //Descomentar para comprobar los resultados de las pruebas
    /*
    g.show();
    g[1][2] = 3;
    g.show();
    //g[8][0] = 4; //Descomentar para comprobar la excepción out of range
    */  
    
    int min = 0.5;
    int max = 5.0;
    makeRandom(g, min, max);
    g.show();
    
    g = Floyd(g);
    g.show();
}
