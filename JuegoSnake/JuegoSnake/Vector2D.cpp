//
//  Vector2D.cpp
//  JuegoSnake
//
//  Created by Richard villanera quiroga on 24/4/18.
//  Copyright © 2018 Richard villanera quiroga. All rights reserved.
//
#include <stdlib.h>
#include <math.h>
#include "Vector2D.h"
#include <time.h>
//#include "Escenario.h"
class Escenario;



Vector2D::Vector2D(float xv, float yv)
{
	x = xv;//vector por defecto(posicion cero=origen, velocidad cero=parado, aceleracion cero=sin aceleracion)
	y = yv;
}
Vector2D::~Vector2D()
{
}

Vector2D Vector2D::random(Vector2D& p)
{
	Vector2D res;
	srand(time(NULL));
	//p.x= 1 + rand() % (38);
	//p.y = 1 + rand() % (38);


	return res;
}
Vector2D Vector2D::operator +(Vector2D v) {
	Vector2D res(*this);
	res.x  += v.x;
	res.y += v.y;
	return res;
}
Vector2D Vector2D::operator *(float real) {
	Vector2D res;
	res.x = real * x;
	res.y = real * y;
	return res;
}
Vector2D Vector2D::operator -(Vector2D v) {
	Vector2D res(*this);
	res.x -= v.x;
	res.y -=v.y;
	return res;
}
Vector2D Vector2D::Unitario() {
	Vector2D retorno(x, y);
	float mod = modulo();
	if (mod > 0.00001) {//puede ser que el modulo del vector sea nulo(indeterminacion matemática),comprobamos que este supera un valor que se considera despreciable(0.00001)
		retorno.x /= mod;
		retorno.y /= mod;
	}
	return retorno;
}
float Vector2D::modulo() {
	return (float)sqrt(x*x + y * y);
}
float Vector2D::argumento() {
	return (float)atan2(y, x);
}
float Vector2D::operator *(Vector2D &v) {
	return x * v.x + y * v.y;
}



