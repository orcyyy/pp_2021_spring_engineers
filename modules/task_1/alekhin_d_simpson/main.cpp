// Copyright 2021 Alekhin Denis
#include <gtest/gtest.h>
#include <math.h>
#include "../../modules/task_1/alekhin_d_simpson/simpson.h"

#define PI 3.14159265

// y = x1( * x2 * ...)
std::function<double(std::vector<double>)> f1 = [](std::vector<double> arg) {
  double result = 1;
  for (size_t i = 0; i < arg.size(); i++) {
    result *= arg[i];
  }
  return result;
};

// y = x1( + x2 + ...)
std::function<double(std::vector<double>)> f2 = [](std::vector<double> arg) {
  double result = 0;
  for (size_t i = 0; i < arg.size(); i++) {
    result += arg[i];
  }
  return result;
};

// y = sin(x1)( + sin(x2) + ...)
std::function<double(std::vector<double>)> f3 = [](std::vector<double> arg) {
  double result = 0;
  for (size_t i = 0; i < arg.size(); i++) {
    result += sin(arg[i]);
  }
  return result;
};

TEST(Functions_Test, Function_F1_Test1) {
  std::vector<double> arg = { 1 };

  EXPECT_DOUBLE_EQ(1.0, f1(arg));
}

TEST(Functions_Test, Function_F1_Test2) {
  std::vector<double> arg = { 5, 20 };

  EXPECT_DOUBLE_EQ(100.0, f1(arg));
}

TEST(Functions_Test, Function_F1_Test3) {
  std::vector<double> arg = { 1, 2, -1, 20, 0.001, 20 };

  EXPECT_DOUBLE_EQ(-0.8, f1(arg));
}

TEST(Input_Data_Test, Scope_Interval_Test1) {
  std::vector<std::pair<double, double>> scope =
  { std::make_pair(1, 0) };

  EXPECT_ANY_THROW(simpsonMethod(scope, f1, 10));
}

TEST(Input_Data_Test, Scope_Interval_Test2) {
  std::vector<std::pair<double, double>> scope = {
    std::make_pair(-1, 1),
    std::make_pair(1, 0) };

  EXPECT_ANY_THROW(simpsonMethod(scope, f1, 10));
}

TEST(Input_Data_Test, Scope_Interval_Test3) {
  std::vector<std::pair<double, double>> scope;

  EXPECT_ANY_THROW(simpsonMethod(scope, f1, 10));
}

TEST(Input_Data_Test, Precision_Test) {
  std::vector<std::pair<double, double>> scope =
  { std::make_pair(0, 10) };

  EXPECT_ANY_THROW(simpsonMethod(scope, f1, 0));
}

TEST(Simpson_Method_Test, Simpson_Test1) {
  std::vector<std::pair<double, double>> scope = {
    std::make_pair(0, 10) };

  EXPECT_DOUBLE_EQ(50, simpsonMethod(scope, f1, 10));
}

TEST(Simpson_Method_Test, Simpson_Test2) {
  std::vector<std::pair<double, double>> scope = {
    std::make_pair(-5, 5),
    std::make_pair(-5, 5) };

  EXPECT_DOUBLE_EQ(0, simpsonMethod(scope, f2, 2));
}

TEST(Simpson_Method_Test, Simpson_Test3) {
  std::vector<std::pair<double, double>> scope = {
    std::make_pair(0, 8) };

  EXPECT_DOUBLE_EQ(32, simpsonMethod(scope, f2, 16));
}

TEST(Simpson_Method_Test, Simpson_Test4) {
  std::vector<std::pair<double, double>> scope = {
    std::make_pair(0, 8),
    std::make_pair(0, 8) };

  EXPECT_DOUBLE_EQ(512, simpsonMethod(scope, f2, 16));
}

TEST(Simpson_Method_Test, Simpson_Test5) {
  std::vector<std::pair<double, double>> scope = {
    std::make_pair(0, 8),
    std::make_pair(0, 8) };

  EXPECT_DOUBLE_EQ(512, simpsonMethod(scope, f2, 2));
}

TEST(Simpson_Method_Test, Simpson_Test6) {
  std::vector<std::pair<double, double>> scope = {
    std::make_pair(0, 8),
    std::make_pair(0, 8) };

  EXPECT_DOUBLE_EQ(512, simpsonMethod(scope, f2, 8));
}

TEST(Simpson_Method_Test, Simpson_Test7) {
  std::vector<std::pair<double, double>> scope = {
    std::make_pair(-3, 12),
    std::make_pair(7, 9) };

  EXPECT_DOUBLE_EQ(375, simpsonMethod(scope, f2, 20));
}

TEST(Simpson_Method_Test, Simpson_Test8) {
  std::vector<std::pair<double, double>> scope = {
    std::make_pair(-3, 12),
    std::make_pair(7, 9),
    std::make_pair(0, 5) };

  EXPECT_NEAR(2250, simpsonMethod(scope, f2, 1000), 1);
}

TEST(Simpson_Method_Test, Simpson_Test9) {
  std::vector<std::pair<double, double>> scope = {
    std::make_pair(5, 10),
    std::make_pair(-10, -5),
    std::make_pair(0, 2) };

  EXPECT_NEAR(35.4, simpsonMethod(scope, f3, 10), 0.1);
}

TEST(Simpson_Method_Test, Simpson_Test10) {
  std::vector<std::pair<double, double>> scope = {
    std::make_pair(5, 10),
    std::make_pair(-10, -5) };

  EXPECT_NEAR(0, simpsonMethod(scope, f3, 10), 0.1);
}

TEST(Simpson_Method_Test, Simpson_Test11) {
  std::vector<std::pair<double, double>> scope = {
    std::make_pair(5, 10) };

  EXPECT_NEAR(1.12, simpsonMethod(scope, f3, 10), 0.01);
}
