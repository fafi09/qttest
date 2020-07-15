#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>

class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = nullptr);
    void sendSlot();
signals:
    /*
     * //信号必须有这个关键字声明，
     * 信号没有返回值，可以有参数
     * 信号就是函数声明，只需声明，无需定义
     *使用：mySignal
     * 信号可以重载
     */
    void mySignal();
    void mySignal(int, QString);

private:
    QPushButton b1;
};

#endif // SUBWIDGET_H
