// Copyright 2025 UNN-CS Team
#include <cmath>
#include "tasks.h"
#include "circle.h"

double earthRopeGap(double earthRadiusKm, double addedLengthM) {
    double earthRadiusM = earthRadiusKm * 1000.0;
    double initialLength = 2.0 * PI * earthRadiusM;
    double newLength = initialLength + addedLengthM;
    double newRadius = newLength / (2.0 * PI);
    return newRadius - earthRadiusM;
}

void poolCosts(double poolRadius, double pathWidth,
               double concreteCostPerSqM, double fenceCostPerM,
               double &concreteCost, double &fenceCost) {
    Circle pool(poolRadius);
    Circle outer(poolRadius + pathWidth);

    double pathArea = outer.getArea() - pool.getArea();
    concreteCost = pathArea * concreteCostPerSqM;

    double fenceLength = outer.getFerence();
    fenceCost = fenceLength * fenceCostPerM;
}
