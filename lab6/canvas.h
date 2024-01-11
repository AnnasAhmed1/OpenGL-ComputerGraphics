#include <Gl/glut.h>

class Point2
{
public:
    Point2() { x = y = 0.0f; } // constructor1
    Point2(float xx, float yy)
    {
        x = xx;
        y = yy;
    } // constructor2
    void set(float xx, float yy)
    {
        x = xx;
        y = yy;
    }
    float getX() { return x; }
    float getY() { return y; }
    void draw()
    {
        glBegin(GL_POINTS); // draw this point
        glVertex2f((GLfloat)x, (GLfloat)y);
        glEnd();
        glFlush();
    }
    void drawArrowMarker(float x, float y, float size)
    {
        // Draw an arrow marker at the specified (x, y) position with the given size.
        // You can customize the arrow drawing code here.
        // This is a simple example that draws an arrowhead.

        float halfSize = size / 2.0f;
        glBegin(GL_TRIANGLES);
        glVertex2f(x, y + halfSize);
        glVertex2f(x - halfSize, y - halfSize);
        glVertex2f(x + halfSize, y - halfSize);
        glEnd();
        glFlush();
    }

private:
    float x, y;
};
class IntRect
{
public:
    IntRect()
    {
        l = 0;
        r = 100;
        b = 0;
        t = 100;
    } // constructors
    IntRect(int left, int right, int bottom, int top)
    {
        l = left;
        r = right;
        b = bottom;
        t = top;
    }
    void set(int left, int right, int bottom, int top)
    {
        l = left;
        r = right;
        b = bottom;
        t = top;
    }
    int getL() { return l; }
    int getR() { return r; }
    int getT() { return t; }
    int getB() { return b; }
    void draw()
    {
        glRecti((GLint)l, (GLint)b, (GLint)r, (GLint)t);
        glFlush();
    } // draw this rectangle using OpenGL
    void drawArrowMarker(float x, float y, float size)
    {
        // Draw an arrow marker at the specified (x, y) position with the given size.
        // You can customize the arrow drawing code here.
        // This is a simple example that draws an arrowhead.

        float halfSize = size / 2.0f;
        glBegin(GL_TRIANGLES);
        glVertex2f(x, y + halfSize);
        glVertex2f(x - halfSize, y - halfSize);
        glVertex2f(x + halfSize, y - halfSize);
        glEnd();
        glFlush();
    }

private:
    int l, r, b, t;
};
class RealRect
{
public:
    RealRect()
    {
        l = 0.0f;
        r = 100.0f;
        b = 0.0f;
        t = 100.0f;
    } // constructors
    RealRect(float left, float right, float bottom, float top)
    {
        l = left;
        r = right;
        b = bottom;
        t = top;
    }
    void set(float left, float right, float bottom, float top)
    {
        l = left;
        r = right;
        b = bottom;
        t = top;
    }
    float getL() { return l; }
    float getR() { return r; }
    float getT() { return t; }
    float getB() { return b; }
    void draw(void)
    {
        glRectf((GLdouble)l, (GLdouble)b, (GLdouble)r, (GLdouble)t);
        glFlush();
    } // draw this rectangle using OpenGL
     void drawArrowMarker(float x, float y, float size)
    {
        // Draw an arrow marker at the specified (x, y) position with the given size.
        // You can customize the arrow drawing code here.
        // This is a simple example that draws an arrowhead.

        float halfSize = size / 2.0f;
        glBegin(GL_TRIANGLES);
        glVertex2f(x, y + halfSize);
        glVertex2f(x - halfSize, y - halfSize);
        glVertex2f(x + halfSize, y - halfSize);
        glEnd();
        glFlush();
    }
private:
    float l, r, b, t;
};
class Canvas
{
public:
    Canvas(int width, int height, char *windowTitle); // constructor
    void setWindow(float l, float r, float b, float t);
    void setViewport(int l, int r, int b, int t);
    void clearScreen() { glClear(GL_COLOR_BUFFER_BIT); }
    void setBackgroundColor(float r, float g, float b) { glClearColor(r, g, b, 0.0); }
    void setColor(float r, float g, float b) { glColor3f(r, g, b); };
    void lineTo(float x, float y);
    void lineTo(Point2 p);
    void moveTo(float x, float y);
    void moveTo(Point2 p);
    void moveRel(float dx, float dy);
    void lineRel(float dx, float dy);
    // others later
private:
    Point2 CP;        // current position in the world
    IntRect viewport; // the current window
    RealRect window;  // the current viewport
    // others later
};
Canvas::Canvas(int width, int height, char *windowTitle)
{
    char *argv[1]; // dummy argument list for glutInit()
    char dummyString[8];

    argv[0] = dummyString; // hook up the pointer
    int argc = 1;          // to satisfy glutInit()
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(20, 20);
    glutCreateWindow(windowTitle);                // open the screen window
    setWindow(0, (float)width, 0, (float)height); // default world window
    setViewport(0, width, 0, height);             // default viewport
    CP.set(0.0f, 0.0f);                           // initialize the CP to (0,0)
}

void Canvas::moveTo(float x, float y)
{
    CP.set(x, y);
}

void Canvas::moveTo(Point2 p)
{
    CP.set(p.getX(), p.getY());
}
void Canvas::lineTo(float x, float y)
{
    glBegin(GL_LINES);
    glVertex2f((GLfloat)CP.getX(), (GLfloat)CP.getY());
    glVertex2f((GLfloat)x, (GLfloat)y); // draw the line
    glEnd();
    CP.set(x, y); // update the CP
    glFlush();
}
void Canvas::lineTo(Point2 p)
{
    glBegin(GL_LINES);
    glVertex2f((GLfloat)CP.getX(), (GLfloat)CP.getY());
    glVertex2f((GLfloat)p.getX(), (GLfloat)p.getY()); // draw the line
    glEnd();
    CP.set(p.getX(), p.getY()); // update the CP
    glFlush();
}
void Canvas::setWindow(float l, float r, float b, float t)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D((GLdouble)l, (GLdouble)r, (GLdouble)b, (GLdouble)t);
    window.set(l, r, b, t);
}

void Canvas::setViewport(int l, int r, int b, int t)
{
    glViewport((GLint)l, (GLint)b, (GLint)(r - l), (GLint)(t - b));
    viewport.set(l, r, b, t);
}
void Canvas ::moveRel(float dx, float dy)
{
    CP.set(CP.getX() + dx, CP.getY() + dy);
}

void Canvas ::lineRel(float dx, float dy)
{
    float x = CP.getX() + dx, y = CP.getY() + dy;

    lineTo(x, y);
    CP.set(x, y);
}
