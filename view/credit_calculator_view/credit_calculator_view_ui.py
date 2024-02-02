# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file '/home/babaka/wspace/CPP3_SmartCalc_v2.0-1/src/view/credit_calculator_view/credit_calculator_view.ui'
#
# Created by: PyQt5 UI code generator 5.15.6
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_CreditCalculatorView(object):
    def setupUi(self, CreditCalculatorView):
        CreditCalculatorView.setObjectName("CreditCalculatorView")
        CreditCalculatorView.resize(900, 647)
        self.gridLayout = QtWidgets.QGridLayout(CreditCalculatorView)
        self.gridLayout.setObjectName("gridLayout")
        self.lable_amount = QtWidgets.QLabel(CreditCalculatorView)
        self.lable_amount.setObjectName("lable_amount")
        self.gridLayout.addWidget(self.lable_amount, 0, 0, 1, 1)
        self.amount = QtWidgets.QDoubleSpinBox(CreditCalculatorView)
        self.amount.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.amount.setDecimals(2)
        self.amount.setMaximum(1000000000000000.0)
        self.amount.setSingleStep(10000.0)
        self.amount.setProperty("value", 1000.0)
        self.amount.setObjectName("amount")
        self.gridLayout.addWidget(self.amount, 0, 1, 1, 2)
        self.lable_term = QtWidgets.QLabel(CreditCalculatorView)
        self.lable_term.setObjectName("lable_term")
        self.gridLayout.addWidget(self.lable_term, 1, 0, 1, 1)
        self.term = QtWidgets.QSpinBox(CreditCalculatorView)
        self.term.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.term.setMaximum(1000)
        self.term.setProperty("value", 12)
        self.term.setObjectName("term")
        self.gridLayout.addWidget(self.term, 1, 1, 1, 2)
        self.lable_interest_rate = QtWidgets.QLabel(CreditCalculatorView)
        self.lable_interest_rate.setObjectName("lable_interest_rate")
        self.gridLayout.addWidget(self.lable_interest_rate, 2, 0, 1, 1)
        self.interest_rate = QtWidgets.QDoubleSpinBox(CreditCalculatorView)
        self.interest_rate.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.interest_rate.setMaximum(1000.0)
        self.interest_rate.setProperty("value", 3.0)
        self.interest_rate.setObjectName("interest_rate")
        self.gridLayout.addWidget(self.interest_rate, 2, 1, 1, 2)
        self.lable_type = QtWidgets.QLabel(CreditCalculatorView)
        self.lable_type.setObjectName("lable_type")
        self.gridLayout.addWidget(self.lable_type, 3, 0, 1, 1)
        self.annuity = QtWidgets.QRadioButton(CreditCalculatorView)
        self.annuity.setCheckable(True)
        self.annuity.setChecked(True)
        self.annuity.setObjectName("annuity")
        self.gridLayout.addWidget(self.annuity, 3, 1, 1, 1)
        self.differentiated = QtWidgets.QRadioButton(CreditCalculatorView)
        self.differentiated.setObjectName("differentiated")
        self.gridLayout.addWidget(self.differentiated, 3, 2, 1, 1)
        self.button_count = QtWidgets.QPushButton(CreditCalculatorView)
        self.button_count.setObjectName("button_count")
        self.gridLayout.addWidget(self.button_count, 4, 1, 1, 1)
        self.button_clear = QtWidgets.QPushButton(CreditCalculatorView)
        self.button_clear.setObjectName("button_clear")
        self.gridLayout.addWidget(self.button_clear, 4, 2, 1, 1)
        self.result = QtWidgets.QGroupBox(CreditCalculatorView)
        self.result.setObjectName("result")
        self.gridLayout_3 = QtWidgets.QGridLayout(self.result)
        self.gridLayout_3.setObjectName("gridLayout_3")
        self.lable_monthly_payment = QtWidgets.QLabel(self.result)
        self.lable_monthly_payment.setObjectName("lable_monthly_payment")
        self.gridLayout_3.addWidget(self.lable_monthly_payment, 0, 0, 1, 1)
        self.lable_overpayment = QtWidgets.QLabel(self.result)
        self.lable_overpayment.setObjectName("lable_overpayment")
        self.gridLayout_3.addWidget(self.lable_overpayment, 1, 0, 1, 1)
        self.monthly_payment = QtWidgets.QLineEdit(self.result)
        self.monthly_payment.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.monthly_payment.setReadOnly(True)
        self.monthly_payment.setObjectName("monthly_payment")
        self.gridLayout_3.addWidget(self.monthly_payment, 0, 1, 1, 1)
        self.overpayment = QtWidgets.QLineEdit(self.result)
        self.overpayment.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.overpayment.setReadOnly(True)
        self.overpayment.setObjectName("overpayment")
        self.gridLayout_3.addWidget(self.overpayment, 1, 1, 1, 1)
        self.total_payment = QtWidgets.QLineEdit(self.result)
        self.total_payment.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.total_payment.setReadOnly(True)
        self.total_payment.setObjectName("total_payment")
        self.gridLayout_3.addWidget(self.total_payment, 2, 1, 1, 1)
        self.lable_total_payment = QtWidgets.QLabel(self.result)
        self.lable_total_payment.setObjectName("lable_total_payment")
        self.gridLayout_3.addWidget(self.lable_total_payment, 2, 0, 1, 1)
        self.gridLayout.addWidget(self.result, 5, 0, 1, 3)
        self.display = QtWidgets.QTextEdit(CreditCalculatorView)
        self.display.setObjectName("display")
        self.gridLayout.addWidget(self.display, 6, 0, 1, 3)

        self.retranslateUi(CreditCalculatorView)
        QtCore.QMetaObject.connectSlotsByName(CreditCalculatorView)

    def retranslateUi(self, CreditCalculatorView):
        _translate = QtCore.QCoreApplication.translate
        CreditCalculatorView.setWindowTitle(_translate("CreditCalculatorView", "Credit Calculator"))
        self.lable_amount.setText(_translate("CreditCalculatorView", "Total amount (RUB)"))
        self.lable_term.setText(_translate("CreditCalculatorView", "Term (month)"))
        self.lable_interest_rate.setText(_translate("CreditCalculatorView", "Interest rate (%)"))
        self.lable_type.setText(_translate("CreditCalculatorView", "Type"))
        self.annuity.setText(_translate("CreditCalculatorView", "annuity"))
        self.differentiated.setText(_translate("CreditCalculatorView", "differentiated"))
        self.button_count.setText(_translate("CreditCalculatorView", "Count"))
        self.button_clear.setText(_translate("CreditCalculatorView", "Clear"))
        self.result.setTitle(_translate("CreditCalculatorView", "Result"))
        self.lable_monthly_payment.setText(_translate("CreditCalculatorView", "monthly payment (RUB)"))
        self.lable_overpayment.setText(_translate("CreditCalculatorView", "overpayment on credit (RUB)"))
        self.lable_total_payment.setText(_translate("CreditCalculatorView", "total payment (RUB)"))
