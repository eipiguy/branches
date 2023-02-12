#include <gtest/gtest.h>
#include "../headers/geom.hpp"

#define _USE_MATH_DEFINES
#include <math.h>
#include <limits>

TEST(PointTests, StartsWithDefaults) {
  Point testPt;
  
  EXPECT_DOUBLE_EQ( testPt[0], 0 );
  EXPECT_DOUBLE_EQ( testPt[1], 0 );
  EXPECT_DOUBLE_EQ( testPt[2], 0 );

  EXPECT_DOUBLE_EQ( testPt.x, 0 );
  EXPECT_DOUBLE_EQ( testPt.y, 0 );
  EXPECT_DOUBLE_EQ( testPt.z, 0 );
}

TEST(PointTests, Assignment) {
  Point testPt(1,2,3);
  EXPECT_DOUBLE_EQ( testPt.x, 1 );
  EXPECT_DOUBLE_EQ( testPt.y, 2 );
  EXPECT_DOUBLE_EQ( testPt.z, 3 );

  testPt = { 4, 5, 6 };
  EXPECT_DOUBLE_EQ( testPt.x, 4 );
  EXPECT_DOUBLE_EQ( testPt.y, 5 );
  EXPECT_DOUBLE_EQ( testPt.z, 6 );

  testPt.x = 7;
  EXPECT_DOUBLE_EQ( testPt.x, 7 );

  testPt[2] = 8;
  EXPECT_DOUBLE_EQ( testPt[2], 8 );
}

TEST(PointTests, DistanceBetween) {
  Point testPt(1,2,2);
  EXPECT_DOUBLE_EQ( testPt.distance(testPt), 0);
  EXPECT_DOUBLE_EQ( testPt.distance(Point(0,0,0)), 3);
}

TEST(CVectorTests, StartsWithDefaults) {
  CVector testCVec;
  EXPECT_DOUBLE_EQ( testCVec.dx, 0 );
  EXPECT_DOUBLE_EQ( testCVec.dy, 0 );
  EXPECT_DOUBLE_EQ( testCVec.dz, 1 );

  EXPECT_DOUBLE_EQ( testCVec[0], 0 );
  EXPECT_DOUBLE_EQ( testCVec[1], 0 );
  EXPECT_DOUBLE_EQ( testCVec[2], 1 );
}

TEST(CVectorTests, Assignment) {
  CVector testCVec(1,2,3);
  EXPECT_DOUBLE_EQ( testCVec.dx, 1 );
  EXPECT_DOUBLE_EQ( testCVec.dy, 2 );
  EXPECT_DOUBLE_EQ( testCVec.dz, 3 );

  testCVec = { 4, 5, 6 };
  EXPECT_DOUBLE_EQ( testCVec[0], 4 );
  EXPECT_DOUBLE_EQ( testCVec[1], 5 );
  EXPECT_DOUBLE_EQ( testCVec[2], 6 );

  testCVec.dx = 7;
  EXPECT_DOUBLE_EQ( testCVec.dx, 7 );

  testCVec[0] = 8;
  EXPECT_DOUBLE_EQ( testCVec[0], 8 );
}

TEST(CVectorTests, Length) {
  CVector testCVec;
  EXPECT_DOUBLE_EQ( testCVec.length(), 1 );

  testCVec = { 1, 2, 2 };
  EXPECT_DOUBLE_EQ( testCVec.length(), 3 );

  testCVec = { 0, 0, 0 };
  EXPECT_DOUBLE_EQ( testCVec.length(), 0 );
}

TEST(CVectorTests, Add) {
  CVector testCVecL(1,1,1);
  CVector testCVecR(2,2,2);
  CVector testCVec = testCVecL + testCVecR;
  EXPECT_DOUBLE_EQ( testCVec.dx, 3 );
  EXPECT_DOUBLE_EQ( testCVec.dy, 3 );
  EXPECT_DOUBLE_EQ( testCVec.dz, 3 );
}

TEST(CVectorTests, Subtract) {
  CVector testCVecL(3,3,3);
  CVector testCVecR(2,2,2);
  CVector testCVec = testCVecL - testCVecR;
  EXPECT_DOUBLE_EQ( testCVec.dx, 1 );
  EXPECT_DOUBLE_EQ( testCVec.dy, 1 );
  EXPECT_DOUBLE_EQ( testCVec.dz, 1 );
}

TEST(CVectorTests, MakeBySubtractingPoints) {
  CVector endPt(3,3,3);
  CVector startPt(2,2,2);
  CVector testCVec = endPt - startPt;
}

TEST(CVectorTests, Scale) {
  double scale = 3;
  CVector testCVec(0,1,2);

  testCVec = scale*testCVec;
  EXPECT_DOUBLE_EQ( testCVec.dx, 0 );
  EXPECT_DOUBLE_EQ( testCVec.dy, 3 );
  EXPECT_DOUBLE_EQ( testCVec.dz, 6 );
}

TEST(CVectorTests, Normalize) {
  CVector testCVec(0,0,2);
  testCVec.normalize();
  EXPECT_DOUBLE_EQ( testCVec.dx, 0 );
  EXPECT_DOUBLE_EQ( testCVec.dy, 0 );
  EXPECT_DOUBLE_EQ( testCVec.dz, 1 );

  testCVec = { 1, 1, 1 };
  testCVec.normalize();
  EXPECT_DOUBLE_EQ( testCVec.length(), 1 );

  testCVec = { 0, 0, 0 };
  testCVec.normalize();
  EXPECT_DOUBLE_EQ( testCVec.dx, 0 );
  EXPECT_DOUBLE_EQ( testCVec.dy, 0 );
  EXPECT_DOUBLE_EQ( testCVec.dz, 0 );
}

TEST(CVectorTests, DotProduct) {
  CVector testCVecL(0,1,0);
  CVector testCVecR(0,0,1);
  EXPECT_DOUBLE_EQ( testCVecL*testCVecR, 0 );
}

TEST(CVectorTests, CrossProduct) {
  CVector testCVecL(0,1,0);
  CVector testCVecR(0,0,1);
  CVector testCVec = testCVecL.cross(testCVecR);
  EXPECT_DOUBLE_EQ( testCVec.dx, 1 );
  EXPECT_DOUBLE_EQ( testCVec.dy, 0 );
  EXPECT_DOUBLE_EQ( testCVec.dz, 0 );
}

TEST(CVectorTests, RotateAroundAxis) {
  CVector testCVec(1,0,0);
  CVector rotationAxis(0,1,0);
  testCVec.rotate(-M_PI/2,rotationAxis);
  // fails with 0 != ~ 1e-16
  // EXPECT_DOUBLE_EQ( testCVec.dx, 0 );
  // EXPECT_DOUBLE_EQ( testCVec.dy, 0 );
  // EXPECT_DOUBLE_EQ( testCVec.dz, 1 );
  EXPECT_NEAR( testCVec.dx, 0, DBL_EPSILON );
  EXPECT_NEAR( testCVec.dy, 0, DBL_EPSILON );
  EXPECT_NEAR( testCVec.dz, 1, DBL_EPSILON );
}