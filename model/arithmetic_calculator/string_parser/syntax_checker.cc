#include "syntax_checker.h"

namespace s21 {

void SyntaxChecker::Check(const TypesPair& pair) {
  if (IsClosingTypes() && !pair.CanFollowOnlyClosings()) {
    throw "Invalide insertion after number or right";
  } else if (!IsClosingTypes() && pair.CanFollowOnlyClosings()) {
    throw "Invalide insertion after empty, operator, left or function";
  }
  type_ = pair.GetType();
  sub_ = pair.GetSub();
}

}  // namespace s21
