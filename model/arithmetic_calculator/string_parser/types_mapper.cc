#include "types_mapper.h"

#include <map>
#include <string>

#include "../token/types.h"
#include "../token/types_pair.h"

namespace s21 {

TypesMapper::TypesMapper() {
  map_->insert({{"+", TypesPair(Type::kFunction, Sub::kPlus)},
                {"-", TypesPair(Type::kFunction, Sub::kMinus)},
                {"*", TypesPair(Type::kOperator, Sub::kMul)},
                {"/", TypesPair(Type::kOperator, Sub::kDiv)},
                {"^", TypesPair(Type::kOperator, Sub::kPow)},
                {"mod", TypesPair(Type::kOperator, Sub::kMod)},
                {"sin", TypesPair(Type::kFunction, Sub::kSin)},
                {"cos", TypesPair(Type::kFunction, Sub::kCos)},
                {"tan", TypesPair(Type::kFunction, Sub::kTan)},
                {"asin", TypesPair(Type::kFunction, Sub::kAsin)},
                {"acos", TypesPair(Type::kFunction, Sub::kAcos)},
                {"atan", TypesPair(Type::kFunction, Sub::kAtan)},
                {"ln", TypesPair(Type::kFunction, Sub::kLn)},
                {"log", TypesPair(Type::kFunction, Sub::kLog)},
                {"sqrt", TypesPair(Type::kFunction, Sub::kSqrt)},
                {"(", TypesPair(Type::kParenthesis, Sub::kLeft)},
                {")", TypesPair(Type::kParenthesis, Sub::kRight)},
                {"X", TypesPair(Type::kNumber, Sub::kVariable)}});
}

TypesPair TypesMapper::ReturnPair(const std::string& key) const {
  if (key.front() >= '0' && key.front() <= '9') {
    return TypesPair(Type::kNumber, Sub::kConst);
  }
  std::map<std::string, TypesPair>::const_iterator iter{map_->find(key)};
  if (iter == map_->end()) {
    throw "token not found";
  }
  return iter->second;
}

}  // namespace s21
