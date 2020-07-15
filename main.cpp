#include "widget.h"

#include <QApplication>
#include <QPushButton>

/*
 * test.pro.user保存了用户的环境信息，
 * 如果编译别人的程序要把此文件删除
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    QPushButton btn;

    btn.move(500,0);
    btn.setParent(&w);
    btn.setText(QString("close"));
    btn.show();

    QObject::connect(&btn, &QPushButton::clicked, &w, &Widget::close);
    /* btn:信号发出者
     * &QPushButton::clicked处理的信号 &发送者的类名::信号名
     * &w信号接受者
     * &Widget::close槽函数，信号处理函数 &接受的类名::槽函数的名字
     *
     */
    return a.exec();
}
