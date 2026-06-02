// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

const double PI = 3.14159265358979323846;

class Circle {
 private:
    double radius;
    double ference; // длина окружности
    double area;

 public:
    explicit Circle(double r = 0.0);

    void setRadius(double r);
    void setFerence(double c);
    void setArea(double a);

    double getRadius() const;
    double getFerence() const;
    double getArea() const;
};

#endif  // INCLUDE_CIRCLE_H_
