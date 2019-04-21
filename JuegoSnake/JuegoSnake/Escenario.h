#pragma once
#ifndef Escenario_h
#define Escenario_h
#include "Vector2D.h"

class Escenario
{
public:
	Escenario();
	virtual ~Escenario();
    void DrawGrid();
    void unit(int x, int y);
    void initGrid(int x,int y);
	friend class Interaccion;
private:
    Vector2D posicion;
};

#endif
