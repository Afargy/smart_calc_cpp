#ifndef CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_STRING_PARSER_SYNTAX_CHECKER_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_STRING_PARSER_SYNTAX_CHECKER_H_

#include "../token/types_pair.h"

namespace s21 {
class SyntaxChecker : public TypesPair {
 public:
  void Check(const TypesPair& pair);
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_STRING_PARSER_SYNTAX_CHECKER_H_