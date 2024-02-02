#include "arithmetic_calculator.h"

#include <string>

#include "vectors/expression.h"

namespace s21 {

double ArithmeticCalculator::Calculate(const std::string& string, double x) {
  expression_ = converter_.ToPolish(parser_.Parse(string));
  return calculator_.Calculate(expression_, x);
}

double ArithmeticCalculator::Calculate(double x) {
  if (expression_.IsEmpty()) {
    throw "Expression is empty";
  }
  return calculator_.Calculate(expression_, x);
}

}  // namespace s21
