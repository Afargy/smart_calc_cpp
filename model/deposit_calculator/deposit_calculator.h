#ifndef CPP3_SMARTCALC_V2_0_1_SRC_MODEL_DEPOSIT_CALCULATOR_DEPOSIT_CALCULATOR_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_MODEL_DEPOSIT_CALCULATOR_DEPOSIT_CALCULATOR_H_

#include "../../structs/deposit.h"
#include "../../structs/deposit_payment.h"

namespace s21 {
class DepositCalculator {
 public:
  DepositPayment Calculate(const Deposit& deposit) const;

 private:
  double CalculateAmount(const Deposit& deposit) const;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_MODEL_DEPOSIT_CALCULATOR_DEPOSIT_CALCULATOR_H_
