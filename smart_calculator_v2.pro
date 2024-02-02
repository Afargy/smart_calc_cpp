QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++11

TARGET = smart_calculator_v2

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
  controller/calculator_controller.cc \
  controller/credit_calculator_controller.cc \
  controller/deposit_calculator_controller.cc \
  main.cc \
  model/arithmetic_calculator/arithmetic_calculator.cc \
  model/arithmetic_calculator/calculator/calculator.cc \
  model/arithmetic_calculator/converter/converter.cc \
  model/arithmetic_calculator/string_parser/lexemes_reader.cc \
  model/arithmetic_calculator/string_parser/parenthesis_counter.cc \
  model/arithmetic_calculator/string_parser/string_parser.cc \
  model/arithmetic_calculator/string_parser/string_reader.cc \
  model/arithmetic_calculator/string_parser/syntax_checker.cc \
  model/arithmetic_calculator/string_parser/type_updater.cc \
  model/arithmetic_calculator/string_parser/types_mapper.cc \
  model/arithmetic_calculator/token/token.cc \
  model/arithmetic_calculator/token/token_data.cc \
  model/arithmetic_calculator/token/types_pair.cc \
  model/credit_calculator/credit_calculator.cc \
  model/deposit_calculator/deposit_calculator.cc \
  view/calculator_view/calculator_view.cc \
  $$PWD/view/calculator_view/qcustomplot.cc \
  view/credit_calculator_view/credit_calculator_view.cc \
  view/deposit_calculator_view/deposit_calculator_view.cc

HEADERS += \
  controller/calculator_controller.h \
  controller/credit_calculator_controller.h \
  controller/deposit_calculator_controller.h \
  model/arithmetic_calculator/arithmetic_calculator.h \
  model/arithmetic_calculator/calculator/calculator.h \
  model/arithmetic_calculator/converter/converter.h \
  model/arithmetic_calculator/string_parser/lexemes_reader.h \
  model/arithmetic_calculator/string_parser/parenthesis_counter.h \
  model/arithmetic_calculator/string_parser/string_parser.h \
  model/arithmetic_calculator/string_parser/string_reader.h \
  model/arithmetic_calculator/string_parser/syntax_checker.h \
  model/arithmetic_calculator/string_parser/type_updater.h \
  model/arithmetic_calculator/string_parser/types_mapper.h \
  model/arithmetic_calculator/token/token.h \
  model/arithmetic_calculator/token/token_data.h \
  model/arithmetic_calculator/token/types.h \
  model/arithmetic_calculator/token/types_pair.h \
  model/arithmetic_calculator/vectors/expression.h \
  model/arithmetic_calculator/vectors/lexemes.h \
  model/arithmetic_calculator/vectors/numbers.h \
  model/arithmetic_calculator/vectors/stack.h \
  model/arithmetic_calculator/vectors/vector.h \
  model/credit_calculator/credit_calculator.h \
  model/deposit_calculator/deposit_calculator.h \
  structs/credit.h \
  structs/credit_payment.h \
  structs/deposit.h \
  structs/deposit_payment.h \
  view/calculator_view/calculator_view.h \
  $$PWD/view/calculator_view/qcustomplot.h \
  view/credit_calculator_view/credit_calculator_view.h \
  view/deposit_calculator_view/deposit_calculator_view.h

FORMS += \
  view/calculator_view/calculator_view.ui \
  view/credit_calculator_view/credit_calculator_view.ui \
  view/deposit_calculator_view/deposit_calculator_view.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
  view/calculator.qrc
