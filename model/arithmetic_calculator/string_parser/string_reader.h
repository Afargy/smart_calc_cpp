#ifndef CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_STRING_PARSER_STRING_READER_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_STRING_PARSER_STRING_READER_H_

#include <regex>
#include <string>

#include "../vectors/lexemes.h"

namespace s21 {
class StringReader {
 public:
  Lexemes Read(const std::string& input) const;

 private:
  std::regex regex_{"((\\d+)(\\.\\d+)?([eE][+-]?\\d+)?)|([a-zA-Z]+)|(\\S)"};
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_STRING_PARSER_STRING_READER_H_
