
#include <iostream>

#include "ray_caster.h"

RayCaster::RayCaster(Camera *_camera, double _viewPlaneDistance, double _viewPlaneWidth,
                     double _viewPlaneHeight, unsigned int _resolutionX,
                     unsigned int _resolutionY)
    : camera(_camera), viewPlaneDistance(_viewPlaneDistance),
      viewPlaneWidth(_viewPlaneWidth), viewPlaneHeight(_viewPlaneHeight),
      resolutionX(_resolutionX), resolutionY(_resolutionY) {}

void RayCaster::addObject(Object *object, RGBColor color, Transformation modelTrans) {
    objectInformations[objectsCount++] = new ObjectInformation(object, color, modelTrans);
}

void RayCaster::toWorldSpace() {
    for (int i = 0; i < objectsCount; i++) {
        objectInformations[i]->applyModelTransformation();
    }
}

void RayCaster::toCameraSpace() {
    Transformation trans = camera->getCoordinateTransformation();

    for (int i = 0; i < objectsCount; i++) {
        objectInformations[i]->applyTransformation(trans);
    }
}

Pixel **RayCaster::getCastedPixels() {

    Pixel **pixels;

    double ratioX = viewPlaneWidth / resolutionX;
    double ratioY = viewPlaneHeight / resolutionY;;

    unsigned int currentPixelIndex = 0;

    // for iteration
    unsigned int i(0), j(0), k(0);

    Vector cop(0, 0, 0);

    pixels = new Pixel*[getPixelsCount()];

    for (i = 0; i < resolutionX; i++) {
        for (j = 0; j < resolutionY; j++) {

            double pixelCenterX = (i + 0.5 - (resolutionX / 2)) * ratioX;
            double pixelCenterY = (j + 0.5 - (resolutionY / 2)) * ratioY;

            // distance from cop to intersection. -1 if no intersection found
            double nearestIntersectionDistance = -1;
            double currentIntersectionDistance = -1;

            Vector pixelCenter(pixelCenterX, pixelCenterY, viewPlaneDistance);
            Vector direction = pixelCenter - cop;

            Vector intersection(false);

            // default color is black
            RGBColor color;

            for (k = 0; k < objectsCount; k++) {

                intersection = objectInformations[k]->getObject()->getIntersection(direction, cop);
                currentIntersectionDistance = intersection.getSize();

                // if no intersection point
                if (currentIntersectionDistance < 0) {
                    continue;
                }

                if ((nearestIntersectionDistance < 0) ||
                    (currentIntersectionDistance < nearestIntersectionDistance)) {
                    color = objectInformations[k]->getColor();
                    nearestIntersectionDistance = currentIntersectionDistance;
                }
            }

            pixels[currentPixelIndex++] = new Pixel(i, j, color);
        }
    }

    return pixels;
}

unsigned int RayCaster::getPixelsCount() {
    return resolutionX * resolutionY;
}

void RayCaster::print() {
    for (int i = 0; i < objectsCount; i++) {
        std::cout << "Object " << i << ": " << std::endl;
        objectInformations[i]->getObject()->print();
    }
}