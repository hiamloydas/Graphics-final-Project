#include <GL/glut.h>
#include <cmath>
#define PI 3.14159265358979323846

float _move4 = 0.0f;
float _move5 = 0.0f;
float _move3 = 0.0f;
float _movePlane = 0.0f;
float _moveCar = 0.0f;
float _moveBus = 0.0f;

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


void drawPlane(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);


    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.1f, 0.0f);
        glVertex2f(0.1f, 0.0f);
        glVertex2f(0.15f, 0.025f);
        glVertex2f(-0.15f, 0.025f);
    glEnd();


    glColor3f(0.7f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.12f, 0.025f);
        glVertex2f(-0.15f, 0.045f);
        glVertex2f(-0.09f, 0.025f);
    glEnd();


    glColor3f(0.0f, 0.0f, 0.0f);
    float wx = -0.05f;
    for (int i = 0; i < 3; i++) {
        glBegin(GL_POLYGON);
            for(int j=0;j<=50;j++){
                float angle = 2 * PI * j / 50;
                float radius = 0.01f;
                glVertex2f(wx + radius * cos(angle), 0.012f + radius * sin(angle));
            }
        glEnd();
        wx += 0.05f;
    }


    glColor3f(0.5f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.0f, 0.025f);
        glVertex2f(0.05f, 0.045f);
        glVertex2f(-0.05f, 0.045f);
        glVertex2f(0.0f, 0.025f);
    glEnd();

    glPopMatrix();
}

void drawCar(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);


    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.08f, 0.0f);
        glVertex2f(0.08f, 0.0f);
        glVertex2f(0.08f, 0.04f);
        glVertex2f(-0.08f, 0.04f);
    glEnd();

    glColor3f(0.8f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.05f, 0.04f);
        glVertex2f(0.05f, 0.04f);
        glVertex2f(0.03f, 0.07f);
        glVertex2f(-0.03f, 0.07f);
    glEnd();


    glColor3f(0.0f, 0.8f, 1.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.03f, 0.045f);
        glVertex2f(0.03f, 0.045f);
        glVertex2f(0.025f, 0.065f);
        glVertex2f(-0.025f, 0.065f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    float radius = 0.012f;
    glBegin(GL_POLYGON);
        for(int i=0;i<=50;i++){
            float angle = 2*PI*i/50;
            glVertex2f(-0.05f + radius*cos(angle), -0.012f + radius*sin(angle));
        }
    glEnd();
    glBegin(GL_POLYGON);
        for(int i=0;i<=50;i++){
            float angle = 2*PI*i/50;
            glVertex2f(0.05f + radius*cos(angle), -0.012f + radius*sin(angle));
        }
    glEnd();

    glPopMatrix();
}

void drawBus(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);


    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.12f, 0.0f);
        glVertex2f(0.12f, 0.0f);
        glVertex2f(0.12f, 0.06f);
        glVertex2f(-0.12f, 0.06f);
    glEnd();

    glColor3f(0.0f, 0.8f, 1.0f);
    float winX = -0.10f;
    for(int i=0;i<4;i++){
        glBegin(GL_POLYGON);
            glVertex2f(winX, 0.02f);
            glVertex2f(winX + 0.05f, 0.02f);
            glVertex2f(winX + 0.05f, 0.05f);
            glVertex2f(winX, 0.05f);
        glEnd();
        winX += 0.055f;
    }

    glColor3f(0.0f, 0.0f, 0.0f);
    float radius = 0.015f;
    glBegin(GL_POLYGON);
        for(int i=0;i<=50;i++){
            float angle = 2*PI*i/50;
            glVertex2f(-0.08f + radius*cos(angle), -0.012f + radius*sin(angle));
        }
    glEnd();
    glBegin(GL_POLYGON);
        for(int i=0;i<=50;i++){
            float angle = 2*PI*i/50;
            glVertex2f(0.08f + radius*cos(angle), -0.012f + radius*sin(angle));
        }
    glEnd();

    glPopMatrix();
}


void drawRoadScene() {
    // Road
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


void drawBackRowBuildings() {
    float buildingX[] = {-0.9f, -0.5f, 0.0f, 0.5f};
    float buildingWidth = 0.15f;
    float buildingHeight[] = {0.3f, 0.25f, 0.35f, 0.28f};

    for (int i = 0; i < 4; i++) {

        glColor3f(0.6f, 0.6f, 0.7f);
        glBegin(GL_POLYGON);
            glVertex2f(buildingX[i], 0.0f);
            glVertex2f(buildingX[i] + buildingWidth, 0.0f);
            glVertex2f(buildingX[i] + buildingWidth, buildingHeight[i]);
            glVertex2f(buildingX[i], buildingHeight[i]);
        glEnd();


        glColor3f(0.9f, 0.9f, 0.0f); // yellow
        float winWidth = 0.03f, winHeight = 0.04f;
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 2; col++) {
                float wx = buildingX[i] + 0.02f + col * 0.065f;
                float wy = 0.05f + row * 0.08f;
                glBegin(GL_POLYGON);
                    glVertex2f(wx, wy);
                    glVertex2f(wx + winWidth, wy);
                    glVertex2f(wx + winWidth, wy + winHeight);
                    glVertex2f(wx, wy + winHeight);
                glEnd();
            }
        }
    }
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
    int segments = 100;
    float radius = 0.2f;
    glBegin(GL_POLYGON);
        for(int i = 0; i <= segments; i++) {
            float angle = 2 * PI * i / segments;
            glVertex2f(radius*cos(angle), radius*sin(angle));
        }
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-0.5f + _move4, 0.7f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    float rx = 0.2f, ry = 0.12f;
    glBegin(GL_POLYGON);
        for(int i = 0; i <= segments; i++){
            float angle = 2 * PI * i / segments;
            glVertex2f(rx*cos(angle), ry*sin(angle));
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f + _move5, 0.85f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    rx = 0.25f; ry = 0.15f;
    glBegin(GL_POLYGON);
        for(int i = 0; i <= segments; i++){
            float angle = 2 * PI * i / segments;
            glVertex2f(rx*cos(angle), ry*sin(angle));
        }
    glEnd();
    glPopMatrix();


    drawBird(-0.4f + _move3, 0.75f);
    drawBird(0.0f + _move3, 0.8f);


    drawPlane(-0.8f + _movePlane, 0.6f);


    drawBackRowBuildings();

    drawRoadScene();


    drawCar(-0.9f + _moveCar, -0.25f);
    drawBus(-1.2f + _moveBus, -0.25f);

    glFlush();
}

void timer(int) {
    _move3 += 0.005f;
    if(_move3 > 1.5f) _move3 = -1.5f;

    _move4 += 0.002f;
    if(_move4 > 2.0f) _move4 = -2.0f;

    _move5 += 0.001f;
    if(_move5 > 2.0f) _move5 = -2.0f;

    _movePlane += 0.004f;
    if(_movePlane > 2.0f) _movePlane = -2.0f;

    _moveCar += 0.006f;
    if(_moveCar > 2.0f) _moveCar = -2.0f;

    _moveBus += 0.004f;
    if(_moveBus > 2.0f) _moveBus = -2.0f;

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
    glutCreateWindow("Grameen Scene: Sky, Sun, Clouds, Birds, Plane, Buildings, Road, Car, Bus");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}
