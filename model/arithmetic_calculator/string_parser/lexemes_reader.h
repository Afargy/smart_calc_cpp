#ifndef CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_STRING_PARSER_LEXEMES_READER_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_STRING_PARSER_LEXEMES_READER_H_

#include "../vectors/expression.h"
#include "../vectors/lexemes.h"
#include "types_mapper.h"

namespace s21 {
class LexemesReader {
 public:
  Expression Read(const Lexemes& input);

 private:
  TypesMapper mapper_;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_STRING_PARSER_LEXEMES_READER_H_
