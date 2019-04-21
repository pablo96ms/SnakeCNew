#include <stdlib.h>
#include <time.h>
#include "Bonus.h"
#include "glut.h"
#include "Vector2D.h"



Bonus::Bonus()
{
	//movimiento gravitatorio
	//velocidad vertical inicial
	aceleracion.y = -9.8f;
	velocidad.y = 15;
	lado = 0.5f;
}


Bonus::~Bonus()
{
}

void Bonus::dibuja() {

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(30, 1, 1, 1);
	glColor3f(rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX);//color aleatorio
	glutSolidCube(lado);
	glPopMatrix();
	
}

