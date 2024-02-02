#include "types_pair.h"

#include "types.h"

namespace s21 {

TypesPair::TypesPair(const Type type, const Sub sub) : type_(type), sub_{sub} {}

bool TypesPair::IsEmpty() const noexcept { return type_ == Type::kEmpty; }

bool TypesPair::IsNumber() const noexcept { return type_ == Type::kNumber; }

bool TypesPair::IsOperator() const noexcept { return type_ == Type::kOperator; }

bool TypesPair::IsFunction() const noexcept { return type_ == Type::kFunction; }

bool TypesPair::IsParenthesis() const noexcept {
  return type_ == Type::kParenthesis;
}

bool TypesPair::IsNone() const noexcept { return sub_ == Sub::kNone; }

bool TypesPair::IsPlus() const noexcept { return sub_ == Sub::kPlus; }

bool TypesPair::IsMinus() const noexcept { return sub_ == Sub::kMinus; }

bool TypesPair::IsMul() const noexcept { return sub_ == Sub::kMul; }

bool TypesPair::IsDiv() const noexcept { return sub_ == Sub::kDiv; }

bool TypesPair::IsMod() const noexcept { return sub_ == Sub::kMod; }

bool TypesPair::IsPow() const noexcept { return sub_ == Sub::kPow; }

bool TypesPair::IsSin() const noexcept { return sub_ == Sub::kSin; }

bool TypesPair::IsCos() const noexcept { return sub_ == Sub::kCos; }

bool TypesPair::IsTan() const noexcept { return sub_ == Sub::kTan; }

bool TypesPair::IsAsin() const noexcept { return sub_ == Sub::kAsin; }

bool TypesPair::IsAcos() const noexcept { return sub_ == Sub::kAcos; }

bool TypesPair::IsAtan() const noexcept { return sub_ == Sub::kAtan; }

bool TypesPair::IsLog() const noexcept { return sub_ == Sub::kLog; }

bool TypesPair::IsLn() const noexcept { return sub_ == Sub::kLn; }

bool TypesPair::IsSqrt() const noexcept { return sub_ == Sub::kSqrt; }

bool TypesPair::IsLeft() const noexcept { return sub_ == Sub::kLeft; }

bool TypesPair::IsRight() const noexcept { return sub_ == Sub::kRight; }

bool TypesPair::IsConstNumber() const noexcept { return sub_ == Sub::kConst; }

bool TypesPair::IsVariable() const noexcept { return sub_ == Sub::kVariable; }

Type TypesPair::GetType() const noexcept { return type_; }

Sub TypesPair::GetSub() const noexcept { return sub_; }

TypesPair TypesPair::GetPair() const noexcept { return {type_, sub_}; }

bool TypesPair::IsPlusOrMinus() const noexcept { return IsPlus() || IsMinus(); }

bool TypesPair::IsLeftAssociative() const noexcept { return IsPow(); }

bool TypesPair::CanFollowOnlyClosings() const noexcept {
  return IsOperator() || IsRight();
}

bool TypesPair::IsClosingTypes() const noexcept {
  return IsNumber() || IsRight();
}

}  // namespace s21
