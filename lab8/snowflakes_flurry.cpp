#include <GL/glut.h>
#include <cmath>
#include <cstdlib>

class Canvas
{
public:
    void initCT()
    {
        glLoadIdentity();
    }

    void translate2D(float x, float y)
    {
        glTranslatef(x, y, 0.0f);
    }
};

Canvas cvs;

void flakeMotif()
{
    glBegin(GL_LINE_STRIP);
    // The polyline coordinates for the snowflake motif
    glVertex2f(0.0f, 0.0025f);      // Decreased size
    glVertex2f(0.25f, 0.0025f);     // Decreased size
    glVertex2f(0.3f, 0.0275f);      // Decreased size
    glVertex2f(0.315f, 0.0265f);    // Decreased size
    glVertex2f(0.27f, 0.0025f);     // Decreased size
    glVertex2f(0.35f, 0.0025f);     // Decreased size
    glVertex2f(0.4f, 0.0205f);      // Decreased size
    glVertex2f(0.415f, 0.0195f);    // Decreased size
    glVertex2f(0.37f, 0.0025f);     // Decreased size
    glVertex2f(0.5f, 0.0025f);      // Decreased size
    glVertex2f(0.5125f, -0.00275f); // Decreased size
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

void drawSnowflakes(int numFlakes)
{
    for (int i = 0; i < numFlakes; ++i)
    {
        cvs.initCT();
        float randX = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 2.0f - 1.0f;
        float randY = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 2.0f - 1.0f;
        cvs.translate2D(randX, randY);
        drawFlake();
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0f, -0.5f, 0.0f); // Optional translation

    glColor3f(0.0f, 0.0f, 0.0f); // Set color to black

    drawSnowflakes(10); // Draw 5 snowflakes

    glutSwapBuffers();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-3.0, 3.0, -3.0, 3.0); // Increased size
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Flurry of Snowflakes");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set clear color to white

    glutMainLoop();

    return 0;
}
