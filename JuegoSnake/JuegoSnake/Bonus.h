#pragma once
#ifndef Bonus_h
#define Bonus_h
#include "ObjetoMovil.h"
#include "Vector2D.h"
#include "Interaccion.h"
#include "Fruta.h"
#include "ColorRGB.h"




class Bonus:public ObjetoMovil
{
	
	friend class Interaccion;
public:

	void dibuja();
	Bonus();
	virtual ~Bonus();
private:
	float lado;
	

	
	
};
#endif // !Bonus_h

