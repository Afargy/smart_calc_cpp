#include "type_updater.h"

#include "../token/types.h"
#include "../token/types_pair.h"

namespace s21 {

TypesPair TypeUpdater::Update(const TypesPair& pair) {
  if (pair.IsPlusOrMinus() && IsClosingTypes()) {
    type_ = Type::kOperator;
  } else {
    type_ = pair.GetType();
  }
  sub_ = pair.GetSub();
  return GetPair();
}

}  // namespace s21
