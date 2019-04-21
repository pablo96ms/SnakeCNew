#pragma once
#include "Mundo.h"
#ifndef Admin_h
#define Admin_h
#include "Juego.h"



class Admin
{
public:
	Admin();
	virtual ~Admin();
protected:
	enum Estado { INICIO, JUEGO, GAMEOVER, FIN, PAUSA };
	Estado estado;
	Mundo mundo;
	Juego juegoSnake;
//protected: si lo pones protegido no lo vas a ver desde fuera de la clase
public:
	void Dibuja();
	void TeclaEspecial(unsigned char key);
	void Tecla(unsigned char key);
	void Mueve();

};
#endif 

