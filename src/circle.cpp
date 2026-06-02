// Copyright 2022 UNN-CS
#include <cmath>
#include "circle.h"

Circle::Circle(double r) {
    setRadius(r);
}

void Circle::setRadius(double r) {
    if (r < 0.0) r = 0.0;
    radius = r;
    ference = 2.0 * PI * radius;
    area = PI * radius * radius;
}

void Circle::setFerence(double c) {
    if (c < 0.0) c = 0.0;
    ference = c;
    radius = ference / (2.0 * PI);
    area = PI * radius * radius;
}

void Circle::setArea(double a) {
    if (a < 0.0) a = 0.0;
    area = a;
    radius = std::sqrt(area / PI);
    ference = 2.0 * PI * radius;
}

double Circle::getRadius() const {
    return radius;
}

double Circle::getFerence() const {
    return ference;
}

double Circle::getArea() const {
    return area;
}
