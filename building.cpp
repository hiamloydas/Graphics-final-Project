#include <GL/glut.h>
#include <cmath>
#define PI 3.14159265358979323846

float _move4 = 0.0f;
float _move5 = 0.0f;
float _move3 = 0.0f;

void drawBird(float x, float y) {
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(x + 0.05f, y + 0.05f);
        glVertex2f(x + 0.05f, y + 0.05f);
        glVertex2f(x + 0.1f, y);
    glEnd();
}

void drawRoadScene() {
    glColor3f(0.698f, 0.745f, 0.7098f);
    glBegin(GL_POLYGON);
        glVertex2f(-1.0f, -0.33f);
        glVertex2f( 1.0f, -0.33f);
        glVertex2f( 1.0f, 0.0f);
        glVertex2f(-1.0f, 0.0f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    for (float startX = -1.0f; startX < 1.0f; startX += 0.33f) {
        glBegin(GL_POLYGON);
            glVertex2f(startX, -0.166f);
            glVertex2f(startX + 0.16f, -0.166f);
            glVertex2f(startX + 0.16f, -0.13f);
            glVertex2f(startX, -0.13f);
        glEnd();
    }

    glColor3f(0.2f, 0.098f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-1.0f, -0.33f);
        glVertex2f(1.0f, -0.33f);
        glVertex2f(1.0f, -0.416f);
        glVertex2f(-1.0f, -0.416f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-1.0f, -0.33f);
        glVertex2f(1.0f, -0.33f);
        glVertex2f(1.0f, -0.35f);
        glVertex2f(-1.0f, -0.35f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(0.6f, 0.9f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f( 1.0f, -1.0f);
        glVertex2f( 1.0f,  1.0f);
        glVertex2f(-1.0f,  1.0f);
    glEnd();

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

    glPushMatrix();
    glTranslatef(-0.5f + _move4, 0.7f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    float rx = 0.2f, ry = 0.12f;
    int segments = 100;
    glBegin(GL_POLYGON);
        for(int i = 0; i <= segments; i++) {
            float angle = 2 * PI * i / segments;
            glVertex2f(rx * cos(angle), ry * sin(angle));
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f + _move5, 0.85f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    rx = 0.25f; ry = 0.15f;
    glBegin(GL_POLYGON);
        for(int i = 0; i <= segments; i++) {
            float angle = 2 * PI * i / segments;
            glVertex2f(rx * cos(angle), ry * sin(angle));
        }
    glEnd();
    glPopMatrix();

    drawBird(-0.4f + _move3, 0.75f);
    drawBird(0.0f + _move3, 0.8f);

    drawRoadScene();

    glFlush();
}

void timer(int) {
    _move3 += 0.005f;
    if(_move3 > 1.5f) _move3 = -1.5f;

    _move4 += 0.002f;
    if(_move4 > 2.0f) _move4 = -2.0f;

    _move5 += 0.001f;
    if(_move5 > 2.0f) _move5 = -2.0f;

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
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
    glutCreateWindow("Sky, Sun, Clouds, Birds, and Road");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}
