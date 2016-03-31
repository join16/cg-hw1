
#ifndef CG_HW1_OBJECT_INFORMATION_H
#define CG_HW1_OBJECT_INFORMATION_H

#include "../math_components/transformation.h"
#include "../draw_components/rgb_color.h"
#include "../objects/object.h"

class ObjectInformation {

public:

    ObjectInformation(Object *_object, RGBColor _color, Transformation _modelTrans);

    Object *getObject();
    RGBColor getColor();
    void applyModelTransformation();
    void applyTransformation(Transformation trans);

private:

    RGBColor color;
    Object *object;
    Transformation modelTrans;

};


#endif //CG_HW1_OBJECT_INFORMATION_H
