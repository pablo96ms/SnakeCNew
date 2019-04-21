#pragma once
#ifndef Fruta_h
#define Fruta_h
#include "Vector2D.h"
#include "Escenario.h"
#include "ObjetoMovil.h"
class Fruta:public ObjetoMovil
{
	
public:
	Fruta();
	virtual ~Fruta();
	void dibuja();
	friend class Interaccion;
private:
	float lado;

    
};
#endif
