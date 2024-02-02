#include "calculator_controller.h"

namespace s21 {

double CalculatorController::Calculate(const std::string& string, double x) {
  return calculator_.Calculate(string, x);
}

double CalculatorController::Calculate(double x) {
  return calculator_.Calculate(x);
}

}  // namespace s21
