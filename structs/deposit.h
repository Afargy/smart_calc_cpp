#ifndef CPP3_SMARTCALC_V2_0_1_SRC_STRUCTS_DEPOSIT_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_STRUCTS_DEPOSIT_H_

namespace s21 {
struct Deposit {
  enum Capitalization { kDaily, kMontly, kQuarterly, kAnnually };
  double amount{0.0};
  int term{0};
  double rate{0.0};
  double tax_rate{0.0};
  Capitalization capitalization{kDaily};
  Deposit(double amount, int term, double rate, double tax_rate,
          Capitalization capitalization = {Capitalization::kDaily})
      : amount(amount),
        term(term),
        rate(rate),
        tax_rate{tax_rate},
        capitalization{capitalization} {}
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_STRUCTS_DEPOSIT_H_
