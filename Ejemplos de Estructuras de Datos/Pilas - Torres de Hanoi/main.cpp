#include <iostream>
#include "Pila.h"
#include "Hanoi.h"
#include <Vector>
#include <cstdlib>
#include <ctime>
using namespace std;
/*****************************************************************************
 ************************ Programa Principal *********************************
 *****************************************************************************/
int main()
{
	Hanoi han;
	int origen, destino, sel = 0;
	
	while ( sel != 2 )
	{
		system("cls");
		cout << endl << "Bienvenido a Hanoi." << endl << "A continuacion dara comienzo una partida." << endl << endl;
		han.IniciarJuego();
		cout << han; 
		while ( !han.JuegoFinalizado() )
		{
			cout << "Introduzca su jugada: " << endl;
			cout << "Pila origen (1-3): ";
			cin >> origen;
			cout << endl;
			cout << "Pila destino (1-3): ";
			cin >> destino;
			cout << endl;
			if(han.MoverCarta(origen, destino))
			{
                 cout<<"movimiento aceptado"<<endl;
                 cout<<han<<endl;
            }
            else
            cout<<"movimiento erroneo, introduzca otro movimiento"<<endl;                     
		}
	cout << "Enhorabuena, ha completado la partida satisfactoriamente. ¿Quiere jugar de nuevo? ( 1 = Si, 2 = No )" << endl;
	cin >> sel;
	}
	system("pause");
	return 0;
}
