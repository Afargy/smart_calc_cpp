#ifndef CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_STRING_PARSER_PARENTHESIS_COUNTER_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_STRING_PARSER_PARENTHESIS_COUNTER_H_

#include "../token/token.h"

namespace s21 {
class ParenthesisCounter {
 public:
  void Count(const Token& token);
  bool NotClosed() const noexcept;

 private:
  int counter_{0};
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_STRING_PARSER_PARENTHESIS_COUNTER_H_
