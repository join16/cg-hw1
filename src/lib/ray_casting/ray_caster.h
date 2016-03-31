#ifndef CG_HW1_RAY_CASTER_H
#define CG_HW1_RAY_CASTER_H

#include <vector>

#include "../math_components/transformation.h"
#include "../draw_components/rgb_color.h"
#include "../draw_components/pixel.h"
#include "camera.h"
#include "object_information.h"

const unsigned int maxObjectsCount = 255;

class RayCaster {

public:

    RayCaster(Camera *_camera,
              double _viewPlaneDistance,
              double _viewPlaneWidth,
              double _viewPlaneHeight,
              unsigned int _resolutionX,
              unsigned int _resolutionY
    );

    Pixel **getCastedPixels();

    void addObject(Object *object, RGBColor color, Transformation modelTrans);
    void toWorldSpace();
    void toCameraSpace();
    void print();
    unsigned int getPixelsCount();

private:

    Camera *camera;
    double viewPlaneDistance;
    double viewPlaneWidth;
    double viewPlaneHeight;
    unsigned int resolutionX;
    unsigned int  resolutionY;
    unsigned int objectsCount = 0;
    ObjectInformation *objectInformations[matrixSize];
};


#endif //CG_HW1_RAY_CASTER_H
