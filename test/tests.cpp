// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

const double EPS = 1e-9;

// ==================== Circle ====================

TEST(CircleTest, ConstructorAndGetters) {
    Circle c(5.0);
    EXPECT_NEAR(c.getRadius(), 5.0, EPS);
    EXPECT_NEAR(c.getFerence(), 2.0 * PI * 5.0, EPS);
    EXPECT_NEAR(c.getArea(), PI * 25.0, EPS);
}

TEST(CircleTest, SetRadius) {
    Circle c;
    c.setRadius(3.0);
    EXPECT_NEAR(c.getRadius(), 3.0, EPS);
    EXPECT_NEAR(c.getFerence(), 2.0 * PI * 3.0, EPS);
    EXPECT_NEAR(c.getArea(), PI * 9.0, EPS);
}

TEST(CircleTest, SetFerence) {
    Circle c;
    double circ = 10.0;
    c.setFerence(circ);
    double expectedRadius = circ / (2.0 * PI);
    EXPECT_NEAR(c.getFerence(), circ, EPS);
    EXPECT_NEAR(c.getRadius(), expectedRadius, EPS);
    EXPECT_NEAR(c.getArea(), PI * expectedRadius * expectedRadius, EPS);
}

TEST(CircleTest, SetArea) {
    Circle c;
    double a = 50.0;
    c.setArea(a);
    double expectedRadius = std::sqrt(a / PI);
    EXPECT_NEAR(c.getArea(), a, EPS);
    EXPECT_NEAR(c.getRadius(), expectedRadius, EPS);
    EXPECT_NEAR(c.getFerence(), 2.0 * PI * expectedRadius, EPS);
}

TEST(CircleTest, NegativeRadius) {
    Circle c(-5.0);
    EXPECT_NEAR(c.getRadius(), 0.0, EPS);
    EXPECT_NEAR(c.getFerence(), 0.0, EPS);
    EXPECT_NEAR(c.getArea(), 0.0, EPS);
}

TEST(CircleTest, NegativeFerence) {
    Circle c(3.0);
    c.setFerence(-10.0);
    EXPECT_NEAR(c.getFerence(), 0.0, EPS);
    EXPECT_NEAR(c.getRadius(), 0.0, EPS);
    EXPECT_NEAR(c.getArea(), 0.0, EPS);
}

TEST(CircleTest, NegativeArea) {
    Circle c(3.0);
    c.setArea(-20.0);
    EXPECT_NEAR(c.getArea(), 0.0, EPS);
    EXPECT_NEAR(c.getRadius(), 0.0, EPS);
    EXPECT_NEAR(c.getFerence(), 0.0, EPS);
}

TEST(CircleTest, ZeroRadius) {
    Circle c(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, EPS);
    EXPECT_NEAR(c.getFerence(), 0.0, EPS);
    EXPECT_NEAR(c.getArea(), 0.0, EPS);
}

TEST(CircleTest, ConsistencyAfterMultipleSets) {
    Circle c(2.0);
    c.setFerence(20.0);
    double r1 = c.getRadius();
    double a1 = c.getArea();
    c.setArea(100.0);
    double r2 = c.getRadius();
    double c2 = c.getFerence();
    EXPECT_NEAR(c2, 2.0 * PI * r2, EPS);
    EXPECT_NEAR(a1, PI * r1 * r1, EPS);
    EXPECT_NEAR(c.getArea(), 100.0, EPS);
}

TEST(CircleTest, SetRadiusThenFerenceThenArea) {
    Circle c;
    c.setRadius(4.0);
    double oldFerence = c.getFerence();
    double oldArea = c.getArea();
    c.setFerence(oldFerence + 1.0);
    EXPECT_NE(c.getRadius(), 4.0);
    c.setArea(oldArea + 5.0);
    EXPECT_NE(c.getFerence(), oldFerence + 1.0);
}

TEST(CircleTest, LargeValues) {
    double large = 1e12;
    Circle c(large);
    EXPECT_NEAR(c.getRadius(), large, EPS);
    EXPECT_NEAR(c.getFerence(), 2.0 * PI * large, EPS);
    EXPECT_NEAR(c.getArea(), PI * large * large, EPS);
}

TEST(CircleTest, VerySmallValues) {
    double small = 1e-12;
    Circle c(small);
    EXPECT_NEAR(c.getRadius(), small, EPS);
    EXPECT_NEAR(c.getFerence(), 2.0 * PI * small, EPS);
    EXPECT_NEAR(c.getArea(), PI * small * small, EPS);
}

// ==================== "Земля и верёвка" ====================

TEST(EarthRopeTest, KnownFormula) {
    double added = 1.0;
    double gap = earthRopeGap(6378.1, added);
    EXPECT_NEAR(gap, added / (2.0 * PI), EPS);
}

TEST(EarthRopeTest, ZeroAddedLength) {
    double gap = earthRopeGap(6378.1, 0.0);
    EXPECT_NEAR(gap, 0.0, EPS);
}

TEST(EarthRopeTest, DifferentEarthRadius) {
    double added = 2.0;
    double gap1 = earthRopeGap(6378.1, added);
    double gap2 = earthRopeGap(1000.0, added);
    EXPECT_NEAR(gap1, gap2, EPS);
    EXPECT_NEAR(gap1, added / (2.0 * PI), EPS);
}

TEST(EarthRopeTest, NegativeAddedLength) {
    double gap = earthRopeGap(6378.1, -1.0);
    EXPECT_NEAR(gap, -1.0 / (2.0 * PI), EPS);
}

TEST(EarthRopeTest, RadiusInKmConversion) {
    double radiusKm = 1.0;
    double added = 1.0;
    double gap = earthRopeGap(radiusKm, added);
    EXPECT_NEAR(gap, added / (2.0 * PI), EPS);
}

// ==================== "Бассейн" ====================

TEST(PoolCostsTest, GivenExample) {
    double concreteCost, fenceCost;
    poolCosts(3.0, 1.0, 1000.0, 2000.0, concreteCost, fenceCost);

    double expectedPathArea = PI * 7.0;
    double expectedConcreteCost = expectedPathArea * 1000.0;
    double expectedFenceLength = 2.0 * PI * 4.0;
    double expectedFenceCost = expectedFenceLength * 2000.0;

    EXPECT_NEAR(concreteCost, expectedConcreteCost, EPS);
    EXPECT_NEAR(fenceCost, expectedFenceCost, EPS);
}

TEST(PoolCostsTest, ZeroPathWidth) {
    double concreteCost, fenceCost;
    poolCosts(3.0, 0.0, 1000.0, 2000.0, concreteCost, fenceCost);
    EXPECT_NEAR(concreteCost, 0.0, EPS);
    EXPECT_NEAR(fenceCost, 2.0 * PI * 3.0 * 2000.0, EPS);
}

TEST(PoolCostsTest, DifferentPoolRadius) {
    double concreteCost, fenceCost;
    poolCosts(5.0, 2.0, 500.0, 1000.0, concreteCost, fenceCost);
    double outerRadius = 7.0;
    double pathArea = PI * (outerRadius * outerRadius - 25.0);
    double expectedConcrete = pathArea * 500.0;
    double expectedFence = (2.0 * PI * outerRadius) * 1000.0;
    EXPECT_NEAR(concreteCost, expectedConcrete, EPS);
    EXPECT_NEAR(fenceCost, expectedFence, EPS);
}

TEST(PoolCostsTest, ZeroPoolRadius) {
    double concreteCost, fenceCost;
    poolCosts(0.0, 1.0, 1000.0, 2000.0, concreteCost, fenceCost);
    double expectedConcrete = PI * 1.0 * 1.0 * 1000.0;
    double expectedFence = (2.0 * PI * 1.0) * 2000.0;
    EXPECT_NEAR(concreteCost, expectedConcrete, EPS);
    EXPECT_NEAR(fenceCost, expectedFence, EPS);
}

TEST(PoolCostsTest, NegativeValues) {
    double concreteCost, fenceCost;
    poolCosts(-3.0, -1.0, 1000.0, 2000.0, concreteCost, fenceCost);
    EXPECT_NEAR(concreteCost, 0.0, EPS);
    EXPECT_NEAR(fenceCost, 0.0, EPS);
}

TEST(PoolCostsTest, VeryLargeValues) {
    double concreteCost, fenceCost;
    double poolRad = 1e6;
    double width = 1e5;
    poolCosts(poolRad, width, 1.0, 1.0, concreteCost, fenceCost);
    double outerRad = poolRad + width;
    double expectedConcrete = PI * (outerRad * outerRad - poolRad * poolRad);
    double expectedFence = 2.0 * PI * outerRad;
    EXPECT_NEAR(concreteCost, expectedConcrete, EPS);
    EXPECT_NEAR(fenceCost, expectedFence, EPS);
}

TEST(CircleTest, CopySemantics) {
    Circle c1(2.5);
    Circle c2 = c1;
    EXPECT_NEAR(c2.getRadius(), c1.getRadius(), EPS);
    EXPECT_NEAR(c2.getFerence(), c1.getFerence(), EPS);
    EXPECT_NEAR(c2.getArea(), c1.getArea(), EPS);
    c2.setRadius(10.0);
    EXPECT_NE(c1.getRadius(), c2.getRadius());
}

TEST(EarthRopeTest, VeryLargeAddedLength) {
    double added = 1e6;
    double gap = earthRopeGap(6378.1, added);
    EXPECT_NEAR(gap, added / (2.0 * PI), 1e-6);
}

TEST(PoolCostsTest, DifferentCosts) {
    double concreteCost, fenceCost;
    poolCosts(2.0, 0.5, 800.0, 1500.0, concreteCost, fenceCost);
    double outerR = 2.5;
    double pathArea = PI * (outerR * outerR - 4.0);
    double expectedConcrete = pathArea * 800.0;
    double expectedFence = (2.0 * PI * outerR) * 1500.0;
    EXPECT_NEAR(concreteCost, expectedConcrete, EPS);
    EXPECT_NEAR(fenceCost, expectedFence, EPS);
}
