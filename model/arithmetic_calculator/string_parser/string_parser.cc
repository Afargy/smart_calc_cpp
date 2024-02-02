#include "string_parser.h"

#include <string>

#include "../vectors/expression.h"

namespace s21 {

Expression StringParser::Parse(const std::string& input) {
  return lexemer_.Read(stringer_.Read(input));
}

}  // namespace s21
