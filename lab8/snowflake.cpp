#include <GL/glut.h>
#include <cmath>

void flakeMotif()
{
    glBegin(GL_LINE_STRIP);
    // The polyline coordinates for the snowflake motif
    glVertex2f(0.0f, 0.025f);
    glVertex2f(0.5f, 0.025f);
    glVertex2f(0.6f, 0.275f);
    glVertex2f(0.63f, 0.265f);
    glVertex2f(0.54f, 0.025f);
    glVertex2f(0.7f, 0.025f);
    glVertex2f(0.8f, 0.205f);
    glVertex2f(0.83f, 0.195f);
    glVertex2f(0.74f, 0.025f);
    glVertex2f(1.0f, 0.025f);
    glVertex2f(1.025f, -0.0275f);
    glEnd();
}

void drawFlake()
{
    for (int count = 0; count < 6; count++)
    {
        flakeMotif();
        glScalef(1.0f, -1.0f, 1.0f); // flip it vertically
        flakeMotif();
        glScalef(1.0f, -1.0f, 1.0f);        // restore the original axis
        glRotatef(60.0f, 0.0f, 0.0f, 1.0f); // concatenate a 60 degree rotation
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0f, -0.5f, 0.0f); // Optional translation

    glColor3f(0.0f, 0.0f, 0.0f); // Set color to black

    drawFlake();
    // flakeMotif();

    glutSwapBuffers();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.5, 1.5, -1.5, 1.5);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Snowflake Example");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set clear color to white

    glutMainLoop();

    return 0;
}
