#ifndef CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_CALCULATOR_CALCULATOR_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_CALCULATOR_CALCULATOR_H_

#include "../vectors/expression.h"
#include "../vectors/numbers.h"

namespace s21 {
class Calculator {
 public:
  double Calculate(const Expression& polish, const double x);

 private:
  void CalculateOperator(const Token& token);
  void CalculateFunction(const Token& token);

 private:
  Numbers result_;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_CALCULATOR_CALCULATOR_H_
