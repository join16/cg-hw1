//
// Created by Join on 2016. 3. 29..
//

#include <iostream>

#include "pixel.h"

Pixel::Pixel(unsigned int _x, unsigned int _y, RGBColor _color)
    : x(_x), y(_y) {
    color = new RGBColor(_color);
}

void Pixel::print() {
    printf("at (%d, %d), color: (%f, %f, %f)\n",
           x, y, color->getR(), color->getG(), color->getB()
    );
}

unsigned int Pixel::getX() {
    return x;
}

unsigned int Pixel::getY() {
    return y;
}

float Pixel::getR() {
    return color->getR();
}

float Pixel::getG() {
    return color->getG();
}

float Pixel::getB() {
    return color->getB();
}