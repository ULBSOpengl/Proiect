/*
Programul afiseaza un patrat pe care il translateaza
pe axa x la apasarea sagetilor stanga, dreapta
*/
#include "glos.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>
#include <math.h>

void myinit(void);
void CALLBACK display(void);
void CALLBACK myReshape(GLsizei w, GLsizei h);
void CALLBACK MutaStanga(void);
void CALLBACK MutaDreapta(void);
void CALLBACK MutaJos(void);
void CALLBACK MutaSus(void);
void CALLBACK rot_z_up(AUX_EVENTREC* event);
void CALLBACK rot_z_down(AUX_EVENTREC* event);
void SystemXoYoZ(void);


static GLfloat x = 0, y = 0, alfa = 270;

GLUquadricObj* qobj;

void myinit(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0);
}

void SystemXoYoZ(void) {
	// Axa OX		
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(150, 0);
	glEnd();

	// Axa Oy		
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(0, 150);
	glEnd();

	// Axa Oz		
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 150);
	glEnd();

}

void CALLBACK MutaStanga(void)
{
	x = x - 10;
}

void CALLBACK MutaDreapta(void)
{
	x = x + 10;
}


void CALLBACK MutaJos(void)
{
	y = y - 10;
}

void CALLBACK MutaSus(void)
{

	y = y + 10;
}

void CALLBACK rot_z_up(AUX_EVENTREC* event)
{
	alfa = alfa + 10;
}

void CALLBACK rot_z_down(AUX_EVENTREC* event)
{
	alfa = alfa - 10;
}

void CALLBACK display(void)
{
	int i = 0;
	qobj = gluNewQuadric();

	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();

	glTranslatef(x, y, 0.0);
	
	glRotatef(alfa, alfa + 30, alfa + 20, alfa + 10);

	//SystemXoYoZ();

	auxWireSphere(50);

	//SFERA
	//glPushMatrix();
	//gluQuadricDrawStyle(qobj, GLU_LINE);
	//glTranslatef(x - 30, y + 90, 0);
	//glRotatef(alfa, 1, 1, 1);
	//glColor3f(1, 0, 0);
	//gluSphere(qobj, 30, 10, 5);
	//glPopMatrix();

	//CILINDRU
	glPushMatrix();
	gluQuadricDrawStyle(qobj, GLU_SILHOUETTE);
	glTranslatef(x - 170, y + 90, 0);
	glRotatef(alfa, 1, 1, 1);
	glColor3f(0.6, 0.1961, 0.8);
	gluCylinder(qobj, 30, 60, 70, 4, 10);
	glPopMatrix();
/*
	//CON
	glPushMatrix();
	gluQuadricDrawStyle(qobj, GLU_LINE);
	glTranslatef(x - 100, y + 90, 0);
	glRotatef(alfa, 1, 1, 1);
	glColor3f(0, 1, 1);
	gluCylinder(qobj, 30, 0, 100, 50, 30);
	glPopMatrix();

	//DISC
	glPushMatrix();
	gluQuadricDrawStyle(qobj, GLU_LINE);
	glTranslatef(x + 50, y + 90, 0);
	glRotatef(alfa, 1, 1, 1);
	glColor3f(1, 0, 1.5);
	gluDisk(qobj, 10, 30, 50, 50);
	glPopMatrix();

	//CERC
	glPushMatrix();
	gluQuadricDrawStyle(qobj, GLU_LINE);
	glTranslatef(x + 130, y + 90, 0);
	glRotatef(alfa, 1, 1, 1);
	glColor3f(0.75, 0.75, 0.75);
	gluDisk(qobj, 0, 30, 50, 50);
	glPopMatrix();


	//SECTOR DE DISC
	glPushMatrix();
	gluQuadricDrawStyle(qobj, GLU_SILHOUETTE);
	glTranslatef(x - 30, y, 0);
	glRotatef(alfa, 1, 1, 1);
	glColor3f(0.5, 0, 0);
	gluPartialDisk(qobj, 10, 30, 10, 10, 10, 100);
	glPopMatrix();


	//SECTOR DE CERC
	glPushMatrix();
	gluQuadricDrawStyle(qobj, GLU_SILHOUETTE);
	glTranslatef(x - 170, y, 0);
	glRotatef(alfa, 1, 1, 1);
	glColor3f(0.5, 0, 0.5);
	gluPartialDisk(qobj, 0, 30, 10, 10, 10, 100);
	glPopMatrix();


	//CUB
	glPushMatrix();
	gluQuadricDrawStyle(qobj, GLU_LINE);
	glTranslatef(x - 100, y, 0);
	glRotatef(alfa, 1, 1, 1);
	glColor3f(0, 0.5, 0.5);
	gluCylinder(qobj, 30, 30, 50, 4, 10);
	glPopMatrix();


	//PRISMA HEXA
	glPushMatrix();
	gluQuadricDrawStyle(qobj, GLU_LINE);
	glTranslatef(x + 50, y, 0);
	glRotatef(alfa, 1, 1, 1);
	glColor3f(0.1176, 0.5647, 1.0);
	gluCylinder(qobj, 30, 30, 70, 6, 30);
	glPopMatrix();


	//PRISMA TRIUNGHIULARA
	glPushMatrix();
	gluQuadricDrawStyle(qobj, GLU_FILL);
	glTranslatef(x + 130, y, 0);
	glRotatef(alfa, 1, 1, 1);
	glColor3f(0.64, 0.58, 0.5);
	gluCylinder(qobj, 30, 30, 70, 3, 20);
	glPopMatrix();


	//PIRAMIDA PATRATICA
	glPushMatrix();
	gluQuadricDrawStyle(qobj, GLU_LINE);
	glTranslatef(x - 30, y - 70, 0);
	glRotatef(alfa, 1, 1, 1);
	glColor3f(1.0, 0.498039, 0.0);
	gluCylinder(qobj, 30, 0, 100, 4, 30);
	glPopMatrix();


	//TRUNCHI DE PIRAMIDA
	glPushMatrix();
	gluQuadricDrawStyle(qobj, GLU_LINE);
	glTranslatef(x - 170, y - 70, 0);
	glRotatef(alfa, 1, 1, 1);
	glColor3f(0.69, 0.09, 0.12);
	gluCylinder(qobj, 30, 10, 70, 4, 30);
	glPopMatrix();


	//HEXA
	glPushMatrix();
	gluQuadricDrawStyle(qobj, GLU_SILHOUETTE);
	glTranslatef(x - 100, y - 70, 0);
	glRotatef(alfa, 1, 1, 1);
	glColor3f(1, 0, 1.5);
	gluDisk(qobj, 0, 30, 6, 1);
	glPopMatrix();


	//PENTA
	glPushMatrix();
	gluQuadricDrawStyle(qobj, GLU_SILHOUETTE);
	glTranslatef(x + 50, y - 70, 0);
	glRotatef(alfa, 1, 1, 1);
	glColor3f(1, 0, 1.5);
	gluDisk(qobj, 0, 30, 5, 1);
	glPopMatrix();


	//TRIUNGHI
	glPushMatrix();
	gluQuadricDrawStyle(qobj, GLU_SILHOUETTE);
	glTranslatef(x + 130, y - 70, 0);
	glRotatef(alfa, 1, 1, 1);
	glColor3f(1, 0, 1.5);
	gluDisk(qobj, 0, 30, 3, 1);
	glPopMatrix();

	// UN PUNCT
	glPointSize(5);
	glBegin(GL_POINTS);
	glColor3f(1.0, 0.0, 0.0);1
		glVertex2f(0.0, 0.0);
	glEnd();
*/
	// UN PATRAT
	//glBegin(GL_QUADS);
	//glColor3f (1.0, 0.0, 0.0);
	//glVertex2f(100,100);
	//glColor3f (1.0, 1.0, 0.0);
	//glVertex2f(150.0,100.0);
	//glColor3f (0.0, 0.0, 1.0);
	//glVertex2f(150.0,150.0);
	//glColor3f (0.0, 1.0, 0.0);
	//glVertex2f(100.0,150.0);
	//glEnd();
	

	// O LINIE		
	//glBegin(GL_LINES);
	//glVertex2f(0,0);
	//glVertex2f(100,150);
	//glEnd();
	

	 //UN POLIGON
	//glBegin(GL_POLYGON);
	//glColor3f (1.0, 0.0, 0.0);
	//glVertex2f(30,80);
	//glColor3f (1.0, 1.0, 0.0);
	//glVertex2f(75.0,30.0);
	//glColor3f (0.0, 0.0, 1.0);
	//glVertex2f(90.0,75.0);
	//glColor3f (0.0, 1.0, 0.0);
	//glVertex2f(110.0,90.0);
	//glColor3f (0.0, 1.0, 0.0);
	//glVertex2f(80.0,110.0);
	//glEnd();
	

	// UN CERC - LINII
	//glColor3f(1,0,0);
	//glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	//glBegin(GL_POLYGON);

	//for(i=0;i<=360;i+=10){
	//	glVertex2f(5*cos(i*3.14/180),5*sin(i*3.14/180));
	//}
	//glEnd();
	

	// UN CERC - PUNCTE
	/*glBegin(GL_POINTS);

	for(i=0;i<=360;i++){

	glVertex2f(50*cos(i*3.14/180),50*sin(i*3.14/180));
	}
	glEnd();
	*/

	//UN CILINDRU
	//glColor3f(1,0,0);
	//glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	//glBegin(GL_QUAD_STRIP);
	//	for(i=0;i<=360;i+=10){
	//	glVertex3d(50*cos(i*3.14/180),50*sin(i*3.14/180),100);
	//	glVertex3d(50*cos(i*3.14/180),50*sin(i*3.14/180),-100);
	//	}
	//glEnd();


	//UN PARALELIPIPED
	//glColor3f(1, 0, 0);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//glBegin(GL_QUAD_STRIP);
	//	for (i = 0; i <= 360; i += 10) {
	//	glVertex3d(35 * cos(i * 3.14 / 180),35 * sin(i * 3.14 / 180), 100);
	//	glVertex3d(50 * cos(i * 3.14 / 180), 50 * sin(i * 3.14 / 180), -100);
	//	}
	//glEnd();


	//UN CON
	//glColor3f(1,0,0);
	//glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	//glBegin(GL_TRIANGLE_FAN);
	//
	//glVertex3f(20, 30,100);

	//for(i=0;i<=360;i+=10)
	//{
	//glVertex3f(50*cos(i*3.14/180),50*sin(i*3.14/180),-100);
	//}

	//glEnd();
	
	auxSwapBuffers(); // trebuie setat AUX_DOUBLE in functia auxInitDisplayMode(AUX_DOUBLE | AUX_RGB);
}

/*void CALLBACK myReshape(GLsizei w, GLsizei h)
{
if (!h) return;			//transformare anizotropica, forma se modifica functie de forma(dimens) viewportului
glViewport(0, 0, w, h);	//daca w>h stabilim ca baza inaltime, si stab unit logica de dimens in fct de h(h/320, 320 lungime lat patrat)
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho (-160.0, 160.0, -160.0,
160.0, -100.0, 100.0);
glMatrixMode(GL_MODELVIEW);
}*/

void CALLBACK myReshape(GLsizei w, GLsizei h)
{
	if (!h) return;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-260.0, 260.0, 260.0 * (GLfloat)h / (GLfloat)w,
			-260.0 * (GLfloat)h / (GLfloat)w, -200.0, 200.0);
	else
		glOrtho(-260.0 * (GLfloat)w / (GLfloat)h,
			260.0 * (GLfloat)w / (GLfloat)h, -260.0, 260.0, -200.0, 200.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	auxInitDisplayMode(AUX_DOUBLE | AUX_RGB);
	auxInitPosition(0, 0, 800, 600);
	auxInitWindow("Laborator 4");
	myinit();
	auxKeyFunc(AUX_LEFT, MutaStanga);
	auxKeyFunc(AUX_RIGHT, MutaDreapta);
	auxKeyFunc(AUX_DOWN, MutaJos);
	auxKeyFunc(AUX_UP, MutaSus);
	auxMouseFunc(AUX_LEFTBUTTON, AUX_MOUSEDOWN, rot_z_up);
	auxMouseFunc(AUX_RIGHTBUTTON, AUX_MOUSEDOWN, rot_z_down);
	auxReshapeFunc(myReshape);
	auxMainLoop(display);
	return(0);
}
