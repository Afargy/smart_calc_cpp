#include "deposit_calculator_controller.h"

namespace s21 {

DepositPayment DepositCalculatorController::Calculate(
    const Deposit& deposit) const {
  return depositor_.Calculate(deposit);
}

}  // namespace s21
