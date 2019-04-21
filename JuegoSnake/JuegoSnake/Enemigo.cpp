#include "Enemigo.h"
#include "glut.h"
#include "time.h"



Enemigo::Enemigo()
{
	enemigo = true;
}


Enemigo::~Enemigo()
{
}
void Enemigo::Dibuja(Vector2D &o){
	srand(time(NULL));
	o.x = 1 + rand() % 38;
	o.y = 1 + rand() % 38;
	glColor3f(0.0, 1.0, 0.6);
	glRectf(o.x, o.y, o.x + 1, o.y + 1);


}
