#include "deposit_calculator_view.h"

#include "../../structs/deposit.h"
#include "../../structs/deposit_payment.h"
#include "ui_deposit_calculator_view.h"

namespace s21 {

DepositCalculatorView::DepositCalculatorView(QWidget *parent)
    : QWidget(parent), ui(new Ui::DepositCalculatorView) {
  ui->setupUi(this);
  connect(ui->button_calculate, SIGNAL(clicked()), SLOT(CalculateClicked()));
}

DepositCalculatorView::~DepositCalculatorView() { delete ui; }

void DepositCalculatorView::CalculateClicked() {
  Deposit::Capitalization type{Deposit::Capitalization::kDaily};
  if (ui->payment_period->currentText() == "Monthly") {
    type = Deposit::Capitalization::kMontly;
  } else if (ui->payment_period->currentText() == "Quarterly") {
    type = Deposit::Capitalization::kQuarterly;
  } else if (ui->payment_period->currentText() == "Annually") {
    type = Deposit::Capitalization::kAnnually;
  }
  Deposit data{ui->initial_amount->value(), ui->term->value(),
               ui->interest->value(), ui->tax->value(), type};
  DepositPayment payment = controller_.Calculate(data);
  ui->income->setText(QString::number(payment.income, 'f', 2));
  ui->tax_amount->setText(QString::number(payment.tax, 'f', 2));
  ui->finite_amount->setText(QString::number(payment.amount, 'f', 2));
}

}  // namespace s21
