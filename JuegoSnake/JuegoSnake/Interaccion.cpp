#include "Interaccion.h"
#include "Snake.h"
#include "Fruta.h"
#include "Mundo.h"
#include "Escenario.h"
#include "Vector2D.h"
#include "Bonus.h"



Interaccion::Interaccion()
{
}


Interaccion::~Interaccion()
{
}

bool Interaccion::colision(Snake &s, Fruta &f) {
	if ((s.posicion.posX[0] == f.posicion.xfruta) && (s.posicion.posY[0] == f.posicion.yfruta))
		return true;
	return false;
}
bool Interaccion::colision(Snake &s) {
	for (int i = 1; i < s.snake_length; i++) {
		if ((s.posicion.posX[0] == s.posicion.posX[i]) && (s.posicion.posY[0] == s.posicion.posY[i]))
			return true;
	}
	return false;
}

bool Interaccion::colision(Escenario &e, Snake &s) {
	if ((s.posicion.posX[0] == 0) || (s.posicion.posX[0] == e.posicion.xgrid - 1) || (s.posicion.posY[0] == 0) || (s.posicion.posY[0] == e.posicion.ygrid - 1))
		return true;
	else return false;
}

bool Interaccion::choque(Snake &s, Bonus &b) {
	if ((s.posicion.posX[0] == b.posicion.x) && (s.posicion.posY[0] == b.posicion.y))
		return true;
	else return false;
}
bool Interaccion::colision(Snake &s, Enemigo &e) {
	if ((s.posicion.posX[0] == e.posicion.x) && (s.posicion.posY[0] == e.posicion.y))
		return true;
	else return false;
}