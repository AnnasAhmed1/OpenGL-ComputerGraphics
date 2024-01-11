#include "canvas.h"

char windowTitle[] = "Spider Game";
Canvas cv(screenWidth, screenHeight, windowTitle);

void myInit(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glColor3f(0, 0, 0);
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_EQUAL, 1.0);
    glViewport(0, 0, 640, 480);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void drawBullet(float width, float height)
{

    cv.moveTo(screenWidth / 2, 2);
    cv.lineTo((screenWidth / 2) + width, 2);
    cv.lineTo((screenWidth / 2) + width, height + 2);
    cv.lineTo((screenWidth / 2) + width / 2, height + width + 2);
    cv.lineTo((screenWidth / 2), height + 2);
    cv.lineTo(screenWidth / 2, 0 + 2);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    drawBullet(10, 40);
    spider.pix[1].mDraw();

    glFlush();
}

void spinner(int t)
{
    glutPostRedisplay();
    glutTimerFunc(500, spinner, t);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Spider Killer :)");

    glutDisplayFunc(display);
    // glutSpecialFunc(mySpecialKeyHandler);
    // glutSpecialUpFunc(mySpecialKeyRelease);

    myInit();
    // glutIdleFunc(display);
    glutMainLoop();
}
