#include "calculator.h"

#include <cmath>

namespace s21 {

double Calculator::Calculate(const Expression& polish, const double x) {
  result_.Clear();
  for (size_t i{0}; i < polish.Size(); ++i) {
    Token current{polish[i]};
    if (current->IsConstNumber()) {
      result_.PushBack(current->Value());
    } else if (current->IsVariable()) {
      result_.PushBack(x);
    } else if (current->IsOperator()) {
      CalculateOperator(current);
    } else if (current->IsFunction()) {
      CalculateFunction(current);
    }
  }
  return result_.PopBack();
}

void Calculator::CalculateOperator(const Token& token) {
  double temp{result_.PopBack()};
  if (token->IsPlus()) {
    result_.PushBack(result_.PopBack() + temp);
  } else if (token->IsMinus()) {
    result_.PushBack(result_.PopBack() - temp);
  } else if (token->IsMul()) {
    result_.PushBack(result_.PopBack() * temp);
  } else if (token->IsDiv()) {
    result_.PushBack(result_.PopBack() / temp);
  } else if (token->IsMod()) {
    result_.PushBack(fmod(result_.PopBack(), temp));
  } else if (token->IsPow()) {
    result_.PushBack(pow(result_.PopBack(), temp));
  }
}

void Calculator::CalculateFunction(const Token& token) {
  if (token->IsMinus()) {
    result_.Back() = -result_.Back();
  } else if (token->IsSin()) {
    result_.Back() = sin(result_.Back());
  } else if (token->IsCos()) {
    result_.Back() = cos(result_.Back());
  } else if (token->IsTan()) {
    result_.Back() = tan(result_.Back());
  } else if (token->IsAsin()) {
    result_.Back() = asin(result_.Back());
  } else if (token->IsAcos()) {
    result_.Back() = acos(result_.Back());
  } else if (token->IsAtan()) {
    result_.Back() = atan(result_.Back());
  } else if (token->IsLn()) {
    result_.Back() = log(result_.Back());
  } else if (token->IsLog()) {
    result_.Back() = log10(result_.Back());
  } else if (token->IsSqrt()) {
    result_.Back() = sqrt(result_.Back());
  }
}

}  // namespace s21
