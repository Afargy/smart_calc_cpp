#include "converter.h"

#include "../token/token.h"
#include "../vectors/expression.h"

namespace s21 {

Expression Converter::ToPolish(const Expression& origin) {
  converted_ = Expression();
  stack_.Clear();
  for (size_t i{0}; i < origin.Size(); ++i) {
    Token current{origin[i]};
    if (current->IsNumber()) {
      converted_.PushBack(current);
    } else if (stack_.IsEmpty() || current->IsFunction() || current->IsLeft()) {
      stack_.PushBack(current);
    } else if (current->IsRight()) {
      while (!stack_.Back()->IsLeft()) {
        StackBackToConverted();
      }
      stack_.PopBack();
      if (stack_.Size() && stack_.Back()->IsFunction()) {
        StackBackToConverted();
      }
    } else if (current->Priority() <= stack_.Back()->Priority() &&
               !current->IsLeftAssociative()) {
      TransferStack();
      stack_.PushBack(current);
    } else {
      stack_.PushBack(current);
    }
  }
  TransferStack();
  return converted_;
}

void Converter::StackBackToConverted() {
  converted_.PushBack(stack_.Back());
  stack_.PopBack();
}

void Converter::TransferStack() {
  while (stack_.Size() && !stack_.Back()->IsLeft()) {
    StackBackToConverted();
  }
}

}  // namespace s21
