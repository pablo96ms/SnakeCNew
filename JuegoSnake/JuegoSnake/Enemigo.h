#pragma once
#ifndef Enemigo_h
#include "Vector2D.h"
#include "ETSIDI.h"
#include "ObjetoMovil.h"
#define MAX_ENEMIGOS 10



class Enemigo:public ObjetoMovil
{
public:
	Enemigo();
	virtual ~Enemigo();
	void Dibuja(Vector2D&);
	friend class Interaccion;
	bool enemigo;
	Vector2D posicion;
private:
	float radio;

	
};
#endif // !Enemigo_h

