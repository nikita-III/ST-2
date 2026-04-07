// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include "circle.h"
#include "tasks.h"

TEST(CircleTest, radius_upd) { // t
  Circle c(10);

  EXPECT_NEAR(c.getFerence(), 62.8318, 0.001);
}

TEST(CircleTest, ference_upd) {
  Circle c(0);

  c.setFerence(62.8318);

  EXPECT_NEAR(c.getRadius(), 10.0, 0.001);
}

TEST(CircleCore, pi) {
  Circle c(1.0);

  EXPECT_NEAR(c.getArea(), PI, 1e-9);
}

TEST(CircleUpdate, radius_ference) {
  Circle c(1.0);

  c.setRadius(2.0);

  EXPECT_NEAR(c.getFerence(), 12.56637, 1e-5);
}

TEST(CircleUpdate, radius_area) {
  Circle c(1.0);

  c.setRadius(3.0);

  EXPECT_NEAR(c.getArea(), 28.27433, 1e-5);
}

TEST(CircleUpdate, ference_radius) {
  Circle c(1.0);

  c.setFerence(31.4159);

  EXPECT_NEAR(c.getRadius(), 5.0, 1e-4);
}

TEST(CircleUpdate, ference_area) {
  Circle c(1.0);

  c.setFerence(6.28318);

  EXPECT_NEAR(c.getArea(), 3.14159, 1e-5);
}

TEST(CircleUpdate, area_radius) {
  Circle c(1.0);

  c.setArea(78.5398);

  EXPECT_NEAR(c.getRadius(), 5.0, 1e-4);
}

TEST(CircleUpdate, area) {
  Circle c(1.0);

  c.setArea(12.56637);

  EXPECT_NEAR(c.getFerence(), 12.56637, 1e-5);
}

TEST(CircleEdge, S_mall) {
  Circle c(10.0);

  c.setArea(1e-10);

  EXPECT_NEAR(c.getRadius(), 0.00000564, 1e-8);
  EXPECT_NEAR(c.getFerence(), 0.00003544, 1e-8);
}

TEST(CircleEdge, r_0) {
  Circle c(0.0);

  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
}

TEST(CircleEdge, circe_big_num) {
  Circle c(1e6);

  EXPECT_NEAR(c.getFerence(), 6283185.3, 0.1);
}

TEST(TaskPool, concrete) {
  double total = taskPool(3, 1, 1000, 0);

  EXPECT_NEAR(total, 21991.1, 0.1);
}

TEST(TaskPool, normal) {
  double total = taskPool(3, 1, 1000, 2000);

  EXPECT_NEAR(total, 72256.6, 0.1);
}

TEST(TaskPool, no_way) {
  Circle pool(3);

  double total = taskPool(3, 0, 1000, 2000);

  EXPECT_NEAR(total, pool.getFerence() * 2000, 0.1);
}

TEST(TaskPool, no_money) {
  double total = taskPool(5, 2, 0, 0);

  EXPECT_DOUBLE_EQ(total, 0.0);
}

TEST(TaskPool, pool_small) {
  double total = taskPool(1, 0.5, 1000, 2000);

  EXPECT_NEAR(total, 22776.5, 0.1);
}

TEST(TaskPool, big_num) {
  double total = taskPool(10, 2, 1000000, 1000000);

  EXPECT_NEAR(total, 213628300.4, 1.0);
}

TEST(Tasks, the_task) {
  double gap = taskEarth(6378.1, 1.0);

  EXPECT_NEAR(gap, 0.159, 0.001);
}

TEST(TaskEarth, gap_norm) {
  double gap = taskEarth(6378.1, 1.0);

  EXPECT_NEAR(gap, 0.159, 0.001);
}

TEST(TaskEarth, gap_10_m) {
  double gap = taskEarth(6378.1, 10.0);

  EXPECT_NEAR(gap, 1.591, 0.001);
}

TEST(TaskEarth, gap_small) {
  double gapEarth = taskEarth(6378.1, 1.0);
  double gapTennisBall = taskEarth(0.000067, 1.0);

  EXPECT_NEAR(gapEarth, gapTennisBall, 1e-7);
}

TEST(TaskEarth, l_neg) {
  double gap = taskEarth(6378.1, -1.0);

  EXPECT_NEAR(gap, -0.159, 0.001);
}
