#include <GL/glut.h>
#include <cmath>

const int sides = 5;                // Number of sides for the star
const float angleIncrement = 72.0f; // Angle increment for rotation

void drawStarMotif()
{
    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white

    glBegin(GL_POLYGON);
    for (int i = 0; i < sides; ++i)
    {
        float angle = i * 2 * M_PI / sides;
        float x = cos(angle);
        float y = sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawInterlockingStripes()
{
    glColor3f(0.0f, 0.0f, 0.0f); // Set color to black

    glBegin(GL_POLYGON);
    for (int i = 0; i < sides; ++i)
    {
        float angle = i * 2 * M_PI / sides;
        float x = cos(angle);
        float y = sin(angle);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(x, y);
        glVertex2f(cos(angle + M_PI / sides), sin(angle + M_PI / sides));
    }
    glEnd();
}

void drawStar()
{
    for (int i = 0; i < sides; ++i)
    {
        drawStarMotif();
        drawInterlockingStripes();
        glRotatef(angleIncrement, 0.0f, 0.0f, 1.0f); // Rotate for next motif
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, 0.0f);     // Optional translation
    glRotatef(45.0f, 0.0f, 0.0f, 1.0f); // Optional initial rotation

    drawStar();

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
    glutCreateWindow("Rotational Symmetry Star");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set clear color to black

    glutMainLoop();

    return 0;
}
