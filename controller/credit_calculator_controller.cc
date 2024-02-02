#include "credit_calculator_controller.h"

namespace s21 {

CreditPayment CreditCalculatorController::CalculateAnnuity(
    const Credit& credit) const {
  return creditor_.CalculateAnnuity(credit);
}

CreditPayment CreditCalculatorController::CalculateDifferntiated(
    const Credit& credit) const {
  return creditor_.CalculateDifferntiated(credit);
}

}  // namespace s21
