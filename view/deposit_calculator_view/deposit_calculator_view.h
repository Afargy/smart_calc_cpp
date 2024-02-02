#ifndef CPP3_SMARTCALC_V2_0_1_SRC_VIEW_DEPOSIT_CALCULATOR_VIEW_DEPOSIT_CALCULATOR_VIEW_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_VIEW_DEPOSIT_CALCULATOR_VIEW_DEPOSIT_CALCULATOR_VIEW_H_

#include <QWidget>

#include "../../controller/deposit_calculator_controller.h"

namespace Ui {
class DepositCalculatorView;
}

namespace s21 {
class DepositCalculatorView : public QWidget {
  Q_OBJECT

 public:
  explicit DepositCalculatorView(QWidget *parent = nullptr);
  ~DepositCalculatorView();

 private slots:
  void CalculateClicked();

 private:
  Ui::DepositCalculatorView *ui;
  DepositCalculatorController controller_;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_VIEW_DEPOSIT_CALCULATOR_VIEW_DEPOSIT_CALCULATOR_VIEW_H_
