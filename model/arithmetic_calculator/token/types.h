#ifndef CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_TOKEN_TYPES_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_TOKEN_TYPES_H_

namespace s21 {

enum class Type { kEmpty, kNumber, kOperator, kFunction, kParenthesis };

enum class Sub {
  kNone,
  kPlus,
  kMinus,
  kMul,
  kDiv,
  kMod,
  kPow,
  kSin,
  kCos,
  kTan,
  kAsin,
  kAcos,
  kAtan,
  kLog,
  kLn,
  kSqrt,
  kLeft,
  kRight,
  kConst,
  kVariable
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_TOKEN_TYPES_H_
