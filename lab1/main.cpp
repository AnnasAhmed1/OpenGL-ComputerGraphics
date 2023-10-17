#include <iostream>
#include <fstream>
#include <string>
#include <GL/glut.h>
using namespace std;

void myDisplay(void)
{
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // R, G, B, Alpha (opacity)

    // Clear the color buffer with the new background color
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the drawing color (e.g., red)
    glColor3f(1.0f, 0.0f, 0.0f);

    // Your OpenGL drawing code goes here

    // Flush the rendering pipeline
    glFlush();
}
int screenWidth = 840;
int screenHeight = 440;

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(30, 30);
    glutCreateWindow("Hi my first window");
    glutDisplayFunc(myDisplay);
    glutMainLoop();

    return 0;
};