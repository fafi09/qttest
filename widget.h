#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include "subwidget.h"
#include <QDebug>
#include "mybuttonmemnoleak.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    QPushButton b1;
    QPushButton *b2;
    QPushButton b3;
    SubWidget subw;
public slots:
    void b1Slot();

    void subSlot();

    void mainSlot();
    void dealSlot(int, QString);

};
#endif // WIDGET_H
