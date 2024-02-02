#ifndef CPP3_SMARTCALC_V2_0_1_SRC_MODEL_CREDIT_CALCULATOR_CREDIT_CALCULATOR_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_MODEL_CREDIT_CALCULATOR_CREDIT_CALCULATOR_H_

#include "../../structs/credit.h"
#include "../../structs/credit_payment.h"

namespace s21 {
class CreditCalculator {
 public:
  CreditPayment CalculateAnnuity(const Credit& credit) const;
  CreditPayment CalculateDifferntiated(const Credit& credit) const;

 private:
  void CheckInput(const Credit& credit) const;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_MODEL_CREDIT_CALCULATOR_CREDIT_CALCULATOR_H_
