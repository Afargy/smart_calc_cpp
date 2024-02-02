#include "parenthesis_counter.h"

namespace s21 {

void ParenthesisCounter::Count(const Token& token) {
  if (!token->IsParenthesis()) {
    return;
  }
  if (token->IsLeft()) {
    ++counter_;
  } else if (token->IsRight()) {
    if (!counter_) {
      throw "Has no left paranthesis";
    }
    --counter_;
  }
}

bool ParenthesisCounter::NotClosed() const noexcept { return counter_; }

}  // namespace s21
