#ifndef CG_HW1_HW1_H
#define CG_HW1_HW1_H

#include "lib/math_components/vector.h"
#include "lib/draw_components/pixel.h"
#include "lib/draw_components/rgb_color.h"
#include "lib/objects/object.h"
#include "lib/objects/sphere.h"
#include "lib/objects/triangle.h"
#include "lib/ray_casting/ray_caster.h"

namespace Hw1 {

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

}


#endif //CG_HW1_HW1_H
