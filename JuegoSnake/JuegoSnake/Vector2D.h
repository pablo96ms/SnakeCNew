//
//  Vector2D.h
//  JuegoSnake
//
//  Created by Richard villanera quiroga on 24/4/18.
//  Copyright © 2018 Richard villanera quiroga. All rights reserved.
//
#pragma once
#ifndef Vector2D_h
#define Vector2D_h
#define MAX 60
#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2
#include "Caja.h"
#include "Pared.h"


class Vector2D
{
	
public:
	Vector2D(float xv = 0.0f, float yv = 0.0f);
	virtual ~Vector2D();
	float x;
	float y;
	float posX[MAX]={20,20,20,20,20,20},posY[MAX]={20,19,18,17,16};
    short sDirection =RIGHT;
	float xfruta, yfruta;
	float xbonus, ybonus;
    int xgrid,ygrid;
    Vector2D random(Vector2D&);//funcion que genera un numero aleatorio
	Vector2D operator -(Vector2D);//resta de vectores
	Vector2D operator +(Vector2D);// suma de vectores
	Vector2D operator *(float);//producto por un escalar
	float operator *(Vector2D&);//producto escalar de vectores;
	float modulo();//modulo del vector
	float argumento();//argumento del vector
	Vector2D Unitario();//devuelve un vector unitario
	friend class Interaccion;
private:
	Caja caja;
	Pared pared;
    
};

#endif /* Vector2D_h */
