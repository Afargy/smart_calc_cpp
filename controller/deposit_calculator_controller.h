#ifndef CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_DEPOSIT_CALCULATOR_CONTROLLER_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_DEPOSIT_CALCULATOR_CONTROLLER_H_

#include "../model/deposit_calculator/deposit_calculator.h"
#include "../structs/deposit.h"
#include "../structs/deposit_payment.h"

namespace s21 {
class DepositCalculatorController {
 public:
  DepositPayment Calculate(const Deposit& deposit) const;

 private:
  DepositCalculator depositor_;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_DEPOSIT_CALCULATOR_CONTROLLER_H_
