#include "string_reader.h"

#include <regex>
#include <string>

#include "../vectors/lexemes.h"

namespace s21 {

Lexemes StringReader::Read(const std::string& input) const {
  std::sregex_iterator iterator(input.begin(), input.end(), regex_);
  std::sregex_iterator endIterator;
  Lexemes lexemes_;
  while (iterator != endIterator) {
    lexemes_->push_back(iterator->str());
    ++iterator;
  }
  return lexemes_;
}

}  // namespace s21
