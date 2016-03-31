#ifndef CG_HW1_CAMERA_H
#define CG_HW1_CAMERA_H

#include "../math_components/vector.h"
#include "../math_components/transformation.h"

class Camera {

public:

    Camera(Vector position, Vector lookAtPoint, Vector viewUp);

    ~Camera();

    Transformation getCoordinateTransformation() const;

private:

    // axis for camera space
    Vector u;
    Vector v;
    Vector w;

    // coordinate changing transformation
    Transformation *trans;

};


#endif //CG_HW1_CAMERA_H
