#ifndef CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_TOKEN_TOKEN_DATA_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_TOKEN_TOKEN_DATA_H_

#include "types_pair.h"

namespace s21 {
class TokenData : public TypesPair {
 public:
  TokenData(const double value);
  TokenData(const TypesPair pair);
  double Value() const noexcept;
  int Priority() const noexcept;

 protected:
  double value_{0};
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_TOKEN_TOKEN_DATA_H_
