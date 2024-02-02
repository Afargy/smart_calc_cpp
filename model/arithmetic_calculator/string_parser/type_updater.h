#ifndef CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_STRING_PARSER_TYPE_UPDATER_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_STRING_PARSER_TYPE_UPDATER_H_

#include "../token/types_pair.h"

namespace s21 {
class TypeUpdater : public TypesPair {
 public:
  TypesPair Update(const TypesPair& pair);
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_STRING_PARSER_TYPE_UPDATER_H_
