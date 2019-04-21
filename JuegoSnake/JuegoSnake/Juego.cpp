#include "Juego.h"
#include <math.h>
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include "Textura.h"
#include "glut.h"
#include <stdlib.h>
#include "Interaccion.h"
#include <time.h>
#include <fstream>
#include "Snake.h"


using namespace std;


Juego::Juego()
{
	//mundo.score = 0;
	/*
	num_mapa = 1;
	carga = 0;
	dificultad = 2;
	*/
}
void Juego::Inicializa(int a)
{
	
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 70;
	/*
	//valor por defecto del final es necesario especificar su valor en el txt aunque no se pinte
	//final.SetPos(0.0f, 0.0f, 0.0f, 0.0f);

	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 70;
	//contadores

	//contadores de los objetos a 0
	cont_p = 0;
	num_enem = 0;
	num_obj = 0;
	num_textura = 0;

	//valores que se obtendran del txt
	int id_text = 0, aux;
	float xl1 = 0.0f, yl1 = 0.0f, xl2 = 0.0f, yl2 = 0.0f, mov, dmg, vida;
	float px = 0.0f, py = 0.0f, v, d, cad, vmov, vdisp, ox = 0.0f, oy = 0.0f;
	float k1 = 0.0f, k2 = 0.0f, k3 = 0.0f, k4 = 0.0f, prof = 0.0f;
	float cargax, cargay, cargav, cargad, cargacad, cargavmov, cargavdisp;
	int cargamapa, cargadificultad;
	//variables para leer el txt
	FILE* f;
	FILE* f2;
	char line[250], token;
	//
	if (carga)
	{
		f2 = fopen("archivoguardado.txt", "r");
		while (!feof(f2))
		{
			fgets(line, 250, f2);
			if (ferror(f2))
			{
				puts("error");
				break;
			}
			sscanf(line, "%c", &token);
			switch (token)
			{
			case 'h':
				sscanf(line, "%c%f%f%f%f%f%f%f", &token, &cargax, &cargay, &cargav, &cargad, &cargacad, &cargavmov, &cargavdisp);

			case 'm':
				sscanf(line, "%c%d%d", &token, &cargamapa, &cargadificultad);
				SetDificultad(cargadificultad);
				aux = cargamapa;
			default:
				puts("error");
				break;
			}
		}
		fclose(f2);
	}

	//asignacion del mapa que cargar en funcion del nivel en el que se este
	if (carga == 0)aux = a;
	if (aux == 1)
		f = fopen("mapa1.txt", "r");
	if (aux == 2)
		f = fopen("mapa2.txt", "r");
	if (aux == 3)
		f = fopen("mapa3.txt", "r");
	//parsing	
	while (!feof(f))
	{
		fgets(line, 250, f);
		if (ferror(f))
		{
			puts("error");
			break;
		}
		sscanf(line, "%c", &token);
		switch (token)
		{
		case 'p': //obtener informacion de las paredes
			sscanf(line, "%c%f%f%f%f", &token, &xl1, &yl1, &xl2, &yl2);
			//mapa.Paredes[cont_p]->SetPos(xl1, yl1, xl2, yl2);
			cont_p++;
			break;
		case 'e': //obtener informacion de los enemigos
			sscanf(line, "%c%f%f%f%f%f%f%f", &token, &px, &py, &v, &d, &cad, &vmov, &vdisp);
			//listaEnem[num_enem] = new Enemigo;
			//listaEnem[num_enem]->SetPosicion(px, py);
			//listaEnem[num_enem]->SetEstadisticas(v, d, cad, vmov, vdisp);
			num_enem++;
			break;
		case 'h': //obtener informacion del personaje
			sscanf(line, "%c%f%f%f%f%f%f%f", &token, &px, &py, &v, &d, &cad, &vmov, &vdisp);
			//personaje.SetPosicion(px, py);
			//personaje.SetEstadisticas(v, d, cad, vmov, vdisp);
			break;
		case 'v': //obtener informacion de los objetos de vida
			sscanf(line, "%c%f%f%f", &token, &ox, &oy, &vida);
			//listaObj[num_obj] = new ObjetoVida;
			//listaObj[num_obj]->SetPosicion(ox, oy);
			//listaObj[num_obj]->SetModificadores(vida, 0.0f, 0.0f);
			//num_obj++;
			break;
		case 'd': //obtener informacion de los objetos de daño
			sscanf(line, "%c%f%f%f", &token, &ox, &oy, &dmg);
			//listaObj[num_obj] = new ObjetoDaño;
			//listaObj[num_obj]->SetPosicion(ox, oy);
			//listaObj[num_obj]->SetModificadores(0.0f, dmg, 0.0f);
			//num_obj++;
			break;
		case 'm': //obtener informacion de los objetos de mov
			//sscanf(line, "%c%f%f%f", &token, &ox, &oy, &mov);
			//listaObj[num_obj] = new ObjetoMov;
			//listaObj[num_obj]->SetPosicion(ox, oy);
			//listaObj[num_obj]->SetModificadores(0.0f, 0.0f, mov);
			//num_obj++;
			break;
		case 't': // obtener informacion para saber donde colocar las texturas del suelo
			sscanf(line, "%c%f%f%f%f%f%d", &token, &k1, &k2, &k3, &k4, &prof, &id_text);
			//listaTextura[num_textura] = new Textura;
			//listaTextura[num_textura]->SetDatos(k1, k2, k3, k4, prof, id_text);
			//num_textura++;
			break;
		case 'f': //datos para el final del mapa
			sscanf(line, "%c%f%f%f%f", &token, &xl1, &yl1, &xl2, &yl2);
			//final.SetPos(xl1, yl1, xl2, yl2);
			break;
		case 'g': //obtener informacion de objeto portal
			sscanf(line, "%c%f%f", &token, &ox, &oy);
			//listaObj[num_obj] = new Portal;
			//listaObj[num_obj]->SetPosicion(ox, oy);
			num_obj++;
			break;
		case '#': //comentario
			break;

		default:
			puts("error");
		}

	}
	fclose(f);
	if (carga)
	{
		//personaje.SetPosicion(cargax, cargay);
		//personaje.SetEstadisticas(cargav, cargad, cargacad, cargavmov, cargavdisp);
	}
	for (int i = 0; i<num_enem; i++)
	{
		if (GetDificultad() == 1) {
			//Stats* aux = new Stats;
			//aux = listaEnem[i]->estadisticas*0.5f;
			//listaEnem[i]->SetEstadisticas(*aux);

		}
		if (GetDificultad() == 2) {
			//Stats* aux = new Stats;
			//aux = listaEnem[i]->estadisticas*1.0f;
			//listaEnem[i]->SetEstadisticas(*aux);
		}
		if (GetDificultad() == 3) {
			//Stats* aux = new Stats;
			//aux = listaEnem[i]->estadisticas*2.0f;
			//listaEnem[i]->SetEstadisticas(*aux);
		}
	}*/
}

/*bool Juego::FinalNivel() //detecta el que el personaje llega al final del nivel
{
	Vector2D dir;
	float dif = final.distancia(personaje.posicion, &dir) - personaje.radio;
	if (dif <= 0.0f)
		return true;
	return false;
	return -1;
}*/
void Juego::Dibuja()
{
	mundo.dibuja();

	//x_ojo = snake.posicion.x;
	//y_ojo = snake.posicion.y;
	

	//gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		//snake.posicion.x, snake.posicion.y, 0.0f,      // hacia que punto mira  (0,0,0) 
		//0.0f, 1.0f, 0.0f);
		
	/*
	personaje.Dibuja();

	mapa.Dibuja(cont_p);


	disparosEnem.Dibuja();
	disparosPj.Dibuja();


	for (int i = 0; i<num_enem; i++)
		listaEnem[i]->Dibuja(personaje.posicion);

	if (num_obj>0)
		for (int i = 0; i<num_obj; i++)
		{
			listaObj[i]->Dibuja();
		}

	if (num_textura>0)
		for (int i = 0; i<num_textura; i++)
			listaTextura[i]->DibujaTextura();
			*/
}
void Juego::Mueve()
{
	mundo.Mover();
	/*
	//animacion del pj
	personaje.Mueve(0.025f);
	//animacion de los disparos
	disparosEnem.Mueve(0.025f);
	disparosPj.Mueve(0.025f);
	//si el personaje entra en el radio de accion un enemigo y ha transcurrido suficiente tiempo dispara
	for (int i = 0; i<num_enem; i++) {
		if (Interaccion::accion(personaje, *listaEnem[i]))
		{
			Disparo *auxdisp = listaEnem[i]->Dispara(personaje.posicion);
			if (auxdisp != 0)
				disparosEnem.agregar(auxdisp);
		}
	}


	//si algun disparo toca al pj se le baja la vida
	Disparo *auxdisp_e1 = disparosEnem.colision(&personaje);
	if (auxdisp_e1 != 0)
	{
		ETSIDI::play("Sonido/BajaSalud.wav");
		personaje.estadisticas.vida = personaje.estadisticas.vida - auxdisp_e1->daño;
		disparosEnem.eliminar(auxdisp_e1);
	}
	//si algun disparo del pj toca a un enemigo se borra y se aplica el daño
	for (int j = 0; j<num_enem; j++)
	{
		Disparo *auxdisp1 = disparosPj.colision(listaEnem[j]);
		if (auxdisp1 != 0)
		{
			listaEnem[j]->estadisticas.vida = listaEnem[j]->estadisticas.vida - auxdisp1->daño;
			disparosPj.eliminar(auxdisp1);
			if (listaEnem[j]->estadisticas.vida<0)
			{
				delete listaEnem[j];
				num_enem--;
				ETSIDI::play("Sonido/BolaFuego.wav");
				for (int i = j; i<num_enem; i++)
					listaEnem[i] = listaEnem[i + 1];
			}
		}
	}
	//cuando el personaje toque un objeto se aplica y se borra
	for (int i = 0; i<num_obj; i++)
	{
		if (Interaccion::colision(personaje, *listaObj[i]) == 1)
		{
			personaje.estadisticas.daño = personaje.estadisticas.daño += listaObj[i]->moddaño;
			personaje.estadisticas.vida = personaje.estadisticas.vida += listaObj[i]->modvida;
			personaje.estadisticas.velMov = personaje.estadisticas.velMov += listaObj[i]->movel;

			delete listaObj[i];
			ETSIDI::play("Sonido/Vidamas.wav");
			num_obj--;
			for (int j = i; j<num_obj; j++)
				listaObj[j] = listaObj[j + 1];
		}
	}
	//si el personaje toca una pared se para
	if (Interaccion::colision(personaje, mapa, cont_p))
		personaje.SetVelocidad(0.0f, 0.0f);
	//comprobacion disparo toque alguna pared del mapa
	Disparo *auxdisp2 = disparosPj.colision(&mapa, cont_p);
	if (auxdisp2 != 0)
		disparosPj.eliminar(auxdisp2);
	Disparo *auxdisp3 = disparosEnem.colision(&mapa, cont_p);
	if (auxdisp3 != 0)
		disparosEnem.eliminar(auxdisp3);

	//comprobacion velocidad
	Vector2D aux = personaje.GetVelocidad();
	if (aux.modulo()<0.5f)
	{
		personaje.SetVelocidad(0.0f, 0.0f);
		personaje.SetAceleracion(0.0f, 0.0f);
	}
*/
}

/*void Juego::Tecla(unsigned char key)
{
	switch (key)
	{//se le da al pj una velocidad en funcion del valor de su estadistica de movimiento
	case 'w':
		personaje.SetVelocidad(0.0f, personaje.estadisticas.velMov);
		personaje.SetAceleracion(0.0f, -20.0f);
		break;
	case 'a':
		personaje.SetVelocidad(-personaje.estadisticas.velMov, 0.0f);
		personaje.SetAceleracion(20.0f, 0.0f);
		break;
	case 's':
		personaje.SetVelocidad(0.0f, -personaje.estadisticas.velMov);
		personaje.SetAceleracion(0.0f, 20.0f);
		break;
	case 'd':
		personaje.SetVelocidad(personaje.estadisticas.velMov, 0.0f);
		personaje.SetAceleracion(-20.0f, 0.0f);
		break;
	}
}*/
void Juego::TeclaEspecial(unsigned char key)
{
	//ETSIDI::play("Sonido/Laser.wav");
	mundo.tecla(key);
	/*switch (key)
	{
		Disparo* auxdisp;
	case GLUT_KEY_LEFT:
		auxdisp = personaje.DisparaIzq();
		disparosPj.agregar(auxdisp);
		break;
	case GLUT_KEY_RIGHT:
		auxdisp = personaje.DisparaDcha();
		disparosPj.agregar(auxdisp);
		break;
	case GLUT_KEY_UP:
		auxdisp = personaje.DisparaArriba();
		disparosPj.agregar(auxdisp);
		break;
	case GLUT_KEY_DOWN:
		auxdisp = personaje.DisparaAbajo();
		disparosPj.agregar(auxdisp);
		break;
	}*/
}
void Juego::GuardarPartida()
{
	ofstream archivoGuardado;
	archivoGuardado.open("archivoguardado.txt");
//	archivoGuardado << "h " << snake.posicion.x  << " " << snake.posicion.y << endl;
	archivoGuardado.close();
}
Juego::~Juego()
{
}
