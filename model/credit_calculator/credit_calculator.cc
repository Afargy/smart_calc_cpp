#include "credit_calculator.h"

#include <cmath>

namespace s21 {

CreditPayment CreditCalculator::CalculateAnnuity(const Credit& credit) const {
  CheckInput(credit);
  double rate = credit.rate / 1200;
  CreditPayment payment;
  payment.monthly.push_back(credit.amount * rate /
                            (1 - pow(1 + rate, -credit.months)));
  payment.total = payment.monthly[0] * credit.months;
  payment.overpayment = payment.total - credit.amount;
  return payment;
}

CreditPayment CreditCalculator::CalculateDifferntiated(
    const Credit& credit) const {
  CheckInput(credit);
  double fixed_part{credit.amount / credit.months};
  double rest{credit.amount};
  double rate{credit.rate / 1200};
  double interest{0.0};
  CreditPayment payment;
  for (int i{0}; i < credit.months; ++i) {
    interest = rest * rate;
    payment.monthly.push_back(fixed_part + interest);
    rest -= fixed_part;
    payment.overpayment += interest;
    payment.total += payment.monthly.back();
  }
  return payment;
}

void CreditCalculator::CheckInput(const Credit& credit) const {
  if (credit.amount <= 0) {
    throw "Amount cannot be less or equal zero";
  }
  if (credit.rate < 0) {
    throw "Interst rate can't be less than zero";
  }
  if (!credit.months) {
    throw "Term must be positive";
  }
}

}  // namespace s21
