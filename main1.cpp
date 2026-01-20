#include <GL/glut.h>

// Display function for sky
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Sky (light blue)
    glColor3f(0.6f, 0.9f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, 0.3f);
        glVertex2f( 1.0f, 0.3f);
        glVertex2f( 1.0f, 1.0f);
        glVertex2f(-1.0f, 1.0f);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // white background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1); // 2D Orthographic projection
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Sky Only");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
