#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#define PI 3.14159265358979323846
using namespace std;


float _move = 0.0f;  // plane
float _move1 = 0.0f; // boat
float _move2 = 0.0f; // bus
float _move3 = 0.0f; // bird
float _move4 = 0.0f; // cloud1
float _move5 = 0.0f; // cloud2
float _move6 = 0.0f; // car


void drawCircle(float cx, float cy, float r, int num_segments, float red, float green, float blue) {
    glColor3f(red, green, blue);
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * PI * float(i) / float(num_segments);
        float x = r * cos(theta);
        float y = r * sin(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}


void drawTree(float x, float y) {
    // Trunk
    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_POLYGON);
    glVertex2f(x - 0.02f, y);
    glVertex2f(x + 0.02f, y);
    glVertex2f(x + 0.02f, y + 0.1f);
    glVertex2f(x - 0.02f, y + 0.1f);
    glEnd();

    // Leaves 
    drawCircle(x, y + 0.13f, 0.05f, 50, 0.0f, 0.6f, 0.0f);
    drawCircle(x - 0.04f, y + 0.10f, 0.05f, 50, 0.0f, 0.8f, 0.0f);
    drawCircle(x + 0.04f, y + 0.10f, 0.05f, 50, 0.0f, 0.8f, 0.0f);
}

// Main scene drawing
void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.49f, 1.0f, 1.0f, 1.0f); // Sky
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);

    // Sun
    drawCircle(0.8f, 0.8f, 0.1f, 100, 1.0f, 1.0f, 0.0f);

    // Clouds
    drawCircle(_move4 + 0.2f, 0.8f, 0.05f, 50, 1.0f, 1.0f, 1.0f);
    drawCircle(_move4 + 0.28f, 0.8f, 0.05f, 50, 1.0f, 1.0f, 1.0f);
    drawCircle(_move4 + 0.35f, 0.8f, 0.05f, 50, 1.0f, 1.0f, 1.0f);

    drawCircle(_move5 + 0.6f, 0.6f, 0.05f, 50, 1.0f, 1.0f, 1.0f);
    drawCircle(_move5 + 0.68f, 0.6f, 0.05f, 50, 1.0f, 1.0f, 1.0f);
    drawCircle(_move5 + 0.75f, 0.6f, 0.05f, 50, 1.0f, 1.0f, 1.0f);

    // Lake
    glColor3f(0.23f, 0.70f, 0.81f);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.33f);
    glVertex2f(-1.0f, -0.33f);
    glEnd();

    // Road
    glColor3f(0.7f, 0.75f, 0.71f);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0f, -0.33f);
    glVertex2f(1.0f, -0.33f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glEnd();

    // Trees
    drawTree(-0.8f, -0.33f);
    drawTree(-0.5f, -0.33f);
    drawTree(-0.2f, -0.33f);
    drawTree(0.1f, -0.33f);
    drawTree(0.4f, -0.33f);
    drawTree(0.7f, -0.33f);

  
    glutSwapBuffers();
}

//move
void update(int value) {
    _move += 0.005f;  // plane
    _move4 += 0.002f; // cloud1
    _move5 += 0.001f; // cloud2
    _move6 += 0.004f; // car

    if (_move > 2.0f) _move = -2.0f;
    if (_move4 > 2.0f) _move4 = -2.0f;
    if (_move5 > 2.0f) _move5 = -2.0f;
    if (_move6 > 2.0f) _move6 = -2.0f;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}


void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-1.0, 1.0, -1.0 * (GLfloat)h / (GLfloat)w,
                1.0 * (GLfloat)h / (GLfloat)w, -1.0, 1.0);
    else
        glOrtho(-1.0 * (GLfloat)w / (GLfloat)h,
                1.0 * (GLfloat)w / (GLfloat)h, -1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Animated Scene with Trees");
    glutDisplayFunc(drawScene);
    glutReshapeFunc(reshape);
    glutTimerFunc(25, update, 0);
    glutMainLoop();
    return 0;
}


