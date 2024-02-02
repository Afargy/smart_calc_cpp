#ifndef CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_ARITHMETIC_CALCULATOR_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_ARITHMETIC_CALCULATOR_H_

#include <string>

#include "calculator/calculator.h"
#include "converter/converter.h"
#include "string_parser/string_parser.h"
#include "vectors/expression.h"

namespace s21 {
class ArithmeticCalculator {
 public:
  double Calculate(const std::string& string, double x = 0.0);
  double Calculate(double x);

 private:
  StringParser parser_;
  Converter converter_;
  Calculator calculator_;
  Expression expression_;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_ARITHMETIC_CALCULATOR_H_
