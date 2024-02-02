#ifndef CPP3_SMARTCALC_V2_0_1_SRC_STRUCTS_CREDIT_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_STRUCTS_CREDIT_H_

namespace s21 {
struct Credit {
  double amount{0.0};
  int months{0};
  double rate{0.0};
  Credit(double amount, int months, double rate)
      : amount(amount), months(months), rate(rate) {}
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_STRUCTS_CREDIT_H_
