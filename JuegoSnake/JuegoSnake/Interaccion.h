#pragma once
#ifndef Interaccion_h
#define Interaccion_h



#include "Escenario.h"


class Bonus;
class Fruta;
class Snake;
class Enemigo;


class Interaccion
{
public:
	Interaccion();
	virtual ~Interaccion();
	static bool colision(Snake&,Fruta&);
	static bool colision(Snake&);//funcion para detectar la colision entre la cabeza de la serpiente con su propio cuerpo
	static bool colision(Escenario&, Snake&);
	static bool choque(Snake&, Bonus&);
	static bool colision(Snake&, Enemigo&);
	
};
#endif // !Interaccion_h

