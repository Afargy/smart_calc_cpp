#ifndef CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_CONVERTER_CONVERTER_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_CONVERTER_CONVERTER_H_

#include "../token/token.h"
#include "../vectors/expression.h"

namespace s21 {
class Converter {
 public:
  Expression ToPolish(const Expression& origin);

 private:
  void StackBackToConverted();
  void TransferStack();

 private:
  Expression converted_;
  Expression stack_;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_CONVERTER_CONVERTER_H_
