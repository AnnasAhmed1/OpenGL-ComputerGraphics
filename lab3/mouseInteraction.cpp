#include <GL/glut.h>
#include <vector>

int screenWidth = 800;
int screenHeight = 600;
std::vector<std::pair<float, float> > dots; // Stores the positions of the dots

void myDisplay(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the drawing color (e.g., red)
    glColor3f(1.0f, 0.0f, 0.0f);

    // Draw all the dots stored in the collection
    glPointSize(5.0); // Set the dot size
    glBegin(GL_POINTS);
    for (const auto &dot : dots)
    {
        glVertex2f(dot.first, dot.second);
    }
    glEnd();

    glFlush();
}

void myMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        // Convert mouse coordinates to OpenGL coordinates
        float mouseX = (2.0f * x / screenWidth) - 1.0f;
        float mouseY = 1.0f - (2.0f * y / screenHeight);

        // Add the new dot to the collection
        dots.push_back(std::make_pair(mouseX, mouseY));

        glutPostRedisplay(); // Trigger a redraw
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Click to Place Dots");

    glutDisplayFunc(myDisplay);
    glutMouseFunc(myMouse);

    glutMainLoop();

    return 0;
}
