
#include <iostream>

#include "camera.h"

Camera::Camera(Vector position, Vector lookAtPoint, Vector viewUp) {

    Transformation rotation, translation;
    Vector up = Vector(viewUp);

    up.normalize();

    w = lookAtPoint - position;
    u = Vector::crossProduct(w, up);
    v = Vector::crossProduct(u, w);

    u.normalize();
    v.normalize();
    w.normalize();

    rotation.setRotationByAxisVector(u, v, w);
    translation.setTranslation(-position.getX(), -position.getY(), -position.getZ());

    trans = Transformation::composite(rotation, translation);
}

Transformation Camera::getCoordinateTransformation() const {
    return Transformation(trans);
}