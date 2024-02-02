#ifndef CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_ARITHMETIC_CALCULATOR_CONTROLLER_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_ARITHMETIC_CALCULATOR_CONTROLLER_H_

#include "../model/arithmetic_calculator/arithmetic_calculator.h"

namespace s21 {
class CalculatorController {
 public:
  double Calculate(const std::string& string, double x);
  double Calculate(double x);

 private:
  ArithmeticCalculator calculator_;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_ARITHMETIC_CALCULATOR_CONTROLLER_H_
