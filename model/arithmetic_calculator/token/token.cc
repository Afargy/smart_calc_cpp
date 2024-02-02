#include "token.h"

#include <memory>

#include "token_data.h"
#include "types_pair.h"

namespace s21 {

Token::Token(double value) : data_{std::make_shared<TokenData>(value)} {}

Token::Token(TypesPair pair) : data_{std::make_shared<TokenData>(pair)} {}

const std::shared_ptr<const TokenData> Token::operator->() const {
  return data_;
}

}  // namespace s21
