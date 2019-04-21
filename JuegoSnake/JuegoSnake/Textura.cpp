#include "Textura.h"
//#define MAX 30
#include "ETSIDI.h"
#include "Vector2D.h"
#include "glut.h"


using namespace ETSIDI;

Textura::Textura(void)
{
	ka1 = 0;
	ka2 = 0;
	ka3 = 0;
	ka4 = 0;
	profundidad = -0.01;
}
void Textura::DibujaTextura(/*float k1,float k2,float k3,float k4,float prof,char id_text*/)
{
	glEnable(GL_TEXTURE_2D);
	
	if (id_textura == 1)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Imagenes/cesped.png").id);
	if (id_textura == 2)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Imagenes/lava.png").id);
	if (id_textura == 3)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Imagenes/Menu.png").id);
	if (id_textura == 4)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Imagenes/SUELO.png").id);
	if (id_textura == 5)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Imagenes/Crema.png").id);
		

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	
	glTexCoord2d(0, 1);		glVertex3f(ka1, ka2, profundidad);
	glTexCoord2d(1, 1);		glVertex3f(ka3, ka2, profundidad);
	glTexCoord2d(1, 0);		glVertex3f(ka3, ka4, profundidad);
	glTexCoord2d(0, 0);		glVertex3f(ka1, ka4, profundidad);
	glEnd();
	

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}
void Textura::DibujaTextura(float k1, float k2, float k3, float k4, float prof, char id_text)
{
	glEnable(GL_TEXTURE_2D);

	if (id_text == 1)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Imagenes/cesped.png").id);
	if (id_text == 2)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Imagenes/lava.png").id);
	if (id_text == 3)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Imagenes/Menu.png").id);
	if (id_text == 4)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Imagenes/victoria.png").id);

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);

	glTexCoord2d(0, 1);		glVertex3f(k1, k2, prof);
	glTexCoord2d(1, 1);		glVertex3f(k3, k2, prof);
	glTexCoord2d(1, 0);		glVertex3f(k3, k4, prof);
	glTexCoord2d(0, 0);		glVertex3f(k1, k4, prof);
	glEnd();

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}
void Textura::DibujaTextura(float k1, float k2, float k3, float k4, float prof, char id_text, bool p)
{
	if (p = true) {

		glEnable(GL_TEXTURE_2D);

		if (id_text == 1)
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Imagenes/cesped.png").id);
		if (id_text == 2)
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Imagenes/lava.png").id);
		if (id_text == 3)
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Imagenes/Menu.png").id);
		if (id_text == 7)
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Imagenes/Pared.png").id);

		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);

		glTexCoord2d(0, 1);		glVertex3f(k1, k2, prof);
		glTexCoord2d(1, 1);		glVertex3f(k1, k4, prof);
		glTexCoord2d(1, 0);		glVertex3f(k1, k4, 0);
		glTexCoord2d(0, 0);		glVertex3f(k1, k2, 0);

		glTexCoord2d(0, 1);		glVertex3f(k1, k2, prof);
		glTexCoord2d(1, 1);		glVertex3f(k3, k2, prof);
		glTexCoord2d(1, 0);		glVertex3f(k3, k2, 0);
		glTexCoord2d(0, 0);		glVertex3f(k1, k2, 0);

		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
}
void Textura::SetDatos(float k1, float k2, float k3, float k4, float prof, char id_text)
{
	ka1 = k1;
	ka2 = k2;
	ka3 = k3;
	ka4 = k4;
	profundidad = prof;
	id_textura = id_text;
}
Textura::~Textura(void)
{
}


