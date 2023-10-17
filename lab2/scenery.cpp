#include <cstdio>
#include <math.h>
#include <vector>
#include <cstdlib>
#define PI 3.14159265358979323846
#include <gl/gl.h>
#include <gl/glut.h>

GLfloat left = 0, up = 0, sscale = 1;

GLfloat dangle = 0;

void PointLight(const float x, const float y, const float z, const float amb, const float diff, const float spec);
void PointLight(const float x, const float y, const float z, const float amb, const float diff, const float spec)
{
    glEnable(GL_LIGHTING);
    GLfloat light_ambient[] = {amb, amb, amb, 1.0};
    GLfloat light_position[] = {-0.9, .9, 0, 0.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHT0); // enable the light after setting the properties
}
GLfloat position22 = 0.0f;
GLfloat speed22 = 0.007f;

GLfloat position4 = 0.0f;
GLfloat speed4 = -0.01f;
void sunn(int value)
{
    if (position4 > 1.0)
        position4 = 0.0f;

    position4 += speed4;

    glutPostRedisplay();

    glutTimerFunc(100, sunn, 0);
}
GLfloat position3 = 0.0f;
GLfloat speed3 = -0.5f;

void rain(int value)
{
    if (position3 < -1.0)
        position3 = 1.0f;
    position3 += speed3;
    glutPostRedisplay();
    glutTimerFunc(100, rain, 0);
}

GLfloat position2 = 0.0f;
GLfloat speed2 = 0.004f;

void cloud(int value)
{
    if (position2 > 1.0)
        position2 = -1.0f;
    position2 += speed2;
    glutPostRedisplay();
    glutTimerFunc(100, cloud, 0);
}
GLfloat position1 = 1.0f;
GLfloat speed1 = -0.005f;
void boat(int value)
{
    if (position1 < -1.0)
        position1 = 1.0f;

    position1 += speed1;

    glutPostRedisplay();

    glutTimerFunc(100, boat, 0);
}
void cloud1()
{
    int i;

    GLfloat x = .5f;
    GLfloat y = .86f;
    GLfloat radius = .05f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 217, 255);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat a = .55f;
    GLfloat b = .83f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 217, 255);
    glVertex2f(a, b); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            a + (radius * cos(i * twicePi / triangleAmount)),
            b + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat c = .45f;
    GLfloat d = .83f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 217, 255);
    glVertex2f(c, d); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            c + (radius * cos(i * twicePi / triangleAmount)),
            d + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat e = .52f;
    GLfloat f = .8f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 217, 255);
    glVertex2f(e, f); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e + (radius * cos(i * twicePi / triangleAmount)),
            f + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat g = .6f;
    GLfloat h = .82f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 217, 255);
    glVertex2f(g, h); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            g + (radius * cos(i * twicePi / triangleAmount)),
            h + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}

void cloud2()
{
    // glLoadIdentity();
    int i;

    GLfloat x = -.5f;
    GLfloat y = .86f;
    GLfloat radius = .05f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 217, 255);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat a = -.55f;
    GLfloat b = .83f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 217, 255);
    glVertex2f(a, b); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            a + (radius * cos(i * twicePi / triangleAmount)),
            b + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat c = -.45f;
    GLfloat d = .83f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 217, 255);
    glVertex2f(c, d); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            c + (radius * cos(i * twicePi / triangleAmount)),
            d + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat e = -.52f;
    GLfloat f = .8f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 217, 255);
    glVertex2f(e, f); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e + (radius * cos(i * twicePi / triangleAmount)),
            f + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat g = -.6f;
    GLfloat h = .82f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 217, 255);
    glVertex2f(g, h); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            g + (radius * cos(i * twicePi / triangleAmount)),
            h + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}
void cloud3()
{
    // glLoadIdentity();
    int i;

    GLfloat x = 0.0f;
    GLfloat y = .86f;
    GLfloat radius = .05f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 217, 255);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat a = .05f;
    GLfloat b = .83f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 217, 255);
    glVertex2f(a, b); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            a + (radius * cos(i * twicePi / triangleAmount)),
            b + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat c = -0.05f;
    GLfloat d = .83f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 217, 255);
    glVertex2f(c, d); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            c + (radius * cos(i * twicePi / triangleAmount)),
            d + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat e = .02f;
    GLfloat f = .8f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 217, 255);
    glVertex2f(e, f); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e + (radius * cos(i * twicePi / triangleAmount)),
            f + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat g = .1f;
    GLfloat h = .82f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 217, 255);
    glVertex2f(g, h); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            g + (radius * cos(i * twicePi / triangleAmount)),
            h + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}
void sky()
{
    glBegin(GL_QUADS);
    glColor3ub(51, 204, 255);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(1.0f, 0.45f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();
}
void sky2()
{
    glBegin(GL_QUADS);
    glColor3ub(0, 51, 204);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(1.0f, 0.45f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();
}

void stars()
{
    glPointSize(2.5);
    glBegin(GL_POINTS);
    glColor3ub(255, 255, 255);
    glVertex2f(0.8f, 0.95f);
    glVertex2f(0.9f, 0.9f);
    glVertex2f(0.95f, 0.7f);
    glVertex2f(0.8f, 0.8f);
    glVertex2f(0.7f, 0.9f);
    glVertex2f(0.6f, 0.8f);
    glVertex2f(0.5f, 0.75f);
    glVertex2f(0.4f, 0.9f);
    glVertex2f(0.3f, 0.7f);
    glVertex2f(0.25f, 0.9f);
    glVertex2f(0.25f, 0.7f);
    glVertex2f(0.1f, 0.9f);
    glVertex2f(0.15f, 0.75f);
    glVertex2f(0.0f, 0.8f);
    glVertex2f(-0.7f, 0.9f);
    glVertex2f(-0.8f, 0.95f);
    glVertex2f(-0.4f, 0.8f);
    glVertex2f(-0.8f, 0.95f);
    glVertex2f(-0.9f, 0.9f);
    glVertex2f(-0.95f, 0.7f);
    glVertex2f(-0.8f, 0.8f);
    glVertex2f(-0.7f, 0.9f);
    glVertex2f(-0.6f, 0.8f);
    glVertex2f(-0.5f, 0.75f);
    glVertex2f(-0.4f, 0.9f);
    glVertex2f(-0.3f, 0.7f);
    glVertex2f(-0.25f, 0.9f);
    glVertex2f(-0.25f, 0.7f);
    glVertex2f(-0.15f, 0.75f);
    glVertex2f(-0.1f, 0.9f);
    glEnd();
}

void Shrink(void)
{
    sscale += -0.5;
    if (sscale <= 0.5)
    {
        sscale = 1;
    }
    glutPostRedisplay();
}
void star()
{

    glBegin(GL_POLYGON);
    glColor3ub(211, 211, 211);
    glVertex3f(0, -.02, 0.0);
    glVertex3f(-.019, -.00618, 0.0);
    glVertex3f(-.01174, .0162, 0.0);
    glVertex3f(.01174, .0162, 0.0);
    glVertex3f(.019, -.00618, 0.0);
    glEnd();

    glColor3ub(211, 211, 211);
    glBegin(GL_TRIANGLES);
    glVertex3f(-.01174, .0162, 0.0);
    glVertex3f(.01174, .0162, 0.0);
    glVertex3f(0, .065, 0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(-.019, -.00618, 0.0);
    glVertex3f(0, -.02, 0.0);
    glVertex3f(-.035, -.05, 0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(0, -.02, 0.0);
    glVertex3f(.019, -.00618, 0.0);
    glVertex3f(.035, -.05, 0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(.01174, .0162, 0.0);
    glVertex3f(.019, -.00618, 0.0);
    glVertex3f(.05, .0162, 0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(-.01174, .0162, 0.0);
    glVertex3f(-.019, -0.00618, 0.0);
    glVertex3f(-.05, .0162, 0.0);
    glEnd();
}

void starss()
{

    glPushMatrix();
    glTranslatef(0, .8, 0);
    glScalef(0.3, 0.3, 0);

    star();

    glPopMatrix();
}
void star_new()
{

    glPushMatrix();
    glTranslatef(0.3, 0, 0);

    starss();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(-.7, 0.25, 0);

    starss();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.3, 0.05, 0);

    starss();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.1, 0.1, 0);

    starss();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4, -0.3, 0);

    starss();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.6, -0.1, 0);

    starss();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.8, -0.2, 0);

    starss();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.7, -0.45, 0);

    starss();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.32, -0.15, 0);

    starss();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.45, 0.295, 0);

    starss();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5, 0, 0);

    starss();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.7, -0.2, 0);

    starss();

    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, -0.1, 0);

    starss();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.9, 0.35, 0);

    starss();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.5, 0.27, 0);

    starss();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.4, 0, 0);

    starss();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.67, -0.2, 0);

    starss();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.67, 0.15, 0);

    starss();

    glPopMatrix();
}

void moon()
{
    int i;

    GLfloat xx = -.5f;
    GLfloat yx = .93f;
    GLfloat radiusx = .06f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 51, 204);
    glVertex2f(xx, yx); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            xx + (radiusx * cos(i * twicePi / triangleAmount)),
            yx + (radiusx * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat x = -.5f;
    GLfloat y = .9f;
    GLfloat radius = .06f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(242, 242, 242);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}
void moon1()
{

    glPushMatrix();

    glTranslatef(1, 0, 0);
    // glScalef(0.75,0.75,1);
    // glRotatef(25, 1.0, 0.0, 0.0);

    moon(); // Reference white color object

    // Rotated object
    glPopMatrix();
}

void ground()
{
    glBegin(GL_POLYGON);
    glColor3ub(107, 142, 35);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.1f, -0.03);
    glVertex2f(0.2f, -0.07);
    glVertex2f(0.3f, -0.1); // 6
    glVertex2f(0.2f, -0.13);
    glVertex2f(0.1f, -0.17);
    glVertex2f(0.2f, -0.2);
    glVertex2f(0.35f, -0.23);
    glVertex2f(0.25f, -0.25);
    glVertex2f(0.18f, -0.28); // 12
    glVertex2f(0.3f, -0.32);
    glVertex2f(0.2f, -0.35);
    glVertex2f(0.4f, -0.4);
    glVertex2f(0.4f, -0.6);
    glVertex2f(0.2f, -0.65);
    glVertex2f(0.3f, -0.7);
    glVertex2f(0.2f, -0.75);
    glVertex2f(0.4f, -0.8);
    glVertex2f(0.2f, -0.85);
    glVertex2f(0.35f, -0.9);
    glVertex2f(0.25f, -0.95);
    glVertex2f(0.4f, -1.0);
    glVertex2f(0.25f, -0.95);
    glVertex2f(0.4f, -1.0);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 153, 102);
    glVertex2f(0.205f, -0.655);
    glVertex2f(0.4f, -0.6);
    glVertex2f(0.4f, -0.625);
    glVertex2f(0.25f, -0.675);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 153, 102);
    glVertex2f(0.3f, -0.7);
    glVertex2f(0.3f, -0.72);
    glVertex2f(0.24f, -0.7595);
    glVertex2f(0.2f, -0.75);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 153, 102);
    glVertex2f(0.4f, -0.8);
    glVertex2f(0.4f, -0.825);
    glVertex2f(0.2f, -0.8);
    glVertex2f(0.2f, -0.85);
    glEnd();
}
void river()
{
    glBegin(GL_QUADS);
    glColor3ub(38, 154, 214);
    // glColor3ub(0,122,204);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(1.0f, 0.45f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();
}
void hut()
{
    glColor3ub(153, 115, 0);
    glBegin(GL_TRIANGLES);
    glVertex3f(-.5, .2, 0.0);
    glVertex3f(-.1, .2, 0.0);
    glVertex3f(-.3, .5, 0.0);
    glEnd();

    glColor3ub(204, 153, 0);
    glBegin(GL_QUADS);

    glVertex3f(-0.45, -0.2, 0);
    glVertex3f(-0.15, -0.2, 0);
    glVertex3f(-.15, .2, 0);
    glVertex3f(-.45, .2, 0);
    glEnd();
    glColor3ub(153, 115, 0);
    glBegin(GL_QUADS);

    glVertex3f(-0.35, -0.2, 0);
    glVertex3f(-0.25, -0.2, 0);
    glVertex3f(-.25, .12, 0);
    glVertex3f(-.35, .12, 0);
    glEnd();
    glColor3ub(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(-0.30, .12, 0);
    glVertex3f(-0.30, -0.2, 0);
    glEnd();

    glColor3ub(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(-0.35, .12, 0);
    glVertex3f(-0.35, -0.2, 0);
    glEnd();

    glColor3ub(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(-0.25, .12, 0);
    glVertex3f(-0.25, -0.2, 0);
    glEnd();

    glColor3ub(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(-0.3, .5, 0);
    glVertex3f(-0.1, .2, 0);
    glEnd();
    glColor3ub(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(-0.3, .5, 0);
    glVertex3f(-0.5, .2, 0);
    glEnd();

    glColor3ub(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(-0.35, .12, 0);
    glVertex3f(-0.25, .12, 0);
    glEnd();
    glColor3ub(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(-0.1, .2, 0);
    glVertex3f(-0.5, .2, 0);
    glEnd();
    glColor3ub(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(-0.45, .2, 0);
    glVertex3f(-0.15, .2, 0);
    glEnd();
    glColor3ub(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(-0.15, .2, 0);
    glVertex3f(-0.15, -.2, 0);
    glEnd();
    glColor3ub(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(-0.45, .2, 0);
    glVertex3f(-0.45, -.2, 0);
    glEnd();
    glColor3ub(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(-0.15, -.2, 0);
    glVertex3f(-0.45, -.2, 0);
    glEnd();

    /* flush all of the drawing commands */
}
void hut1()
{
    glPushMatrix();

    glTranslatef(-.3, 0, 0);
    // glScalef(0.75,0.75,1);
    glRotatef(25, 1.0, 0.0, 0.0);

    hut(); // Reference white color object

    // Rotated object
    glPopMatrix();
}
void hut2()
{
    glPushMatrix();

    glTranslatef(-.3, 0, 0);
    glScalef(0.75, 0.75, 1);
    // glRotatef(25, 1.0, 0.0, 0.0);

    hut(); // Reference white color object

    // Rotated object
    glPopMatrix();
}

void tree()
{
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f, -0.15f);
    glVertex2f(-0.65f, -0.2f);
    glVertex2f(-0.735f, -0.17f);
    glVertex2f(-0.74f, -0.25f);
    glVertex2f(-0.775f, -0.17f);
    glVertex2f(-0.85f, -0.2f);
    glVertex2f(-0.78f, -0.15f);
    // glVertex2f(-0.7f,-0.25f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f, -0.15f);
    glVertex2f(-0.78f, 0.23f);
    glVertex2f(-0.72f, 0.23f);
    glVertex2f(-0.72f, -0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f, 0.23f);
    glVertex2f(-0.76f, 0.3f);
    glVertex2f(-0.74f, 0.3f);
    glVertex2f(-0.74f, 0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f, 0.23f);
    glVertex2f(-0.71f, 0.29f);
    glVertex2f(-0.7f, 0.28f);
    glVertex2f(-0.72f, 0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f, 0.23f);
    glVertex2f(-0.8f, 0.28f);
    glVertex2f(-0.79f, 0.29f);
    glVertex2f(-0.76f, 0.23f);
    glEnd();

    int i;

    GLfloat x = -.75f;
    GLfloat y = .33f;
    GLfloat radius = .06f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(34, 139, 34);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat a = -.68f;
    GLfloat b = .31f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(34, 139, 34);
    glVertex2f(a, b); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            a + (radius * cos(i * twicePi / triangleAmount)),
            b + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat c = -.81f;
    GLfloat d = .31f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(34, 139, 34);
    glVertex2f(c, d); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            c + (radius * cos(i * twicePi / triangleAmount)),
            d + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat e = -.87f;
    GLfloat f = .35f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(34, 139, 34);
    glVertex2f(e, f); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e + (radius * cos(i * twicePi / triangleAmount)),
            f + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat g = -.61f;
    GLfloat h = .35f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(34, 139, 34);
    glVertex2f(g, h); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            g + (radius * cos(i * twicePi / triangleAmount)),
            h + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    GLfloat a1 = -.61f;
    GLfloat b1 = .4f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(34, 139, 34);
    glVertex2f(a1, b1); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            a1 + (radius * cos(i * twicePi / triangleAmount)),
            b1 + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat c1 = -.88f;
    GLfloat d1 = .4f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(34, 139, 34);
    glVertex2f(c, d); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            c1 + (radius * cos(i * twicePi / triangleAmount)),
            d1 + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat e1 = -.87f;
    GLfloat f1 = .44f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(34, 139, 34);
    glVertex2f(e1, f1); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e1 + (radius * cos(i * twicePi / triangleAmount)),
            f1 + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat g1 = -.61f;
    GLfloat h1 = .4f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(34, 139, 34);
    glVertex2f(g, h); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            g1 + (radius * cos(i * twicePi / triangleAmount)),
            h1 + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    GLfloat e11 = -.64f;
    GLfloat f11 = .44f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(34, 139, 34);
    glVertex2f(e11, f11); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e11 + (radius * cos(i * twicePi / triangleAmount)),
            f11 + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat e12 = -.75f;
    GLfloat f12 = .44f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(34, 139, 34);
    glVertex2f(e12, f12); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e12 + (radius * cos(i * twicePi / triangleAmount)),
            f12 + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(34, 139, 34);
    glVertex2f(-0.85f, 0.33f);
    glVertex2f(-0.85f, 0.44f);
    glVertex2f(-0.65f, 0.44f);
    glVertex2f(-0.65f, 0.33f);
    glEnd();

    GLfloat e123 = -.8f;
    GLfloat f123 = .5f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(34, 139, 34);
    glVertex2f(e123, f123); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e123 + (radius * cos(i * twicePi / triangleAmount)),
            f123 + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    GLfloat e1232 = -.7f;
    GLfloat f1232 = .5f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(34, 139, 34);
    glVertex2f(e1232, f1232); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e1232 + (radius * cos(i * twicePi / triangleAmount)),
            f1232 + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}
void tree1()
{
    glPushMatrix();

    glTranslatef(-.05, 0, 0);
    glScalef(1.2, 1.2, 0);
    // glRotatef(25, 1.0, 0.0, 0.0);

    tree(); // Reference white color object

    // Rotated object
    glPopMatrix();
}
void tree2()
{
    glPushMatrix();

    glTranslatef(-.1, 0, 0);

    tree(); // Reference white color object

    // Rotated object
    glPopMatrix();
}

void boat()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.2f, 0.4f);
    glVertex2f(-0.15f, 0.35f);
    glVertex2f(0.15f, 0.35f);
    glVertex2f(0.2f, 0.4f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 153, 0);
    glVertex2f(-0.13f, 0.4f);
    glVertex2f(-0.11f, 0.48f);
    glVertex2f(-0.088f, 0.52f);
    glVertex2f(0.13f, 0.52f);
    glVertex2f(0.14f, 0.49f);
    glVertex2f(0.15f, 0.4f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 25, 25);
    glVertex2f(-0.038f, 0.57f);
    glVertex2f(-0.038f, 0.73f);
    glVertex2f(-0.035f, 0.75f);
    glVertex2f(0.064f, 0.73f);
    glVertex2f(0.065f, 0.71f);
    glVertex2f(0.065f, 0.55f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(136, 204, 0);
    glVertex2f(0.0f, 0.52f);
    glVertex2f(0.0f, 0.79f);
    glVertex2f(0.01f, 0.79f);
    glVertex2f(0.01f, 0.52f);
    glEnd();
}
void boat2()
{

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(0.63f, -0.53f);
    glVertex2f(0.53f, -0.53f);
    glVertex2f(0.43f, -0.5f);
    glVertex2f(0.53f, -0.6f);
    glVertex2f(0.78f, -0.6f);
    glVertex2f(0.88f, -0.5f);
    glVertex2f(0.78f, -0.53f);
    glVertex2f(0.73f, -0.53f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(122, 122, 82);
    glVertex2f(0.43f, -0.5f);
    glVertex2f(0.53f, -0.53f);
    glVertex2f(0.63f, -0.53f);
    glVertex2f(0.73f, -0.53f);
    glVertex2f(0.78f, -0.53f);
    glVertex2f(0.88f, -0.5f); ////
    glVertex2f(0.78f, -0.48f);
    glVertex2f(0.73f, -0.48f);
    glVertex2f(0.63f, -0.48f);
    glVertex2f(0.53f, -0.48f);
    glVertex2f(0.43f, -0.5f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(0.88f, -0.5f); ////
    glVertex2f(0.78f, -0.48f);
    glVertex2f(0.78f, -0.48f);
    glVertex2f(0.73f, -0.48f);
    glVertex2f(0.73f, -0.48f);
    glVertex2f(0.63f, -0.48f);
    glVertex2f(0.63f, -0.48f);
    glVertex2f(0.53f, -0.48f);
    glVertex2f(0.53f, -0.48f);
    glVertex2f(0.43f, -0.5f);
    glEnd();

    glLineWidth(9);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(0.53f, -0.48f);
    glVertex2f(0.53f, -0.535f);
    glVertex2f(0.63f, -0.48f);
    glVertex2f(0.63f, -0.535f);
    glVertex2f(0.73f, -0.48f);
    glVertex2f(0.73f, -0.535f);
    glVertex2f(0.81f, -0.48f);
    glVertex2f(0.81f, -0.535f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(204, 153, 0);
    glVertex2f(0.38f, -0.38f);
    glVertex2f(0.4f, -0.53f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(153, 153, 102);
    glVertex2f(0.38f, -0.42f);
    glVertex2f(0.43f, -0.5f);
    glEnd();
}
void boat3()
{
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(0.88f, -0.5f); ////
    glVertex2f(0.78f, -0.48f);
    glVertex2f(0.78f, -0.48f);
    glVertex2f(0.73f, -0.48f);
    glVertex2f(0.73f, -0.48f);
    glVertex2f(0.63f, -0.48f);
    glVertex2f(0.63f, -0.48f);
    glVertex2f(0.53f, -0.48f);
    glVertex2f(0.53f, -0.48f);
    glVertex2f(0.43f, -0.5f);
    glEnd();

    glLineWidth(9);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(0.53f, -0.48f);
    glVertex2f(0.53f, -0.535f);
    glVertex2f(0.63f, -0.48f);
    glVertex2f(0.63f, -0.535f);
    glVertex2f(0.73f, -0.48f);
    glVertex2f(0.73f, -0.535f);
    glVertex2f(0.81f, -0.48f);
    glVertex2f(0.81f, -0.535f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(204, 153, 0);
    glVertex2f(0.38f, -0.38f);
    glVertex2f(0.4f, -0.53f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(153, 153, 102);
    glVertex2f(0.38f, -0.42f);
    glVertex2f(0.43f, -0.5f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(0.63f, -0.53f);
    glVertex2f(0.53f, -0.53f);
    glVertex2f(0.43f, -0.5f);
    glVertex2f(0.53f, -0.6f);
    glVertex2f(0.78f, -0.6f);
    glVertex2f(0.88f, -0.5f);
    glVertex2f(0.78f, -0.53f);
    glVertex2f(0.73f, -0.53f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(122, 122, 82);
    glVertex2f(0.43f, -0.5f);
    glVertex2f(0.53f, -0.53f);
    glVertex2f(0.63f, -0.53f);
    glVertex2f(0.73f, -0.53f);
    glVertex2f(0.78f, -0.53f);
    glVertex2f(0.88f, -0.5f); ////
    glVertex2f(0.78f, -0.48f);
    glVertex2f(0.73f, -0.48f);
    glVertex2f(0.63f, -0.48f);
    glVertex2f(0.53f, -0.48f);
    glVertex2f(0.43f, -0.5f);
    glEnd();
}

void boat4()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(0.3f, -0.25f);
    glVertex2f(0.35f, -0.3f);
    glVertex2f(0.65f, -0.3f);
    glVertex2f(0.7f, -0.25f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 153, 0);
    glVertex2f(0.37f, -0.25f);
    glVertex2f(0.39f, -0.17f);
    glVertex2f(0.412f, -0.13f);
    glVertex2f(0.63f, -0.13f);
    glVertex2f(0.64f, -0.16f);
    glVertex2f(0.65f, -0.25f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 25, 25);
    glVertex2f(0.462f, -0.08f);
    glVertex2f(0.462f, 0.08f);
    glVertex2f(0.465f, 0.1f);
    glVertex2f(0.564f, 0.08f);
    glVertex2f(0.565f, 0.06f);
    glVertex2f(0.565f, -0.1f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(136, 204, 0);
    glVertex2f(0.5f, -0.13f);
    glVertex2f(0.5f, 0.14f);
    glVertex2f(0.51f, 0.14f);
    glVertex2f(0.51f, -0.13f);
    glEnd();
}

void way()
{
    glBegin(GL_QUADS);
    glColor3ub(153, 153, 102);
    glVertex2f(-0.35f, -0.2f);
    glVertex2f(-0.22f, -0.2f);
    glVertex2f(-0.28f, -0.5f);
    glVertex2f(-0.43f, -0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 153, 102);
    glVertex2f(-0.43f, -0.5f);
    glVertex2f(-0.75f, -1.0f);
    glVertex2f(-0.56f, -1.0f);
    glVertex2f(-0.28f, -0.5f);
    glEnd();
}

void fence()
{
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 102);
    glVertex2f(-1.0f, -0.1f);
    glVertex2f(-0.6f, -0.1f);

    glColor3ub(255, 255, 102);
    glVertex2f(-1.0f, -0.05f);
    glVertex2f(-0.6f, -0.05f);

    glColor3ub(255, 255, 102);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(-0.6f, 0.0f);

    glColor3ub(255, 255, 102);
    glVertex2f(-1.0f, 0.05f);
    glVertex2f(-0.6f, 0.05f);

    glColor3ub(255, 255, 102);
    glVertex2f(-1.0f, 0.1f);
    glVertex2f(-0.6f, 0.1f);

    glColor3ub(255, 255, 102);
    glVertex2f(-0.95f, 0.13f);
    glVertex2f(-0.95f, -0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(-0.9f, 0.13f);
    glVertex2f(-0.9f, -0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(-0.85f, 0.13f);
    glVertex2f(-0.85f, -0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(-0.8f, 0.13f);
    glVertex2f(-0.8f, -0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(-0.75f, 0.13f);
    glVertex2f(-0.75f, -0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(-0.7f, 0.13f);
    glVertex2f(-0.7f, -0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(-0.65f, 0.13f);
    glVertex2f(-0.65f, -0.12f);

    glEnd();
}

void well()
{

    glBegin(GL_POLYGON);
    glColor3ub(205, 133, 63);
    glVertex2f(-0.9f, -0.35f);
    glVertex2f(-0.9f, -0.55f);
    glVertex2f(-0.85f, -0.575f);
    glVertex2f(-0.8f, -0.59f);
    glVertex2f(-0.7f, -0.59f);
    glVertex2f(-0.65f, -0.575f);
    glVertex2f(-0.6f, -0.55f);
    glVertex2f(-0.6f, -0.35f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(38, 154, 214);
    glVertex2f(-0.9f, -0.35f);
    glVertex2f(-0.85f, -0.375f);
    glVertex2f(-0.8f, -0.38f);
    glVertex2f(-0.7f, -0.38f);
    glVertex2f(-0.65f, -0.375f);
    glVertex2f(-0.6f, -0.35f);
    glVertex2f(-0.65f, -0.33f);
    glVertex2f(-0.7f, -0.325f);
    glVertex2f(-0.8f, -0.325f);
    glVertex2f(-0.85f, -0.33f);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(205, 133, 63);
    glVertex2f(-0.9f, -0.35f);
    glVertex2f(-0.85f, -0.33f); //
    glVertex2f(-0.85f, -0.33f);
    glVertex2f(-0.8f, -0.325f); //
    glVertex2f(-0.8f, -0.325f);
    glVertex2f(-0.7f, -0.325f); //
    glVertex2f(-0.7f, -0.325f);
    glVertex2f(-0.65f, -0.33f); //
    glVertex2f(-0.65f, -0.33f);
    glVertex2f(-0.6f, -0.35f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(194, 194, 163);
    glVertex2f(-0.59f, -0.43f);
    glVertex2f(-0.57f, -0.5f);
    glVertex2f(-0.52f, -0.5f);
    glVertex2f(-0.5f, -0.43f);
    glVertex2f(-0.52f, -0.42f);
    glVertex2f(-0.57f, -0.42f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(38, 154, 214);
    glVertex2f(-0.585f, -0.43f);
    glVertex2f(-0.568f, -0.44f);
    glVertex2f(-0.528f, -0.44f);
    glVertex2f(-0.505f, -0.43f);
    glVertex2f(-0.528f, -0.425f);
    glVertex2f(-0.57f, -0.425f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(194, 194, 163);
    glVertex2f(-0.59f, -0.43f);
    glVertex2f(-0.57f, -0.39f); //
    glVertex2f(-0.57f, -0.39f);
    glVertex2f(-0.55f, -0.39f); //
    glVertex2f(-0.55f, -0.39f);
    glVertex2f(-0.52f, -0.39f); //
    glVertex2f(-0.52f, -0.39f);
    glVertex2f(-0.5f, -0.43f); //
    glEnd();

    glLineWidth(2.5);
    glBegin(GL_LINES);
    glColor3ub(230, 172, 0);
    glVertex2f(-0.545f, -0.385f);
    glVertex2f(-0.57f, -0.45f); //
    glVertex2f(-0.57f, -0.45f);
    glVertex2f(-0.575f, -0.5f); //
    glVertex2f(-0.575f, -0.5f);
    glVertex2f(-0.58f, -0.53f); //
    glVertex2f(-0.58f, -0.53f);
    glVertex2f(-0.57f, -0.55f); //
    glVertex2f(-0.57f, -0.55f);
    glVertex2f(-0.48f, -0.53f); //
    glEnd();
}

void well1()
{

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(205, 133, 63);
    glVertex2f(-0.9f, -0.35f);
    glVertex2f(-0.85f, -0.33f); //
    glVertex2f(-0.85f, -0.33f);
    glVertex2f(-0.8f, -0.325f); //
    glVertex2f(-0.8f, -0.325f);
    glVertex2f(-0.7f, -0.325f); //
    glVertex2f(-0.7f, -0.325f);
    glVertex2f(-0.65f, -0.33f); //
    glVertex2f(-0.65f, -0.33f);
    glVertex2f(-0.6f, -0.35f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(194, 194, 163);
    glVertex2f(-0.59f, -0.43f);
    glVertex2f(-0.57f, -0.39f); //
    glVertex2f(-0.57f, -0.39f);
    glVertex2f(-0.55f, -0.39f); //
    glVertex2f(-0.55f, -0.39f);
    glVertex2f(-0.52f, -0.39f); //
    glVertex2f(-0.52f, -0.39f);
    glVertex2f(-0.5f, -0.43f); //
    glEnd();

    glLineWidth(2.5);
    glBegin(GL_LINES);
    glColor3ub(230, 172, 0);
    glVertex2f(-0.545f, -0.385f);
    glVertex2f(-0.57f, -0.45f); //
    glVertex2f(-0.57f, -0.45f);
    glVertex2f(-0.575f, -0.5f); //
    glVertex2f(-0.575f, -0.5f);
    glVertex2f(-0.58f, -0.53f); //
    glVertex2f(-0.58f, -0.53f);
    glVertex2f(-0.57f, -0.55f); //
    glVertex2f(-0.57f, -0.55f);
    glVertex2f(-0.48f, -0.53f); //
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205, 133, 63);
    glVertex2f(-0.585f, -0.43f);
    glVertex2f(-0.568f, -0.44f);
    glVertex2f(-0.528f, -0.44f);
    glVertex2f(-0.505f, -0.43f);
    glVertex2f(-0.528f, -0.425f);
    glVertex2f(-0.57f, -0.425f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205, 133, 63);
    glVertex2f(-0.9f, -0.35f);
    glVertex2f(-0.9f, -0.55f);
    glVertex2f(-0.85f, -0.575f);
    glVertex2f(-0.8f, -0.59f);
    glVertex2f(-0.7f, -0.59f);
    glVertex2f(-0.65f, -0.575f);
    glVertex2f(-0.6f, -0.55f);
    glVertex2f(-0.6f, -0.35f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(38, 154, 214);
    glVertex2f(-0.9f, -0.35f);
    glVertex2f(-0.85f, -0.375f);
    glVertex2f(-0.8f, -0.38f);
    glVertex2f(-0.7f, -0.38f);
    glVertex2f(-0.65f, -0.375f);
    glVertex2f(-0.6f, -0.35f);
    glVertex2f(-0.65f, -0.33f);
    glVertex2f(-0.7f, -0.325f);
    glVertex2f(-0.8f, -0.325f);
    glVertex2f(-0.85f, -0.33f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(194, 194, 163);
    glVertex2f(-0.59f, -0.43f);
    glVertex2f(-0.57f, -0.5f);
    glVertex2f(-0.52f, -0.5f);
    glVertex2f(-0.5f, -0.43f);
    glVertex2f(-0.52f, -0.42f);
    glVertex2f(-0.57f, -0.42f);
    glEnd();
}
void well2()
{
    glPushMatrix();

    glTranslatef(.45, .04, 0);
    glScalef(.65, .65, 0);
    // glRotatef(45, 0.0, 1.0, 0.0);

    well(); // Reference white color object

    // Rotated object
    glPopMatrix();
}
void well3()
{
    glPushMatrix();

    glTranslatef(.45, .04, 0);
    glScalef(.65, .65, 0);
    well1(); // Reference white color object

    // Rotated object
    glPopMatrix();
}

void man()
{
    // glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(244, 164, 96);
    glPushMatrix();
    // glColor3f(1,0,0);
    glScalef(1, 1.8, 0);
    glutSolidSphere(.03, 100, 10);

    glPopMatrix();
    glEnd();

    glLineWidth(10);
    glColor3ub(244, 164, 96);
    glBegin(GL_LINES); // body
    glVertex3f(0, -0.05, 0);
    glVertex3f(0, -.2, 0);
    glEnd();

    // glRotatef(-2.5, 0.0, 0.0, 1.0);
    glBegin(GL_LINES); // left leg

    glVertex3f(0, -0.19, 0);
    glVertex3f(-0.02, -.24, 0); //
    glEnd();
    glBegin(GL_LINES); // right leg

    glVertex3f(0, -0.19, 0);
    glVertex3f(0.02, -.24, 0);
    glEnd();

    glBegin(GL_LINES);

    glVertex3f(0, -0.1, 0);
    glVertex3f(0.04, -.08, 0); // upper hand
    glEnd();
    glBegin(GL_LINES); // lower hand

    glVertex3f(0, -0.1, 0);
    glVertex3f(0.04, -.12, 0);
    glEnd();
    glLineWidth(4);
    glColor3ub(128, 0, 128);
    glBegin(GL_LINES); // umbrella stick

    glVertex3f(0.04, -0.13, 0);
    glVertex3f(0.04, .08, 0);
    glEnd();

    glBegin(GL_LINES); // st line

    glVertex3f(-0.05, .08, 0);
    glVertex3f(0.13, .08, 0);
    glEnd();
    glBegin(GL_TRIANGLES);

    glVertex3f(-0.05, .08, 0);
    glVertex3f(0.13, .08, 0);
    glVertex3f(0.04, .17, 0);
    glEnd();
    glBegin(GL_TRIANGLES);

    glVertex3f(-0.05, .08, 0);

    glVertex3f(0.04, .17, 0);
    glVertex3f(0.00, .16, 0);

    glEnd();
    glBegin(GL_TRIANGLES);

    glVertex3f(0.13, .08, 0);
    glVertex3f(0.08, .16, 0);
    glVertex3f(0.04, .17, 0);

    glEnd();

    glFlush();
}
void human()
{

    glPushMatrix();

    glTranslatef(-0.7, -0.5, 0);
    // glScalef(0.75,0.75,1);
    // glRotatef(25, 1.0, 0.0, 0.0);

    man(); // Reference white color object

    // Rotated object
    glPopMatrix();
}
void sun_new()
{
    glColor3ub(194, 194, 163);
    glPushMatrix();
    glColor3f(1, 0, 0);
    glScalef(2, 3, 0);
    glutSolidSphere(.03, 100, 10);
    glPopMatrix();
    glEnd();
}
void sun()
{
    glPushMatrix();

    glTranslatef(0, 0.85, 0);
    // glScalef(0.75,0.75,1);
    // glRotatef(25, 1.0, 0.0, 0.0);

    sun_new(); // Reference white color object

    // Rotated object
    glPopMatrix();
}

void DrawSphere()
{
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(position2, 0.0f, 0.0f);
    cloud3();
    glPopMatrix();
    moon1();
    // sun();
    boat4();
    boat3();
    hut();
    hut2();

    tree();
    tree1();
    tree2();

    fence();
    human();

    way();
    well3();

    ground();
    river();

    glScalef(sscale, sscale, 0);
    star_new();
    sky2();
    glFlush();
}

void display2()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    PointLight(0, 0, 1, 0, 1, 1);
    DrawSphere();
    glLoadIdentity();
    glutSwapBuffers();
}

struct Point
{
    float x, y;
    unsigned char r, g, b, a;
};
std::vector<Point> points;

void display1(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glLineWidth(2);
    sky();
    cloud1();
    cloud2();
    cloud3();

    river();
    ground();

    way();
    boat2();
    fence();

    well2();
    human();
    hut();
    hut1();
    tree();
    tree1();
    tree2();

    glOrtho(-50, 50, -50, 50, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // draw
    glPushMatrix();
    glTranslatef(0.0f, position3, 0.0f);
    glColor3ub(255, 255, 255);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(2, GL_FLOAT, sizeof(Point), &points[0].x);
    glColorPointer(4, GL_UNSIGNED_BYTE, sizeof(Point), &points[0].r);
    glPointSize(1.5);
    glDrawArrays(GL_POINTS, 0, points.size());
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}

void display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glLineWidth(2);
    sky();
    sun();
    glPushMatrix();
    glTranslatef(position2, 0.0f, 0.0f);
    cloud1();
    cloud2();
    glPopMatrix();

    river();
    glPushMatrix();
    glTranslatef(position1, 0.0f, 0.0f);
    boat();
    glPopMatrix();
    ground();
    way();

    boat2();
    fence();

    well2();

    hut();
    hut1();
    tree();
    tree1();
    tree2();
    glPushMatrix();
    glTranslatef(position1, 0.0f, 0.0f);
    human();
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}
void reshape(int w, int h)
{
    //    std::cout<<"Reshape is called"<<std::endl;
    float aspectRatio = (float)w / (float)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(145, aspectRatio, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void Display(void)
{
    // std::cout<<"Display 1 called"<<std::endl;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0, 0, -20);

    glFlush();
    glutSwapBuffers();
}

void init(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_LIGHT0);
    // std::cout<<"Init is called"<<std::endl;
}
void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'd':
        glutDestroyWindow(1);
        glutInitWindowSize(1240, 750);
        glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 1240) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - 750) / 2);
        glutCreateWindow("village scenario");
        glutKeyboardFunc(handleKeypress);
        glutDisplayFunc(display);
        break;
        break;
    case 'r':
        glutDestroyWindow(1);
        glutInitWindowSize(1240, 750);
        glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 1240) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - 750) / 2);
        glutCreateWindow("village scenario");
        glutKeyboardFunc(handleKeypress);
        glutDisplayFunc(display1);
        break;
    case 'n':
        glutDestroyWindow(1);
        glutInitWindowSize(1240, 750);
        glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 1240) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - 750) / 2);
        glutCreateWindow("village scenario");
        glutKeyboardFunc(handleKeypress);
        glutDisplayFunc(display2);
        glutPostRedisplay();
        break;
    case 'D':
        glutDestroyWindow(1);
        glutInitWindowSize(1240, 750);
        glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 1240) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - 750) / 2);
        glutCreateWindow("village scenario");
        glutKeyboardFunc(handleKeypress);
        glutDisplayFunc(display);
        break;
        break;
    case 'R':
        glutDestroyWindow(1);
        glutInitWindowSize(1240, 750);
        glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 1240) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - 750) / 2);
        glutCreateWindow("village scenario");
        glutKeyboardFunc(handleKeypress);
        glutDisplayFunc(display1);
        break;
    case 'N':
        glutDestroyWindow(1);
        glutInitWindowSize(1240, 750);
        glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 1240) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - 750) / 2);
        glutCreateWindow("village scenario");
        glutKeyboardFunc(handleKeypress);
        glutDisplayFunc(display2);
        glutPostRedisplay();
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1240, 750);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 1240) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - 750) / 2);
    glutCreateWindow("village scenario");
    init();
    glutReshapeFunc(reshape);
    glutDisplayFunc(Display);
    for (size_t i = 0; i < 1000; ++i)
    {
        Point pt;
        pt.x = -50 + (rand() % 100);
        pt.y = -50 + (rand() % 100);
        pt.r = 255;
        pt.g = 255;
        pt.b = 255;
        pt.a = 255;
        points.push_back(pt);
    }
    glutTimerFunc(100, cloud, 0);
    glutTimerFunc(100, sunn, 0);
    glutTimerFunc(100, boat, 0);
    glutTimerFunc(100, rain, 0);

    glutKeyboardFunc(handleKeypress);
    init();
    glutMainLoop();
    return 0;
}