#pragma once
#include "Vector2D.h"
//#define MAX 30
#include <string>


class Textura
{
	float ka1, ka2, ka3, ka4;
	float profundidad;
	int id_textura;
public:
	Textura(void);
	~Textura(void);
	static void DibujaTextura(float k1, float k2, float k3, float k4, float prof, char id_text);
	static void DibujaTextura(float k1, float k2, float k3, float k4, float prof, char id_text, bool p);
	void DibujaTextura();
	void SetDatos(float k1, float k2, float k3, float k4, float prof, char id_text);
	friend class Admin;
};


