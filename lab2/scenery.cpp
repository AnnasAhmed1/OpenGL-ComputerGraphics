#include <GL/glut.h>

void drawRectangle(float x, float y, float width, float height, float color[])
{
    glColor3f(color[0], color[1], color[2]);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3, float color[])
{
    glColor3f(color[0], color[1], color[2]);
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

void drawHouse(float scale)
{
    // House base (square)
    float baseColor[] = {0.6f, 0.4f, 0.3f};
    drawRectangle(-0.2 * scale, -0.5 * scale, 0.4 * scale, 0.4 * scale, baseColor);

    // Roof (triangle)
    float roofColor[] = {0.8f, 0.2f, 0.2f};
    drawTriangle(-0.3 * scale, -0.1 * scale, 0 * scale, 0.3 * scale, 0.3 * scale, -0.1 * scale, roofColor);

    // Windows
    float windowColor[] = {0.8f, 0.8f, 0.8f};

    // Window 1 (left)
    drawRectangle(-0.05, -0.4, 0.15, 0.2, windowColor);
    glColor3f(0.0f, 0.0f, 0.0f); // Black lines for the window
    glBegin(GL_LINES);
    glVertex2f(-0.05, -0.2);
    glVertex2f(0.1, -0.2);
    glVertex2f(0.025, -0.4);
    glVertex2f(0.025, -0.2);
    glEnd();

    // Window 2 (right)
    // drawRectangle(0.2, -0.4, 0.15, 0.2, windowColor);
    // glColor3f(0.0f, 0.0f, 0.0f); // Black lines for the window
    // glBegin(GL_LINES);
    // glVertex2f(0.2, -0.2);
    // glVertex2f(0.35, -0.2);
    // glVertex2f(0.275, -0.4);
    // glVertex2f(0.275, -0.2);
    // glEnd();
}

void drawTree(float x, float y, float scale)
{
    // Tree top (triangle)
    float treeTopColor[] = {0.0f, 0.4f, 0.0f}; // Darker green color for trees
    drawTriangle(x - 0.05 * scale, y, x + 0.05 * scale, y, x, y + 0.3 * scale, treeTopColor);

    // Tree trunk (rectangle)
    float trunkColor[] = {0.4f, 0.2f, 0.0f};
    drawRectangle(x - 0.02 * scale, y - 0.15 * scale, 0.04 * scale, 0.15 * scale, trunkColor);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the sky
    float skyColor[] = {0.0f, 0.7f, 1.0f};
    drawRectangle(-1, 0, 2, 1, skyColor);

    // Draw the land
    float landColor[] = {0.0f, 0.5f, 0.0f};
    drawRectangle(-1, -1, 2, 1, landColor);

    // Draw mountains
    float mountainColor[] = {0.5f, 0.3f, 0.2f};
    drawTriangle(-1, 0, -0.5, 1, 0, 0, mountainColor);
    drawTriangle(0, 0, 0.5, 1, 1, 0, mountainColor);

    // Draw the house
    drawHouse(1.5f);

    // Draw two trees on the sides of the house
    drawTree(-0.7, -0.6, 1.5f);
    drawTree(0.7, -0.6, 1.5f);

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 400);
    glutCreateWindow("Scenery with House and Trees");

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
