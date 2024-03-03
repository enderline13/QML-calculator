#ifndef CALCSYSTEM_H
#define CALCSYSTEM_H

#include <QObject>
#include <QStack>
#include <QString>

class CalcSystem : public QObject
{
    Q_OBJECT
    QStack<QString> stk;
    QString tempStr;
    QString m_display;
    Q_PROPERTY(QString display MEMBER m_display READ display WRITE setDisplay NOTIFY displayChanged)
public:
    explicit CalcSystem(QObject *parent = nullptr);
    void calculate();
    QString display();
    void setDisplay(QString);
Q_SIGNALS:
    void displayChanged();
public Q_SLOTS:
    void slotButtonClicked(QString);
};

#endif // CALCSYSTEM_H
