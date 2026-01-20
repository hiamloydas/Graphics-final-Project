#include <GL/glut.h>
#include <cmath>
#define PI 3.14159265358979323846

float _moveCloud1 = 0.0f;
float _moveCloud2 = 0.0f;
float _moveBird = 0.0f;
float _movePlane = -1.5f;
float _moveCar = -1.2f;
float _moveBus = 1.2f;

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
    // Plane body
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(x, y);
        glVertex2f(x + 0.3f, y);
        glVertex2f(x + 0.3f, y + 0.05f);
        glVertex2f(x, y + 0.05f);
    glEnd();


    glColor3f(0.0f, 1.0f, 1.0f);
    for(float wx = x + 0.02f; wx < x + 0.28f; wx += 0.06f){
        glBegin(GL_POLYGON);
            glVertex2f(wx, y + 0.01f);
            glVertex2f(wx + 0.04f, y + 0.01f);
            glVertex2f(wx + 0.04f, y + 0.04f);
            glVertex2f(wx, y + 0.04f);
        glEnd();
    }


    glColor3f(0.6f, 0.6f, 0.6f);
    glBegin(GL_TRIANGLES);
        glVertex2f(x + 0.3f, y);
        glVertex2f(x + 0.33f, y + 0.025f);
        glVertex2f(x + 0.3f, y + 0.05f);
    glEnd();
}

void drawBackRowBuildings() {
    float buildingX[] = {-0.9f, -0.5f, 0.0f, 0.5f};
    float buildingWidth = 0.18f;
    float buildingHeight[] = {0.35f, 0.3f, 0.4f, 0.32f};

    for(int i = 0; i < 4; i++) {
        glColor3f(0.5f, 0.5f, 0.8f);
        glBegin(GL_POLYGON);
            glVertex2f(buildingX[i], -0.2f);
            glVertex2f(buildingX[i] + buildingWidth, -0.2f);
            glVertex2f(buildingX[i] + buildingWidth, buildingHeight[i] - 0.2f);
            glVertex2f(buildingX[i], buildingHeight[i] - 0.2f);
        glEnd();

        
        glColor3f(0.0f, 0.8f, 1.0f);
        float winWidth = 0.03f, winHeight = 0.035f;
        for(int row = 0; row < 3; row++){
            for(int col = 0; col < 2; col++){
                float wx = buildingX[i] + 0.02f + col * 0.065f;
                float wy = -0.18f + row * 0.07f;
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


void drawFrontRowBuildings() {
    float buildingX[] = {-0.8f, -0.4f, 0.0f, 0.4f};
    float buildingWidth = 0.18f;
    float buildingHeight[] = {0.25f, 0.2f, 0.3f, 0.22f};

    for (int i = 0; i < 4; i++) {
        glColor3f(0.8f, 0.5f, 0.5f);
        glBegin(GL_POLYGON);
            glVertex2f(buildingX[i], -0.05f);
            glVertex2f(buildingX[i] + buildingWidth, -0.05f);
            glVertex2f(buildingX[i] + buildingWidth, buildingHeight[i] - 0.05f);
            glVertex2f(buildingX[i], buildingHeight[i] - 0.05f);
        glEnd();


        glColor3f(0.0f, 0.8f, 1.0f);
        float winWidth = 0.03f, winHeight = 0.035f;
        for(int row = 0; row < 3; row++){
            for(int col = 0; col < 2; col++){
                float wx = buildingX[i] + 0.02f + col * 0.065f;
                float wy = 0.01f + row * 0.07f;
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


void drawRoad() {
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -0.2f);
        glVertex2f( 1.0f, -0.2f);
        glVertex2f( 1.0f, -0.4f);
        glVertex2f(-1.0f, -0.4f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    for(float lx = -1.0f; lx < 1.0f; lx += 0.2f){
        glBegin(GL_QUADS);
            glVertex2f(lx, -0.3f);
            glVertex2f(lx + 0.1f, -0.3f);
            glVertex2f(lx + 0.1f, -0.295f);
            glVertex2f(lx, -0.295f);
        glEnd();
    }

    
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(3.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-1.0f, -0.2f);
        glVertex2f( 1.0f, -0.2f);
        glVertex2f( 1.0f, -0.4f);
        glVertex2f(-1.0f, -0.4f);
    glEnd();
}


void drawCar(float x, float y) {
    // Car Body
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
        glVertex2f(x, y);
        glVertex2f(x + 0.3f, y);
        glVertex2f(x + 0.3f, y + 0.1f);
        glVertex2f(x, y + 0.1f);
    glEnd();
 
    glColor3f(0.0f, 0.0f, 0.0f);
    for(float wx = x + 0.05f; wx <= x + 0.25f; wx += 0.2f){
        glBegin(GL_POLYGON);
        for(int i = 0; i < 100; i++){
            float angle = 2 * PI * i / 100;
            glVertex2f(wx + 0.025f * cos(angle), y - 0.025f * sin(angle));
        }
        glEnd();
    }
}

void drawBus(float x, float y) {
   
    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(x, y);
        glVertex2f(x + 0.5f, y);
        glVertex2f(x + 0.5f, y + 0.12f);
        glVertex2f(x, y + 0.12f);
    glEnd();
 
    glColor3f(0.0f, 1.0f, 1.0f);
    for(float wx = x + 0.05f; wx < x + 0.45f; wx += 0.1f){
        glBegin(GL_POLYGON);
            glVertex2f(wx, y + 0.02f);
            glVertex2f(wx + 0.08f, y + 0.02f);
            glVertex2f(wx + 0.08f, y + 0.08f);
            glVertex2f(wx, y + 0.08f);
        glEnd();
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
    glBegin(GL_POLYGON);
        int segments = 100;
        float radius = 0.2f;
        for(int i = 0; i <= segments; i++){
            float angle = 2 * PI * i / segments;
            glVertex2f(radius * cos(angle), radius * sin(angle));
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.5f + _moveCloud1, 0.7f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
        float rx = 0.2f, ry = 0.12f;
        for(int i = 0; i <= segments; i++){
            float angle = 2 * PI * i / segments;
            glVertex2f(rx * cos(angle), ry * sin(angle));
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f + _moveCloud2, 0.85f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
        rx = 0.25f; ry = 0.15f;
        for(int i = 0; i <= segments; i++){
            float angle = 2 * PI * i / segments;
            glVertex2f(rx * cos(angle), ry * sin(angle));
        }
    glEnd();
    glPopMatrix();

  
    drawBird(-0.4f + _moveBird, 0.75f);
    drawBird(0.0f + _moveBird, 0.8f);

    
    drawPlane(_movePlane, 0.6f);


    drawBackRowBuildings();
    drawFrontRowBuildings();

 
    drawRoad();

    // Vehicles
    drawCar(_moveCar, -0.35f);
    drawBus(_moveBus, -0.33f);

    glFlush();
}


void timer(int) {
    _moveBird += 0.005f; if(_moveBird > 1.5f) _moveBird = -1.5f;
    _moveCloud1 += 0.002f; if(_moveCloud1 > 2.0f) _moveCloud1 = -2.0f;
    _moveCloud2 += 0.001f; if(_moveCloud2 > 2.0f) _moveCloud2 = -2.0f;
    _movePlane += 0.004f; if(_movePlane > 1.5f) _movePlane = -1.5f;
    _moveCar += 0.008f; if(_moveCar > 1.5f) _moveCar = -1.5f;
    _moveBus -= 0.006f; if(_moveBus < -1.5f) _moveBus = 1.5f;

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}


void init() {
    glClearColor(0.6f, 0.9f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}


int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("City Scene Animation");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}

