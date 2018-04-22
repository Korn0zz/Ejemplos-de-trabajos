/********************************************************/
/*              INFORMÁTICA GRÁFICA                     */
/*                 Sistema Solar                        */
/*                                                      */
/* Pascual Roca, Javier                                 */
/*                                                      */
/* 2º de Grado en Ingeniería Multimedia                 */
/*                                                      */
/********************************************************/

#include <GL/openglut.h>
#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;


int screenWidth =640; 
int screenHeight = 480;

//Variables globales
float const PI = 3.14159265;
float mercurio = 0, venus = 0, tierra=0, marte=0, luna = 0;     // Variables para la rotacion de los planetas
float thecta = 1;                                               // alrededor del eje Y
bool pto_vista = false;      //Variable para la transformación del punto de vista
bool ver_ejes = true;        //Variable para enseñar o no los ejes

float a = 22.79904, b = 20.67872928;
float tecta = PI/4, phi = PI/4;
int x_ant = 0, y_ant = 0;
int r = 1;

//Prototipo de funciones
void miIdle();
void SistemaSolar();
void dibujarEjes();
void mov_raton(int, int);

/*********************************************/
/*   DEFINICIONES DE FUNCIONES DE CALLBACK   */
/*********************************************/

/*
 * Coloca la imagen raster en la posicion del puntero del raton al pulsar boton izdo. Limpia la ventana co el boton derecho
 */
void myMouse(int button, int state, int mx, int  my){

  if(button == GLUT_LEFT_BUTTON){
 
  }
  if(button == GLUT_RIGHT_BUTTON){
            
  }
  glutPostRedisplay();
}

/*
 * Coloca el punto de vista según el movimiento del ratón cuando uno d elos dos botones está pulsado
 */
void mov_raton(int x, int y)
{
    if (x > x_ant)
        phi += 0.02;
    else if (x < x_ant)
        phi -= 0.02;

    x_ant = x;
    
    if (y < y_ant)
        tecta += 0.02;
    else if (y > y_ant)
        tecta -= 0.02;

    y_ant = y;
    
    glutPostRedisplay();
}
/*
 * Cambia las dimensiones de la pantalla
 */
void myReshape(int w, int h){
    screenWidth = w;
    screenHeight = h;
  
}
/*
 * Dibuja los ejes
 */
void dibujarEjes()
{
    glBegin(GL_LINES);
    glColor3f(0.0,1.0,0);
    glVertex3f(-30.0,0.0,0.0);
    glVertex3f(30.0,0.0,0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,1.0);
    glVertex3f(0.0,-30.0,0.0);
    glVertex3f(0.0,30.0,0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(0.0,0.0,-30.0);
    glVertex3f(0.0,0.0,30.0);
    glEnd();

}
/*
 * Dibuja el Sol, los planetas y la Luna
 */ 
void SistemaSolar()
{
    //Sol
    glColor3f(1.0,1.0,0.0);
    glutSolidSphere(4.5,30,30);
    glPushMatrix();
    
    //Mercurio
    glPushMatrix();
    glColor3f(0.0,0.0,1.0);
    glTranslatef(6 * cos(mercurio), 6 * sin(mercurio), 0.0);
    glRotatef(mercurio, 0.0, 0.0, 1.0);
    glutSolidSphere(0.244*2,10,10);
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    
    
    //Venus
    glPushMatrix();
    glColor3f(1.0,0.4,0.0);
    glTranslatef(10 * cos(venus), 10 * sin(venus), 0.0);
    glRotatef(venus, 0.0, 0.0, 1.0);
    glutSolidSphere(0.6052*2,20,20);
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    

    //Tierra
    glPushMatrix();
    glColor3f(0.0,1.0,0.5);
    glTranslatef(13 * cos(tierra), 13 * sin(tierra), 0.0);
    glRotatef(tierra, 0.0, 0.0, 1.0);
    glutSolidSphere(0.6378*2,20,20);
    glMatrixMode(GL_MODELVIEW);
    
    //Luna
    glColor3f(0.7,0.7,0.7);
    glTranslatef(2.4 * cos(luna), 2.4 * sin(luna), 0.0);
    glRotatef(luna, 0.0, 0.0, 1.0);
    glutWireSphere(0.2,10,10);
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    
    
    //Marte
    glPushMatrix();
    glColor3f(1.0,0.0,0.0);
    glTranslatef((cos(marte)/(sqrt((cos(marte)*cos(marte)/(a*a))+(sin(marte)*sin(marte)/(b*b))))), (sin(marte)/(sqrt((cos(marte)*cos(marte)/(a*a))+(sin(marte)*sin(marte)/(b*b))))),0.0);
    glutSolidSphere(0.3397*2,10,10);
    glMatrixMode(GL_MODELVIEW);     
    glPopMatrix();
}

/*
 *Cámara
 */
void puntoVista(){
     //Punto de vista por defecto
     if (pto_vista == false){
                glLoadIdentity();
                gluLookAt(r*sin(tecta) * cos(phi), r*cos(tecta), r*sin(tecta) * sin(phi), 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
     }
     else{
             //Punto de vista tierra
             if (pto_vista == true){
                        glLoadIdentity();
                        gluLookAt(13*cos(tierra),13*sin(tierra),0.0, 0.0,0.0,0.0, 0.0,0.0,1.0);
             }     
     }
}
 

/*
 * Dibuja el raster
 */
void myDisplay(void){
    
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    puntoVista();
    
    if(ver_ejes == true)
        dibujarEjes();
    
    SistemaSolar();
        
    
    glFlush();
    glutSwapBuffers();
  
}

/*
 * Control por teclado
 */
void myKeys(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'q': exit(0);
            break;
            
        case 't':
             if (pto_vista == false)
                pto_vista = true;
             else
                 pto_vista = false;
             break;
             
        case 'e':
             if (ver_ejes == true)
                ver_ejes = false;
             else
                 ver_ejes = true;
             break;
        
    }
    glutPostRedisplay();
}
/*
 * Función que se repite cuando no se realiza ninguna acción
 */
void myIdle()
{
    mercurio += 0.00088;
    venus += 0.0002247;
    tierra += 0.000365;
    luna += 0.001;
    marte += 0.0006789;
        
    glutPostRedisplay();
}

/*
 * Programa principal
 */
int main(int argc, char ** argv)
{
    //CREACION DEL ENTORNO GRAFICO
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(0,0);
    glutInit(&argc, argv);
    glutCreateWindow("Lab. Informatica Grafica");


    //Damos de alta a las funciones de Callback
    glutKeyboardFunc(myKeys);
    glutIdleFunc(myIdle);
    glutMotionFunc(mov_raton);
    glutDisplayFunc(myDisplay);
    glutReshapeFunc(myReshape);
    //--------------------
    
    //Funciones de limpieza de la pantalla
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    //---------------------
    
    glFlush();
    glMatrixMode(GL_PROJECTION);
    //izda,dcha,abajo,arriba
    glLoadIdentity();
    glOrtho(-30.0,30.0,-30.0,30.0,-30.0,30.0);
    glMatrixMode(GL_MODELVIEW);
    //x,y,anchura,altura
    glViewport(0,0,640,480);
    
    //Llamada al bucle principal de recoleccion de eventos
    glutMainLoop();
}
