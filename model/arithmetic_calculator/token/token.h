#ifndef CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_TOKEN_TOKEN_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_TOKEN_TOKEN_H_

#include <memory>

#include "token_data.h"
#include "types_pair.h"

namespace s21 {
class Token {
 public:
  Token(double value);
  Token(TypesPair pair);
  const std::shared_ptr<const TokenData> operator->() const;

 private:
  const std::shared_ptr<const TokenData> data_;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_TOKEN_TOKEN_H_
