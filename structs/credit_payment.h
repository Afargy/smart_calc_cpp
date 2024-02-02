#ifndef CPP3_SMARTCALC_V2_0_1_SRC_STRUCTS_CREDIT_PAYMENT_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_STRUCTS_CREDIT_PAYMENT_H_

#include <vector>

namespace s21 {
struct CreditPayment {
  double total{0.0};
  double overpayment{0.0};
  std::vector<double> monthly;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_STRUCTS_CREDIT_PAYMENT_H_
