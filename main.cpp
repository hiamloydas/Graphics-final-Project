#include <GL/glut.h>
#include <cmath>
#define PI 3.14159265358979323846


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Sky
    glColor3f(0.6f, 0.9f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f( 1.0f, -1.0f);
        glVertex2f( 1.0f,  1.0f);
        glVertex2f(-1.0f,  1.0f);
    glEnd();

    //Sun
    glPushMatrix();
    glTranslatef(0.6f, 0.8f, 0.0f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
        int segments = 100;
        float radius = 0.2f;
        for(int i = 0; i <= segments; i++) {
            float angle = 2 * PI * i / segments;
            float x = radius * cos(angle);
            float y = radius * sin(angle);
            glVertex2f(x, y);
        }
    glEnd();
    glPopMatrix();

    glFlush();
}


void init() {
    glClearColor(0.6f, 0.9f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Sky with Sun");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
