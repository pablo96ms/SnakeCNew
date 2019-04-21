#pragma once
#pragma once
//#include "Personaje.h"
//#include "Mapa.h"
#include "Enemigo.h"
//#include "Objeto.h"
//#include "ListaDisparos.h"
//#include "ObjetoDaño.h"
//#include "ObjetoMov.h"
//#include "ObjetoVida.h"
//#include "Portal.h"
#include "Textura.h"
#include "Mundo.h"
#include "Snake.h"


class Juego
{
public:
	Juego();
	~Juego();
protected:
	Mundo mundo;
	Snake snake;
private:
	//Personaje personaje;
	//Mapa mapa;
	//Pared final;
	//Objeto* listaObj[MAX_PAREDES];
	//Enemigo *listaEnem[MAX_PAREDES];//se añadirá aquí el enemigo de la serpiente
	//Textura *listaTextura[MAX_PAREDES];
	//ListaDisparos disparosPj;
	//ListaDisparos disparosEnem;
	//Mundo mundo;
	int num_enem, num_mapa, num_obj, num_textura; //contadores 
	int cont_p; //contador paredes
	float x_ojo;
	float y_ojo;
	float z_ojo;
	//Snake snake;
	bool carga;
	int dificultad;

public:
	void Dibuja();
	void Mueve();
	void Inicializa(int a);
	void Tecla(unsigned char key);
	void TeclaEspecial(unsigned char key);
	//void Textura(float k1, float k2, float k3,float k4);
	int GetNumMapa() { return num_mapa; }
	void SetNumMapa(int x) { num_mapa = x; }
	//float GetVida() { return personaje.estadisticas.vida; }
	bool FinalNivel();
	void GuardarPartida();
	void SetCarga(bool c) { carga = c; }
	bool GetCarga() { return carga; }
	void SetDificultad(int d) { dificultad = d; }
	int GetDificultad() { return dificultad; }

	friend class Admin;
};

