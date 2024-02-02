#ifndef CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_STRING_PARSER_TYPES_MAPPER_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_STRING_PARSER_TYPES_MAPPER_H_

#include <map>
#include <memory>
#include <string>

#include "../token/types_pair.h"

namespace s21 {
class TypesMapper {
 public:
  TypesMapper();
  TypesPair ReturnPair(const std::string& key) const;

 private:
  std::shared_ptr<std::map<std::string, TypesPair>> map_{
      std::make_shared<std::map<std::string, TypesPair>>()};
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_STRING_PARSER_TYPES_MAPPER_H_
