//
// Created by Join on 2016. 3. 28..
//

#ifndef CG_HW1_RGB_COLOR_H
#define CG_HW1_RGB_COLOR_H


class RGBColor {

public:

    // constructors
    RGBColor();
    RGBColor(const RGBColor &color);
    RGBColor(float _red, float _green, float _blue);

    void print();
    void set(RGBColor color);
    float getR() const;
    float getG() const;
    float getB() const;

private:
    float red;
    float green;
    float blue;

};


#endif //CG_HW1_RGB_COLOR_H