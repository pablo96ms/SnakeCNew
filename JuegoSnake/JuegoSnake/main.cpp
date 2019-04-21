//
//  main.cpp
//  JuegoSnake
//
//  Created by Richard villanera quiroga on 24/4/18.
//  Copyright © 2018 Richard villanera quiroga. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS
//#include "stdafx.h"
#include <stdlib.h>
#include "glut.h"
#include <iostream>
#include "Mundo.h"
#include "Admin.h"
#include <stdio.h>
#include <string.h>
#define COLUMNS 40
#define ROWS 40
#define FPS 10 //marca la velocidad de la animacion
Admin juegoSnake;
Mundo mundo;


//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
//void Display_callbacks(void); //esta funcion sera llamada para dibujar
void onDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void onKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla
//void init();
//void reshape_callback(int, int);
void OnSpecialKeyboardDown(int key, int x, int y);

int main(int argc, char* argv[])
{
    //Inicializar el gestor de ventanas GLUT
    //y crear la ventana
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Snake C++ by RICHARD Y PABLO");
    
    //habilitar luces y definir perspectiva
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(40.0, 800 / 600.0f, 0.1, 150);
    
    //Registrar los callbacks
    glutDisplayFunc(onDraw);
    //glutReshapeFunc(reshape_callback);
    //init();
    glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(onKeyboardDown);
    glutSpecialFunc(OnSpecialKeyboardDown);
    
    
	mundo.Inicializa();


    //pasarle el control a GLUT,que llamara a los callbacks
    glutMainLoop();
    
    return 0;
}


void onDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	mundo.dibuja();

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}


/*void Display_callbacks(void) //display callback
{
    //Borrado de la pantalla
    glClear(GL_COLOR_BUFFER_BIT);
    
    //Para definir el punto de vista
    
    
    //aqui es donde hay que poner el cÛdigo de dibujo
	mundo.dibuja();
	//juegoSnake.Dibuja();
	
    //no borrar esta linea ni poner nada despues
    glutSwapBuffers(); //Activa Buffers
    if(juegoSnake.GAMEOVER) //si gameover es true
    {
       char _score[10];
       _itoa(juegoSnake.mundo.score,_score,10); //score coge la puntuacion y se la lleva a _score 10 es decimal
     char text[50]="SCORE: ";
       strcat(text, _score);
       MessageBox(NULL,text,"GAME OVER",0);
        exit(0);
    }
}*/
void onKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
	//mundo.tecla(key);

	glutPostRedisplay();
}
void OnSpecialKeyboardDown(int key, int x, int y)
{
	mundo.TeclaEspecial(key);
	//juegoSnake.TeclaEspecial(key);


}

void OnTimer(int value)
{
	//poner aqui el código de animacion
	mundo.Mover();
	//juegoSnake.Mueve();
    

	//no borrar estas lineas
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
    //glutTimerFunc(1000/FPS, OnTimer, 0); //necesita que sea asi, porque la serpiente se movera muy rapido
	//glutPostRedisplay();
}
/*void init()
{
	//juegoSnake.DibujaCuadricula(); //admin no tiene ninguna funcion llamada DibujaCuadricula por lo que da error, hay que acceder desde mundo
	//juegoSnake.mundo.DibujaCuadricula();
}*/
/*void reshape_callback(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);//agrandar o hace mas pequeña la pantalla
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
}*/

