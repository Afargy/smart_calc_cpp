#ifndef CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_CREDIT_CALCULATOR_CONTROLLER_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_CREDIT_CALCULATOR_CONTROLLER_H_

#include "../model/credit_calculator/credit_calculator.h"
#include "../structs/credit.h"
#include "../structs/credit_payment.h"

namespace s21 {
class CreditCalculatorController {
 public:
  CreditPayment CalculateAnnuity(const Credit& credit) const;
  CreditPayment CalculateDifferntiated(const Credit& credit) const;

 private:
  CreditCalculator creditor_;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_CREDIT_CALCULATOR_CONTROLLER_H_
