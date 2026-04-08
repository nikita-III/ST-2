// Copyright 2025 UNN-CS Team
#include "tasks.h"
#include "circle.h"

double processForEarth(double radiusKm, double lengthMeters) {
  Circle earth(radiusKm * 1000);
  double initialFerence = earth.getFerence();
  earth.setFerence(initialFerence + lengthMeters);
  return earth.getRadius() - (radiusKm * 1000);
}

double processForPool(double radius, double pathWidth, double priceForConcrete,
                double priceForFence) {
  Circle pool(radius);
  Circle outer(radius + pathWidth);
  double areaPath = outer.getArea() - pool.getArea();
  double costOfConcrete = areaPath * priceForConcrete;
  double costOfFence = outer.getFerence() * priceForFence;

  return costOfConcrete + costOfFence;
}
