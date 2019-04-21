#pragma once
#include "Vector2D.h"
class ObjetoMovil
{
public:
	ObjetoMovil(void);
	virtual ~ObjetoMovil(void);
	void mueve(float t);
	Vector2D getPos();
	void setVel(float vx, float vy);
	void setVel(Vector2D vel);
	void setPos(float x, float y);
	void setPos(Vector2D pos);
	//void dibuja();
protected:
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
private:
	float radio;

};

