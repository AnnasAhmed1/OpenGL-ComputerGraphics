#include <stdio.h>
#include <fstream>
#include <iostream>
#include <GL/glut.h>
#include <math.h>

void drawPolyLineFile(const char *fileName)
{
    std::ifstream inStream(fileName);
    if (inStream.fail())
        return;
    int numpolys, numLines, x, y;
    inStream >> numpolys;
    for (int j = 0; j < numpolys; j++)
    {
        inStream >> numLines;
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i < numLines; i++)
        {
            inStream >> x >> y;
            glVertex2i(x, y);
        }
        glEnd();
    }
    glFlush();
    inStream.close();
}

void setWindow(float left, float right, float bottom, float top)
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
    int displayWidth = glutGet(GLUT_WINDOW_WIDTH);
    int displayHeight = glutGet(GLUT_WINDOW_HEIGHT);
    setWindow(0, static_cast<float>(displayWidth), 0, static_cast<float>(displayHeight));

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if ((i + j) % 2 == 0)
                setWindow(0.0, static_cast<float>(displayWidth), 0.0, static_cast<float>(displayHeight));
            else
                setWindow(0.0, static_cast<float>(displayWidth), static_cast<float>(displayHeight), 0.0);

            int viewportWidth = displayWidth / 5;
            int viewportHeight = displayHeight / 5;
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
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("FLIP DINOSAUR");
    glutDisplayFunc(render);
    glutMainLoop();
    return 0;
}
