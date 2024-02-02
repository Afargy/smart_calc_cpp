#include "token_data.h"

#include "types.h"
#include "types_pair.h"

namespace s21 {

TokenData::TokenData(const double value)
    : TypesPair(Type::kNumber, Sub::kConst), value_{value} {}

TokenData::TokenData(const TypesPair pair) : TypesPair(pair) {
  if (IsOperator()) {
    if (IsPlus() || IsMinus()) {
      value_ = 1;
    } else if (IsMul() || IsDiv()) {
      value_ = 2;
    } else if (IsPow()) {
      value_ = 3;
    }
  } else if (IsFunction()) {
    value_ = 4;
  }
}

double TokenData::Value() const noexcept { return value_; }

int TokenData::Priority() const noexcept { return value_; }

}  // namespace s21
