#include "Entidad.h"



Entidad::Entidad()
{
	radio = 2;
	posicion.x = 0.0f;
	posicion.y = 0.0f;
	velocidad.x = 0.0f;
	velocidad.y = 0.0f;
	aceleracion.x = 0.0f;
	aceleracion.y = 0.0f;
}
void Entidad::SetRadio(float r)
{
	radio = r;
}
void Entidad::SetPosicion(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}
void Entidad::SetVelocidad(float x, float y)
{
	velocidad.x = x;
	velocidad.y = y;
}
void Entidad::SetAceleracion(float x, float y)
{
	aceleracion.x = x;
	aceleracion.y = y;
}

float Entidad::GetRadio()
{
	return radio;
}
Vector2D Entidad::GetPosicion()
{
	return posicion;
}
Vector2D Entidad::GetVelocidad()
{
	return velocidad;
}
Vector2D Entidad::GetAceleracion()
{
	return aceleracion;
}
void Entidad::Mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f*t*t);
	velocidad = velocidad + aceleracion * t;
}

Entidad::~Entidad(void)
{
}
