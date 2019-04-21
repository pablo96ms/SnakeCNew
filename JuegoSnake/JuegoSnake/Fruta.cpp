#include <stdlib.h>
#include "Fruta.h"
#include "glut.h"
#include <ctime>
#include "Vector2D.h"



Fruta::Fruta()
{
	//posicion.x = 0.0;
	//posicion.y = 0.0;
}


Fruta::~Fruta()
{
}

void Fruta::dibuja()
{
	glPushMatrix();
    /*if(food)
        posicion.random(posicion.xfruta, posicion.yfruta);
    food=false;
    glColor3f(1.0, 0.0, 0.0);
    glRectf(posicion.xfruta, posicion.yfruta, posicion.xfruta+1, posicion.yfruta+1);
	*/
	//posicion.random(posicion.x, posicion.y);

	glPopMatrix();
    
}

