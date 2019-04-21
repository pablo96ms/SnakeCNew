#include "menu.h"
#include "glut.h"

void GoMenu(int value);

menu::menu()
{
	val = 0;
}


menu::~menu()
{
}
void menu::createMenu(void) {
	
	
	// Creación del submenu
	Pausa = glutCreateMenu(GoMenu); //el nombre pausa
							  // Un submenu de Pausa
	glutAddMenuEntry("Abrir", 1);
	glutAddMenuEntry("Incio", 2);

	Inicio = glutCreateMenu(GoMenu); //menu inicio

	glutAddMenuEntry("Usuarios", 3); //Creación de una entrada
	glutAddMenuEntry("Niveles", 4);

	// Create the menu, this menu becomes the current menu
	Siguiente = glutCreateMenu(GoMenu);

	// Creacion de una entrada para Menu Principal 
	glutAddSubMenu("Pausa", Pausa);
	glutAddSubMenu("Inicio", Inicio);
	glutAddSubMenu("Siguiente", Siguiente);

	// Creación de una entrada para Menu Principal
	glutAddMenuEntry("Salir", 0);
	

	// Permite abrir el menu con el boton derecho del raton
	glutAttachMenu(GLUT_RIGHT_BUTTON);


}
void GoMenu(int value) {
	switch (value)
	{
	case 0: 
		exit(0);
		break;
		
	}
	glutPostRedisplay();
}