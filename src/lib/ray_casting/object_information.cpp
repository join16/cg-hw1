#include "object_information.h"

ObjectInformation::ObjectInformation(Object *_object,
                                     RGBColor _color,
                                     Transformation _modelTrans) {
    color = RGBColor(_color);
    object = _object;
    modelTrans = Transformation(_modelTrans);
}

Object *ObjectInformation::getObject() {
    return object;
}

RGBColor ObjectInformation::getColor() {
    return RGBColor(color);
}

void ObjectInformation::applyModelTransformation() {
    object->transform(modelTrans);
}

void ObjectInformation::applyTransformation(Transformation trans) {
    object->transform(trans);
}