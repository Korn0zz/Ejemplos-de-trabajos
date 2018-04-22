/******************************************************************/
/*      AUTORES: David Cervera y Javier Pascual                   */
/*                                                                */
/*      PROPÓSITO: Implementación del juego de lógica MasterMind  */
/*                                                                */
/******************************************************************/
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <cmath>
using namespace std;
const int MAX = 5;
typedef float numero [MAX];
typedef string resultado [MAX];
typedef float guardado [15];
struct partida 
{
       int intentos;
       string nombre;
       string fecha;
};
typedef partida top[10];
void SumarGanada ();
void SumarJugada ();
void Comparar (numero, numero, resultado&);
void Guardar (partida);
void GenerarAleatorioCinco (numero&);
void Comprobar (int&, resultado, bool&);
void SumarRacha();
void FinalizarRacha();
void LeerArrayTop (top &, int&);
void EscribirFichero(top , int);        
void AnyadirTop (top&, int, partida);
int NumeroAleatorio(int);
float JuntarNumeros (numero);
/*
 * Programa principal.
 */
int main()
{
  srand((unsigned)time(0)); 
  int seleccion = 100, continuar = 0, dato, dato1, dato2, intentoss = 0, pjugadas = 0,contadorguardados = 1, contadortop = 0, auxemergencia = 0;
  float guar;
  numero random, introducidoo, aux;
  resultado r;
  partida p;
  guardado g;
  ofstream f1;
  ifstream f2;
  bool s;
  string nom, fecha;
  top t;
  
  LeerArrayTop(t, contadortop); 
  
  while (seleccion != 0)
  {     
        cout << endl << "                               -------------------" << endl << "                     ------" << "    MasterMind THE GAME    ------" << endl << "                               -------------------"<< endl << "Instrucciones: " << endl << endl << "El juego MasterMind es un juego de logica donde el jugador debe adivinar una" << endl <<  "combinacion de cinco digitos elegida aleatoriamente. Para ello dispone de un" << endl << "numero maximo de intentos, tras cada uno de los cuales se le indica como pista" << endl << "la cantidad de digitos acertados en sus posiciones correctas y los que no estan correctamente ubicados." << endl << endl << "Menu: " << endl << endl << "1- Comenzar partida." << endl << "2- Cargar partida." << endl << "3- Numero de partidas jugadas." << endl << "4- Numero de partidas resueltas." << endl << "5- Porcentaje de partidas resueltas." << endl << "6- Racha de partidas mas largas resueltas." << endl << "7- Records." << endl << "0- Salir." << endl;
        cin >> seleccion;
        switch (seleccion)
        {
               case 1:
                    system("cls");
                    cout << "Introduzca su nombre: ";
                    cin >> p.nombre;
                    cout << "Introduzca la fecha(dd/mm/aa): ";
                    cin >> p.fecha;
                    GenerarAleatorioCinco(random);
                    SumarJugada();
                    auxemergencia = 0;
                    for (int i = 0; i < 5; i++)
                    { 
                        cout << random[i] << " ";
                    }
                    cout << endl;
                    for (int i = intentoss; i <= 14; i++)
                    {
                        cout << "Le quedan " << 15-intentoss << " intentos." << endl; 
                        for (int j = 0; j < 5; j++)
                        {
                            cin >> introducidoo [j];
                           
                        }                            
                        guar = JuntarNumeros(introducidoo);
                        g[i] = guar;  
                        auxemergencia++;
                        p.intentos = auxemergencia;                                                   
                        Comparar (random, introducidoo, r);
                        Comprobar (intentoss,r,s);
                        if (intentoss == 14)
                        {
                               if (s == true)
                               { 
                                  SumarGanada();
                                  SumarRacha();
                                  AnyadirTop(t, contadortop, p);
                                  contadortop++;
                                  EscribirFichero(t, contadortop);
                                  cout << "Se acabo."<< endl;
                                  system("pause");
                                  intentoss = 0;
                                  break;
                               }
                               else 
                               {
                                  cout << "Ha perdido."<< endl;
                                  AnyadirTop(t, contadortop, p);
                                  contadortop++;
                                  EscribirFichero(t, contadortop);
                                  FinalizarRacha();
                                  system("pause");
                                  intentoss = 0;
                                  break;
                               }    
                        }
                        else     
                        {
                               intentoss++;
                               cout << "Desea abandonar la partida(0) o continuar(introduzca un numero distinto de 0)?" << endl;
                               cin >> continuar;                           
                               if (continuar == 0)
                               {
                                  f1.open("partida.txt");
                                  if (!f1) cout << "Error";
                                  else
                                  {         
                                        f1 << p.nombre << endl;
                                        f1 << p.fecha << endl;
                                        f1 << intentoss << endl;          
                                        for (int i = 0; i < 5; i++)
                                        {
                                            f1 << random[i] << endl;
                                        }
                                        for (int j = 0; j < intentoss; j++)
                                        {
                                            f1 << g[j] << endl;
                                        }
                               }
                               f1.close(); 
                               break;
                             } 
                        }
                    }
                            seleccion = 0;                   
                            break;
                            
               case 2:
                    system("cls"); 
                    f2.open("partida.txt");
                    if(!f2) 
                    {
                            cout << "No ha guardado ninguna partida.";
                            break;
                    }
                    else
                    {
                            f2 >> p.nombre;
                            f2 >> p.fecha;
                            f2 >> intentoss;
                            cout << intentoss << endl << endl;
                            for (int i = 0; i < 5; i++)
                            {
                                f2 >> dato;
                                random[i] = dato;
                            }
                            auxemergencia = intentoss;
                            for (int i = 0; i < 5; i++)
                            { 
                                cout << random[i] << " ";
                            }
                            cout << endl;
                            cout << "Bienvenido de nuevo, " << p.nombre << endl;
                            cout << "Lista de intentos: " << endl;                        
                            for(int i = 0; i < intentoss; i++)
                            {
                                f2 >> g[i];
                                cout << g[i] << endl;
                            } 
                            cout << endl;
                    }
                    for (int i = intentoss; i <= 14; i++)
                    {
                        
                            cout << "Le quedan " << 15 - intentoss << " intentos." << endl;
                            for (int j = 0; j < 5; j++)
                            {
                                cin >> introducidoo [j];
                            }
                            guar = JuntarNumeros(introducidoo);
                            g[i] = guar;    
                            auxemergencia++;
                            p.intentos = auxemergencia;
                            Comparar (random, introducidoo, r);
                            Comprobar (intentoss, r, s);
                            if (intentoss == 14)
                            {
                                if(s == true)
                                {
                                     SumarGanada();
                                     SumarRacha();
                                     AnyadirTop(t, contadortop, p);
                                     contadortop++;
                                     EscribirFichero(t, contadortop);
                                     cout << "Fin del juego."<< endl;
                                     system("pause");
                                     intentoss = 0;
                                     break;
                                }
                                else 
                                {
                                     cout << "Se acabo."<< endl;
                                     AnyadirTop(t, contadortop, p);
                                     contadortop++;
                                     EscribirFichero(t, contadortop);
                                     FinalizarRacha();
                                     system("pause");
                                     intentoss = 0;
                                     break;
                                }    
                                   
                            }
                            else
                            {
                                cout << "Desea abandonar la partida(0) o continuar(introduzca un numero distinto de 0)?" << endl;
                                cin >> continuar;
                                intentoss++;
                                if (continuar == 0)
                                {
                                   f1.open("partida.txt");
                                   if (!f1) cout << "Error";
                                   else
                                   {     
                                         f1 << p.nombre << endl;
                                         f1 << p.fecha << endl;
                                         f1 << intentoss << endl;          
                                         for (int i = 0; i < 5; i++)
                                         {
                                             f1 << random[i] << endl;
                                         }
                                         for (int j = 0; j < intentoss; j++)
                                         {
                                             f1 << g[j] << endl;
                                         }
                                   }
                                f1.close(); 
                                break;
                                } 
                            }
                    }
                            seleccion = 0;                   
                            break;
                      
                         
               case 3:
                    system("cls"); 
                    f2.open("partidasjugadas.txt");
                    if(!f2)
                    {
                          cout << "Usted no ha jugado ninguna partida." << endl;        
                    }
                    else  
                    {
                          f2 >> dato;
                          cout << "Usted ha jugado " << dato << " partidas."<< endl;
                    }
                    f2.close();
                    break;      
                    
               case 4:
                    system("cls");
                    f2.open("partidasganadas.txt");
                    if(!f2)
                    {
                          cout << "Usted no ha ganado ninguna partida. Siga intentandolo." << endl;        
                    }
                    else  
                    {
                          f2 >> dato;
                          cout << "Usted ha ganado " << dato << " partidas."<< endl;
                    }
                    f2.close();
                    break; 
                    
               case 5:
                    system("cls");
                    f2.open("partidasjugadas.txt");
                    if(!f2)
                    {
                          cout << "Usted no ha ganado ninguna partida por lo tanto no tiene porcentaje de victorias." << endl;   
                          break;     
                    }
                    
                    else  
                    {
                          f2 >> dato;
                    }
                    f2.close();                    
                    f2.open("partidasganadas.txt");
                    if(!f2)
                    {
                          cout << "Usted no ha ganado ninguna partida, por lo tanto su porcentaje" << endl <<  "de victorias es del 0%" << endl;
                          break;        
                    }
                    else  
                    {
                          f2 >> dato1;
                          dato = (dato1 * 100) / dato;
                          cout << "Su porcentaje de victorias es de " << dato << "%." << endl;
                    }
                    f2.close();
                    break; 
                    
               case 6:
                    system("cls");
                    f2.open("racha.txt");
                    if (!f2)
                    {
                         cout << "Todavia no ha ganado ninguna partida por lo tanto no tiene ninguna racha." << endl;
                    }
                    else
                    {
                         f2 >> dato2;
                         f2 >> dato2;
                         cout << "La racha mas larga ha sido de " << dato2 << " victoria/s." << endl;
                    }
                    f2.close();
                    break;
              case 7: 
                   system("cls");
                   cout << endl << "                           ------            " << endl << "               -------" << "     TOP 10     -------" << endl << "                           ------            " << endl << endl;
                   for (int i = 0; i < contadortop; i++)
                   {
                       cout << "                       " << "Nombre: " <<  t[i].nombre << endl << "                     " << "Fecha:  " << t[i].fecha << endl << "                         " << "Intentos: " << t[i].intentos << endl << endl << "             >----------------------------------<" << endl << endl; 
                   }
                   system("pause");
                   break; 
                   
                         
               default: cout << "Introduzca una seleccion correcta, por favor." << endl;       
        }
  }
}

/********************************************************************************/

/*
 * Funcion para comparar el número introducido por el usuario con el generado aleatoriamente.
 */

void Comparar (numero aleatorio, numero introducido, resultado &a)
{
     int contador = 0;
     int contador2 = 0;
     numero repetidos;
     numero aux;
     bool aux1;
     for (int i = 0; i < MAX; i++)
     {
         aux[i] = aleatorio[i];
     }
     for (int p = 0; p < MAX; p++)
     {
         a[p] = " ";
     }
     for (int s = 0; s < MAX; s++)
     {
         repetidos[s] = 10;
     }
         
     for (int i = 0; i  < MAX; i++)
     {
                   
           for (int j = 0; j < MAX; j++)
           {
               
               if (introducido[i] == aleatorio[j] && i == j ) 
               { 
                   aux[j] = 10;               
                   introducido[i] = 10;
                   a[contador] = "+";
                   contador++;
               }
              
      }
      }
      for (int i = 0; i < MAX; i++)
      {
                   
           for (int j = 0; j < MAX; j++)
           {
               if(introducido [i] == aux[j] && introducido[i] != 10 )
               {
                     repetidos[contador2] = introducido[i];
                     contador2++;
               }
           }
      }
                        

         for (int  i = 0; i < 5; i++)
         {
             for (int j = i + 1; j < 5; j++)
             {
                 if(repetidos[i] == repetidos [j] && repetidos[i] < 10)
                 { 
                    repetidos[i] = 10;
                 }
             }
         }
     
     for (int n = 0; n < MAX; n++)
     {
         if (repetidos [n] < 10)
         {
            a[contador] = "-";
            contador++;     
         }
     }         
}

/********************************************************************************/

/*
 * Funcion para generar un número aleatorio.
 */

int NumeroAleatorio(int N) 
{ 
    
    return ( rand() % (N + 1) ); 
}

/********************************************************************************/

/*
 * Funcion para rellenar un array de cinco huecos con números aleatorios.
 */

void GenerarAleatorioCinco(numero &aleatorio1)
{
     int p;
     for (int i = 0; i < 5; i ++)
     {
         p = NumeroAleatorio(9);
         aleatorio1 [i] = p; 
     }
} 

/********************************************************************************/

/*
 * Funcion para comprobar si el usuario ha encontrado la combinación correcta ( cinco "+" ).
 */

void Comprobar (int  &p,resultado final, bool &k)
{
     k = false;
     if (final[0] == "+" && final[1] == "+" && final[2] == "+"  && final[3] == "+"  && final[4] == "+")
     {
                     p = 14;
                     k = true;
                     for(int i = 0; i < 5; i++)
                     {
                             cout << final[i];
                     }
                     cout << endl;
                     cout << "¡FELICIDADES, HA ENCONTRADO LA COMBINACION CORRECTA!" << endl;
     }
     else 
     {
          for(int i = 0; i < 5; i++)
          {
              cout << final[i];
          }
          cout << endl;
          cout << "Siga intentandolo" << endl;
     }

}

/********************************************************************************/

/*
 * Funcion para transformar el array en un número.
 */
     
float JuntarNumeros (numero a)
{
    float p = 0;
    float exp = 4;
    float k;
    for (int i = 0; i < 5; i++)
    {
        k = pow(10, exp);
        p = p + a[i] * k;
        exp--;
    }
    return p;
}
/********************************************************************************/

/*
 * Funcion para sumar la cantidad de partidas ganadas.
 */

void SumarGanada ()
{
    
                      ofstream f1;
                      ifstream f2;
                      int aux = 0;
                      f2.open("partidasganadas.txt");
                      if (!f2)
                      {
                             f1.open("partidasganadas.txt");
                             if(!f1)
                             {
                                    cout << "ERROR DE FICHEROS";
                             }
                             else
                             {
                                    aux = 1;
                                    f1 << aux << endl;
                                    f1.close();
                             }
                      }
                      else 
                      {
                            f2 >> aux;
                            f2.close();
                            f1.open("partidasganadas.txt");
                            if(!f1)
                            {
                                    cout << "ERROR DE ARCHIVOS";
                            }
                             else
                             {
                                    aux = aux + 1;
                                    f1 << aux << endl;
                                    f1.close();
                             }
                      }
}

/********************************************************************************/

/*
 * Funcion para sumar la cantidad de partidas jugadas.
 */

void SumarJugada ()
{
                      ofstream f1;
                      ifstream f2;
                      int aux = 0;
                      f2.open("partidasjugadas.txt");
                      if (!f2)
                      {      
                             cout << "Es su primera partida." << endl;
                             f2.close();
                             f1.open("partidasjugadas.txt");
                             if(!f1)
                             {
                                 cout << "ERROR DE ARCHIVOS.";
                             }
                             else
                             {
                                 aux = 1;
                                 f1 << aux << endl;
                             }
                             f1.close();
                      }
                      else 
                      {
                            f2 >> aux;
                            f2.close();
                            f1.open("partidasjugadas.txt");
                            if(!f1)
                            {
                                 cout << "ERROR DE ARCHIVOS";
                            }
                            else
                            {
                                 aux = aux + 1;
                                 f1 << aux << endl;
                            }
                            f1.close();
                      }

}

/********************************************************************************/

/*
 * Funcion para contabilizar la racha de victorias.
 */

void SumarRacha()
{
     ofstream f1;
                      ifstream f2;
                      int aux = 0;
                      f2.open("racha.txt");
                      if (!f2)
                      {      
                             f2.close();
                             f1.open("racha.txt");
                             if(!f1)
                             {
                                 cout << "ERROR DE ARCHIVOS.";
                             }
                             else
                             {
                                 aux = 1;
                                 f1 << aux << endl;
                                 f1 << aux << endl;
                             }
                             f1.close();
                      }
                      else 
                      {
                            f2 >> aux;
                            f2.close();
                            f1.open("racha.txt");
                            if(!f1)
                            {
                                cout << "ERROR DE ARCHIVOS";
                            }
                            else
                            {
                                aux = aux + 1;
                                f1 << aux << endl;
                            }
                      f1.close();
                      }
}

/********************************************************************************/

/*
 * Funcion para terminar la racha de victorias.
 */
 
void FinalizarRacha()
{
     int aux, aux1;
     ifstream f1;
     ofstream f2;
     f1.open("racha.txt");
     if(!f1)
     {
          cout << "No has inciado una racha. Lo siento." << endl;
     }
     else 
     {
          f1 >> aux;
          f1 >> aux1;
          if (aux > aux1)
          {
             f2.open("racha.txt");
             if (!f2)
             {
                 cout << "ERROR." << endl;
             }
             else
             {
                 f2 << 0;
                 f2 << aux;
             }
             f2.close();
          }     
          else 
          {
             f2.open("racha.txt");
             if (!f2)
             {
                cout << "ERROR." << endl;
             }
             else
             {
                f2 << 0;
                f2 << aux1;
             }
             f2.close();
          }     
     }
     
     
     
     
}

/********************************************************************************/

/*
 * Funcion para leer el array en el que se guardará el Top.
 */

void LeerArrayTop (top &a, int &b)
{
     ifstream f1;
     f1.open("ranking.txt");
     if (!f1)
     {
           
     }
     else 
     {
          f1 >> b;    
          for (int i = 0; i < 10; i++)
          {
              f1 >> a[i].nombre;
              f1 >> a[i].fecha;
              f1 >> a[i].intentos;
          }
      }
      f1.close();
}

/********************************************************************************/

/*
 * Funcion para añadir una partida al Top.
 */

void AnyadirTop (top &a, int b, partida c )
{
     partida aux;
     if (b == 10)
     {
          if (c.intentos <= a[10].intentos)
          {
             a[10] = c;
          } 
          for (int i =0; i < b; i++)
          {
              for (int j = 0; j < b; j++)
              {
                if(a[j].intentos > a[j+1].intentos)
                {
                  aux = a[j];
                  a[j] = a[j + 1];
                  a[j + 1] = aux;
                }
              }
          }
     }
     
     else
     {
         a[b] = c;
         for (int i = 0; i < b; i++)
         {
              for (int j = 0; j < b; j++)      
              {
                  if(a[j].intentos > a[j+1].intentos)
                  {
                       aux = a[j];
                       a[j] = a[j + 1];
                       a[j + 1] = aux;
                  }
              }
         }
     }
}

/********************************************************************************/

/*
 * Funcion para escribir el array en el fichero.
 */

void EscribirFichero(top a, int b) 
{
     ofstream f1;
     f1.open("ranking.txt");
     if (!f1)
     {
             cout << "Error con los archivos.";
     }
     else
     {
         f1 << b << endl;
         for (int i = 0; i <= b; i++)                                          
         {
             f1 << a[i].nombre << endl;
             f1 << a[i].fecha << endl;
             f1 << a[i].intentos << endl;
         }
     }
}
     
/********************************************************************************/     
