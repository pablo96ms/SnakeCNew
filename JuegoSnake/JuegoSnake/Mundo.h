#pragma once
#ifndef Mundo_h
#define Mundo_h

#include "Snake.h"
#include "Escenario.h"
#include "Fruta.h"
#include "Vector2D.h"
#include "Bonus.h"
#include "Enemigo.h"
#include "Interaccion.h"
#include "menu.h"
#include "Pared.h"
#include "Caja.h"

class Mundo
{
public:
	void juegoterminado();
    void tecla(unsigned char key);
	void TeclaEspecial(unsigned char key);
	bool ComerFruta();
	bool ComerBonus();
	Mundo();
    void dibuja();
	virtual ~Mundo();
	//void DibujaCuadricula();
	bool gameover;
	void Mover();
	void Inicializa();
	
	void GuardarPartida();
	void rotarOjo();
	friend class Interaccion;
	

	 //int val = 0;
	 //void menu(int );
	 //static int win;
	  

private:

	Snake serpiente;
    Escenario escenario;
    Fruta fruta;
    Vector2D posicion;
	Bonus bonus;
	Enemigo enemigo;
	menu menu;
	Pared plataforma;
	Caja caja;
	float x_ojo;
	float y_ojo;
	float z_ojo;
	int score;
	
	

};
#endif 
