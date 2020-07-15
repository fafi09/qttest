#include "subwidget.h"

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    b1.setWindowTitle("sub");
    b1.setText("switch to mainwin");
    b1.setParent(this);
    b1.move(100,100);

    connect(&b1, &QPushButton::clicked, this, &SubWidget::sendSlot);

}

void SubWidget::sendSlot()
{
    emit mySignal();
    emit mySignal(12,"asdfdf");
}
