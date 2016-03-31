#include <cstdlib>

#ifdef __APPLE__
#include <GLUT/GLUT.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>

#include "lib/math_components/vector.h"

#include "lib/draw_components/pixel.h"
#include "lib/draw_components/rgb_color.h"

#include "lib/objects/object.h"
#include "lib/objects/sphere.h"
#include "lib/objects/triangle.h"

#include "lib/ray_casting/ray_caster.h"

using namespace std;

void renderHomework1(void (*drawPixel)(float, float, float, float, float)) {

    unsigned int resolutionX(400), resolutionY(400);
    double viewPlaneDistance(2.0), viewPlaneWidth(4.0), viewPlaneHeight(4.0);

    unsigned int pixelsCount;

    Pixel **pixels;

    Vector cop(100.0, 100.0, 100.0);
    Vector cameraLookAtPoint(0.0, 0.0, 0.0);
    Vector approximateViewUpVector(0.0, 1.0, 0.0);

    // vertex of triangles
    Vector vertexA(-50.0, -50.0, 0.0);
    Vector vertexB(-50.0, 50.0, 0.0);
    Vector vertexC(50.0, -50.0, 0.0);

    Camera *cam;

    cam = new Camera(cop, cameraLookAtPoint, approximateViewUpVector);

    RayCaster caster(cam,
                     viewPlaneDistance,
                     viewPlaneWidth,
                     viewPlaneHeight,
                     resolutionX,
                     resolutionY
    );

    Transformation sphereModelTrans, triangle1ModelTrans, triangle2ModelTrans;
    Transformation triangle2Rotation, triangle2Translation;

    sphereModelTrans.setTranslation(50.0, 0.0, 0.0);

    triangle2Rotation.setRotationByAngle(ROTATION_X_AXIS, 90);
    triangle2Translation.setTranslation(40.0);

    triangle2ModelTrans = Transformation::composite(triangle2Translation, triangle2Rotation);

    // add sphere
    caster.addObject(new Sphere(40.0), RGBColor(0.9f, 0.3f, 0.3f), sphereModelTrans);

    // add triangle 1
    caster.addObject(new Triangle(vertexA, vertexB, vertexC),
                     RGBColor(0.3f, 0.9f, 0.3f),
                     triangle1ModelTrans
    );

    // add triangle 2
    caster.addObject(new Triangle(vertexA, vertexB, vertexC),
                     RGBColor(0.3f, 0.3f, 0.9f),
                     triangle2ModelTrans
    );

    // executes model transformations
    caster.toWorldSpace();

    // executes camera transformations
    caster.toCameraSpace();

    pixels = caster.getCastedPixels();
    pixelsCount = caster.getPixelsCount();

    for (int i = 0; i < pixelsCount; i++) {
        Pixel *pixel = pixels[i];

        drawPixel(pixel->getX(), pixel->getY(), pixel->getR(), pixel->getG(), pixel->getB());
    }

}

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
    renderHomework1(drawPixel);

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
