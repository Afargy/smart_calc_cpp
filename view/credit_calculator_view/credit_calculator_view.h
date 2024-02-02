
#ifndef CPP3_SMARTCALC_V2_0_1_SRC_VIEW_CREDIT_CALCULATOR_VIEW_CREDIT_CALCULATOR_VIEW_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_VIEW_CREDIT_CALCULATOR_VIEW_CREDIT_CALCULATOR_VIEW_H_

#include <QWidget>

#include "../../controller/credit_calculator_controller.h"

namespace Ui {
class CreditCalculatorView;
}

namespace s21 {
class CreditCalculatorView : public QWidget {
  Q_OBJECT

 public:
  explicit CreditCalculatorView(QWidget *parent = nullptr);
  ~CreditCalculatorView();

 private slots:
  void CountClicked();
  void ClearClicked();

 private:
  Ui::CreditCalculatorView *ui;
  CreditCalculatorController controller_;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_VIEW_CREDIT_CALCULATOR_VIEW_CREDIT_CALCULATOR_VIEW_H_
