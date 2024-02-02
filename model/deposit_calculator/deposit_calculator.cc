#include "deposit_calculator.h"

#include <cmath>

#include "../../structs/deposit.h"
#include "../../structs/deposit_payment.h"

namespace s21 {
DepositPayment DepositCalculator::Calculate(const Deposit& deposit) const {
  DepositPayment payment;
  payment.amount = CalculateAmount(deposit);
  payment.income = payment.amount - deposit.amount;
  payment.tax = payment.income * (deposit.tax_rate / 100);
  return payment;
}

double DepositCalculator::CalculateAmount(const Deposit& deposit) const {
  if (deposit.capitalization == Deposit::Capitalization::kDaily) {
    return deposit.amount * pow((1 + deposit.rate / 36500), deposit.term);
  } else if (deposit.capitalization == Deposit::Capitalization::kMontly) {
    return deposit.amount * pow((1 + deposit.rate / 1200), deposit.term);
  } else if (deposit.capitalization == Deposit::Capitalization::kQuarterly) {
    return deposit.amount * pow((1 + deposit.rate / 400), deposit.term);
  } else if (deposit.capitalization == Deposit::Capitalization::kAnnually) {
    return deposit.amount * pow((1 + deposit.rate / 100), deposit.term);
  }
  return 0.0;
}

}  // namespace s21
