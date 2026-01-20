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

    // Sun
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

    //  Cloud 1
    glPushMatrix();
    glTranslatef(-0.5f + _move4, 0.7f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
        float rx = 0.2f, ry = 0.12f;
        for(int i = 0; i <= segments; i++) {
            float angle = 2 * PI * i / segments;
            float x = rx * cos(angle);
            float y = ry * sin(angle);
            glVertex2f(x, y);
        }
    glEnd();
    glPopMatrix();

    //  Cloud 2
    glPushMatrix();
    glTranslatef(0.0f + _move5, 0.85f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
        rx = 0.25f; ry = 0.15f;
        for(int i = 0; i <= segments; i++) {
            float angle = 2 * PI * i / segments;
            float x = rx * cos(angle);
            float y = ry * sin(angle);
            glVertex2f(x, y);
        }
    glEnd();
    glPopMatrix();

    //  Birds
    drawBird(-0.4f + _move3, 0.75f);
    drawBird(0.0f + _move3, 0.8f);

    glFlush();
}

//  Timer
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
    glutCreateWindow("Sky with Sun, Clouds, and Birds");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}
