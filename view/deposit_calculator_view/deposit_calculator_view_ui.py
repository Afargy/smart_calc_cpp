# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file '/home/babaka/wspace/CPP3_SmartCalc_v2.0-1/src/view/deposit_calculator_view/deposit_calculator_view.ui'
#
# Created by: PyQt5 UI code generator 5.15.6
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_DepositCalculatorView(object):
    def setupUi(self, DepositCalculatorView):
        DepositCalculatorView.setObjectName("DepositCalculatorView")
        DepositCalculatorView.resize(457, 524)
        self.gridLayout = QtWidgets.QGridLayout(DepositCalculatorView)
        self.gridLayout.setObjectName("gridLayout")
        self.formLayout = QtWidgets.QFormLayout()
        self.formLayout.setObjectName("formLayout")
        self.label_income = QtWidgets.QLabel(DepositCalculatorView)
        self.label_income.setObjectName("label_income")
        self.formLayout.setWidget(1, QtWidgets.QFormLayout.LabelRole, self.label_income)
        self.income = QtWidgets.QLineEdit(DepositCalculatorView)
        self.income.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.income.setReadOnly(True)
        self.income.setObjectName("income")
        self.formLayout.setWidget(1, QtWidgets.QFormLayout.FieldRole, self.income)
        self.label_tax_amount = QtWidgets.QLabel(DepositCalculatorView)
        self.label_tax_amount.setObjectName("label_tax_amount")
        self.formLayout.setWidget(2, QtWidgets.QFormLayout.LabelRole, self.label_tax_amount)
        self.tax_amount = QtWidgets.QLineEdit(DepositCalculatorView)
        self.tax_amount.setText("")
        self.tax_amount.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.tax_amount.setReadOnly(True)
        self.tax_amount.setObjectName("tax_amount")
        self.formLayout.setWidget(2, QtWidgets.QFormLayout.FieldRole, self.tax_amount)
        self.label_finite_amount = QtWidgets.QLabel(DepositCalculatorView)
        self.label_finite_amount.setObjectName("label_finite_amount")
        self.formLayout.setWidget(3, QtWidgets.QFormLayout.LabelRole, self.label_finite_amount)
        self.finite_amount = QtWidgets.QLineEdit(DepositCalculatorView)
        self.finite_amount.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.finite_amount.setReadOnly(True)
        self.finite_amount.setObjectName("finite_amount")
        self.formLayout.setWidget(3, QtWidgets.QFormLayout.FieldRole, self.finite_amount)
        self.button_calculate = QtWidgets.QPushButton(DepositCalculatorView)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.button_calculate.sizePolicy().hasHeightForWidth())
        self.button_calculate.setSizePolicy(sizePolicy)
        self.button_calculate.setObjectName("button_calculate")
        self.formLayout.setWidget(4, QtWidgets.QFormLayout.SpanningRole, self.button_calculate)
        self.groupBox = QtWidgets.QGroupBox(DepositCalculatorView)
        self.groupBox.setTitle("")
        self.groupBox.setObjectName("groupBox")
        self.gridLayout_2 = QtWidgets.QGridLayout(self.groupBox)
        self.gridLayout_2.setObjectName("gridLayout_2")
        self.label_tax_rate = QtWidgets.QLabel(self.groupBox)
        self.label_tax_rate.setObjectName("label_tax_rate")
        self.gridLayout_2.addWidget(self.label_tax_rate, 5, 0, 1, 1)
        self.label_amount = QtWidgets.QLabel(self.groupBox)
        self.label_amount.setObjectName("label_amount")
        self.gridLayout_2.addWidget(self.label_amount, 1, 0, 1, 1)
        self.label_term = QtWidgets.QLabel(self.groupBox)
        self.label_term.setObjectName("label_term")
        self.gridLayout_2.addWidget(self.label_term, 3, 0, 1, 1)
        self.tax = QtWidgets.QDoubleSpinBox(self.groupBox)
        self.tax.setMaximum(1000.0)
        self.tax.setProperty("value", 5.0)
        self.tax.setObjectName("tax")
        self.gridLayout_2.addWidget(self.tax, 5, 1, 1, 1)
        self.interest = QtWidgets.QDoubleSpinBox(self.groupBox)
        self.interest.setMaximum(1000.0)
        self.interest.setProperty("value", 5.0)
        self.interest.setObjectName("interest")
        self.gridLayout_2.addWidget(self.interest, 4, 1, 1, 1)
        self.capitalization = QtWidgets.QCheckBox(self.groupBox)
        self.capitalization.setChecked(True)
        self.capitalization.setObjectName("capitalization")
        self.gridLayout_2.addWidget(self.capitalization, 7, 1, 1, 1)
        self.term = QtWidgets.QSpinBox(self.groupBox)
        self.term.setMinimum(1)
        self.term.setMaximum(100000000)
        self.term.setSingleStep(30)
        self.term.setProperty("value", 30)
        self.term.setObjectName("term")
        self.gridLayout_2.addWidget(self.term, 3, 1, 1, 1)
        self.label_capitalization_of_interest = QtWidgets.QLabel(self.groupBox)
        self.label_capitalization_of_interest.setObjectName("label_capitalization_of_interest")
        self.gridLayout_2.addWidget(self.label_capitalization_of_interest, 7, 0, 1, 1)
        self.label_interest_rate = QtWidgets.QLabel(self.groupBox)
        self.label_interest_rate.setObjectName("label_interest_rate")
        self.gridLayout_2.addWidget(self.label_interest_rate, 4, 0, 1, 1)
        self.initial_amount = QtWidgets.QDoubleSpinBox(self.groupBox)
        self.initial_amount.setMaximum(1e+19)
        self.initial_amount.setSingleStep(10000.0)
        self.initial_amount.setProperty("value", 1000.0)
        self.initial_amount.setObjectName("initial_amount")
        self.gridLayout_2.addWidget(self.initial_amount, 1, 1, 1, 1)
        self.label_periodicity_of_payments = QtWidgets.QLabel(self.groupBox)
        self.label_periodicity_of_payments.setObjectName("label_periodicity_of_payments")
        self.gridLayout_2.addWidget(self.label_periodicity_of_payments, 2, 0, 1, 1)
        self.payment_period = QtWidgets.QComboBox(self.groupBox)
        self.payment_period.setObjectName("payment_period")
        self.payment_period.addItem("")
        self.payment_period.addItem("")
        self.payment_period.addItem("")
        self.payment_period.addItem("")
        self.gridLayout_2.addWidget(self.payment_period, 2, 1, 1, 1)
        self.formLayout.setWidget(0, QtWidgets.QFormLayout.SpanningRole, self.groupBox)
        self.gridLayout.addLayout(self.formLayout, 4, 0, 1, 1)

        self.retranslateUi(DepositCalculatorView)
        QtCore.QMetaObject.connectSlotsByName(DepositCalculatorView)

    def retranslateUi(self, DepositCalculatorView):
        _translate = QtCore.QCoreApplication.translate
        DepositCalculatorView.setWindowTitle(_translate("DepositCalculatorView", "Form"))
        self.label_income.setText(_translate("DepositCalculatorView", "Income"))
        self.label_tax_amount.setText(_translate("DepositCalculatorView", "Tax amount"))
        self.label_finite_amount.setText(_translate("DepositCalculatorView", "Deposit amount"))
        self.button_calculate.setText(_translate("DepositCalculatorView", "Calculate"))
        self.label_tax_rate.setText(_translate("DepositCalculatorView", "Tax rate"))
        self.label_amount.setText(_translate("DepositCalculatorView", "Deposit amount"))
        self.label_term.setText(_translate("DepositCalculatorView", "deposit term (days)"))
        self.capitalization.setText(_translate("DepositCalculatorView", "CheckBox"))
        self.label_capitalization_of_interest.setText(_translate("DepositCalculatorView", "Capitalization of interest"))
        self.label_interest_rate.setText(_translate("DepositCalculatorView", "Interest rate"))
        self.label_periodicity_of_payments.setText(_translate("DepositCalculatorView", "Periodicity of payments"))
        self.payment_period.setItemText(0, _translate("DepositCalculatorView", "Daily"))
        self.payment_period.setItemText(1, _translate("DepositCalculatorView", "Monthly"))
        self.payment_period.setItemText(2, _translate("DepositCalculatorView", "Quarterly"))
        self.payment_period.setItemText(3, _translate("DepositCalculatorView", "Annually"))
