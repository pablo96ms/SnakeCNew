#pragma once
#include "Vector2D.h"


class Entidad
{
public:
	Entidad(void);
	virtual ~Entidad(void);
protected:
	float radio;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
public:
	//setters
	void SetRadio(float r);
	void SetPosicion(float x, float y);
	virtual void SetVelocidad(float x, float y);
	void SetAceleracion(float x, float y);
	//getters
	float GetRadio();
	Vector2D GetPosicion();
	Vector2D GetVelocidad();
	Vector2D GetAceleracion();
	//metodos
	virtual void Dibuja() {}
	virtual void Mueve(float t);

	friend class Interaccion;
};

