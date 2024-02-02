#include "credit_calculator_view.h"

#include "../../structs/credit.h"
#include "../../structs/credit_payment.h"
#include "ui_credit_calculator_view.h"

namespace s21 {

CreditCalculatorView::CreditCalculatorView(QWidget *parent)
    : QWidget(parent), ui(new Ui::CreditCalculatorView) {
  ui->setupUi(this);
  connect(ui->button_clear, SIGNAL(clicked()), SLOT(ClearClicked()));
  connect(ui->button_count, SIGNAL(clicked()), SLOT(CountClicked()));
}

CreditCalculatorView::~CreditCalculatorView() { delete ui; }

void CreditCalculatorView::CountClicked() {
  ui->display->clear();
  Credit data{ui->amount->value(), ui->term->value(),
              ui->interest_rate->value()};
  CreditPayment payment;
  if (ui->annuity->isChecked()) {
    payment = controller_.CalculateAnnuity(data);
    ui->monthly_payment->setText(QString::number(payment.monthly[0], 'f', 2));
  } else {
    payment = controller_.CalculateDifferntiated(data);
    ui->monthly_payment->setText(
        QString::number(payment.monthly[0], 'f', 2) + " - " +
        QString::number(payment.monthly[payment.monthly.size() - 1], 'f', 2));
    for (size_t i{0}; i < payment.monthly.size(); ++i) {
      QString str{"Month " + QString::number(i + 1, 'f', 2) + ": " +
                  QString::number(payment.monthly[i], 'f', 2) + "\n"};
      ui->display->insertPlainText(str);
    }
  }
  ui->total_payment->setText(QString::number(payment.total, 'f', 2));
  ui->overpayment->setText(QString::number(payment.overpayment, 'f', 2));
}

void CreditCalculatorView::ClearClicked() {
  ui->amount->setValue(1000.0);
  ui->term->setValue(12);
  ui->interest_rate->setValue(3.0);
  ui->annuity->setChecked(true);
  ui->display->clear();
}

}  // namespace s21
