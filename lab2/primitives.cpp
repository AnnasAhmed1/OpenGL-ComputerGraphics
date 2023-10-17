#include <iostream>
#include <cmath>
#include <GL/glut.h>
using namespace std;

int screenWidth = 800; // You can choose any value you prefer
int screenHeight = 400;

void drawTriangle(float x, float y)
{
    // Set the drawing color (e.g., red)
    glColor3f(1.0f, 0.0f, 0.0f);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Draw a triangle
    glBegin(GL_TRIANGLES);
    glVertex2f(x - 0.05f, y + 0.1f); // Top vertex
    glVertex2f(x - 0.15f, y - 0.1f); // Bottom-left vertex
    glVertex2f(x + 0.05f, y - 0.1f); // Bottom-right vertex
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void drawQuad(float x, float y)
{
    // Set the drawing color (e.g., green)
    glColor3f(0.0f, 1.0f, 0.0f);

    // Draw a quad
    glBegin(GL_QUADS);
    glVertex2f(x - 0.1f, y + 0.1f); // Top-left vertex
    glVertex2f(x + 0.1f, y + 0.1f); // Top-right vertex
    glVertex2f(x + 0.1f, y - 0.1f); // Bottom-right vertex
    glVertex2f(x - 0.1f, y - 0.1f); // Bottom-left vertex
    glEnd();
}

void drawLineStrip(float x, float y)
{
    // Set the drawing color (e.g., blue)
    glColor3f(0.0f, 0.0f, 1.0f);

    // Draw a line strip
    glBegin(GL_LINE_STRIP);
    glVertex2f(x - 0.1f, y + 0.1f);  // First point
    glVertex2f(x - 0.05f, y - 0.1f); // Second point
    glVertex2f(x + 0.0f, y + 0.1f);  // Third point
    glVertex2f(x + 0.05f, y - 0.1f); // Fourth point
    glEnd();
}

void drawPolygon(float x, float y)
{
    // Set the drawing color (e.g., purple)
    glColor3f(0.5f, 0.0f, 0.5f);

    // Increase the size of the polygon (scaling factor)
    float scale = 1.5f;

    // Draw a polygon (hexagon in this case)
    glBegin(GL_POLYGON);
    for (int i = 0; i < 6; i++)
    {
        float angle = 2.0f * M_PI * i / 6;
        float px = x + scale * 0.1f * cos(angle);
        float py = y + scale * 0.1f * sin(angle);
        glVertex2f(px, py);
    }
    glEnd();
}

void drawLabel(float x, float y, const char *text)
{
    // Set the drawing color (e.g., white)
    glColor3f(1.0f, 1.0f, 1.0f);

    // Set the position for the first character
    glRasterPos2f(x, y);

    // Loop through each character in the text and render it
    for (int i = 0; text[i] != '\0'; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
    }
}
void drawTriangleStrip(float x, float y)
{
    // Set the drawing color (e.g., orange)
    glColor3f(1.0f, 0.5f, 0.0f);

    // Draw a triangle strip
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(x - 0.05f, y + 0.1f); // First point
    glVertex2f(x - 0.15f, y - 0.1f); // Second point
    glVertex2f(x + 0.05f, y + 0.1f); // Third point
    glVertex2f(x + 0.15f, y - 0.1f); // Fourth point
    glEnd();
}

void drawTriangleFan(float x, float y)
{
    // Set the drawing color (e.g., yellow)
    glColor3f(1.0f, 1.0f, 0.0f);

    // Draw a triangle fan
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);                // Center point
    glVertex2f(x + 0.05f, y + 0.1f); // First point
    glVertex2f(x - 0.15f, y - 0.1f); // Second point
    glVertex2f(x + 0.05f, y - 0.2f); // Third point
    glVertex2f(x + 0.15f, y - 0.1f); // Fourth point
    glEnd();
}

void drawQuadStrip(float x, float y)
{
    // Set the drawing color (e.g., cyan)
    glColor3f(0.0f, 1.0f, 1.0f);

    // Draw a quad strip
    glBegin(GL_QUAD_STRIP);
    glVertex2f(x - 0.1f, y + 0.1f);   // First top-left vertex
    glVertex2f(x + 0.1f, y + 0.1f);   // First top-right vertex
    glVertex2f(x - 0.1f, y - 0.1f);   // First bottom-left vertex
    glVertex2f(x + 0.1f, y - 0.1f);   // First bottom-right vertex
    glVertex2f(x + 0.15f, y + 0.15f); // Second top-left vertex
    glVertex2f(x + 0.25f, y + 0.15f); // Second top-right vertex
    glVertex2f(x + 0.15f, y - 0.15f); // Second bottom-left vertex
    glVertex2f(x + 0.25f, y - 0.15f); // Second bottom-right vertex
    glEnd();
}

void myDisplay(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the shapes and labels
    drawTriangle(0.6f, 0.0f);
    drawLabel(0.6f, 0.0f, "Points");

    drawQuad(-0.6f, 0.0f);
    drawLabel(-0.6f, 0.0f, "Quad");

    drawLineStrip(0.0f, 0.0f);
    drawLabel(0.0f, 0.0f, "Line Strip");

    drawPolygon(-0.6f, -0.6f);
    drawLabel(-0.6f, -0.6f, "Polygon");

    drawTriangleStrip(0.0f, -0.6f);
    drawLabel(0.0f, -0.6f, "Triangle Strip");

    // drawTriangleFan(0.6f, -0.6f);
    // drawLabel(0.6f, -0.6f, "Triangle Fan");

    // drawQuadStrip(0.0f, 0.0f);
    // drawLabel(-0.6f, -1.2f, "Quad Strip");

    // Add more shapes and labels as needed

    // Flush the rendering pipeline
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(30, 30);
    glutCreateWindow("Shapes Example");

    glutDisplayFunc(myDisplay);

    glutMainLoop();

    return 0;
}
