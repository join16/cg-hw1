//
// Created by Join on 2016. 3. 29..
//

#include "rgb_color.h"

#ifndef CG_HW1_PIXEL_H
#define CG_HW1_PIXEL_H


class Pixel {

public:
    Pixel(unsigned int _x, unsigned int _y, RGBColor _color);

    unsigned int getX();
    unsigned int getY();
    float getR();
    float getG();
    float getB();

    void print();

private:
    unsigned int x;
    unsigned int y;
    RGBColor *color;

};


#endif //CG_HW1_PIXEL_H