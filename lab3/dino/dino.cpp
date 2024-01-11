#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

const int screenWidth = 650;  // width of screen window in pixels
const int screenHeight = 450; // height of screen window in pixels

void drawPolyLineFile(string fileName)
{
	fstream inStream;

	inStream.open(fileName, ios::in); // open the file

	if (inStream.fail())
	{
		cout << "can't open it!";
		return;
	}

	glClear(GL_COLOR_BUFFER_BIT); // clear the screen

	// GLint numpolys, numPoints, x ,y;

	GLfloat numpolys, numPoints, x, y;
	inStream >> numpolys; // read the number of polylines

	for (int j = 0; j < numpolys; j++) // read each polyline
	{
		inStream >> numPoints;	// number of points in first PolyLine
		glBegin(GL_LINE_STRIP); // draw the next polyline
		for (int i = 0; i < numPoints; i++)
		{
			inStream >> x >> y; // read the next x, y pair
			glVertex2f(x, y);
		}
		glEnd();
	}
	glFlush();
	inStream.close();
}

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0); // background color is white
	glColor3f(0.0f, 0.0f, 0.0f);	  // drawing color is black
	glPointSize(2.0);				  // a 'dot' is 2 by 2 pixels
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight); // dino window
	glViewport(0, 0, screenWidth, screenHeight);
}

void myDisplay(void)
{

	drawPolyLineFile("dino.dat"); // send all output to display

	drawPolyLineFile("dino.dat");

	// house wali ? knsi ? lab 2 >>?  nai lab 4 me lab 4 nh ki na hi file h uski ye lab 3 tk h
	// file bejo lab 4 ki banayi hi nahi ha lab 2 acha wo uski file down kr grp sa open grp p sahi he game ajao ajao id dedo anas ki id se nai khela jata ok
	glutSwapBuffers();
}

int main(int argc, char **argv)		
{
	glutInit(&argc, argv);						   // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);   // Set display mode
	glutInitWindowSize(screenWidth, screenHeight); // Set window size
	glutInitWindowPosition(10, 10);				   // Set window position on screen
	glutCreateWindow("Dino Line Drawing");		   // Open the screen window
	glutDisplayFunc(myDisplay);					   // Register redraw function
	myInit();
	glutMainLoop(); // Go into a perpetual loop
	return 0;
}
