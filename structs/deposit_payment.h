#ifndef CPP3_SMARTCALC_V2_0_1_SRC_STRUCTS_DEPOSIT_PAYMENT_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_STRUCTS_DEPOSIT_PAYMENT_H_

namespace s21 {
struct DepositPayment {
  double amount{0.0};
  double tax{0.0};
  double income{0.0};
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_STRUCTS_DEPOSIT_PAYMENT_H_
