#pragma once
#ifndef Snake_h
#define Snake_h
#include "Vector2D.h"
#include "Fruta.h"
#include "Escenario.h"
#include "ObjetoMovil.h"
#include "ETSIDI.h"
#include "ColorRGB.h"
#define MAX_LENGHT 10

using ETSIDI::SpriteSequence;

class Snake:public ObjetoMovil
{
public:
	Snake();
    void dibuja();
	virtual ~Snake();
	void mueve(float t);
	int GetLength() { return snake_length; }
	float GetAltura() { return altura; }
	friend class Interaccion;
	void setColor(unsigned char r, unsigned char v, unsigned char a);
	void setRadio(float r);
	bool agregar(ObjetoMovil* o);
	void DestruirContenido();
	void eliminar(int index);
	void eliminar(ObjetoMovil* o);
protected:
    Fruta fruta;
    //Escenario escenario;
	//SpriteSequence sprite;
	ObjetoMovil *snake[MAX_LENGHT];
	int snake_length;
	float altura;
	ColorRGB color;
	float radio;
	
   
	
};

#endif
