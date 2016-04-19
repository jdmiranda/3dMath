//
// Created by JEREMY Miranda on 4/18/16.
//

#include "Vector.h"
#include <iostream>

Vector::Vector(float x, float y, float z)
{
    X = x;
    Y = y;
    Z = z;
}

Vector::Vector(int x, int y, int z)
{
    X = (float) x;
    Y = (float) y;
    Z = (float) z;
}

void Vector::Print() {
    std::cout << X << "," << Y << "," << Z;
}

bool Vector::operator==(Vector v) {
    Vector t = *this;
    return ((t.X == v.X) && (t.Y == v.Y) && (t.Z == v.Z));
}

bool Vector::operator!=(Vector v) {
    return not (*this == (v));
}







