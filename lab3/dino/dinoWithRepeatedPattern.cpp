#include <stdio.h>
#include <fstream>
#include <iostream>
#include <GL/glut.h>
#include <math.h>

int displayWidth = 1280; // Change this to your desired display width
int displayHeight = 720; // Change this to your desired display height

void drawPolyLineFile(const char *fileName)
{
    std::ifstream inStream;
    inStream.open(fileName); // open the file
    if (inStream.fail())
        return;

    GLint numpolys, numLines, x, y;
    inStream >> numpolys; // read the number of polylines

    for (int j = 0; j < numpolys; j++)
    { // read each polyline
        inStream >> numLines;
        glBegin(GL_LINE_STRIP); // draw the next polyline
        for (int i = 0; i < numLines; i++)
        {
            inStream >> x >> y; // read the next x, y pair
            glVertex2i(x, y);
        }
        glEnd();
    }

    glFlush();
    inStream.close();
}

void setWindow(float left, float right, int bottom, int top)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(left, right, bottom, top);
}

void setViewport(int left, int bottom, int width, int height)
{
    glViewport(left, bottom, width, height);
}

void render()
{
    glClear(GL_COLOR_BUFFER_BIT);

    setWindow(0, static_cast<float>(displayWidth), 0, static_cast<float>(displayHeight));

    int numColumns = 5;
    int numRows = 5;
    int viewportWidth = displayWidth / numColumns;
    int viewportHeight = displayHeight / numRows;

    for (int i = 0; i < numColumns; i++)
    {
        for (int j = 0; j < numRows; j++)
        {
            glViewport(i * viewportWidth, j * viewportHeight, viewportWidth, viewportHeight);
            drawPolyLineFile("dino.dat"); // send all output to display
        }
    }

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(displayWidth, displayHeight);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("FLIP DINOSAUR");
    glutDisplayFunc(render);
    glutMainLoop();

    return 0;
}