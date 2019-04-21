#include <stdlib.h>
#include "Admin.h"
#include "glut.h"
#include "ETSIDI.h"
#include "Textura.h"
#include "Juego.h"
#include "Mundo.h"


Admin::Admin()
{
	estado = INICIO;
}


Admin::~Admin()
{
}

void Admin::Dibuja()
{
	if (estado == INICIO)
	{

		/*gluLookAt(0.0, 0.0, 100.0, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
			*/
			
			
			
			


	//Hay que crear una clase llamada textura o crear un espacio de nombres, es decir, using namespace o class Textura porque sino no funciona
		//mundo.dibuja();//si quito esto, no dibuja nada porque esta en el estado de inicio
		Textura::DibujaTextura(-80, 40, 80, -40, -0.01, 3);// quito esta textura porque no nos permite ver la pantalla de juego
		
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("Fuentes/Yukon.ttf", 10);
		ETSIDI::printxy("SNAKE C++", -5, 4);

		ETSIDI::setTextColor(1,1,1);
		ETSIDI::setFont("Fuentes/Cafe.ttf", 7);
		ETSIDI::printxy("Pablo Mongo & Richard Enric", -10, 16.4);

		/*ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::printxy("Pulsa E para empezar", 15, -15);
		ETSIDI::printxy("Pulsa L para cargar partida", 15, -20);
		ETSIDI::printxy("Pulsa S para salir", 15, -25);
		*/
		
		//ETSIDI::printxy("Pulsa 1 para seleccionar en mapa 1", -45, -15);
		//ETSIDI::printxy("Pulsa 2 para seleccionar en mapa 2", -45, -20);
		//ETSIDI::printxy("Pulsa 3 para seleccionar en mapa 3", -45, -25);
		//ETSIDI::printxy("Pulsa K para dificultad facil", -45, 0);
		//ETSIDI::printxy("Pulsa J para dificultad normal", -45, -5);
		//ETSIDI::printxy("Pulsa H para dificultad dificil", -45, -10);
		

		
	}
	else if (estado == JUEGO)
	{
		mundo.dibuja();
		
		//ETSIDI::setFont("Fuentes/Cafe.ttf", 18);
	
	
		

		
	}
	else if (estado == GAMEOVER)
	{
		mundo.juegoterminado();

	}
	else if (estado == FIN)
	{
		
	}
	else if (estado == PAUSA)
	{
		
		
	}

}
void Admin::Tecla(unsigned char key)
{
	if (estado == INICIO)
	{

		if (key == 'j')
		{
			
			estado = JUEGO;
		}
		
			
	}

	else if (estado == JUEGO)
	{
		//pasa el control a juego
		//juego.Tecla(key);
		if (key == 'p')
			estado = PAUSA;
	}
	else if (estado == GAMEOVER)
	{
		if (key == 'i')
			estado = INICIO;
		if (key == 's') {
			estado = FIN;
			exit(0);
		}
	}
	else if (estado == FIN)
	{
		if (key == 'i')
			estado = INICIO;
	}
	else if (estado == PAUSA)
	{

		if (key == 'j')
			estado = JUEGO;
		if (key == 's') {
			estado = FIN;
			exit(0);//salir del juego
		}
		if (key == 'g') {
			juegoSnake.GuardarPartida();
			exit(0);
		}
	}
}
void Admin::TeclaEspecial(unsigned char key)
{
	if (estado == JUEGO)//pasa el control a juego
		juegoSnake.TeclaEspecial(key);
}
void Admin::Mueve()
{

	if (estado == JUEGO)//pasa el control a juego
		juegoSnake.Mueve();
}