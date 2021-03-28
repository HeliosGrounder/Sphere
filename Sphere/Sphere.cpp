#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

#define _USE_MATH_DEFINES
#include <math.h>


void init()
{
	glClearColor(9.0, 9.0, 9.0, 0.0);
	glShadeModel(GL_FLAT);
}

float x = 6.0;
float y = 0.0;
float z = 0.0;
float lx = -1.0;
float ly = 0.0;
float lz = 0.0;
float angle = 0.0;
float angle2 = M_PI / 2;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(2);
	glutWireSphere(2.0, 4, 2);

	glLoadIdentity();
	gluLookAt(x, y, z, lx, ly, lz, 0.0, 0.0, 1.0);

	glPointSize(20);
	glBegin(GL_POINTS);
	glColor3f(1.0f, .0f, .0f);
	glVertex3f(.0f, .0f, .0f);
	glVertex3f(2, 0, 0);
	glVertex3f(0, 0, 2);
	glVertex3f(0, 2, 0);
	glEnd();

	glLineWidth(7.5f);
	glBegin(GL_LINES);
	glColor3f(.0f, .0f, 1.0f);

	glVertex3f(2, 0, 0);
	glVertex3f(0, 2, 0);

	glVertex3f(0, 2, 0);
	glVertex3f(0, 0, 2);
	glEnd();

	glutSwapBuffers();


}

float temp = 0.0;

void processSpecialKeys(int key, int xx, int yy) {
	switch (key) {
	case GLUT_KEY_END:
		x = 6.0;
		y = 0.0;
		z = 0.0;
		lx = -1.0;
		ly = 0.0;
		lz = 0.0;
		temp = 0.0;
		angle = 0.0;
		angle2 = M_PI / 2;
		break;
	case GLUT_KEY_LEFT:
		angle -= 0.05f;
		temp = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
		x = temp * cos(angle) * abs(sin(angle2));
		y = temp * sin(angle) * abs(sin(angle2));
		z = temp * cos(angle2);
		lx = -cos(angle) * abs(sin(angle2));
		ly = -sin(angle) * abs(sin(angle2));
		lz = -abs(cos(angle2));
		break;
	case GLUT_KEY_RIGHT:
		angle += 0.05f;
		temp = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
		x = temp * cos(angle) * abs(sin(angle2));
		y = temp * sin(angle) * abs(sin(angle2));
		z = temp * cos(angle2);
		lx = -cos(angle) * abs(sin(angle2));
		ly = -sin(angle) * abs(sin(angle2));
		lz = -abs(cos(angle2));
		break;
	case GLUT_KEY_UP:
		angle2 -= 0.05f;
		temp = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
		x = temp * cos(angle) * abs(sin(angle2));
		y = temp * sin(angle) * abs(sin(angle2));
		z = temp * cos(angle2);
		lx = -cos(angle) * abs(sin(angle2));
		ly = -sin(angle) * abs(sin(angle2));
		lz = -abs(cos(angle2));
		break;
	case GLUT_KEY_DOWN:
		angle2 += 0.05f;
		temp = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
		x = temp * cos(angle) * abs(sin(angle2));
		y = temp * sin(angle) * abs(sin(angle2));
		z = temp * cos(angle2);
		lx = -cos(angle) * abs(sin(angle2));
		ly = -sin(angle) * abs(sin(angle2));
		lz = -abs(cos(angle2));
		break;
	case GLUT_KEY_HOME:
		exit(0);
		break;
	}
}

void reshape(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	gluPerspective(50.0, w / (GLfloat)h, 3.0, 90.0);
	glMatrixMode(GL_MODELVIEW);

}



void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Sphere");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(display);

	glutSpecialFunc(processSpecialKeys);

	glEnable(GL_DEPTH_TEST);

	glutMainLoop();
}