#include <QRegularExpression>
#include "calcsystem.h"
#include <iostream>

const QRegularExpression& getRegex()
{
    static const QRegularExpression regex("[0-9]");
    return regex;
}

CalcSystem::CalcSystem(QObject *parent)
    : QObject{parent}
{}

void CalcSystem::calculate() {
    qreal fOperand2 = stk.pop().toDouble();
    QString strOperation = stk.pop();
    qreal fOperandl = stk.pop().toDouble();
    qreal fResult = 0;
    if (strOperation == "+") {
        fResult = fOperandl + fOperand2;
    }
    else if (strOperation == "-") {
        fResult = fOperandl - fOperand2;
    }
    else if (strOperation == "/") {
        fResult = fOperandl / fOperand2;
    }
    else if (strOperation == "*"){
        fResult = fOperandl * fOperand2;
    }
    m_display = QString::number(fResult);
}

void CalcSystem::slotButtonClicked(QString str) {
    if (str == "%") {
        if(stk.count() >= 2) {
            QString strOperation = stk.pop();
            qreal fOperand1 = stk.pop().toDouble();
            qreal fOperand2 = tempStr.toDouble();
            qreal tempVar = fOperand2 / 100 * fOperand1;
            tempStr = QString::number(tempVar);
            setDisplay(tempStr);
            stk.push(QString::number(fOperand1));
            stk.push(strOperation);
        }
        return;
    }
    if (str == "C") {
        stk.clear();
        tempStr = "";
        setDisplay("0");
        return;
    }
    if (str == "CE") {
        tempStr = "";
        setDisplay("0");
        return;
    }
    if (str == "1/x") {
        double real = 1 / (m_display.toDouble());
        tempStr = QString::number(real);
        setDisplay(tempStr);
        return;
    }
    if (str == "X^2") {
        double real = pow(m_display.toDouble(), 2);
        tempStr = QString::number(real);
        setDisplay(tempStr);
        return;
    }
    if (str == "Back") {
        tempStr.removeLast();
        setDisplay(tempStr);
        return;
    }
    if (str == "root") {
        double real = sqrt(m_display.toDouble());
        tempStr = QString::number(real);
        setDisplay(tempStr);
        return;
    }
    if (str == "+/-") {
        double temp = -m_display.toDouble();
        tempStr = QString::number(temp);
        setDisplay(tempStr);
        return;
    }
    if (str.contains(getRegex())) {
        if(tempStr == "0" and str == "0") return;
        tempStr += str;
        setDisplay(tempStr);
    }
    else if (str == ".") {
        tempStr += str;
        setDisplay(tempStr);
    }
    else {
        if (stk.count() >= 2) {
            stk.push(QString().setNum(m_display.toDouble()));
            calculate();
            stk.clear();
            tempStr = "";
            stk.push(QString().setNum(m_display.toDouble()));
            if (str != "=") {
                stk.push(str);
            }
        }
        else {
            stk.push(QString().setNum(m_display.toDouble()));
            stk.push(str);
            tempStr = "";
        }
    }
    emit displayChanged();
    std::cout << stk.count();
}

QString CalcSystem::display() {
    return m_display;
}

void CalcSystem::setDisplay(QString str) {
    m_display = str;
    emit displayChanged();
}
