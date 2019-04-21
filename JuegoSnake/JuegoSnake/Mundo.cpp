#include <iostream>
#include "Mundo.h"
#include "glut.h"
#define COLUMNS 40
#define ROWS 40
#define MIN 2
#include <string>
#include <fstream>

using namespace std;

Mundo::Mundo()
{


}


Mundo::~Mundo()
{
	serpiente.DestruirContenido();
}

void Mundo::Inicializa() {
	score = 0;
	gameover = false;
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;
	for (int i = 0; i < 6; i++) {
		Snake* s = new Snake();
	}
}

void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		0.0, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 


	serpiente.dibuja();
    juegoterminado();
    //escenario.DrawGrid();
	bonus.dibuja();
	plataforma.dibuja();
	caja.dibuja();
    ComerFruta();
    fruta.dibuja();
	ComerBonus();
	if (score % 5 == 0 && score != 0) {
		std::cout << "LLAMANDO A BONUS DIBUJA" << std::endl;
		bonus.dibuja();
	}
	if (score % 3 == 0 && score != 0) {
		std::cout << "LLAMANDO A ENEMIGO DIBUJA" << std::endl;
		enemigo.Dibuja(enemigo.posicion);
	}
	ETSIDI::setTextColor(1, 1, 0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
	ETSIDI::printxy("SNAKE", -10, 17);

	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
	ETSIDI::printxy("RICHARD ENRIC Y PABLO MONGO", -10, 16.4);
}

void Mundo::juegoterminado()
{
	if ((Interaccion::colision(escenario, serpiente)) || (Interaccion::colision(serpiente)) || (Interaccion::colision(serpiente, enemigo))) {
		gameover = true;
		cout << "SE HA PRODUCIDO UNA COLISION" << endl;
	}
}
bool Mundo::ComerFruta()
{
	if (Interaccion::colision(serpiente, fruta)) {
		score++;
		return 1;
		serpiente.GetLength();
		//serpiente.snake_length++; //aumenta uno el tamaño de la serpiente
		//if (serpiente.snake_length > MAX)
			//serpiente.snake_length = MAX;
		//fruta.food = true;
	}
	else
		return 0;
    
}
bool Mundo::ComerBonus() {
	if (Interaccion::choque(serpiente, bonus)) {
		score += 3;//Cambio el valor de aumento de score, para que al aumentar no siga siendo multiplo de 5 y desaparezca
		return 1;
		//serpiente.snake_length++; //aumenta uno el tamaño de la serpiente
		//if (serpiente.snake_length > MAX)
			//serpiente.snake_length = MAX;
		//bonus.bonus = true;
	}
	else
		return 0;
}
void Mundo::TeclaEspecial(unsigned char key)
{
    switch (key) {
        case GLUT_KEY_UP:
			serpiente.setVel(0.0f, 5.0f);
            break;
        case GLUT_KEY_DOWN:
			serpiente.setVel(0.0f, -5.0f);
			break;
        case GLUT_KEY_LEFT:
			serpiente.setVel(-5.0f, 0.0f);
            break;
        case GLUT_KEY_RIGHT:
			serpiente.setVel(5.0f, 0.0);
            break;
    }
}
/*void Mundo::DibujaCuadricula()
{
    glClearColor(0.0, 0.0, 0.0, 1.0); //Coloca la pantalla en rojo o cualquier color
    escenario.initGrid(COLUMNS, ROWS); //dibuja en rojo los bordes
}*/

void Mundo::Mover() {

	serpiente.mueve(0.025f);
	bonus.mueve(0.025f);
}
void Mundo::GuardarPartida()
{
	ofstream archivoGuardado;
	archivoGuardado.open("archivoguardado.txt");
	//archivoGuardado << "h " << serpiente.posicion ;
	//archivoGuardado << "m " << num_mapa << " " << dificultad;
	archivoGuardado.close();
}

void Mundo::rotarOjo() {
	float dist = sqrt(x_ojo*x_ojo + z_ojo * z_ojo);
	float ang = atan2(z_ojo, x_ojo);
	ang += 0.05f;
	x_ojo = dist * cos(ang);
	z_ojo = dist * sin(ang);
}


void Mundo::tecla(unsigned char key) {

}

