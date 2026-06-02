// Copyright 2025 UNN-CS Team
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

double earthRopeGap(double earthRadiusKm, double addedLengthM);

void poolCosts(double poolRadius, double pathWidth,
               double concreteCostPerSqM, double fenceCostPerM,
               double &concreteCost, double &fenceCost);

#endif  // INCLUDE_TASKS_H_
