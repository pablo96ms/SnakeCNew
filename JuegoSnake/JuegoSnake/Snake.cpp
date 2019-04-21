#include "Snake.h"
#include "glut.h"
#include <iostream>

using namespace std;


Snake::Snake()
{
	snake_length = 5;
	for (int i = 0; i < MAX_LENGHT; i++)
		snake[i] = 0;
	altura = 1.8f;
}


Snake::~Snake()
{
}
void Snake::dibuja()
{
    /*for(int i=snake_length-1;i>0;i--)
    {
		
        posicion.posX[i]=posicion.posX[i-1];
        posicion.posY[i]=posicion.posY[i-1];
    }
    if(posicion.sDirection==UP)
        posicion.posY[0]++;
    else if(posicion.sDirection==DOWN)
        posicion.posY[0]--;
    else if (posicion.sDirection==RIGHT)
        posicion.posX[0]++;
    else if (posicion.sDirection==LEFT)
        posicion.posX[0]--;
    glColor3f(0.0, 1.0, 0.0); //colour green
    for(int i=0;i<snake_length;i++)
    {
        if(i==0)
            glColor3f(0.0, 1.0, 0.0);
        else
            glColor3f(0.0, 0.0, 1.0);
        glRectd(posicion.posX[i], posicion.posY[i], posicion.posX[i]+1, posicion.posY[i]+1);
    }
    
    */
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	//glutSolidSphere(altura, 20, 20); //esfera antigua de diseño
	for (int i = 0; i < snake_length; i++) 
	{

		if (i == 0)//cabeza de la serpiernte
		{
			cout << "Cabeza de la serpiente" << endl;
			//snake[i]->dibuja();
			glColor3ub(0.0, 0.0, 255);//azul
			glutSolidSphere(altura, 10, 10);
		}

		else //cuerpo de la serpiente
		{
			cout << "Cuerpo de la serpiente" << endl;
			//snake[i]->dibuja();
			glColor3ub(255, 0, 0.0);//rojo
			glutSolidSphere(altura, 20, 20);
		}

		
	}
	glPopMatrix();
}


void Snake::mueve(float t) {
	/*for (int i = 0; i < snake_length; i++) {
		snake[i]->mueve(t);
	}*/
	ObjetoMovil::mueve(t);
}


void Snake::setColor(unsigned char r, unsigned char v, unsigned char a) {
	color.set(r, v, a);

}

void Snake::setRadio(float r)
{
	if (r<0.1F)
		r = 0.1F;
	radio = r;
}

bool Snake::agregar(ObjetoMovil* o) {
	for (int i = 0; i<snake_length; i++)//para evitar que se añada una esfera ya existente
		if (snake[i] == o)
			return false;

	if (snake_length<MAX_LENGHT)
		snake[snake_length++] = o;
	else
		return false;
	return true;
}

void Snake::eliminar(int index) {
	if ((index<0) || (index >= snake_length))
		return;

	delete snake[index];

	snake_length--;
	for (int i = index; i<snake_length; i++)
		snake[i] = snake[i + 1];

}

void Snake::DestruirContenido() {
	for (int i = 0; i < snake_length; i++)
		delete snake[i];
}

void Snake::eliminar(ObjetoMovil* o) {
	for (int i = 0; i<snake_length; i++)
		if (snake[i] == o)
		{
			eliminar(i);
			return;
		}
}

