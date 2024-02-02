#ifndef CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_STRING_PARSER_STRING_PARSER_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_STRING_PARSER_STRING_PARSER_H_

#include <string>

#include "../vectors/expression.h"
#include "lexemes_reader.h"
#include "string_reader.h"

namespace s21 {
class StringParser {
 public:
  Expression Parse(const std::string& input);

 private:
  StringReader stringer_;
  LexemesReader lexemer_;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_STRING_PARSER_STRING_PARSER_H_
