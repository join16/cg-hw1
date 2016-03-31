#include <cstdlib>

#ifdef __APPLE__
#include <GLUT/GLUT.h>
#else
#include <GL/glut.h>
#endif

#include "hw1.h"

int window;

int width = 400;
int height = 400;

void drawPixel(float x, float y, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_POINTS);
    glVertex3f(x, y, 0.0f);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // WRITE YOUR CODE HERE
    Hw1::renderHomework1(drawPixel);

    glutSwapBuffers();
}

// window resize handler function
void reshape(int w, int h) {
    width = w;
    height = h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
}

// keyboard handler function
void keyboard(unsigned char key, int x, int y) {
    switch ((char)key) {
        case 'q':
        case 27: // ESC
            glutDestroyWindow(window);
            exit(0);
        default:
            break;
    }

    return;
}

int main(int argc, char *argv[]) {
    // initialize GLUT
    glutInit(&argc, argv);

    // specify the display to be double buffered an color as RGB values
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    // set the initial window size
    glutInitWindowSize(width, height);
    // create window and store the handle
    window = glutCreateWindow("CSI4105");

    // register function to draw
    glutDisplayFunc(display);
    // register function to handle window resizes
    glutReshapeFunc(reshape);
    // register function to handle keyboard events
    glutKeyboardFunc(keyboard);

    glClearColor(0.0, 0.0, 0.0, 1.0);

    // start the GLUT main loop
    glutMainLoop();

    return 0;
}
