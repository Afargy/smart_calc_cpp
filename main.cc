#include <QApplication>

#include "view/calculator_view/calculator_view.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::CalculatorView w;
  w.show();
  return a.exec();
}
