#include <gtest/gtest.h>

#include <cmath>

#include "../model/arithmetic_calculator/arithmetic_calculator.h"

namespace s21 {

class CalculatorTest : public testing::Test {
 protected:
  ArithmeticCalculator calculator_;
};

TEST_F(CalculatorTest, WrongExpression) {
  EXPECT_ANY_THROW(calculator_.Calculate(1));
  EXPECT_ANY_THROW(calculator_.Calculate("sinX"));
  EXPECT_ANY_THROW(calculator_.Calculate("asd"));
  EXPECT_ANY_THROW(calculator_.Calculate("*sin(X)"));
  EXPECT_ANY_THROW(calculator_.Calculate("+*1"));
  EXPECT_ANY_THROW(calculator_.Calculate("-1**12"));
  EXPECT_ANY_THROW(calculator_.Calculate("^log(12)"));
  EXPECT_ANY_THROW(calculator_.Calculate("sin(1"));
  EXPECT_ANY_THROW(calculator_.Calculate("(1"));
  EXPECT_ANY_THROW(calculator_.Calculate("1)"));
  EXPECT_ANY_THROW(calculator_.Calculate("((1)"));
  EXPECT_ANY_THROW(calculator_.Calculate("(1))"));
  EXPECT_ANY_THROW(calculator_.Calculate("(1))*sin(1)-()"));
  EXPECT_ANY_THROW(calculator_.Calculate("(1))*sin(1)-)"));
  EXPECT_ANY_THROW(calculator_.Calculate("1(+1)"));
}

TEST_F(CalculatorTest, SimpleExpressions) {
  EXPECT_EQ(calculator_.Calculate("1+1"), 2);
  EXPECT_EQ(calculator_.Calculate("2+1"), 3);
  EXPECT_EQ(calculator_.Calculate("1-2"), -1);
  EXPECT_EQ(calculator_.Calculate("3+6"), 9);
  EXPECT_EQ(calculator_.Calculate("sin(1)"), sin(1));
  EXPECT_EQ(calculator_.Calculate("cos(1)"), cos(1));
  EXPECT_EQ(calculator_.Calculate("tan(1)"), tan(1));
  EXPECT_EQ(calculator_.Calculate("asin(1)"), asin(1));
  EXPECT_EQ(calculator_.Calculate("acos(1)"), acos(1));
  EXPECT_EQ(calculator_.Calculate("atan(1)"), atan(1));
  EXPECT_EQ(calculator_.Calculate("ln(1)"), log(1));
  EXPECT_EQ(calculator_.Calculate("log(1)"), log10(1));
  EXPECT_EQ(calculator_.Calculate("sqrt(2)"), sqrt(2));
}

TEST_F(CalculatorTest, UnaryPlus) {
  EXPECT_EQ(calculator_.Calculate("+0"), 0);
  EXPECT_EQ(calculator_.Calculate("+1"), 1);
  EXPECT_EQ(calculator_.Calculate("+2"), 2);
  EXPECT_EQ(calculator_.Calculate("+3"), 3);
  EXPECT_EQ(calculator_.Calculate("+4"), 4);
  EXPECT_EQ(calculator_.Calculate("+5"), 5);
  EXPECT_EQ(calculator_.Calculate("+6"), 6);
  EXPECT_EQ(calculator_.Calculate("+7"), 7);
  EXPECT_EQ(calculator_.Calculate("+8"), 8);
  EXPECT_EQ(calculator_.Calculate("+9"), 9);
  EXPECT_EQ(calculator_.Calculate("+0.1"), 0.1);
  EXPECT_EQ(calculator_.Calculate("+1.5"), 1.5);
  EXPECT_EQ(calculator_.Calculate("+2.6"), 2.6);
}

TEST_F(CalculatorTest, UnaryMinus) {
  EXPECT_EQ(calculator_.Calculate("-0"), -0);
  EXPECT_EQ(calculator_.Calculate("-1"), -1);
  EXPECT_EQ(calculator_.Calculate("-2"), -2);
  EXPECT_EQ(calculator_.Calculate("-3"), -3);
  EXPECT_EQ(calculator_.Calculate("-4"), -4);
  EXPECT_EQ(calculator_.Calculate("-5"), -5);
  EXPECT_EQ(calculator_.Calculate("-6"), -6);
  EXPECT_EQ(calculator_.Calculate("-7"), -7);
  EXPECT_EQ(calculator_.Calculate("-8"), -8);
  EXPECT_EQ(calculator_.Calculate("-9"), -9);
  EXPECT_EQ(calculator_.Calculate("-0.1"), -0.1);
  EXPECT_EQ(calculator_.Calculate("-1.5"), -1.5);
  EXPECT_EQ(calculator_.Calculate("-2.6"), -2.6);
}

TEST_F(CalculatorTest, Plus) {
  EXPECT_EQ(calculator_.Calculate("0+1"), 1);
  EXPECT_EQ(calculator_.Calculate("1+2"), 3);
  EXPECT_EQ(calculator_.Calculate("2+3"), 5);
  EXPECT_EQ(calculator_.Calculate("3+4"), 7);
  EXPECT_EQ(calculator_.Calculate("4+5"), 9);
}

TEST_F(CalculatorTest, Minus) {
  EXPECT_EQ(calculator_.Calculate("0-1"), -1);
  EXPECT_EQ(calculator_.Calculate("1-2"), -1);
  EXPECT_EQ(calculator_.Calculate("2-3"), -1);
  EXPECT_EQ(calculator_.Calculate("3-1"), 2);
  EXPECT_EQ(calculator_.Calculate("4-3"), 1);
}

TEST_F(CalculatorTest, Mul) {
  EXPECT_EQ(calculator_.Calculate("0*1"), 0);
  EXPECT_EQ(calculator_.Calculate("1*2"), 2);
  EXPECT_EQ(calculator_.Calculate("2*3"), 6);
  EXPECT_EQ(calculator_.Calculate("3*1"), 3);
  EXPECT_EQ(calculator_.Calculate("4*3"), 12);
}

TEST_F(CalculatorTest, Div) {
  EXPECT_EQ(calculator_.Calculate("0/1"), 0.0 / 1.0);
  EXPECT_EQ(calculator_.Calculate("1/2"), 1.0 / 2.0);
  EXPECT_EQ(calculator_.Calculate("2/3"), 2.0 / 3.0);
  EXPECT_EQ(calculator_.Calculate("3/1"), 3.0 / 1.0);
  EXPECT_EQ(calculator_.Calculate("4/3"), 4.0 / 3.0);
}

TEST_F(CalculatorTest, Mod) {
  EXPECT_EQ(calculator_.Calculate("0mod1"), fmod(0.0, 1.0));
  EXPECT_EQ(calculator_.Calculate("1mod2"), fmod(1.0, 2.0));
  EXPECT_EQ(calculator_.Calculate("2mod3"), fmod(2.0, 3.0));
  EXPECT_EQ(calculator_.Calculate("3mod1"), fmod(3.0, 1.0));
  EXPECT_EQ(calculator_.Calculate("4mod3"), fmod(4.0, 3.0));
}

TEST_F(CalculatorTest, Pow) {
  EXPECT_EQ(calculator_.Calculate("0^1"), pow(0.0, 1.0));
  EXPECT_EQ(calculator_.Calculate("1^2"), pow(1.0, 2.0));
  EXPECT_EQ(calculator_.Calculate("2^3"), pow(2.0, 3.0));
  EXPECT_EQ(calculator_.Calculate("3^1"), pow(3.0, 1.0));
  EXPECT_EQ(calculator_.Calculate("4^3"), pow(4.0, 3.0));
  EXPECT_EQ(calculator_.Calculate("2^2^3"), pow(2, pow(2, 3)));
}

TEST_F(CalculatorTest, Sin) {
  EXPECT_EQ(calculator_.Calculate("sin(0.0)"), sin(0.0));
  EXPECT_EQ(calculator_.Calculate("sin(1.0)"), sin(1.0));
  EXPECT_EQ(calculator_.Calculate("sin(2.0)"), sin(2.0));
  EXPECT_EQ(calculator_.Calculate("sin(3.0)"), sin(3.0));
  EXPECT_EQ(calculator_.Calculate("sin(4.0)"), sin(4.0));
  EXPECT_EQ(calculator_.Calculate("sin(5.0)"), sin(5.0));
  EXPECT_EQ(calculator_.Calculate("sin(6.0)"), sin(6.0));
  EXPECT_EQ(calculator_.Calculate("sin(7.0)"), sin(7.0));
  EXPECT_EQ(calculator_.Calculate("sin(8.0)"), sin(8.0));
  EXPECT_EQ(calculator_.Calculate("sin(9.0)"), sin(9.0));
  EXPECT_EQ(calculator_.Calculate("sin(0.1)"), sin(0.1));
  EXPECT_EQ(calculator_.Calculate("sin(1.5)"), sin(1.5));
  EXPECT_EQ(calculator_.Calculate("sin(2.6)"), sin(2.6));
}

TEST_F(CalculatorTest, Cos) {
  EXPECT_EQ(calculator_.Calculate("cos(0.0)"), cos(0.0));
  EXPECT_EQ(calculator_.Calculate("cos(1.0)"), cos(1.0));
  EXPECT_EQ(calculator_.Calculate("cos(2.0)"), cos(2.0));
  EXPECT_EQ(calculator_.Calculate("cos(3.0)"), cos(3.0));
  EXPECT_EQ(calculator_.Calculate("cos(4.0)"), cos(4.0));
  EXPECT_EQ(calculator_.Calculate("cos(5.0)"), cos(5.0));
  EXPECT_EQ(calculator_.Calculate("cos(6.0)"), cos(6.0));
  EXPECT_EQ(calculator_.Calculate("cos(7.0)"), cos(7.0));
  EXPECT_EQ(calculator_.Calculate("cos(8.0)"), cos(8.0));
  EXPECT_EQ(calculator_.Calculate("cos(9.0)"), cos(9.0));
  EXPECT_EQ(calculator_.Calculate("cos(0.1)"), cos(0.1));
  EXPECT_EQ(calculator_.Calculate("cos(1.5)"), cos(1.5));
  EXPECT_EQ(calculator_.Calculate("cos(2.6)"), cos(2.6));
}

TEST_F(CalculatorTest, Tan) {
  EXPECT_EQ(calculator_.Calculate("tan(0.0)"), tan(0.0));
  EXPECT_EQ(calculator_.Calculate("tan(1.0)"), tan(1.0));
  EXPECT_EQ(calculator_.Calculate("tan(2.0)"), tan(2.0));
  EXPECT_EQ(calculator_.Calculate("tan(3.0)"), tan(3.0));
  EXPECT_EQ(calculator_.Calculate("tan(4.0)"), tan(4.0));
  EXPECT_EQ(calculator_.Calculate("tan(5.0)"), tan(5.0));
  EXPECT_EQ(calculator_.Calculate("tan(6.0)"), tan(6.0));
  EXPECT_EQ(calculator_.Calculate("tan(7.0)"), tan(7.0));
  EXPECT_EQ(calculator_.Calculate("tan(8.0)"), tan(8.0));
  EXPECT_EQ(calculator_.Calculate("tan(9.0)"), tan(9.0));
  EXPECT_EQ(calculator_.Calculate("tan(0.1)"), tan(0.1));
  EXPECT_EQ(calculator_.Calculate("tan(1.5)"), tan(1.5));
  EXPECT_EQ(calculator_.Calculate("tan(2.6)"), tan(2.6));
}

TEST_F(CalculatorTest, Asin) {
  EXPECT_EQ(calculator_.Calculate("asin(0.0)"), asin(0.0));
  EXPECT_EQ(calculator_.Calculate("asin(0.1)"), asin(0.1));
  EXPECT_EQ(calculator_.Calculate("asin(1.0)"), asin(1.0));
  EXPECT_TRUE(std::isnan(calculator_.Calculate("asin(2.0)")));
  EXPECT_TRUE(std::isnan(calculator_.Calculate("asin(3.0)")));
  EXPECT_TRUE(std::isnan(calculator_.Calculate("asin(4.0)")));
  EXPECT_TRUE(std::isnan(calculator_.Calculate("asin(5.0)")));
  EXPECT_TRUE(std::isnan(calculator_.Calculate("asin(6.0)")));
  EXPECT_TRUE(std::isnan(calculator_.Calculate("asin(7.0)")));
  EXPECT_TRUE(std::isnan(calculator_.Calculate("asin(8.0)")));
  EXPECT_TRUE(std::isnan(calculator_.Calculate("asin(9.0)")));
  EXPECT_TRUE(std::isnan(calculator_.Calculate("asin(1.5)")));
  EXPECT_TRUE(std::isnan(calculator_.Calculate("asin(2.6)")));
}

TEST_F(CalculatorTest, Acos) {
  EXPECT_EQ(calculator_.Calculate("acos(0.0)"), acos(0.0));
  EXPECT_EQ(calculator_.Calculate("acos(0.1)"), acos(0.1));
  EXPECT_EQ(calculator_.Calculate("acos(1.0)"), acos(1.0));
  EXPECT_TRUE(std::isnan(calculator_.Calculate("acos(2.0)")));
  EXPECT_TRUE(std::isnan(calculator_.Calculate("acos(3.0)")));
  EXPECT_TRUE(std::isnan(calculator_.Calculate("acos(4.0)")));
  EXPECT_TRUE(std::isnan(calculator_.Calculate("acos(5.0)")));
  EXPECT_TRUE(std::isnan(calculator_.Calculate("acos(6.0)")));
  EXPECT_TRUE(std::isnan(calculator_.Calculate("acos(7.0)")));
  EXPECT_TRUE(std::isnan(calculator_.Calculate("acos(8.0)")));
  EXPECT_TRUE(std::isnan(calculator_.Calculate("acos(9.0)")));
  EXPECT_TRUE(std::isnan(calculator_.Calculate("acos(1.5)")));
  EXPECT_TRUE(std::isnan(calculator_.Calculate("acos(2.6)")));
}

TEST_F(CalculatorTest, Atan) {
  EXPECT_EQ(calculator_.Calculate("atan(0.0)"), atan(0.0));
  EXPECT_EQ(calculator_.Calculate("atan(1.0)"), atan(1.0));
  EXPECT_EQ(calculator_.Calculate("atan(2.0)"), atan(2.0));
  EXPECT_EQ(calculator_.Calculate("atan(3.0)"), atan(3.0));
  EXPECT_EQ(calculator_.Calculate("atan(4.0)"), atan(4.0));
  EXPECT_EQ(calculator_.Calculate("atan(5.0)"), atan(5.0));
  EXPECT_EQ(calculator_.Calculate("atan(6.0)"), atan(6.0));
  EXPECT_EQ(calculator_.Calculate("atan(7.0)"), atan(7.0));
  EXPECT_EQ(calculator_.Calculate("atan(8.0)"), atan(8.0));
  EXPECT_EQ(calculator_.Calculate("atan(9.0)"), atan(9.0));
  EXPECT_EQ(calculator_.Calculate("atan(0.1)"), atan(0.1));
  EXPECT_EQ(calculator_.Calculate("atan(1.5)"), atan(1.5));
  EXPECT_EQ(calculator_.Calculate("atan(2.6)"), atan(2.6));
}

TEST_F(CalculatorTest, Ln) {
  EXPECT_EQ(calculator_.Calculate("ln(0.0)"), log(0.0));
  EXPECT_EQ(calculator_.Calculate("ln(1.0)"), log(1.0));
  EXPECT_EQ(calculator_.Calculate("ln(2.0)"), log(2.0));
  EXPECT_EQ(calculator_.Calculate("ln(3.0)"), log(3.0));
  EXPECT_EQ(calculator_.Calculate("ln(4.0)"), log(4.0));
  EXPECT_EQ(calculator_.Calculate("ln(5.0)"), log(5.0));
  EXPECT_EQ(calculator_.Calculate("ln(6.0)"), log(6.0));
  EXPECT_EQ(calculator_.Calculate("ln(7.0)"), log(7.0));
  EXPECT_EQ(calculator_.Calculate("ln(8.0)"), log(8.0));
  EXPECT_EQ(calculator_.Calculate("ln(9.0)"), log(9.0));
  EXPECT_EQ(calculator_.Calculate("ln(0.1)"), log(0.1));
  EXPECT_EQ(calculator_.Calculate("ln(1.5)"), log(1.5));
  EXPECT_EQ(calculator_.Calculate("ln(2.6)"), log(2.6));
}

TEST_F(CalculatorTest, Log) {
  EXPECT_EQ(calculator_.Calculate("log(0.0)"), log10(0.0));
  EXPECT_EQ(calculator_.Calculate("log(1.0)"), log10(1.0));
  EXPECT_EQ(calculator_.Calculate("log(2.0)"), log10(2.0));
  EXPECT_EQ(calculator_.Calculate("log(3.0)"), log10(3.0));
  EXPECT_EQ(calculator_.Calculate("log(4.0)"), log10(4.0));
  EXPECT_EQ(calculator_.Calculate("log(5.0)"), log10(5.0));
  EXPECT_EQ(calculator_.Calculate("log(6.0)"), log10(6.0));
  EXPECT_EQ(calculator_.Calculate("log(7.0)"), log10(7.0));
  EXPECT_EQ(calculator_.Calculate("log(8.0)"), log10(8.0));
  EXPECT_EQ(calculator_.Calculate("log(9.0)"), log10(9.0));
  EXPECT_EQ(calculator_.Calculate("log(0.1)"), log10(0.1));
  EXPECT_EQ(calculator_.Calculate("log(1.5)"), log10(1.5));
  EXPECT_EQ(calculator_.Calculate("log(2.6)"), log10(2.6));
}

TEST_F(CalculatorTest, Sqrt) {
  EXPECT_EQ(calculator_.Calculate("sqrt(0.0)"), sqrt(0.0));
  EXPECT_EQ(calculator_.Calculate(0), sqrt(0.0));
  EXPECT_EQ(calculator_.Calculate("sqrt(1.0)"), sqrt(1.0));
  EXPECT_EQ(calculator_.Calculate("sqrt(2.0)"), sqrt(2.0));
  EXPECT_EQ(calculator_.Calculate("sqrt(3.0)"), sqrt(3.0));
  EXPECT_EQ(calculator_.Calculate("sqrt(4.0)"), sqrt(4.0));
  EXPECT_EQ(calculator_.Calculate("sqrt(5.0)"), sqrt(5.0));
  EXPECT_EQ(calculator_.Calculate("sqrt(6.0)"), sqrt(6.0));
  EXPECT_EQ(calculator_.Calculate("sqrt(7.0)"), sqrt(7.0));
  EXPECT_EQ(calculator_.Calculate("sqrt(8.0)"), sqrt(8.0));
  EXPECT_EQ(calculator_.Calculate("sqrt(9.0)"), sqrt(9.0));
  EXPECT_EQ(calculator_.Calculate("sqrt(0.1)"), sqrt(0.1));
  EXPECT_EQ(calculator_.Calculate("sqrt(1.5)"), sqrt(1.5));
  EXPECT_EQ(calculator_.Calculate("sqrt(2.6)"), sqrt(2.6));
}

}  // namespace s21

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
