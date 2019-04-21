#include <stdlib.h>
#include "Escenario.h"
#include "glut.h"
#include <ctime>



Escenario::Escenario()
{
}


Escenario::~Escenario()
{
}
void Escenario::DrawGrid()
{
    for(int x=0;x<posicion.xgrid;x++)
    {
        for(int y=0;y<posicion.ygrid;y++)
        {
            unit(x,y);
        }
    }
    
}
void Escenario::unit(int x,int y)
{
    if(x==0 || y==0 || x==posicion.xgrid-1 || y==posicion.ygrid-1)//color blanco para la reticula
    {
        glLineWidth(3.0);
        glColor3f(1.0, 0.0, 0.0);
    }
    else{// le coloco el color rojo en los bordes
        glLineWidth(1.0);
        glColor3f(1.0, 1.0, 1.0);
    }
    glBegin(GL_LINE_LOOP); //Lineas que encierran un cuadrado y se va haciendo la cuadricula
    glVertex2f(x, y);
    glVertex2f(x+1, y); //estoy haciendo la cuadricula
    glVertex2f(x+1, y+1);
    glVertex2f(x, y+1);
    glEnd();
}
void Escenario::initGrid(int x,int y)
{
    posicion.xgrid=y;
    posicion.ygrid=x;
}



