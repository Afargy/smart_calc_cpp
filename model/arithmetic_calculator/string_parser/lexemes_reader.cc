#include "lexemes_reader.h"

#include "../vectors/expression.h"
#include "parenthesis_counter.h"
#include "syntax_checker.h"
#include "type_updater.h"

namespace s21 {

Expression LexemesReader::Read(const Lexemes& input) {
  Expression output;
  TypeUpdater updated;
  SyntaxChecker syntaxer;
  ParenthesisCounter parenthesis;
  for (size_t i{0}; i < input.Size(); ++i) {
    updated.Update(mapper_.ReturnPair(input.At(i)));
    syntaxer.Check(updated.GetPair());
    parenthesis.Count(updated.GetPair());
    if (updated.IsConstNumber()) {
      output.PushBack(std::stod((input.At(i)).c_str()));
    } else {
      output.PushBack(updated.GetPair());
    }
  }
  if (!(updated.IsNumber() || updated.IsRight()) || parenthesis.NotClosed()) {
    throw "expression isn't closed";
  }

  return output;
}

}  // namespace s21
