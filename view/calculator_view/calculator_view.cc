#include "calculator_view.h"

#include <QKeyEvent>
#include <QKeySequence>
#include <QMainWindow>
#include <QPair>
#include <QPushButton>
#include <QString>
#include <QVector>

#include "ui_calculator_view.h"

namespace s21 {

CalculatorView::CalculatorView(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::CalculatorView) {
  ui->setupUi(this);
  InitKeypad();
  SetShortcuts();
  QFile file(":/calculator_view_style");
  file.open(QFile::ReadOnly);
  this->setStyleSheet(file.readAll());
}

CalculatorView::~CalculatorView() { delete ui; }

void CalculatorView::UpdateDisplay() {
  QPushButton *clicked{static_cast<QPushButton *>(sender())};
  ui->display->setPlainText(ui->display->toPlainText() + clicked->text());
  ui->result->setText("");
}

void CalculatorView::Calculate() {
  try {
    QString string{ui->display->toPlainText()};
    double result{
        controller_.Calculate(string.toStdString(), ui->spinbox_x->value())};
    ui->result->setText(QString::number(result));
    SetGraph();
    ui->graph->replot();
  } catch (...) {
    qDebug() << "error";
  }
}

void CalculatorView::ClearDisplay() {
  ui->display->setPlainText("");
  ui->result->setText("");
}

void CalculatorView::DeleteSymbolFromDisplay() {
  QString string{ui->display->toPlainText()};
  string.chop(1);
  ui->display->setPlainText(string);
  ui->result->setText("");
}

void CalculatorView::OpenCreditCalculator() { credit_calculator_view_.show(); }

void CalculatorView::OpenDepositCalculator() {
  deposit_calculator_view_.show();
}

void CalculatorView::InitKeypad() {
  QVector<QString> list{"0",    "1",       "2",       "3",    "4",   "5",
                        "6",    "7",       "8",       "9",    "mul", "div",
                        "mod",  "pow",     "add",     "sub",  "sin", "cos",
                        "tan",  "asin",    "acos",    "atan", "ln",  "log",
                        "sqrt", "l_paren", "r_paren", "dot",  "x",   "e"};

  for (qsizetype i = 0; i < list.size(); ++i) {
    QPushButton *button{
        CalculatorView::findChild<QPushButton *>("button_" + list[i])};
    connect(button, SIGNAL(clicked()), SLOT(UpdateDisplay()));
  }
  connect(ui->button_eq, SIGNAL(clicked()), SLOT(Calculate()));
  connect(ui->button_ac, SIGNAL(clicked()), SLOT(ClearDisplay()));
  connect(ui->button_del, SIGNAL(clicked()), SLOT(DeleteSymbolFromDisplay()));
  connect(ui->credit_calculator, SIGNAL(triggered()),
          SLOT(OpenCreditCalculator()));
  connect(ui->deposit_calculator, SIGNAL(triggered()),
          SLOT(OpenDepositCalculator()));
}

void CalculatorView::SetShortcuts() {
  QVector<QPair<QKeySequence, QPushButton *>> keys{
      {Qt::Key_0, ui->button_0},
      {Qt::Key_1, ui->button_1},
      {Qt::Key_2, ui->button_2},
      {Qt::Key_3, ui->button_3},
      {Qt::Key_4, ui->button_4},
      {Qt::Key_5, ui->button_5},
      {Qt::Key_6, ui->button_6},
      {Qt::Key_7, ui->button_7},
      {Qt::Key_8, ui->button_8},
      {Qt::Key_9, ui->button_9},
      {Qt::Key_Asterisk, ui->button_mul},
      {Qt::Key_AsciiCircum, ui->button_pow},
      {Qt::Key_Backspace, ui->button_del},
      {Qt::Key_Delete | Qt::ShiftModifier, ui->button_ac},
      {Qt::Key_Equal, ui->button_eq},
      {Qt::Key_Minus, ui->button_sub},
      {Qt::Key_ParenLeft, ui->button_l_paren},
      {Qt::Key_ParenRight, ui->button_r_paren},
      {Qt::Key_Plus, ui->button_add},
      {Qt::Key_Period, ui->button_dot},
      {Qt::Key_Slash, ui->button_div},
      {Qt::Key_C, ui->button_cos},
      {Qt::Key_C | Qt::ShiftModifier, ui->button_acos},
      {Qt::Key_L, ui->button_ln},
      {Qt::Key_L | Qt::ShiftModifier, ui->button_log},
      {Qt::Key_M, ui->button_mod},
      {Qt::Key_M | Qt::ShiftModifier, ui->button_sqrt},
      {Qt::Key_T, ui->button_tan},
      {Qt::Key_T | Qt::ShiftModifier, ui->button_atan},
      {Qt::Key_S, ui->button_sin},
      {Qt::Key_S | Qt::ShiftModifier, ui->button_asin},
      {Qt::Key_X, ui->button_x},
      {Qt::Key_E, ui->button_e}};
  for (qsizetype i = 0; i < keys.size(); ++i) {
    keys[i].second->setShortcut(keys[i].first);
  }
}

void CalculatorView::SetGraph() {
  ui->graph->clearGraphs();
  ui->graph->xAxis->setRange(ui->x_min->value(), ui->x_max->value());
  ui->graph->yAxis->setRange(ui->y_min->value(), ui->y_max->value());
  ui->graph->clearGraphs();
  QVector<double> x;
  QVector<double> y;
  int points{40000};
  double x_min{(double)ui->x_min->value()};
  double x_max{(double)ui->x_max->value()};
  ui->graph->xAxis->setRange(ui->x_min->value(), ui->x_max->value());
  ui->graph->yAxis->setRange(ui->y_min->value(), ui->y_max->value());
  double step{(std::abs(x_min) + std::abs(x_max)) / points};
  double gone{x_min};
  for (int i{0}; i < points; ++i) {
    x.push_back(gone);
    y.push_back(controller_.Calculate(gone));
    gone += step;
  }

  ui->graph->addGraph(0)->addData(x, y);
  ui->graph->replot();
}

}  // namespace s21
