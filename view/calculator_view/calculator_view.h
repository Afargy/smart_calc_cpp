#ifndef CPP3_SMARTCALC_V2_0_1_SRC_VIEW_CALCULATOR_VIEW_CALCULATOR_VIEW_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_VIEW_CALCULATOR_VIEW_CALCULATOR_VIEW_H_

#include <QMainWindow>
#include <QWidget>

#include "../../controller/calculator_controller.h"
#include "../credit_calculator_view/credit_calculator_view.h"
#include "../deposit_calculator_view/deposit_calculator_view.h"

namespace Ui {
class CalculatorView;
}

namespace s21 {
class CalculatorView : public QMainWindow {
  Q_OBJECT

 public:
  explicit CalculatorView(QWidget *parent = nullptr);
  ~CalculatorView();

 private slots:
  void UpdateDisplay();
  void Calculate();
  void ClearDisplay();
  void DeleteSymbolFromDisplay();
  void OpenCreditCalculator();
  void OpenDepositCalculator();

 private:
  void InitKeypad();
  void SetShortcuts();
  void SetGraph();

 private:
  Ui::CalculatorView *ui;
  CreditCalculatorView credit_calculator_view_;
  DepositCalculatorView deposit_calculator_view_;
  CalculatorController controller_;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_VIEW_CALCULATOR_VIEW_CALCULATOR_VIEW_H_
