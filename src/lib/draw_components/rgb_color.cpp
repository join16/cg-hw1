//
// Created by Join on 2016. 3. 28..
//

#include <iostream>

#include "rgb_color.h"

//
// constructors
//

RGBColor::RGBColor() : red(0), green(0), blue(0) { }

RGBColor::RGBColor(const RGBColor &color) {
    red = color.getR();
    green = color.getG();
    blue = color.getB();
}

RGBColor::RGBColor(float _red, float _green, float _blue)
    : red(_red), green(_green), blue(_blue) { }


//
// methods
//

float RGBColor::getR() const {
    return red;
}

float RGBColor::getG() const {
    return green;
}

float RGBColor::getB() const {
    return blue;
}

void RGBColor::print() {
    printf("Color: (%f, %f, %f)\n", red, green, blue);
}

void RGBColor::set(RGBColor color) {
    red = color.getR();
    green = color.getG();
    blue = color.getB();
}