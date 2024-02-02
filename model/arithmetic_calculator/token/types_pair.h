#ifndef CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_TOKEN_TYPES_PAIR_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_TOKEN_TYPES_PAIR_H_

#include "types.h"

namespace s21 {
class TypesPair {
 public:
  TypesPair(const Type type = Type::kEmpty, const Sub sub = Sub::kNone);
  bool IsEmpty() const noexcept;
  bool IsNumber() const noexcept;
  bool IsOperator() const noexcept;
  bool IsFunction() const noexcept;
  bool IsParenthesis() const noexcept;
  bool IsNone() const noexcept;
  bool IsPlus() const noexcept;
  bool IsMinus() const noexcept;
  bool IsMul() const noexcept;
  bool IsDiv() const noexcept;
  bool IsMod() const noexcept;
  bool IsPow() const noexcept;
  bool IsSin() const noexcept;
  bool IsCos() const noexcept;
  bool IsTan() const noexcept;
  bool IsAsin() const noexcept;
  bool IsAcos() const noexcept;
  bool IsAtan() const noexcept;
  bool IsLog() const noexcept;
  bool IsLn() const noexcept;
  bool IsSqrt() const noexcept;
  bool IsLeft() const noexcept;
  bool IsRight() const noexcept;
  bool IsConstNumber() const noexcept;
  bool IsVariable() const noexcept;
  Type GetType() const noexcept;
  Sub GetSub() const noexcept;
  TypesPair GetPair() const noexcept;
  bool IsPlusOrMinus() const noexcept;
  bool IsLeftAssociative() const noexcept;
  bool CanFollowOnlyClosings() const noexcept;
  bool IsClosingTypes() const noexcept;

 protected:
  Type type_;
  Sub sub_;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_TOKEN_TYPES_PAIR_H_
